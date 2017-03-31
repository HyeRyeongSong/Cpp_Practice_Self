#include<iostream>

using namespace std;

//몫과 나머지 값을 묶어 놓은 구조체
typedef struct _RESULTNUM
{
    int iQuotient;
    int iRemainder;
}SResultNum;

//몫과 나머지를 계산하는 함수
//Divide 함수가 main 함수의 iNum1과 iNum2를 변경하면 안되므로 'const'를 붙여 상수화해줌
SResultNum Divide(const int iNum1, const int iNum2);

int main()
{
    //피연산자 2개 선언 후 입력 받는다
    int iNum1, iNum2;
    cout << "Input 2 integers which are the number and the divisor in sequence" << endl;
    cout << "Number: ";
    cin >> iNum1;
    cout << "Divisor: ";
    cin >> iNum2;

    //0으로 나누는 경우에 대한 예외처리
    try
    {
        //제수가 0일 경우 catch문을 실행하도록 함
        if(iNum2 == 0)
        {
            throw iNum2;
        }

        //결과값을 저장할 구조체 변수를 선언 후 함수 실행의 결과값을 받아옴
        SResultNum sResult = Divide(iNum1, iNum2);

        //몫과 나머지를 출력함
        cout << "\n" << iNum1 << " / " << iNum2 << " = " << sResult.iQuotient << endl;
        cout << iNum1 << " % " << iNum2 << " = " << sResult.iRemainder << endl;
    } catch(int expn){
        //예외상황이 발생하였다는 에러 메시지 출력
        cout << "\nThe divisor cannot be 0\n" << "Restart the Program" << endl;
    }

    //프로그램 종료 메시지 출력
    cout << "\nend of main" << endl;

    return 0;
}

SResultNum Divide(const int iNum1, const int iNum2)
{
    //나눗셈 연산의 결과값들을 저장할 구조체 변수 선언
    SResultNum sResult;

    //몫과 나머지를 계산
    sResult.iQuotient = iNum1 / iNum2;
    sResult.iRemainder = iNum1 % iNum2;

    //리턴값으로 구조체를 줌
    return sResult;
}
