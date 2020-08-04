#include <iostream>

using namespace std;

int N;
int h[1000][3];
int cost[1000][3];

int main(void)
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>h[i][j];
        }
    }

    cost[0][0] = h[0][0];
    cost[0][1] = h[0][1];
    cost[0][2] = h[0][2];

    for(int i=1; i<N; i++)
    {
        cost[i][0] = h[i][0] + min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] = h[i][1] + min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] = h[i][2] + min(cost[i-1][0], cost[i-1][1]);
    }

    int res = min(cost[N-1][0], min(cost[N-1][1], cost[N-1][2]));
    cout<<res<<"\n";

    return 0;
}