#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct pos{
    int y, x, n;
    char c;
};

char map[12][6];
bool chk[12][6];
deque<struct pos> dq, cq;

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

bool _bfs()
{
    memset(chk, 0, sizeof(chk));
    bool flag = 0;
    struct pos cPos, nPos;

    for(int i=11; i>=0; i--)
    {
        for(int j=0; j<6; j++)
        {
            if(chk[i][j] == 0 && map[i][j] != '.')
            {
                chk[i][j] = 1;
                dq.push_back({i, j, 1, map[i][j]});
                cq.push_back({i, j, 1, map[i][j]});

                while(!dq.empty())
                {
                    cPos = dq.front();
                    dq.pop_front();

                    for(int i=0; i<4; i++)
                    {
                        nPos.y = cPos.y + yadd[i];
                        nPos.x = cPos.x + xadd[i];

                        if(nPos.y < 0 || nPos.y >= 12 || nPos.x < 0 || nPos.x >= 6) continue;
                        if(chk[nPos.y][nPos.x] == 0 && map[nPos.y][nPos.x] == cPos.c)
                        {
                            chk[nPos.y][nPos.x] = 1;
                            nPos.n = cPos.n + 1;
                            nPos.c = cPos.c;

                            dq.push_back(nPos);
                            cq.push_back(nPos);
                        }
                    }
                }

                if((int)cq.size()>=4)
                {
                    flag = 1;
                    int tn = (int)cq.size();
                    for(int i=0; i<tn; i++)
                    {
                        map[cq[i].y][cq[i].x] = '.';
                    }
                }

                cq.clear();
            }
        }
    }

    return flag;
}

void _down()
{
    int widx;
    for(int j=0; j<6; j++)
    {
        widx = 11;
        for(int i=11; i>=0; i--)
        {
            if(map[i][j] != '.')
            {
                map[widx][j] = map[i][j];
                if(i!=widx)
                    map[i][j] = '.';
                widx--;
            }
        }
    }
}

void _print()
{
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<6; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<12; i++)
    {
        for(int j=0; j<6; j++)
        {
            cin>>map[i][j];
        }
    }

    int idx = 0;
    while(1)
    {
        idx++;
        if(!_bfs())
        {
            idx--;
            break;
        }

        //cout<<"idx "<<idx<<"\n";
        //_print();

        _down();

        //cout<<"idx "<<idx<<"\n";
        //_print();
    }
    cout<<idx<<"\n";

    return 0;
}