//
// Created by HyeRyeongSong on 2017. 4. 30..
//

#include <iostream>

template <class T>
class Bag
{
public:
    Bag (int bagCapacity = 3);
    Bag(const Bag<T>& copyBag);
    Bag<T>& operator=(const Bag<T> ref);
    ~Bag();

    void ChangeSize1D(T*& a, const int oldSize, const int newSize);

    int Size() const;
    bool IsEmpty() const;
    T& Element() const;

    void Push(const T&);
    void Pop();

private:
    T *array;
    int capacity;
    int top;
};

using namespace std;

template <class T>
Bag<T>::Bag (int bagCapacity): capacity ( bagCapacity )
{
    if (capacity < 1)
        std::cout << "Capacity must be > 0" << std::endl;
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::Bag(const Bag<T>& copyBag):capacity(copyBag.capacity), top(copyBag.top)
{
    array = new T[capacity];
    for(int i=0; i<Size(); ++i)
    {
        array[i] = copyBag.array[i];
    }
}

template <class T>
Bag<T>& Bag<T>::operator=(const Bag<T> ref)
{
    delete[] array;
    array = new T[ref.capacity];
    for(int i=0; i<ref.Size(); ++i)
    {
        array[i] = ref.array[i];
    }
    capacity = ref.capacity;
    top = ref.top;
    return *this;
}



template <class T>
Bag<T>::~Bag()
{
    delete [ ] array;
}

template <class T>
void Bag<T>::Push(const T& x)
{
    if (capacity ==top+1)
    {
        ChangeSize1D(array, capacity, 2 * capacity);
        capacity *=2;
    }
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty())
        std::cout<< "Bag is empty, cannot delete"<<std::endl;
    int deletePos = top / 2;
    copy(array+deletePos+1,array+top+1,array+deletePos);
    // compact array
    array[top--].~T();   // destructor for T
}

template  <class T>
inline int Bag<T>::Size() const
{
    return top+1;
}

template <class T>
inline bool Bag<T>::IsEmpty() const
{
    return (Size() == 0);
}

template <class T>
inline T& Bag<T>::Element() const
{
    if(IsEmpty())
        std::cout<< "Bag is empty"<<std::endl;
    return array[0];
}

template <class T>
void Bag<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
    if (newSize < 0)
        std::cout<< "New length must be >= 0" << std::endl;

    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete [] a;
    a = temp;
}

class Bizcard
{
private:
    char* cName;
    char* cPhone;

public:
    Bizcard(char* cName, char* cPhone)
    {
        this->cName = new char[strlen(cName+1)];
        strcpy(this->cName, cName);
        this->cPhone = new char[strlen(cPhone+1)];
        strcpy(this->cPhone, cPhone);
    }

    Bizcard(const Bizcard& bizcard)
    {
        cName = new char[strlen(bizcard.cName)];
        strcpy(this->cName, bizcard.cName);
        cPhone = new char[strlen(bizcard.cPhone)];
        strcpy(this->cPhone, bizcard.cPhone);
    }

    Bizcard& operator=(const Bizcard ref)
    {
        delete[] this->cName;
        delete[] this->cPhone;

        cName = new char[strlen(ref.cName)];
        strcpy(this->cName, ref.cName);
        cPhone = new char[strlen(ref.cPhone)];
        strcpy(this->cPhone, ref.cPhone);

        return *this;
    }


    ~Bizcard()
    {
        delete[] cName;
        delete[] cPhone;
    }

    void ShowInfo()
    {
        cout << "이름: " << this->cName << endl;
        cout << "전화번호: " << this->cPhone << endl;
    }
};

void CheckResult(Bag<int> bag);
void CheckResult(Bag<Bizcard> bag);

int main()
{
    Bag<int> bag;
//    Bag<Bizcard> bag1;

    cout << "빈 Bag에 대한 결과" <<endl;
    CheckResult(bag);

    for(int i=0; i<3; ++i)
    {
        int iNum = 0;
        cout << "숫자를 하나 입력하세요: " <<endl;
        cin >>iNum;
        bag.Push(iNum);
    }

    cout << "정수 3개 추가 후 결과" <<endl;
    CheckResult(bag);

    for(int i=0; i<4; ++i)
    {
        int iNum = 0;
        cout << "숫자를 입력하세요: " <<endl;
        cin >>iNum;
        bag.Push(iNum);
    }

    cout << "정수 4개 추가 후 결과" <<endl;
    CheckResult(bag);

    for(int i=0; i<2; ++i)
    {
        bag.Pop();
    }

    cout << "정수 2개 제 후 결과" <<endl;
    CheckResult(bag);
/*
    cout << endl << endl <<"--------------------------------------------------" <<endl << endl;
    cout << "빈 Bag에 대한 결과" <<endl;
    CheckResult(bag1);

    char* cName = new char[256];
    char* cPhone = new char[256];

    for(int i=0; i<3; ++i)
    {
        cout << "이름을 입력하세요: ";
        cin >>cName;
        cout << "전화번호를 입력하세요: ";
        cin >>cPhone;
        Bizcard bizcard(cName, cPhone);
        bag1.Push(bizcard);
    }

    cout << "객체 3개 추가 후 결과" <<endl;
    CheckResult(bag1);

    for(int i=0; i<4; ++i)
    {
        cout << "이름을 입력하세요: ";
        cin >>cName;
        cout << "전화번호를 입력하세요: ";
        cin >>cPhone;
        Bizcard bizcard(cName, cPhone);
        bag1.Push(bizcard);
    }

    cout << "객체 4개 추가 후 결과" <<endl;
    CheckResult(bag1);

    for(int i=0; i<2; ++i)
    {
        bag1.Pop();
    }

    cout << "객체 2개 제 후 결과" <<endl;
    CheckResult(bag1);

    delete[] cName;
    delete[] cPhone;
*/

    return 0;

}

void CheckResult(Bag<int> bag)
{
    cout << "bag.Size(): " << bag.Size() << endl;
    cout << "bag.IsEmpty(): ";
    if(bag.IsEmpty())
    {
        cout<< "true" <<endl;
    }
    else
    {
        cout << "false" <<endl;
    }
    cout << "bag.Element(): " << bag.Element() << endl;
    cout << endl;
}

void CheckResult(Bag<Bizcard> bag1)
{
    cout << "bag.Size(): " << bag1.Size() << endl;
    cout << "bag.IsEmpty(): ";
    if(bag1.IsEmpty())
    {
        cout<< "true" <<endl;
    }
    else
    {
        cout << "false" <<endl;
    }
    cout << "bag.Element(): ";
    Bizcard element = bag1.Element();
    element.ShowInfo();
    cout << endl;
}


