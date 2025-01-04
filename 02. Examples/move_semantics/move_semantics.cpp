#include <iostream>


class MoveableClass
{
    public:
        MoveableClass(size_t size)
        {
            size_ = size;
            data_ = new int[size_];
            std::cout << "creating instance of Moveable class at " << this << " allocated with size " << size_*sizeof(int) << " bytes" << std::endl;
        }

        ~MoveableClass()
        {   
            std::cout << "Deleing the instance of Moveable class at " << this << std::endl;
            delete[] data_;
        }

        MoveableClass(const MoveableClass &source)
        {
            size_ = source.size_;
            data_ = new int[size_];
            *data_ = *source.data_;

            std::cout <<"Copy Constructor: Copying instance from "<< &source << " to the instance " << this << std::endl;
        }

        MoveableClass &operator=(const MoveableClass &source)
        {
            std::cout << "Assignment operator: Assigning instance of " << &source << " to instance of " << this << std::endl;
            if (this == &source) { return *this; }

            size_ = source.size_;
            data_ = new int[size_];
            *data_ = *source.data_;
            return *this;
        }
        MoveableClass(MoveableClass &&source)
        {
            std::Cout << "Move constructor: Moving instance of " << &source << " to instance " << this << std::endl;
            size_ = source.size_;
            data_ = source.data_;
            source.data_ = nullptr;
            source.size_ = 0;
        }

        MoveableClass &operator=(MoveableClass &&source)
        {
            std::cout << "Move Assignment: Assigning instance of " << &source << " to instance " << this << std::endl;

            if (this == &source) { return *this; }

            delete[] data_;

            data_ = source.data_;
            size_ = source.size_;
            source.data_ = nullptr;
            source.size_ = 0;
        }

    private:
        int size_;
        int *data_;
};

int main()
{
    int size = 5;
    MoveableClass m(size); //calls default constructor
    MoveableClass n(m); // calls copy constructor
    MoveableClass o = m; //calls the copy constructor agains since o is initialised now only;
    n = m; // calls assignemnt operator since n is instantiated earlier.

    return 0;
}