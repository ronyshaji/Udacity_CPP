#include <iostream>

int main()
{
    // initialize some variables on the stack
    int i, j, *p;

    i = 42;  //i is an lvalue and 42 is an rvalue

    p = new int;
    *p = i; //the dereferenced pointer is an ivalue
    delete p;

    ((i < 42) ? i : j) = 23;  //The conditional operator returns an lvalue 


    // incorrect usage of lvalues and rvalues
    //42 = i; // error : the left operand must be an lvalue
    //j * 42 = 23; // error : the left operand must be an lvalue

    // Using the address operator & we can generate an lvalue from an rvalue and assign it to another lvalue:

    int *k = &i; //*k is an rvalue    

    return 0;
}