#include <iostream>
#include <memory>
#include <string>

class uPointer
{
public:
    uPointer() {}
    uPointer(std::string text)
    {
        text_ = text;
    }

    ~uPointer()
    {
        std::cout << text_ << " destroyed" << std::endl;
    }

    void setText(std::string text)
    {
        text_ = text;
    }

private:
    std::string text_;
};

int main()
{

    // create two unique pointers
    std::unique_ptr<uPointer> uP1(new uPointer());
    std::unique_ptr<uPointer> uP2(new uPointer("Rony"));

    // Calling memeber function just like a raw pointer
    uP1->setText("Shaji");

    // Dereferencing like  araw pointer
    *uP1 = *uP2;

    // Using the .get() to get the addresses of the heap memory where the smart pointer is pointing.
    std::cout << "Objects have heap address " << uP1.get() << " and " << uP2.get() << std::endl;

    return 0;
}