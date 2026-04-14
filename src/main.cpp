
#include "A.h"
#include <iostream>
#include <memory> // for unique pointer
#include <string>

#include "DeepCopyClass.h"

int getIntFromUser()
{
    std::string input;
    int number;

    while (true)
    {
        try
        {
            std::cout << "Enter an integer: ";
            std::getline(std::cin, input);

            number = std::stoi(input);  // יכול לזרוק exception
            break;
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "Invalid input! Please enter a valid number.\n";
        }
        catch (const std::out_of_range&)
        {
            std::cout << "Number is too large or too small.\n";
        }
    }
    return number;
}

int main()
{

	deepCopyExample();

	A a;
	a.getSize();
	std::cout << "size: " << a.getSize()<<endl;
	printHello();
	
	//A *arr = new A[5];
	//delete [] arr;
/*

//	cout<<"init unique pointer arr\n";
//	auto arr2 = std::make_unique<A[]>(3);
	auto arr2 = std::make_unique<A[]>(4);
	
	getIntFromUser();
	
	// Template examples:
	cout << myMax(3, 7) << endl;        // int
    	cout << myMax(2.5, 1.1) << endl;    // double
    	cout << myMax('a', 'z') << endl;    // char
	//cout << myMax(3.0, 7) << endl;    // illegal*/
    	cout <<"End of program\n";
	return 0;
}
