#include "DeepCopyClass.h"

void deepCopyExample() {

    cout << "===== SHALLOW COPY =====\n";
    {
        DeepCopyClass a(3, false);
        DeepCopyClass b = a;

        b.set(0, 99);

        a.print("a"); // משתנה!
        b.print("b");
    }

    cout << "\n===== DEEP COPY =====\n";
    {
        DeepCopyClass a(3, true);
        DeepCopyClass b = a;

        b.set(0, 99);

        a.print("a"); // לא משתנה
        b.print("b");
    }

 
}
