//
// The program is supposed to print output from each of the two threads alternatingly.
//
// Like so:
//
// thread0: 0
// thread1: 0
// thread0: 1
// thread1: 1
// thread0: 2
// thread1: 2
// ...
//
// But it prints output in unpredictable order.
//
// See if you can make it do the right thing.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutexes[2];

void foo(int id, int next_id)
{
    for (int ii=0; ii < 16; ++ii)
    {
        mutexes[id].lock();
        std::cout << "thread" << id << ": " << ii << std::endl;
        mutexes[next_id].unlock();
    }
}

int main()
{
    mutexes[1].lock();

    std::thread thread0(foo, 0, 1);
    std::thread thread1(foo, 1, 0);

    thread0.join();
    thread1.join();

    return 0;
}
