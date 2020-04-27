#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x;
    char col;
};

int N;
bool chk[100][100], chk2[100][100];
char map[100][100];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

deque<struct pos> dq;

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
            cin>>map[i][j];
        }
    }

    int tNum = 0, fNum = 0;
    struct pos cPos, nPos;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(chk[i][j] == 0)
            {
                tNum++;
                chk[i][j] = 1;
                cPos = {i, j, map[i][j]};

                dq.push_back(cPos);

                while(!dq.empty())
                {
                    cPos = dq.front();
                    dq.pop_front();

                    for(int k=0; k<4; k++)
                    {
                        nPos.y = cPos.y + yadd[k];
                        nPos.x = cPos.x + xadd[k];

                        if(nPos.y < 0 || nPos.y >= N || nPos.x < 0 || nPos.x >= N)
                            continue;
                        if(chk[nPos.y][nPos.x] == 0 && map[nPos.y][nPos.x] == cPos.col)
                        {
                            chk[nPos.y][nPos.x] = 1;
                            dq.push_back({nPos.y, nPos.x, cPos.col});
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(chk2[i][j] == 0)
            {
                fNum++;
                chk2[i][j] = 1;
                dq.push_back({i, j, map[i][j]});

                while(!dq.empty())
                {
                    cPos = dq.front();
                    dq.pop_front();

                    for(int k=0; k<4; k++)
                    {
                        nPos.y = cPos.y + yadd[k];
                        nPos.x = cPos.x + xadd[k];

                        if(nPos.y < 0 || nPos.y >= N || nPos.x < 0 || nPos.x >= N)
                            continue;
                        if(chk2[nPos.y][nPos.x] == 0)
                        {
                            if(map[nPos.y][nPos.x] == 'R' || map[nPos.y][nPos.x] == 'G')
                            {
                                if(cPos.col == 'R' || cPos.col == 'G')
                                {
                                    chk2[nPos.y][nPos.x] = 1;
                                    dq.push_back({nPos.y, nPos.x, map[nPos.y][nPos.x]});
                                }
                            }
                            else
                            {
                                if(cPos.col == 'B')
                                {
                                    chk2[nPos.y][nPos.x] = 1;
                                    dq.push_back({nPos.y, nPos.x, map[nPos.y][nPos.x]});
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<tNum<<' '<<fNum<<"\n";

    return 0;
}