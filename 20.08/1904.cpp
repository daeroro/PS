#include <iostream>

using namespace std;

int N;
long long num[1000001];

long long _go(int n)
{
    //cout<<n<<"\n";
   if(num[n]) return num[n];

    //cout<<"after\n";
    return num[n] = (_go(n-1) + _go(n-2)) % 15746;
}

int main(void)
{
    cin>>N;

    num[1] = 1;
    num[2] = 2;

    _go(N);

    cout<<num[N]<<"\n";

    return 0;
}