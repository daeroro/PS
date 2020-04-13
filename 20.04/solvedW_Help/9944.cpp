/*

1. 테스트 케이스가 나와있지 않는 문제의 경우 처리
  -> while(cin>>N>>M)
     {

     }

2. bfs는 그냥 단순하게 다 해보는 것!
3. 코드를 짤 때 좀 더 정확하게...!

*/

#include <iostream>

using namespace std;

int N, M, tNum, ret = 1000000;
char map[30][30];
bool chk[30][30];

int yadd[4] = {0, -1, 0, 1};
int xadd[4] = {1, 0, -1, 0};

void _dfs(int cy, int cx, int st, int bNum)
{
    //cout<<"cur "<<cy<<' '<<cx<<' '<<st<<' '<<bNum<<' '<<tNum<<"\n";
    if(bNum == tNum)
    {
        if(st < ret) ret = st;
        return;
    }

    int ny, nx;
    for(int i=0; i<4; i++)
    {
        int tnum = 0;
        ny = cy, nx = cx;
        while(1)
        {
            ny += yadd[i];
            nx += xadd[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M ||
            map[ny][nx] == '*' || chk[ny][nx] == 1)
            {
                if(tnum == 0)
                {
                    //cout<<"dir "<<i<<' '<<ny<<' '<<nx<<"\n";
                    break;
                }

                _dfs(ny-yadd[i], nx-xadd[i], st+1, bNum + tnum);

                for(int j=0; j<tnum; j++)
                {
                    ny -= yadd[i];
                    nx -= xadd[i];
                    chk[ny][nx] = 0;
                }

                break;
            }
            chk[ny][nx] = 1;
            tnum++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int index = 1;
    while(cin>>N>>M)
    {
        tNum = 0;
        ret = 1000000;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                cin>>map[i][j];
                if(map[i][j] == '.')
                {
                    tNum++;
                }
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(map[i][j] == '.')
                {
                    chk[i][j] = 1;
                    _dfs(i, j, 0, 1);
                    chk[i][j] = 0;
                }
            }
        }

        if(ret == 1000000) ret = -1;
        cout<<"Case "<<index<<": "<<ret<<"\n";
        index++;
    }

    return 0;
}