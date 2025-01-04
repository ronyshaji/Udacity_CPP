#include <iostream>

// The important message to the reader is that the function argument of myFunc is a rvalue reference.
// The object that binds to the rvalue reference &&val is yours, it is not needed anymore within the scope of the caller (which is main)

// Perpectives:
// - Passing values like this improves performance as no temporary copy needs to be made anymore
// - ownership changes, since the object the reference binds to has been abandoned by the caller and now binds to a 
//   handle which is available only to the receiver. This could not have been achieved with lvalue references as any change to the object 
//   that binds to the lvalue reference would also be visible on the caller side.

//rvalue references are themselves lvalues

void myFunc(int &&val)
{
    std::cout << val;
}

int main()
{
    myFunc(42);

    int i = 10;
    myFunc(i); // Not possible. rvalue reference cannot bind to an lvalue. The solution to this problem is std::move

    // std::move - converts an lvalue into an rvalue 

    myFunc(std::move(i)); // now in the scope of main we will not use i anymore, which now exists only in the scope of myFunc

    return 0;
}