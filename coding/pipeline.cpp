//
// The program implements a producer consumer pattern with two threads.
//
// Work is exchanged between threads via a queue.
//
// While the program seems to work, it does not implement proper multithreading
// mutual exclusion and synchronization.
//
// Two mutexes - mutex and wait - are provided for this purpose.
//
// You are asked to implement proper mutual exclusion and synchronization between
// the threads.
//
#include <thread>
#include <iostream>
#include <mutex>
#include <queue>

std::queue<int> queue;
std::mutex mutex;
std::mutex wait;

class Foo
{
public:
    void operator()(int count)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        producer(count);
    }

private:
    void producer(int count)
    {
        for (int ii = 0; ii < count; ++ii)
        {
            mutex.lock();
            std::cout << __PRETTY_FUNCTION__ << "producing: " << ii << std::endl;
            queue.push(ii);
            wait.unlock();
        }
    }
};

class Bar
{
public:
    void operator()(int count)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        consumer(count);
    }

private:
    void consumer(int count)
    {
        int consumed = 0;

        do
        {
            while (queue.size() > 0)
            {
                wait.lock();
                std::cout << __PRETTY_FUNCTION__ << "consuming: " << queue.front() << std::endl;
                queue.pop();
                mutex.unlock();
                consumed++;
            }

        } while (consumed < count);
    }
};

int main()
{
    // Wait will be used to lock the consumer until there is data to consume.
    wait.lock();

    Foo foo;
    Bar bar;

    std::thread threadFoo(foo, 16);
    std::thread threadBar(bar, 16);

    threadFoo.join();
    threadBar.join();

    return 0;
}
