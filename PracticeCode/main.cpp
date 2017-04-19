#include <iostream>

using namespace std;

template <typename T>

inline T test(T name)
{
    cout << name <<endl;
}

int iValue = 3;

int main()
{
    int iValue = 5;
    char* cName = new(char);
    strcpy(cName, "hyeryung");
    test(cName);
    cout << "전역변수: " << ::iValue << endl << "지역변수: " << iValue << endl;
    return 0;
}