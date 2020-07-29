#include <iostream>

using namespace std;

int _sum(int N)
{
    if(N == 0) return 1;

    return _sum(N-1) * N;
}

int main(void)
{
    int N;

    cin>>N;
    cout<<_sum(N)<<"\n";

    return 0;
}