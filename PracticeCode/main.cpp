#include <iostream>
#include <cstring>

using namespace std;

class First
{
 //   void FirstFunc()
   // {
     //   cout << "first func" <<endl;
    //}
public:
    virtual int SimpleFunc() = 0;
};

class Second : public First
{
public:
    void SecondFunc()
    {
        cout << "second func" << endl;
    }
    int SimpleFunc()
    {
        cout << "second SimpleFunc()" <<endl;
    }
};

class Third : public Second
{
public:
    void ThirdFunc()
    {
        cout << "third func" << endl;
    }
    int SimpleFunc()
    {
        cout <<"third SimpleFunc()" <<endl;
    }
};

int main() {
    Third third;
    third.ThirdFunc();
    third.SimpleFunc();
    Second& second = third;
    second.SecondFunc();
    second.SimpleFunc();

    return 0;
}