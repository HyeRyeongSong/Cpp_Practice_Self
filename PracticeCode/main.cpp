#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    {}
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
};


/*istream& operator>>(istream& is, Point pos)
{
    is>>pos.xpos>>pos.ypos;
    return is;
}*/

ostream& operator<< (ostream& os, Point pos)
{
    os<<'[' <<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

int main()
{
    Point pos1;
    cout<<"x, y 좌표 순으로 입력: ";
   // cin >> pos1;
    cout<< pos1;

    Point pos2;
    cout<<"x, y 좌표 순으로 입력: ";
    //cin >> pos2;
    cout << pos2;
    return 0;
}