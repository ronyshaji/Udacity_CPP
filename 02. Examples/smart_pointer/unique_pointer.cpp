#include <iostream>
#include <memory>


void rawPointer()
{
    int *raw = new int;
    *raw = 5;
    std::cout << "Raw pointer " << *raw << std::endl;
    delete raw;
}

int main()
{

    std::unique_ptr<int> unique(new int); //create a unique pointer on the stack
    *unique = 2; // assign a value
    std::cout << "Smart pointer " << *unique << std::endl;
    rawPointer();
    return 0;
}