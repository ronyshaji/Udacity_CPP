#include <iostream>

// Here val is a rvalue reference so it can only take rvalues.
// While using rvalue reference(&&), the function caller loses the ownership of that object(here 42)
// Although val is an rvalue reference, it is still a lvalue in the scope of myFunc, since it stores the address of an rvalue.
// Also, here no copy operation, since the ownership is transferred and 42 is not available in main() anymore
// But we cant pass an lvalue through the fucntion call like myFunc(i), since the int &&val expects an rvalue.
// Inorder to convert lvalue to rvalue we can use a std::move() from move semantics which is more efficient that lvalue reference passing
// While lvalue reference passing, the object is still available in the main function and any change made in myFunc() with reflect in main()


void myFunc(int &&val)
{
    std::cout << "val: " << val << std::endl;
}

int main()
{
    int i = 10;

    myFunc(42);

    //Doesnot work since passing lvalue to an rvalue
    //myFunc(i);

    //Works as std::move converts lvalue to rvalue(xvalue to be precise)
    myFunc(std::move(i));
}