#include <iostream>
#include <vector>

using namespace std;

int N;
int v[1000001];
int tmp[1000001];

void merge(int i1, int mid, int i2)
{
    int i = i1, j = mid + 1, idx = i1;

    while(i <= mid && j <= i2)
    {
        if(v[i] < v[j])
        {
            tmp[idx++] = v[i];
            i++;
        }
        else
        {
            tmp[idx++] = v[j];
            j++;  
        }
    }

    while(i <= mid) tmp[idx++] = v[i++];
    while(j <=i2) tmp[idx++] = v[j++];


    for(int ic = i1; ic<=i2; ic++)
    {
        v[ic] = tmp[ic];
    }
}

void merge_sort(int i1, int i2)
{
    int mid = (i1 + i2) / 2;
    if(i1 < i2)
    {
        merge_sort(i1, mid);
        merge_sort(mid+1, i2);
        merge(i1, mid, i2);
    }
}

int main(void)
{
    cin>>N;
    int tnum;
    for(int i=0; i<N; i++)
    {
        cin>>tnum;
        v[i] = tnum;
    }

    merge_sort(0, N-1);

    for(int i=0; i<N; i++)
        cout<<v[i]<<"\n";

    return 0;
}