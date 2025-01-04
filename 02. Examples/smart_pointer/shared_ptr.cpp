#include <iostream>
#include <memory>

class MyClass
{
    public:
        ~MyClass()
        {
            std::cout << "Destructor of MyClass is called" << std::endl;
        }
};

int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "Shared pointer count " << shared1.use_count() << std::endl;

    //Shared2 goe sout of scope after the curly braces
    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "Shared pointer count " << shared1.use_count() << std::endl;
    }

    std::cout << "Shared pointer count " << shared1.use_count() << std::endl;


    // A shared pointer can also be redirected by using the reset() function. 
    // If the resource which a shared pointer manages is no longer needed in the current scope, the pointer can be reset to manage a difference resource
    std::cout << "Reset Function " << std::endl;
    std::shared_ptr<MyClass> shared(new MyClass);
    std::cout << "Shared pointer count " << shared.use_count() << std::endl;

    shared.reset(new MyClass);
    std::cout << "Shared pointer count " << shared.use_count() << std::endl;
}