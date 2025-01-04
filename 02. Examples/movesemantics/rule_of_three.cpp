#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    
    MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

};

MyMovableClass createObject(int size){
  MyMovableClass obj(size); // regular constructor
  return obj; // return MyMovableClass object by value
}

int main()
{
    MyMovableClass obj1(10); // regular constructor
    MyMovableClass obj2(obj1); // copy constructor
    obj2 = obj1; // copy assignment operator
    
    MyMovableClass obj3 = obj1;  // Here, we are instantiating obj3 in the same statement; hence the copy assignment operator would not be called.
    MyMovableClass obj4 = createObject(10); // createObject(10) returns a temporary copy of the object as an rvalue, which is passed to the copy constructor. 

    return 0;
}

// limitations of the above class
// - In our current class design, while creating obj4, the data is dynamically allocated on the stack, which is then copied from the temporary object to its target destination. 
//   This means that two expensive memory operations are performed with the first occurring during the creation of the temporary rvalue and the second during the execution of the copy constructor. 
//   The similar two expensive memory operations would be performed with the assignment operator if we execute the following statement inside main: