#include <iostream>

using namespace std;

int N;
long long num[92];

long long fibo(int N)
{
    if(num[N]) return num[N];

    return num[N] = fibo(N-1) + fibo(N-2);
}

int main(void)
{
    cin>>N;

    num[1] = 1;
    num[2] = 1;

    fibo(N);

    cout<<num[N]<<"\n";

    return 0;
}