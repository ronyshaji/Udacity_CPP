#include <iostream>
#include <stdlib.h>

class Example
{
    public:
        Example()
        {
            std::cout << "The constructor is called \n";
            number_ = (int*)malloc(sizeof(int));
        }

        ~Example()
        {
            std::cout << "Destrcutor is called \n";
            free(number_);
        }

        void setNumber(int num)
        {
            *number_ = num; 
            std::cout << *number_ <<"\n";
        }
    
    private:
        int *number_ = nullptr;
};

int main()
{
    //Example *eg = (Example*)malloc(sizeof(Example));
    //eg->setNumber(20);
    //free(eg);

    Example *eg1 = new Example();
    eg1->setNumber(20);
    delete eg1;
}