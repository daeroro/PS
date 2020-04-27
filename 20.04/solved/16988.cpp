#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x;
};

int N, M, idx, ret;
int map[20][20];
bool chk[20][20];
bool zchk[400];
deque<struct pos> gq[400];
deque<struct pos> dq, zq;

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

void _grouping()
{
    idx = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(map[i][j] == 2 && chk[i][j] == 0)
            {
                chk[i][j] = 1;
                dq.push_back({i, j});
                gq[idx].push_back({i, j});

                struct pos cPos, nPos;
                while(!dq.empty())
                {
                    cPos = dq.front();
                    dq.pop_front();

                    for(int k=0; k<4; k++)
                    {
                        nPos.y = cPos.y + yadd[k];
                        nPos.x = cPos.x + xadd[k];

                        if(nPos.y < 0 || nPos.y >= N || nPos.x < 0 || nPos.x >= M)
                            continue;
                        if(map[nPos.y][nPos.x] == 2 && chk[nPos.y][nPos.x] == 0)
                        {
                            chk[nPos.y][nPos.x] = 1;
                            dq.push_back(nPos);
                            gq[idx].push_back(nPos);
                        }
                    }
                }
                idx++;
            }
        }
    }
}

void _check()
{
    int tret = 0;
    struct pos cPos, nPos;
    for(int i=0; i<idx; i++)
    {
        int flag = 0;
        int tmp = gq[i].size();
        for(int j=0; j<tmp; j++)
        {
            cPos = gq[i][j];
            for(int k=0; k<4; k++)
            {
                nPos.y = cPos.y + yadd[k];
                nPos.x = cPos.x + xadd[k];

                if(nPos.y < 0 || nPos.y >= N || nPos.x < 0 || nPos.x >=M)
                    continue;
                if(map[nPos.y][nPos.x] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }

        if(flag == 0)
        {
            tret += gq[i].size();
        }
    }

    if(tret > ret) ret = tret;
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
            if(map[i][j] == 0)
            {
                zq.push_back({i, j});
            }
        }
    }

    _grouping();
    /*
    cout<<"idx "<<idx<<"\n";
    for(int i=0; i<idx; i++)
    {
        cout<<"size "<<gq[i].size()<<"\n";
    }
    */

    int tmp = zq.size();
    struct pos t1, t2;
    for(int i=0; i<tmp-1; i++)
    {
        for(int j=i+1; j<tmp; j++)
        {
            t1 = zq[i];
            t2 = zq[j];

            map[t1.y][t1.x] = 1;
            map[t2.y][t2.x] = 1;
/*
            for(int k=0; k<N; k++)
            {
                for(int l=0; l<M; l++)
                {
                    cout<<map[k][l]<<' ';
                }
                cout<<"\n";
            }
*/            
            _check();

            map[t1.y][t1.x] = 0;
            map[t2.y][t2.x] = 0;
        }
    }

    cout<<ret<<"\n";

    return 0;
}