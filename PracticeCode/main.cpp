#include <iostream>

using namespace std;

void func(const int& iNum)
{
    cout << iNum <<endl;
}

void func2(int& iNum)
{
    cout << iNum <<endl;
}


int main()
{
    func(1);
    func2(2);
    return 0;
}