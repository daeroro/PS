/*
    1. 간단하게 접근하기!
    2. x, y 헷갈리지 않기...
*/
#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

struct pos{
    int y, x;
};
int N, res = 100*20*20;
int map[21][21], cmap[21][21];
int cy, cx, d1, d2;
int Num[6];

deque<struct pos> dq;

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

void _checkBoundary()
{
    memset(Num, 0, sizeof(Num));
    memset(cmap, 0, sizeof(cmap));
    dq.clear();
    for(int i=0; i<d1; i++)
    {
        cmap[cy+i][cx-i] = 5;
        cmap[cy+d2+d1-i][cx+d2-d1+i] = 5;
    }
    for(int i=0; i<d2; i++)
    {
        cmap[cy+d1+i][cx-d1+i] = 5;
        cmap[cy+d2-i][cx+d2-i] = 5;
    }

    dq.push_back({1, 1});
    cmap[1][1] = -1;

    struct pos cPos, nPos;
    while(!dq.empty())
    {
        cPos = dq.front();
        dq.pop_front();

        for(int i=0; i<4; i++)
        {
            nPos.y = cPos.y + yadd[i];
            nPos.x = cPos.x + xadd[i];

            if(nPos.y <=0 || nPos.y >N || nPos.x <= 0 || nPos.x >N) continue;
            if(cmap[nPos.y][nPos.x] == 0)
            {
                cmap[nPos.y][nPos.x] = -1;

                dq.push_back(nPos);
            }
        }
    }

    for(int i=1; i<cy+d1; i++)
    {
        for(int j=1; j<=cx; j++)
        {
            if(cmap[i][j] == -1)
                cmap[i][j] = 1;
        }
    }

    for(int i=1; i<=cy+d2; i++)
    {
        for(int j=cx+1; j<=N; j++)
        {
            if(cmap[i][j] == -1)
                cmap[i][j] = 2;
        }
    }

    for(int i=cy+d1; i<=N; i++)
    {
        for(int j=1; j<cx-d1+d2; j++)
        {
            if(cmap[i][j] == -1)
                cmap[i][j] = 3;
        }
    }

    for(int i=cy+d2+1; i<=N; i++)
    {
        for(int j=cx-d1+d2; j<=N; j++)
        {
            if(cmap[i][j] == -1)
                cmap[i][j] = 4;
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            switch(cmap[i][j])
            {
                case 0:
                case 5:
                    Num[5] += map[i][j];
                break;

                case 1:
                    Num[1] += map[i][j];
                break;

                case 2:
                    Num[2] += map[i][j];
                break;

                case 3:
                    Num[3] += map[i][j];
                break;

                case 4:
                    Num[4] += map[i][j];
                break;
            }
        }
    }

    for(int i=1; i<=5; i++)
    {
        if(Num[i] == 0) return;
    }
    for(int i=1; i<=5; i++)
    {
        cout<<Num[i]/5<<' ';
    }
    cout<<"\n";

    int tma = Num[1], tmi = Num[1];
    for(int i=2; i<=5; i++)
    {
        if(tma < Num[i]) tma = Num[i];
        if(tmi > Num[i]) tmi = Num[i];
    }

    if((tma - tmi)  < res) res = tma- tmi;
/*
    cout<<tma-tmi<<"\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<cmap[i][j]<<' ';
        }
        cout<<"\n";
    }
*/
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=N; k++)
            {
                for(int l=1; l<=N; l++)
                {
                    cy = i;
                    cx = j;
                    d1 = k;
                    d2 = l;

                    if(cy + d1 + d2 <=N && 1+d2<=cx && cx+d2<=N)
                    {
                        _checkBoundary();
                    }
                }
            }
        }
    }

    cout<<res<<"\n";

    return 0;
}