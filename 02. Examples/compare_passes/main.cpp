#include <iostream>

void callByValue(int i)
{
    int j = 0;
    std::cout << "Call by value: " << &j << "\n";
}

void callByPointer(int *i)
{
    int j = 0;
    std::cout << "Call by pointer: " << &j << "\n";
}

void callByReference(int &i)
{
    int j = 0;
    std::cout << "Call by reference: " << &j << "\n";
}

int main()
{
    int val = 0;
    std::cout << "Stack bottom " << &val << "\n";

    std::vector<int> m = {10, 20, 30};

    callByValue(val);

    callByPointer(&val);

    callByReference(val);

    return 0;

}

// Here in this example, the memory required for callByValue is less than callByPointer and callByReference
// This is becuase the size of int *i is about 8 bytes as compared to the size of int i (4 bytes)
// Earlier we have argued at length that passing a parameter by reference avoids a costly copy and should - in many situations - be preferred over passing a parameter by value. Yet, in the experiment above, we have witnessed the exact opposite.
// In order to benefit from call-by-reference, the size of the data type passed to the function has to surpass the size of the pointer on the respective architecture (i.e. 32 bit or 64 bit).