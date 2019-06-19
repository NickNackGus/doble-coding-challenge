//
// The program implements a callback mechanism, whereby various objects can register
// callbacks with a manager object. The manager object can then dispatch events to 
// all the registered callbacks as shown.
//
// The expected output is:
//
// int Foo::fooCallback(int) : 5
// int Bar::barCallback(int) : 5
//
// You are asked to implement the registerCallback() function in the Manager class.
//

#include <functional>
#include <iostream>
#include <vector>

class Manager
{
public:
    template<typename T>
    void registerCallback(T* object, int (T::*handler)(int arg))
    {
        // Register a callback to run at a later time.

        // We need to use _1 as a placeholder arguement
        using namespace std::placeholders;

        // Create a valid callback entry
        std::function<int(int)> callback = std::bind(handler, object, _1);

        // Once we have a valid callback entry, we can add it to the vector.
        m_callbacks.push_back(callback);
    }

    // dispatch an event to all registered callbacks
    void dispatch(int arg)
    {
        for (auto& callback : m_callbacks)
        {
            callback(arg);
        }
    }

private:
    std::vector<std::function<int(int)>> m_callbacks;
};

class Foo
{
public:
    int fooCallback(int arg)
    {
        std::cout << __PRETTY_FUNCTION__ << " : " << arg << std::endl;
    }
};

class Bar
{
public:
    int barCallback(int arg)
    {
        std::cout << __PRETTY_FUNCTION__ << " : " << arg << std::endl;
    }
};

int main()
{
    Manager manager;

    Foo foo;
    Bar bar;

    manager.registerCallback(&foo, &Foo::fooCallback);
    manager.registerCallback(&bar, &Bar::barCallback);

    manager.dispatch(5);

    return 0;
}
