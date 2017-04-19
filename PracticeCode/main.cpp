#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char* name, int age)
    :age(age)
    {
        this ->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름: " <<name<<endl;
        cout << "나이: " <<age<<endl;
    }
    ~MyFriendInfo()
    {
        delete[] name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(char* name, int age, char* addr, char* phone)
    :MyFriendInfo(name, age)
    {
        this->addr = new char[strlen(addr)+1];
        this->phone = new char[strlen(phone)+1];
        strcpy(this->addr, addr);
        strcpy(this->phone, phone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " <<addr<<endl;
        cout << "전화: " <<phone<<endl;
    }
    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    }
};

int main()
{
    MyFriendDetailInfo MFD("hyeryung", 22, "hanti", "010-1111-1111");
    MFD.ShowMyFriendDetailInfo();
    cout << endl;
    MFD.ShowMyFriendInfo();

    return 0;
}