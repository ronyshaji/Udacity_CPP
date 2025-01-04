#include <iostream>
#include <memory>

int main()
{
    //Construct a unique pointer
    std::unique_ptr<int> uniquePtr(new int);

    // (1) Shared pointer from unique pointer
    std::shared_ptr<int> sharedPtr1 = std::move(uniquePtr);

    // (2) Shared pointer from weak pointer
    std::weak_ptr<int> weakPtr(sharedPtr1);
    std::shared_ptr<int> sharedPtr2 = weakPtr.lock();

    // (3) Raw pointer from shared (or unique pointer) pointer
    int *rawPtr = sharedPtr2.get();
    delete rawPtr;

    return 0;
}