//
// The program is supposed to print out the area of the rectangle.
//
// But it fails.
//
// See if you can fix the bug.
//

#include <iostream>

class Rectangle
{
public:
    Rectangle(int length, int width) : m_length(length), m_width(width) {}

    int area()
    {
        int value;
        if (compute(&value))
        {
            return value;
        }
        std::cout << "bad length(" << m_length << ") or width(" << m_width << ")" << std::endl;
        return -1;
    }

private:
    bool compute(int *value)
    {
        if (m_length > 0 && m_width > 0)
        {
            *value = m_length * m_width;
            return true;
        }
        return false;
    }

    int m_length = -1;
    int m_width = -1;
};

int main()
{
    Rectangle rect(4, 5);
    int area = rect.area();
    if (area < 0)
    {
        std::cout << "failed" << std::endl;
    }
    else
    {
        std::cout << "area=" << area << std::endl;
    }
    return 0;
}
