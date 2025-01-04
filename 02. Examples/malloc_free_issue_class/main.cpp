#include <iostream>
#include <stdlib.h>

// malloc & calloc are functions where as new and delete are operators (can overload)
//with object oriented programming there is issue with malloc and free usage in c++

class myClass
{
    public:
        myClass()
        {
            std::cout << "Allocate memory \n";
            num_ = (int*)malloc(sizeof(int));
        }

        ~myClass()
        {
            std::cout << "Free memory \n";
            free(num_);
        }

        void setNumber(int number)
        {
            *num_ = number;
            std::cout << "The Number is " << *num_ << std::endl;
        }
    private:
        int *num_;
};

int main()
{
    /* HERE Malloc wont work since the constructor is never called --> No memory is created in heap*/

    /*myClass *my = (myClass*)malloc(sizeof(myClass));
    my->setNumber(42);
    free(my); */

    myClass *myy = new myClass();
    myy->setNumber(52);
    delete myy;

    return 0;
}

// In main, we will allocate memory for an instance of MyClass using both malloc/ free and new/delete.

// With malloc, the program crashes on calling the method setNumber, as no memory has been allocated for _num - because the constructor has not been called. 
// Hence, an EXC_BAD_ACCESS error occurs, when trying to access the memory location to which num_ is pointing. With _new, the output looks like the following:

// malloc returns a void pointer, which needs to be cast into the appropriate data type it points to. 
// This is not type safe, as you can freely vary the pointer type without any warnings or errors from the compiler as in the following small example: MyObject *p = (MyObject*)malloc(sizeof(int));