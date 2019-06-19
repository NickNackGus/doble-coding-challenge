//
// The program is supposed to print out the following:
//
//  1 2 3 4 5
//  2 4 6 8 10
//
// But it prints out:
//
//  1 2 3 4 5
//  1 2 3 4 5
//
// See if you can fix the bug.
//

#include <iostream>
#include <memory>
#include <vector>

class Object
{
public:
    Object(int value) : m_value(value) {};
    int m_value;
};

int main()
{
    std::vector<Object> objects = { Object(1), Object(2), Object(3), Object(4), Object(5) };

    for (auto & obj : objects)
    {
        std::cout << obj.m_value << " ";
        obj.m_value *= 2;
    }
    std::cout << std::endl;

    for (auto & obj : objects)
    {
        std::cout << obj.m_value << " ";
    }
    std::cout << std::endl;

    return 0;
}
