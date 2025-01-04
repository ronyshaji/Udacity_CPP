#include <iostream>
#include <stdlib.h>

// overload syntax --> void* operator new(size_t size);

// The operator receives a parameter size of type size_t, which specifies the number of bytes of memory to be allocated.
// The return type of the overloaded new is a void pointer, which references the beginning of the block of allocated memory.

// delete overload syntax --> void operator delete(void*)

// The operator takes a pointer to the object which is to be deleted. As opposed to new, the operator delete does not have a return value.

class myClass
{
public:
    myClass()
    {
        std::cout << "Constrctor called " << std::endl;
    }

    ~myClass()
    {
        std::cout << "Destructor called " << std::endl;
    }

    void *operator new(size_t size)
    {
        std::cout << "Allocating " << size << " of memory" << std::endl;
        void *p = malloc(size); // new can also be used

        return p;
    }

    void operator delete(void *p)
    {
        std::cout << "Deallocating memory" << std::endl;
        free(p);
    }

    // Overloading new[] and delete[]

    void *operator new[](size_t size)
    {
        std::cout << "Allocating " << size << " of memory" << std::endl;
        void *p = malloc(size); // new can also be used

        return p;
    }

    void operator delete[](void *p)
    {
        std::cout << "Deallocating memory" << std::endl;
        free(p);
    }
};

int main()
{
    myClass *my = new myClass[3]();
    delete[] my;
}