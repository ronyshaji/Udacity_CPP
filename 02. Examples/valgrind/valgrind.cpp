#include <iostream>

void print(int &num)
{
    //num++;
    std::cout << num << std::endl;
}

int main()
{
    //int *ptr = new int[10];

    int i = 423;
    int &j = i;

    print(j++);

    return 0;
}