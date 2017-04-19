#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    {}
    void ShowPosition() const
    {
        cout<<'[' <<xpos<<", "<<ypos<<']'<<endl;
    }
    friend Point operator+(const Point &pos1, const Point &pos2);

    Point& operator+=(const Point &pos)
    {
        this->xpos+=pos.xpos;
        this->ypos+=pos.ypos;
        return *this;
    }

    Point& operator-=(const Point &pos)
    {
        this->xpos-=pos.xpos;
        this->ypos-=pos.ypos;
        return *this;
    }
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos;
    pos.xpos = pos1.xpos + pos2.xpos;
    pos.ypos = pos1.ypos + pos2.ypos;
    return pos;
}

int main() {
    Point pos1(1, 1);
    Point pos2(2, 2);
    Point pos3;
    pos1.ShowPosition();
    pos2.ShowPosition();
    operator+(pos1, pos2);
    pos1.operator+=(pos2);
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos2.operator-=(pos1);
    pos1.ShowPosition();
    pos2.ShowPosition();



    return 0;
}