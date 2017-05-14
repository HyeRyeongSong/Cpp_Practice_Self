#include <iostream>

using namespace std;

void insertsort(int* arr , int size)
{
    int i, j, a, k;
    for(i=0; i<size; i++)
    {
        a=i;
        for(j=i+1;i<size;j++)
        {
            if(arr[j] < arr[a])
                a=j;
        }
        swap(arr[i], arr[a]);
        for(int b=0; b<size;b++)
            cout<<arr[b]<<" ";
        cout << endl;
    }
}

void swap(int& iNum1, int& iNum2)
{
    int iTmp = iNum1;
    iNum1 = iNum2;
    iNum2 = iTmp;
}

int main(void) {
    int arr[5] = {9,4,3,7,2};
    insertsort(arr, 5);
    return  0;
}