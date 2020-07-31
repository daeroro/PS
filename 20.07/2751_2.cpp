#include <iostream>

using namespace std;

int N;
int num[1000001];

void quick_sort(int i1, int i2)
{
    //if(i1 >= i2) return;

    int pivot = num[(i1)];
    int l = i1+1, r = i2;

    while(l<=r)
    {
        while(num[l] < pivot) l++;
        while(num[r] > pivot) r--;

        if(l <= r)
        {
            int tmp = num[l];
            num[l] = num[r];
            num[r] = tmp;
        }
    }

    if(i1 < i2)
    {
    int tmp = num[(i1)];
    num[(i1)] = num[r];
    num[r] = tmp;

    quick_sort(i1, r-1);
    quick_sort(r+1, i2);
    }
}

int main(void)
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>num[i];
    }

    quick_sort(0, N-1);

    for(int i=0; i<N; i++)
    {
        cout<<num[i]<<"\n";
    }

    return 0;
}