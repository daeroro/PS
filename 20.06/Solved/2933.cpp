#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x;
};

int R, C, N;
char map[100][100];
int hi[100];
int xnum;

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

deque<struct pos> dq, tq;

void _move()
{
    int tsize = (int)tq.size();
    int td = 1;
    struct pos cPos, nPos;
    bool flag = 0;
    while(1)
    {
        flag = 0;
        for(int i=0; i<tsize; i++)
        {
            cPos = tq[i];
            nPos.y = cPos.y + td;
            nPos.x = cPos.x;
            if(map[nPos.y][nPos.x] == 'x' || nPos.y == R)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1) break;
        td++;
    }

    td--;
    if(flag == 1)
    {
        for(int i=0; i<tsize; i++)
        {
            tq[i].y += td;
            cPos = tq[i];
            map[cPos.y][cPos.x] = 'x';
        }
    }
    //cout<<"td "<<td<<"\n";
}

void _bfs()
{
    int tnum = 0;
    bool chk[100][100] = {0, };
    int flag = 0;

    for(int j=0; j<C; j++)
    {
        if(chk[R-1][j] == 0 && map[R-1][j] == 'x')
        {
            chk[R-1][j] = 1;
            dq.push_back({R-1, j});
            tnum++;
        }
    }

    struct pos cPos, nPos;
    while(!dq.empty())
    {
        cPos = dq.front();
        dq.pop_front();

        for(int i=0; i<4; i++)
        {
            nPos.y = cPos.y + yadd[i];
            nPos.x = cPos.x + xadd[i];

            if(nPos.y <0 || nPos.y >= R || nPos.x <0 || nPos.x >= C) continue;
            if(chk[nPos.y][nPos.x] == 0 && map[nPos.y][nPos.x] == 'x')
            {
                chk[nPos.y][nPos.x] = 1;
                tnum++;
                dq.push_back({nPos.y, nPos.x});
            }
        }
    }

    tq.clear();
    if(tnum != xnum)
    {
        for(int i=R-1; i>=0; i--)
        {
            for(int j=0; j<C; j++)
            {
                if(chk[i][j] == 0 && map[i][j] == 'x')
                {
                    map[i][j] = '.';
                    tq.push_back({i, j});
                }
            }
        }
    }

    //cout<<"tq size "<<tq.size()<<"\n";
    if((int)tq.size() > 0)
    {
        _move();
    }
}

void _print()
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
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

    cin>>R>>C;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 'x')
            {
                xnum++;
            }
        }
    }
    cin>>N;
    for(int i=0; i<N; i++) cin>>hi[i];

    int thi;
    for(int i=0; i<N; i++)
    {
        if(i%2==0)
        {
            thi = R-hi[i];
            for(int j=0; j<C; j++)
            {
                if(map[thi][j] == 'x')
                {
                    map[thi][j] = '.';
                    xnum--;
                    break;
                }
            }
        }
        else
        {
            thi = R-hi[i];
            for(int j=C-1; j>=0; j--)
            {
                if(map[thi][j] == 'x')
                {
                    map[thi][j] = '.';
                    xnum--;
                    break;
                }
            }
        }
        //cout<<"cur "<<i<<"\n";
        //_print();

        if(xnum > 0)
            _bfs();
        
        //cout<<"cur "<<i<<"\n";
        //_print();
    }

    _print();

    return 0;
}