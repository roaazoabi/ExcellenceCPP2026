#include <iostream>
using namespace std;

class DeepCopyClass {
private:
    int* data;
    int size;
    bool deepCopyMode;

public:
    // Constructor
    DeepCopyClass(int s, bool deepMode) {
        size = s;
        deepCopyMode = deepMode;
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }

        cout << "Constructor\n";
    }

    // Copy Constructor
    DeepCopyClass(const DeepCopyClass& other) {
        size = other.size;
        deepCopyMode = other.deepCopyMode;

        if (deepCopyMode) {
            // DEEP COPY
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
            cout << "Deep Copy Constructor\n";
        } else {
            // SHALLOW COPY
            data = other.data;
            cout << "Shallow Copy Constructor\n";
        }
    }

    // Destructor
    ~DeepCopyClass() {
        if (deepCopyMode) {
            delete[] data;
            cout << "Destructor (deep)\n";
        } else {
            cout << "Destructor (shallow - no delete)\n";
        }
    }

    void set(int index, int value) {
        data[index] = value;
    }

    void print(const string& name) {
        cout << name << ": ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

void deepCopyExample();
