#include <iostream>

using namespace std;

int N;
int num[100001];
int dp[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>num[i];
    }

    dp[0] = num[0];

    for(int i=1; i<N; i++)
    {
        dp[i] = max(dp[i-1] + num[i], num[i]);
    }

    int ma = -1000;
    for(int i=0; i<N; i++)
    {
        if(ma < dp[i]) ma = dp[i];
    }

    cout<<ma<<"\n";

    return 0;
}