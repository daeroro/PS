#include <iostream>

using namespace std;

int T, N;
long long num[105] = {0, 1, 1, 1, 2, 2, 3, 4, 5, };

long long _go(int n)
{
    if(num[n]>0) return num[n];

    return num[n] = _go(n-1) + _go(n-5);
}

int main(void)
{
    cin>>T;

    for(int i=0; i<T; i++)
    {
        cin>>N;
        _go(N);

        cout<<num[N]<<"\n";
    }

    return 0;
}