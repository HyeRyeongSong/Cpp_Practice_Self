#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENOIR,
        ASSIST,
        MANAGER
    };

    void ShowPositionInfo(int iPosition)
    {
        switch(iPosition)
        {
            case CLERK:
                cout << "사원" <<endl;
                break;
            case SENOIR:
                cout << "주임" <<endl;
                break;
            case ASSIST:
                cout << "대리" <<endl;
                break;
            case MANAGER:
                cout << "과장" <<endl;
                break;
        }
    }

}

class NameCard
{
private:
    char* cName;
    char* cCompanyName;
    char* cPhoneNum;
    int iPosition;

public:
    NameCard(char* cName, char* cCompanyName, char* cPhoneNum, int iPosition)
            :iPosition(iPosition)
    {
        this->cName = new char[strlen(cName)+1];
        this->cCompanyName = new char[strlen(cCompanyName)+1];
        this->cPhoneNum = new char[strlen(cPhoneNum)+1];
        strcpy(this->cName, cName);
        strcpy(this->cCompanyName, cCompanyName);
        strcpy(this->cPhoneNum, cPhoneNum);
    }

    /*explicit*/ NameCard(const NameCard& copy) //묵시적 형 변환 막아주는 키워드
                                                //명시적 호출만 인정하겠다
    :iPosition(copy.iPosition)
    {
        this->cCompanyName = new char[strlen(copy.cCompanyName) + 1];
        this ->cName = new char[strlen(copy.cName) + 1];
        this->cPhoneNum = new char[strlen(copy.cPhoneNum) + 1];
        strcpy(this->cName, copy.cName);
        strcpy(this->cCompanyName, copy.cCompanyName);
        strcpy(this->cPhoneNum,  copy.cPhoneNum);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << this->cName <<endl;
        cout << "회사: " << this->cCompanyName <<endl;
        cout << "전화번호: " << this->cPhoneNum <<endl;
        cout << "직급: ";
        COMP_POS::ShowPositionInfo(this->iPosition);
        cout << endl;
    }

    ~NameCard()
    {
        delete[] this->cName;
        delete[] this->cCompanyName;
        delete[] this->cPhoneNum;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCENG", "010-1111-2222", COMP_POS::CLERK);
    manClerk.ShowNameCardInfo();
    NameCard man2(manClerk);
    NameCard man3 = manClerk;
    man2.ShowNameCardInfo();
    const NameCard& tmp=NameCard("Lee", "ABCENG", "010-1111-2222", COMP_POS::CLERK);
    NameCard("Lee", "ABCENG", "010-1111-2222", COMP_POS::CLERK).ShowNameCardInfo();
    return 0;
}