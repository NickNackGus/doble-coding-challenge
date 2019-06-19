//
// The main program leaks allocated memory.
//
// Memory allocated for pointers derived0 and derived1 is not freed.
//
// See if you can fix the bug.
//

#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "allocating base: " << __PRETTY_FUNCTION__ << std::endl;
        base = new int[100];
    }

    virtual ~Base()
    {
        std::cout << "freeing base: " << __PRETTY_FUNCTION__ << std::endl;
        delete[] base;
    }

private:
    int* base = nullptr;
};

class Derived0 : public Base
{
public:
    Derived0()
    {
        std::cout << "allocating derived0: " << __PRETTY_FUNCTION__ << std::endl;
        derived0 = new int[100];
    }

    ~Derived0()
    {
        std::cout << "freeing derived0: " << __PRETTY_FUNCTION__ << std::endl;
        delete[] derived0;
    }

private:
    int* derived0 = nullptr;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        std::cout << "allocating derived1: " << __PRETTY_FUNCTION__ << std::endl;
        derived1 = new int[100];
    }

    ~Derived1()
    {
        std::cout << "freeing derived1: " << __PRETTY_FUNCTION__ << std::endl;
        delete[] derived1;
    }

private:
    int* derived1 = nullptr;
};

int main()
{
    Base* p_base0 = new Derived0;
    Base* p_base1 = new Derived1;

    delete p_base0;
    delete p_base1;

    return 0;
}
