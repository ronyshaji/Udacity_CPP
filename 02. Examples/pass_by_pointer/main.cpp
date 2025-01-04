#include <iostream>

void addThree(int *val)
{
    *val += 3;
}

int main()
{
    int val = 0;
    std::cout << "The updated value before function call is " << val << std::endl;
    addThree(&val);
    std::cout << "The updated value after function call is " << val << std::endl; 

    return 0;

}