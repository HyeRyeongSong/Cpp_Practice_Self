#include <iostream>

using namespace std;

int SimpleFunc(int a = 10)
{
    cout << "int" << endl;
    return a+1;
}

int SimpleFunc(void)
{
    cout << "void" << endl;
    return 10;
}


int main()
{
    SimpleFunc();
    return 0;
}