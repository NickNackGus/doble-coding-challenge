//
// The program is supposed to print out the name of each object in the objects array.
//
// Like so:
//
// My name is: Base
// My name is: Derived0
// My name is: Derived1
//
// But it prints out:
//
// My name is: Base
// My name is: Base
// My name is: Base
//
// See if you can fix the bug.
//

#include <iostream>
#include <memory>
#include <vector>

class Base
{
public:
    void printName()
    {
        std::cout << "My name is: " << getName() << std::endl;
    }

protected:
    virtual std::string getName()
    {
        return "Base";
    }
};

class Derived0 : public Base
{
protected:
    std::string getName()
    {
        return "Derived0";
    }
};

class Derived1 : public Base
{
protected:
    std::string getName()
    {
        return "Derived1";
    }
};

int main()
{
    std::vector<std::shared_ptr<Base>> objects = {
        std::make_shared<Base>(),
        std::make_shared<Derived0>(),
        std::make_shared<Derived1>(),
    };

    for (auto object : objects)
    {
        object->printName();
    }

    return 0;
}
