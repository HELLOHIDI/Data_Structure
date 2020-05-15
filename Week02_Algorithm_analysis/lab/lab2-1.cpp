//  이진탐색프로그램  //

#include <iostream>
using namespace std;
int RecusiveBinSearch(int* a, const int, const int, const int);
int BinarySearch(int* a, const int, const int, const int);

int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int x, p;
    int choice = 0;
    if (choice == 3) {
        return 0;
    }
    while (choice != 3) {
        cout << "Enter methods of Search:1. Bin-search  2. Recursive search     3.Exit:        ";
        cin >> choice;
        cout << "Enter one of data to search : ";
        cin >> x;

        if (choice == 1) {
            p = BinarySearch(arr, x, 0, 9);
            cout << x << "is at position " << p << endl;
            
        }
        else if (choice == 2) {
            p = RecusiveBinSearch(arr,0,9,x);
            cout << x << "is at position " << p << endl;
            
        }
    }
    
    return 0;
}

int BinarySearch(int* a, const int x, const int left, const int right)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        //           cout << left << right << middle << endl;
        if (x > a[middle])return BinarySearch(a, x, middle + 1, right);
        if (x < a[middle])return BinarySearch(a, x, left, middle - 1);
        if (x == a[middle])return middle;
    }
    return -1;
}
int RecusiveBinSearch(int nArr[], int nBegin, int nEnd, int nTarget)
{
    int nMid = 0;

    if (nBegin > nEnd)
    {
        return -1;	//탈출 조건 및 탐색 실패
    }

    nMid = (nBegin + nEnd) / 2;

    if (nArr[nMid] == nTarget)
    {
        return nMid;			//타겟을 찾았다.
    }
    else if (nTarget < nArr[nMid])
    {
        return RecusiveBinSearch(nArr, nBegin, nMid - 1, nTarget);
    }
    else
    {
        return RecusiveBinSearch(nArr, nMid + 1, nEnd, nTarget);
    }
}
