#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, n;
};

int N, M, ret;
bool map[500][500];
bool chk[500][500];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

deque<struct pos> dq;

void _bfs()
{
    struct pos cPos, nPos;
    int tret = 0;
    while(!dq.empty())
    {
        cPos = dq.front();
        tret++;
        dq.pop_front();

        for(int i=0; i<4; i++)
        {
            nPos.y = cPos.y + yadd[i];
            nPos.x = cPos.x + xadd[i];

            if(nPos.y<0 || nPos.y >= N || nPos.x < 0 || nPos.x >= M)
                continue;
            if(map[nPos.y][nPos.x] == 1 && chk[nPos.y][nPos.x] == 0)
            {
                chk[nPos.y][nPos.x] = 1;

                dq.push_back({nPos.y, nPos.x, cPos.n+1});
            }
        }
    }

    if(ret < tret) ret = tret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(map[i][j] == 1 && chk[i][j] == 0)
            {
                cnt++;
                chk[i][j] = 1;
                dq.push_back({i, j, 1});

                _bfs();
            }
        }
    }

    cout<<cnt<<"\n";
    cout<<ret<<"\n";

    return 0;
}