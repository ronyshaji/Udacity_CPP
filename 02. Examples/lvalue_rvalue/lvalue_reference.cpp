#include <iostream>

void myFunc(int &k)
{
    k++;
}

int main()
{
    int i = 10;
    int &j = i;
    ++i;
    ++j;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    // One of the primary use-cases for lvalue references is the pass-by-reference semantics in function calls.

    myFunc(i);
    // myFunc(42); Doesnot work since the function is defined for lvalue reference as parameter ->cant pass rvalue

    return 0;
}
