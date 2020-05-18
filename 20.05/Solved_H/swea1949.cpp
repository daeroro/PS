/*
    #### 시작점 방문 체크 해주기!!!!!!! #####
*/

#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x;
};

int T, N, K;
int map[8][8];
bool chk[8][8];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

void _dfs(int st, int cy, int cx, int flag, int* tres)
{
    //cout<<st<<' '<<cy<<' '<<cx<<' '<<flag<<' '<<*tres<<"\n";
    struct pos nPos;
    for(int i=0; i<4; i++)
    {
        nPos.y = cy + yadd[i];
        nPos.x = cx + xadd[i];

        if(nPos.y <0 || nPos.y >= N || nPos.x <0 || nPos.x >= N) continue;

        if(chk[nPos.y][nPos.x] == 0)
        {
            if(map[nPos.y][nPos.x] < map[cy][cx])
            {
                chk[nPos.y][nPos.x] = 1;

                _dfs(st+1, nPos.y, nPos.x, flag, tres);

                chk[nPos.y][nPos.x] = 0;
            }
            else if(map[nPos.y][nPos.x] >= map[cy][cx] && flag == 0)
            {
                chk[nPos.y][nPos.x] = 1;
                int tmi = (map[nPos.y][nPos.x] - map[cy][cx]) + 1;
                for(int j=tmi; j<=K; j++)
                {
                    map[nPos.y][nPos.x] -= j;

                    _dfs(st+1, nPos.y, nPos.x, 1, tres);

                    map[nPos.y][nPos.x] += j;
                }

                chk[nPos.y][nPos.x] = 0;
            }
        }
    }

    if(*tres < st) *tres = st;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st=0; st<T; st++)
    {
        cin>>N>>K;

        deque<struct pos> hq;
        int ma = 0;
        int tres = 1;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                map[i][j] = 0;
                chk[i][j] = 0;
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>map[i][j];
                if(map[i][j] > ma) ma = map[i][j];
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(map[i][j] == ma)
                {
                    hq.push_back({i, j});
                }
            }
        }

        for(int i=0; i<(int)hq.size(); i++)
        {
            chk[hq[i].y][hq[i].x] = 1;
            _dfs(1, hq[i].y, hq[i].x, 0, &tres);
            chk[hq[i].y][hq[i].x] = 0;
        }

        cout<<"#"<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}