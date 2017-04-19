#include <iostream>

using namespace std;

struct Point
{
    int xpos;
    int ypos;
};

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point* ptr = new Point;
    ptr->xpos = p1.xpos + p2.xpos;
    ptr->ypos = p1.ypos + p2.ypos;
    return *ptr;
}

int main()
{
    Point* ptr1 = new Point;
    Point* ptr2 = new Point;
    ptr1->xpos = 10;
    ptr2->xpos = 5;
    ptr1->ypos = 1;
    ptr2->ypos = 2;
    Point& ptr = PntAdder(*ptr1, *ptr2);
    delete ptr1;
    delete ptr2;
    cout << "x: " << ptr.xpos << endl;
    cout << "y: " << ptr.ypos << endl;
    delete &ptr;
}