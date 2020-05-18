#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, n;
};

int T;
int N, M, R, C, L, tnum;
int map[50][50];
bool chk[50][50];

// 우 상 좌 하 0, 1, 2, 3
int yadd[4] = {0, -1, 0, 1};
int xadd[4] = {1, 0, -1, 0};

int tadd[8][4] = {{}, {0, 1, 2, 3}, {1, 3}, {0, 2},
                    {0, 1}, {0, 3}, {2, 3}, {1, 2}};

deque<struct pos> dq;

void _dq_insert(int ny, int nx, int cn, int cdir)
{
    if(chk[ny][nx] == 0)
    {
        //cout<<"dq "<<ny<<' '<<nx<<' '<<cn<<' '<<cdir<<"\n";        
        switch(cdir)
        {
            case 0:
                if(map[ny][nx] == 1 || map[ny][nx] == 3 
                || map[ny][nx] == 6 || map[ny][nx] == 7)
                {
                    chk[ny][nx] = 1;
                    dq.push_back({ny, nx, cn+1});
                    tnum++;
                }
            break;

            case 2:
                if(map[ny][nx] == 1 || map[ny][nx] == 3 
                || map[ny][nx] == 4 || map[ny][nx] == 5)
                {
                    chk[ny][nx] = 1;
                    dq.push_back({ny, nx, cn+1});
                    tnum++;
                }            
            break;

            case 1:
                if(map[ny][nx] == 1 || map[ny][nx] == 2 
                || map[ny][nx] == 5 || map[ny][nx] == 6)
                {
                    chk[ny][nx] = 1;
                    dq.push_back({ny, nx, cn+1});
                    tnum++;
                }            
            break;

            case 3:
                if(map[ny][nx] == 1 || map[ny][nx] == 2 
                || map[ny][nx] == 4 || map[ny][nx] == 7)
                {
                    chk[ny][nx] = 1;
                    dq.push_back({ny, nx, cn+1});
                    tnum++;
                }            
            break;
        }
    }
}

void _bfs()
{
    struct pos cPos, nPos;

    while(!dq.empty())
    {
        cPos = dq.front();

        //cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<map[cPos.y][cPos.x]<<' '<<cPos.n<<"\n";
        dq.pop_front();
        if(cPos.n >= L) break;

        if(map[cPos.y][cPos.x] == 1)
        {
            for(int i=0; i<4; i++)
            {
                nPos.y = cPos.y + yadd[tadd[1][i]];
                nPos.x = cPos.x + xadd[tadd[1][i]];

                if(nPos.y <0 || nPos.y >= N || nPos.x <0 || nPos.x >=M
                || map[nPos.y][nPos.x] == 0)
                    continue;
                
                _dq_insert(nPos.y, nPos.x, cPos.n, tadd[1][i]);
            }
        }
        else if(map[cPos.y][cPos.x] > 1)
        {
            for(int i=0; i<2; i++)
            {
                nPos.y = cPos.y + yadd[tadd[map[cPos.y][cPos.x]][i]];
                nPos.x = cPos.x + xadd[tadd[map[cPos.y][cPos.x]][i]];

                if(nPos.y <0 || nPos.y >= N || nPos.x <0 || nPos.x >=M
                || map[nPos.y][nPos.x] == 0)
                    continue;

                _dq_insert(nPos.y, nPos.x, cPos.n, tadd[map[cPos.y][cPos.x]][i]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st = 0; st<T; st++)
    {
        tnum = 1;
        dq.clear();
        for(int i=0; i<50; i++)
            for(int j=0; j<50; j++)
            {
                chk[i][j] = 0;
                map[i][j] = 0;
            }
            
        cin>>N>>M>>R>>C>>L;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                cin>>map[i][j];
            }
        }

        chk[R][C] = 1;
        dq.push_back({R, C, 1});

        _bfs();

        cout<<"#"<<st+1<<' '<<tnum<<"\n";
    }

    return 0;
}