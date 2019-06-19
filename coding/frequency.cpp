//
// The program implements a frequency counter, that counts the frequency of each number.
//
// At the end it prints out the frequency count for each number.
//
// The expected output is:
//
// 0 = 10
// 1 = 10
// 2 = 10
// ...
//
// You are asked to implement the add() and print() methods for the class Frequency.
//

#include <iostream>
#include <map>

class Frequency
{
public:
    void add(int value)
    {
        // Adds 1 to the occurances of value.
        if (m_counts.count(value) == 0)
        {
            // First occurance of this value.
            m_counts[value] = 0;
        }
        m_counts[value] += 1;
    }

    void print()
    {
        // Prints the frequency of each value.
        for (auto & item : m_counts)
        {
            print(item.first, item.second);
        }
    }

private:
    void print(int number, int count)
    {
        std::cout << number << " = " << count << std::endl;
    }

    std::map<int, int> m_counts;
};

int main()
{
    Frequency frequency;

    int data[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    for (auto value : data)
    {
        frequency.add(value);
    }

    frequency.print();

    return 0;
}
