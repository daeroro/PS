#include <iostream>
#include <cstring>

using namespace std;

struct pos{
    int y, x, d;
};

int T;
int N, res;
int map[100][100];
struct pos stt;

int yadd[5] = {0, 0, -1, 0, 1};
int xadd[5] = {0, 1, 0, -1, 0};

struct pos wh[2][5];
int cDir[5][4] = {{3, 4, 2, 1}, {3, 1, 4, 2}, {4, 3, 1, 2},
                    {2, 4, 1, 3}, {3, 4, 1, 2}};

void _go()
{
    struct pos cPos = stt, nPos;
    int tres = 0;
    while(1)
    {
        nPos.y = cPos.y + yadd[cPos.d];
        nPos.x = cPos.x + xadd[cPos.d];
        //cout<<"stt "<<stt.y<<' '<<stt.x<<"\n";
        //cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.d<<' '<<map[cPos.y][cPos.x]<<" nPos "<<nPos.y<<' '<<nPos.x<<' '<<map[nPos.y][nPos.x]<<"\n";

        if(nPos.y<0 || nPos.y >= N || nPos.x <0 || nPos.x >= N)
        {
            tres++;
            switch(cPos.d)
            {
                case 1:
                    nPos.d = 3;
                break;

                case 2:
                    nPos.d = 4;
                break;

                case 3:
                    nPos.d = 1;
                break;

                case 4:
                    nPos.d = 2;
                break;
            }
        }
        else if((nPos.y == stt.y && nPos.x == stt.x) || map[nPos.y][nPos.x] == -1)
            break;        
        else if(map[nPos.y][nPos.x] == 0)
        {
            nPos.d = cPos.d;
        }
        else if(map[nPos.y][nPos.x] > 0 && map[nPos.y][nPos.x] < 6)
        {
            nPos.d = cDir[map[nPos.y][nPos.x]-1][cPos.d-1];
            tres++;
        }
        else
        {
            nPos.d = cPos.d;
            int ty = nPos.y, tx = nPos.x;
            if(wh[0][map[ty][tx]-6].y == nPos.y && wh[0][map[ty][tx]-6].x == nPos.x)
            {
                nPos.y = wh[1][map[ty][tx]-6].y;
                nPos.x = wh[1][map[ty][tx]-6].x;
            }
            else
            {
                nPos.y = wh[0][map[ty][tx]-6].y;
                nPos.x = wh[0][map[ty][tx]-6].x;                
            }
        }

        cPos = nPos;
    }

    //cout<<"tres "<<tres<<"\n";
    if(res < tres) res = tres;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st = 0; st<T; st++)
    {
        memset(wh, 0, sizeof(wh));
        memset(map, 0, sizeof(map));
        res = 0;

        cin>>N;
        //cout<<"N "<<N<<"\n";
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>map[i][j];
                if(map[i][j] > 5)
                {
                    if(wh[0][map[i][j]-6].d == 0)
                    {
                        wh[0][map[i][j]-6] = {i, j, -1};
                    }
                    else
                    {
                        wh[1][map[i][j]-6] = {i, j, -1};   
                    }
                }
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(map[i][j] == 0)
                {
                    //cout<<"cur "<<i<<' '<<j<<"\n";
                    stt.y = i;
                    stt.x = j;
                    stt.d = 0;

                    for(int k=1; k<5; k++)
                    {
                        stt.d = k;
                        _go();
                    }
                }
            }
        }

        cout<<'#'<<st+1<<' '<<res<<"\n";
    }

    return 0;
}