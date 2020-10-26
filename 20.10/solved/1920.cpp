#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100000];

bool _find(int num)
{
    int st = 0, en = N-1;
    while(st <= en)
    {
        int mid = (st+en)/2;
        //cout<<mid<<' '<<A[mid]<<' '<<st<<' '<<en<<' '<<num<<"\n";
        if(A[mid] == num)
        {
            return true;
        }
        else if(A[mid] < num)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>A[i];
    }

    sort(A, A+N);

    cin>>M;
    int tmp;
    for(int i=0; i<M; i++)
    {
        cin>>tmp;

        cout<<_find(tmp)<<"\n";
    }

    return 0;
}