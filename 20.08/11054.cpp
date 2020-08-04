#include <iostream>

using namespace std;

int N;
int num[1001];
int incr[1001];
int decr[1001];

int main(void)
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>num[i];
    }

    int res = 1;
    incr[0] = 1;
    decr[N-1] = 1;
    int tmp = 0;
    for(int i=0; i<N; i++)
    {
        
        tmp = 0;
        for(int j=0; j<i; j++)
        {
            if(num[j] < num[i]) tmp = max(incr[j], tmp);
        }

        incr[i] = tmp+1;
    }
    for(int i=N-1; i>=0; i--)
    {
        tmp = 0;
        for(int j=N-1; j>i; j--)
        {
            if(num[j] < num[i]) tmp = max(decr[j], tmp);
        }

        decr[i] = tmp + 1;
    }

    for(int i=0; i<N; i++)
    {
        if(incr[i] + decr[i] - 1 > res) res = incr[i] + decr[i] - 1;
    }

    cout<<res<<"\n";

    return 0;
}