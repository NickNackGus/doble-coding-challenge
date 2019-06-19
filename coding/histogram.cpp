//
// The program implements a histogram that counts numbers falling into 3 bins:
//
// bin 0-2
// bin 3-5
// bin 6-9
//
// At the end it prints out the numbers counted in each bin.
//
// The expected output is:
//
// bin 0-2 = 30
// bin 3-5 = 30
// bin 6-9 = 40
//
// You are asked to implement the add() and print() methods for the class Histogram.
//

#include <iostream>
#include <map>

class NamedBound
{
// A helper class that tests if a number is in its bounds.

public:
    NamedBound(std::string name, int min, int max) : m_name(name), m_min(min), m_max(max) {}

    std::string name()
    {
        return m_name;
    }

    bool contains(int value)
    {
        return m_min <= value && value <= m_max;
    }

private:
    std::string m_name;
    int m_min, m_max;
};

class Histogram
{
public:
    Histogram()
    {
        // Ensure all bins exist even if unused.
        for (auto & bounds : m_bounds)
        {
            m_counts[bounds.name()] = 0;
        }
    }

    void add(int value)
    {
        // Add the value to the relevant bin
        for (auto & bounds : m_bounds)
        {
            if (bounds.contains(value))
            {
                m_counts[bounds.name()] += 1;
                // Ensure the valule appears in only one bin.
                // Since no bins overlap, this can be skipped.
                break;
            }
        }
    }

    void print()
    {
        // Print the histogram
        for (auto & item : m_counts)
        {
            print(item.first, item.second);
        }
    }

private:
    void print(std::string bin, int count)
    {
        std::cout << "bin " << bin << " = " << count << std::endl;
    }

    std::string bin_0_2 = "0-2";
    std::string bin_3_5 = "3-5";
    std::string bin_6_9 = "6-9";

    NamedBound m_bounds[3] = {
        NamedBound(bin_0_2, 0, 2),
        NamedBound(bin_3_5, 3, 5),
        NamedBound(bin_6_9, 6, 9),
    };
    std::map<std::string, int> m_counts;
};

int main()
{
    Histogram histogram;

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
        histogram.add(value);
    }

    histogram.print();

    return 0;
}
