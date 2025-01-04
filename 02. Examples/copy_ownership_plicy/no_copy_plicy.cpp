#include <iostream>

class noCopyClass1
{
    private:
        noCopyClass1(const noCopyClass1 &);
        noCopyClass1 &operator=(const noCopyClass1 &);

    public:
        noCopyClass1(){};
};

class noCopyClass2
{
    public:
        noCopyClass2(){};
        noCopyClass2(const noCopyClass2 &) = delete;
        noCopyClass2 &operator=(const noCopyClass2 &) = delete;
};

int main()
{
    noCopyClass1 org1;

    // Below lines 26 & 27 are not possible because of no copying policy of copy constructor
    noCopyClass1 org2(org1); // copy constructor
    noCopyClass1 org3 = org1; // assignment operator

    noCopyClass2 original;
    noCopyClass2 original2(original);
    noCopyClass2 original3 = original;
}