#include <iostream>

using namespace std;


// Template example for ma function.
// 2 arguments must be of the same type
template <typename T>
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}


inline void printHello()
{
   cout<<"Hello\n";
}

class A {

public: 
	A();
	~A();
	int getSize()const;
private:

	int m_size;
};
