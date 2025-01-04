#include <iostream>

class myInt
{
    private:
        int *p_;

    public:
        myInt(int *p = NULL)
        {
            p_ = p;
        }
        ~myInt()
        {
            std::cout << "Resource " << *p_ << " deallocated\n";
            delete p_;
        }

        //Operator overloading

        int &operator*()
        {
            return *p_; 
        }
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    for (size_t i = 0; i < 5; i++)
    {
        //allocate the resource on the stack
        myInt en(new int(i));

        //use the resource
        std::cout << *en << "/"<< den[i] << " = " << *en/den[i] << std::endl;
    }

    return 0;
}

// Here the RAII class is responsible for the deletion. Since the object is on the stack, after each loop, it goes out of scope and deletes the resource allocated