#include <iostream>
#include <memory>


int main()
{
    std::shared_ptr<int> s1(new int);
    std::weak_ptr<int> w1(s1);

    s1.reset(new int);

    if (w1.expired() == true)
    {
        std::cout << "Weak pointer expired" <<std::endl;
    }

    return 0;
}