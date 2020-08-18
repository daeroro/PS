#include <iostream>

using namespace std;

int N, K;
int map[101][100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    int tW, tV, res = 0;
    for(int i=1; i<=N; i++)
    {
        cin>>tW>>tV;
        for(int j=1; j<=K; j++)
        {
            if(j<tW)
            {
                map[i][j] = map[i-1][j];
                if(map[i][j] > res) res = map[i][j];
            }
            else
            {
                map[i][j] = max(map[i-1][j-tW] + tV, map[i-1][j]);   
                if(map[i][j] > res) res = map[i][j];
            }
        }
    }

    cout<<res<<"\n";

    return 0;
}