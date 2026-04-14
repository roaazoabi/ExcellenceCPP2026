#include <iostream>
#include <utility> // עבור std::move

class Buffer {
private:
    int* data;
    size_t size;

public:
    // 1. בנאי רגיל (Constructor)
    Buffer(size_t s) : size(s), data(new int[s]) {
        std::cout << "Constructor: Allocated " << size << " elements.\n";
    }

    // 2. מפרק (Destructor)
    ~Buffer() {
        if (data != nullptr) {
            std::cout << "Destructor: Freed memory.\n";
            delete[] data;
        } else {
            std::cout << "Destructor: Object was empty (moved), nothing to free.\n";
        }
    }

    // --- החלק החשוב: Move Semantics ---

    // 3. Move Constructor (בנאי העברה)
    // שים לב לשימוש ב-noexcept, שמבטיח שהפעולה לא תזרוק חריגות (חשוב עבור ביצועים ב-STL)
    Buffer(Buffer&& other) noexcept : data(nullptr), size(0) {
        std::cout << "Move Constructor: Stealing resources.\n";
        
        // "גניבת" המשאבים מהאובייקט הישן
        data = other.data;
        size = other.size;

        // איפוס האובייקט הישן כדי שה-Destructor שלו לא ישחרר את הזיכרון שגנבנו
        other.data = nullptr;
        other.size = 0;
    }

    // 4. Move Assignment Operator (אופרטור השמת העברה)
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "Move Assignment Operator: Stealing resources.\n";
        
        // בדיקה שאיננו מנסים להציב את האובייקט לתוך עצמו (למשל a = std::move(a))
        if (this != &other) {
            // שחרור הזיכרון הקיים של האובייקט הנוכחי
            delete[] data;

            // "גניבת" המשאבים החדשים
            data = other.data;
            size = other.size;

            // איפוס האובייקט הישן
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // ביטול פונקציות העתקה (Copy) כדי לוודא שבדוגמה הזו מתבצעת רק העברה
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;
};

// פונקציה שמקבלת את האובייקט By Value (ללא Reference)
// במצב רגיל זה היה דורש העתקה, אך בעזרת std::move זה יפעיל את ה-Move Constructor
void processBuffer(Buffer buf) {
    std::cout << "Inside processBuffer function.\n";
    // כאשר הפונקציה תסתיים, ה-Destructor של 'buf' יופעל
}

int main() {
    std::cout << "--- Creating b1 ---\n";
    Buffer b1(10); // קריאה לבנאי הרגיל

    std::cout << "\n--- Moving b1 to b2 ---\n";
    // שימוש ב-Move Constructor
    Buffer b2 = std::move(b1); 
    // כעת b1 ריק, והמשאבים שלו עברו ל-b2

    std::cout << "\n--- Creating b3 and Moving b2 to b3 ---\n";
    Buffer b3(20);
    // שימוש ב-Move Assignment Operator
    b3 = std::move(b2); 
    // b3 שחרר את ה-20 איברים שלו, ולקח את ה-10 איברים מ-b2

    std::cout << "\n--- Passing b3 to a function ---\n";
    // העברה לפונקציה כפרמטר
    processBuffer(std::move(b3)); 
    // b3 מועבר לתוך הפרמטר 'buf' בפונקציה באמצעות Move Constructor.
    // לאחר שורה זו, b3 יישאר ריק.

    std::cout << "\n--- End of main ---\n";
    return 0;
}
