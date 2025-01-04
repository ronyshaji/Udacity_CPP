#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;

    myFunction(j);
    myFunction(42); //Cant pass an rvalue 

    int k = 23; 
    myFunction(j+k); // j+k is an rvalue since it is in an arbitrary location and cant pass.

    //rvalue reference
    int &&sum = j+k; //with && operator, now its possible to modify or store an rvalue,  i.e. a temporary object which would otherwise be lost quickly.
    myFunction(sum); //valid here since we can pass rvalue reference to an lvalue reference

    return 0; 
}

//so why we are using int &&sum instead of saving in a new variable like int sum = j+k an dthen pass sum as argument ?
// - The sum i+j is created as an rvalue, which holds the result of the addition before being copied into the memory location of sum. 
// - This is quite a lot of copying and holding of temporary values in memory. With an rvalue reference, this can be done more efficiently.

// Move semantics and rvalue references make it possible to write code that transfers resources such as dynamically allocated memory 
// from one object to another in a very efficient manner and also supports the concept of exclusive ownership,