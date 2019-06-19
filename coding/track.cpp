//
// The program implements a tracker, that tracks all values for each tracepoint.
//
// At the end it prints out all the tracked values for each tracepoint.
//
// The expected output is:
//
// tracepoint0: 0 1 2 3 4 5 6 7 8 9
// tracepoint1: 0 1 2 3 4 5 6 7 8 9
// tracepoint2: 0 1 2 3 4 5 6 7 8 9
//
// You are asked to implement the add() and print() methods for the class Track.
//

#include <iostream>
#include <map>
#include <vector>

class Track
{
public:
    void add(std::string key, int value)
    {
        // Add a value to a tracepoint (key).
        if (m_tracepoints.count(key) == 0)
        {
            // First occurance of this tracepoint.
            std::vector<int> tracepoint;
            m_tracepoints[key] = tracepoint;
        }
        m_tracepoints[key].push_back(value);
    }

    void print()
    {
        // Prints all values for each tracepoint.
        for (auto & item : m_tracepoints)
        {
            print(item.first, item.second);
        }
    }

private:
    void print(std::string key, std::vector<int> values)
    {
        // implement this
        std::cout << key << ":";
        for (auto value : values)
        {
            std::cout << " " << value;
        }
        std::cout << std::endl;
    }

    std::map<std::string, std::vector<int>> m_tracepoints;
};

int main()
{
    Track track;

    std::vector<std::string> tracepoints =
    {
        "tracepoint0",
        "tracepoint1",
        "tracepoint2",
    };

    for (int ii = 0; ii < 10; ++ii)
    {
        for (auto tracepoint : tracepoints)
        {
            track.add(tracepoint, ii);
        }
    }

    track.print();

    return 0;
}
