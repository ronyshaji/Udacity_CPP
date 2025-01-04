#include <iostream>

class Example
{
    public:
        Example(int num) : number_(num)
        {
            std::cout << "Constructor is called\n";
        }

        ~Example()
        {
            std::cout << "Destructor is called\n";
        }

        void* operator new(size_t size)
        {
            void* p = malloc(size);
            return p;
        }

        void operator delete(void* p)
        {
            std::cout << "Delete called\n";
            free(p);
        }

        void printNum()
        {
            std::cout << number_ << std::endl; 
        }

    private:
        int number_;
};

int main()
{
    Example* exmple = new Example(10);
    exmple->printNum();

    delete exmple;

}