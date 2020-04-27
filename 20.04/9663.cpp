#include <iostream>

using namespace std;

int N, ret;
int map[15][15];

void _dfs(int cy, int cx, int st)
{
    if(st == N)
    {

        cout<<ret<<"\n";
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<map[i][j];
            }
            cout<<"\n";
        }
        
        ret++;
        return;
    }

    for(int i = cy; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] == 0)
            {
                //cout<<i<<' '<<j<<' '<<st<<"\n";
                for(int k=0; k<N; k++)
                {
                    map[k][j]++;
                    map[i][k]++;
                }

                int ty = i, tx = j;
                while(ty>=0 && tx >= 0)
                {
                    map[ty--][tx--]++;
                }
                ty = i, tx = j;
                while(ty>=0 && tx <N)
                {
                    map[ty--][tx++]++;
                }
                ty = i, tx = j;
                while(ty<N && tx>=0)
                {
                    map[ty++][tx--]++;
                }
                ty = i, tx = j;
                while(ty < N && tx < N)
                {
                    map[ty++][tx++]++;
                }
                map[i][j] = 1;
/*
                for(int k=0; k<N; k++)
                {
                    for(int l=0; l<N; l++)
                    {
                        cout<<map[k][l];
                    }
                    cout<<"\n";
                }
*/
                _dfs(i, j, st+1);

                for(int k=0; k<N; k++)
                {
                    map[k][j]--;
                    map[i][k]--;
                }

                ty = i, tx = j;
                while(ty>=0 && tx >= 0)
                {
                    map[ty--][tx--]--;
                }
                ty = i, tx = j;
                while(ty>=0 && tx <N)
                {
                    map[ty--][tx++]--;
                }
                ty = i, tx = j;
                while(ty<N && tx>=0)
                {
                    map[ty++][tx--]--;
                }
                ty = i, tx = j;
                while(ty < N && tx < N)
                {
                    map[ty++][tx++]--;
                }
                map[i][j] = 0;

            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] == 0)
            {
                _dfs(i, j, 0);
            }
        }
    }

    cout<<ret<<"\n";

    return 0;
}