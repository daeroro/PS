#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, t;
};

int N, M, vnum, znum, ret = 50*50;
int map[50][50];
bool vchk[10], tchk[50][50];

deque<struct pos> vq, dq;

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

void bfs()
{
    for(int i=0; i<50; i++)
        for(int j=0; j<50; j++)
            tchk[i][j] = 0;

    for(int i=0; i<vnum; i++)
    {
        if(vchk[i] == 1)
        {
            dq.push_back({vq[i].y, vq[i].x, 0});
            map[vq[i].y][vq[i].x] = -1;
            tchk[vq[i].y][vq[i].x] = 1;
        }
    }

    int tznum = 0, flag = 0;;
    struct pos cPos, nPos;
    while(!dq.empty())
    {
        cPos = dq.front();
        dq.pop_front();

        for(int i=0; i<4; i++)
        {
            nPos.y = cPos.y + yadd[i];
            nPos.x = cPos.x + xadd[i];

            if(nPos.y < 0 || nPos.y >= N || nPos.x < 0 || nPos.x >= N)
                continue;
            if(tchk[nPos.y][nPos.x] == 0)
            {
                if(map[nPos.y][nPos.x] == 0)
                {
                    tznum++;
                    tchk[nPos.y][nPos.x] = 1;
                    dq.push_back({nPos.y, nPos.x, cPos.t+1});

                    if(tznum == znum)
                    {
                        if(ret > cPos.t+1) ret = cPos.t+1;
                        flag = 0;
                        break;
                    }
                }
                else if(map[nPos.y][nPos.x] == 2)
                {
                    tchk[nPos.y][nPos.x] = 1;
                    dq.push_back({nPos.y, nPos.x, cPos.t+1});
                }
            }
        }
        if(flag == 1)
        {
            dq.clear();
            break;
        }
    }
}

void dfs(int st, int ci)
{
    if(st == M)
    {
        /*
        for(int i=0; i<10; i++)
        {
            cout<<vchk[i]<<' ';
        }
        cout<<"\n";
        */
        bfs();
        for(int i=0; i<vnum; i++)
            if(vchk[i] == 1)
                map[vq[i].y][vq[i].x] = 2;

        return;
    }

    for(int i= ci+1; i<vnum; i++)
    {
        if(vchk[i] == 0)
        {
            vchk[i] = 1;
            dfs(st+1, i);
            vchk[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 0)
            {
                znum++;
            }
            else if(map[i][j] == 2)
            {
                vq.push_back({i, j, 0});
            }
        }
    }

    vnum = (int)vq.size();

    if(znum == 0)
    {
        cout<<"0\n";
        return 0;
    }    
    dfs(0, -1);

    if(ret == 50*50) ret = -1;
    cout<<ret<<"\n";

    return 0;
}