#include <iostream>

using namespace std;

int N;
int map[501][501];
int sum[501][501];

int main(void)
{
    cin>>N;
    int i=1;
    while(i<=N)
    {
        for(int j=1; j<=i; j++)
        {
            cin>>map[i][j];
        }
        i++;
    }

    i=1;
    while(i<= N)
    {
        for(int j=1; j<=i; j++)
        {
            if(j==1)
            {
                sum[i][j] = map[i][j] + sum[i-1][j];
            }
            else if(i==j)
            {
                sum[i][j] = map[i][j] + sum[i-1][j-1];
            }
            else
            {
                sum[i][j] = map[i][j] + max(sum[i-1][j-1], sum[i-1][j]);   
            }
        }
        i++; 
    }

    int res = 0;
    for(int i=1; i<=N; i++)
    {
        if(res < sum[N][i]) res = sum[N][i];
    }

    cout<<res<<"\n";

    return 0;
}