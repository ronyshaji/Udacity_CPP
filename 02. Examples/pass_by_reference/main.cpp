#include <iostream>

void add(int &x)
{
    x += 10;
}

int main()
{
    int val = 0;
    std::cout << "The updated value before function call is " << val << std::endl;
    add(val);
    val += 2;
    std::cout << "The updated value after function call is " << val << std::endl;
}