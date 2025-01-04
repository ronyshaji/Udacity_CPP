#include <iostream>

// Exclusive Ownership Policy
// This policy states that whenever a resource management object is copied, the resource handle is transferred from the source pointer to the destination pointer.
// In the process, the source pointer is set to nullptr to make ownership exclusive.
// At any time, the resource handle belongs only to a single object, which is responsible for its deletion when it is no longer needed.

// So normally if you use a copy constructor, only shallow copy happens. The pointer points to the memory location is copied but not the actual content in the memory location.

class exclusiveCopy
{
private:
    int *myInt_;

public:
    exclusiveCopy()
    {
        myInt_ = (int *)malloc(sizeof(int));
        std::cout << "Resource allocated" << std::endl;
    }
    ~exclusiveCopy()
    {
        if (myInt_ != nullptr)
        {
            free(myInt_);
            std::cout << "Resource freed" << std::endl;
        }
    }

    // copy constructor
    exclusiveCopy(exclusiveCopy &source)
    {

        myInt_ = source.myInt_;
        source.myInt_ = nullptr;
    }

    // assignment constructor

    exclusiveCopy &operator=(exclusiveCopy &source)
    {
        myInt_ = source.myInt_;
        source.myInt_ = nullptr;

        return *this;
    }
};

int main()
{
    exclusiveCopy exc;
    exclusiveCopy des(exc);
    exclusiveCopy sou = exc;
}