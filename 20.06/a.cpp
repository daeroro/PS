#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x;
};

int N, res;
int ct, cy, cx;
int map[10][10];
int gtmp, btmp;
deque<int> gq, bq;

void _slide()
{
    // green
    struct pos cPos, nPos;
    deque<struct pos> dq, dq2;

    switch(ct)
    {
        case 1:
            dq.push_back({cy, cx});
        break;

        case 2:
            dq.push_back({cy, cx});
            dq.push_back({cy, cx+1});
        break;

        case 3:
            dq.push_back({cy+1, cx});
        break;
    }

    int tnum = (int)dq.size();
    int flag = 0;
    while(1)
    {
        for(int i=0; i<tnum; i++)
        {
            nPos.y = dq[i].y + 1;
            nPos.x = dq[i].x;

            if(nPos.y > 9 || map[nPos.y][nPos.x] == 1)
            {
                flag = 1;
                break;
            }
            dq[i].y = nPos.y;
            dq[i].x = nPos.x;            
        }

        if(flag == 1) break;
    }

    switch(ct)
    {
        case 1:
            map[dq[0].y][dq[0].x] = 1;
        break;

        case 2:
            map[dq[1].y][dq[1].x-1] = 1;
            map[dq[1].y][dq[1].x] = 1;
        break;

        case 3:
            map[dq[0].y][dq[0].x] = 1;
            map[dq[0].y-1][dq[0].x] = 1;
        break;
    }

    //blue
    switch(ct)
    {
        case 1:
            dq2.push_back({cy, cx});
        break;

        case 2:
            dq2.push_back({cy, cx+1});
        break;

        case 3:
            dq2.push_back({cy, cx});
            dq2.push_back({cy+1, cx});
        break;
    }

    tnum = (int)dq2.size();
    flag = 0;
    while(1)
    {
        for(int i=0; i<tnum; i++)
        {
            nPos.y = dq2[i].y;
            nPos.x = dq2[i].x+1;

            if(nPos.x > 9 || map[nPos.y][nPos.x] == 1)
            {
                flag = 1;
                break;
            }
            dq2[i].y = nPos.y;
            dq2[i].x = nPos.x;            
        }

        if(flag == 1) break;
    }

    switch(ct)
    {
        case 1:
            map[dq2[0].y][dq2[0].x] = 1;
        break;

        case 2:
            map[dq2[0].y][dq2[0].x] = 1;
            map[dq2[0].y][dq2[0].x-1] = 1;
        break;

        case 3:
            map[dq2[1].y-1][dq2[1].x] = 1;
            map[dq2[1].y][dq2[1].x] = 1;
        break;
    }
}

void _print()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout<<map[i][j]<<' ';
        }
        cout<<"\n";
    }
}

void _checkFull()
{
    gq.clear();
    bq.clear();

    int j;
    // green
    for(int i=6; i<=9; i++)
    {
        for(j=0; j<=3; j++)
        {
            if(map[i][j] == 0) break;
        }

        if(j == 4)
        {
            res++;
            gq.push_back(i);            
            for(j=0; j<=3; j++)
            {
                map[i][j] = 0;

            }
        }
    }

    // blue
    for(int i=6; i<=9; i++)
    {
        for(j=0; j<=3; j++)
        {
            if(map[j][i] == 0) break;
        }

        if(j==4)
        {
            bq.push_back(i);
            res++;
            for(j=0; j<=3; j++)
            {
                map[j][i] = 0;
                //cout<<"blue "<<i<<"\n";
            }
        }
    }
}

void _down()
{
    // green
    if((int)gq.size() > 0)
    {
        int fidx = gq.front();
        
        for(int i=0; i<4; i++)
        {
            int oNum = 0;
            for(int j=4; j<fidx; j++)
            {
                if(map[j][i] == 1)
                {
                    map[j][i] = 0;
                    oNum++;
                }
            }

            if(oNum > 0)
            {
                int lidx = fidx;
                while(map[lidx][i] == 0 && lidx<10) lidx++;
                for(int j=1; j<=oNum; j++)
                {
                    map[lidx-j][i] = 1;
                }
            }
        }
    }

    // blue
    if((int)bq.size() > 0)
    {
        int fidx = bq.front();

        for(int i=0; i<4; i++)
        {
            int oNum = 0;
            for(int j=4; j<fidx; j++)
            {
                if(map[i][j] == 1)
                {
                    map[i][j] = 0;
                    oNum++;
                }
            }

            if(oNum > 0)
            {
                int lidx = fidx;
                while(map[i][lidx] == 0 && lidx < 10) lidx++;
                for(int j=1; j<=oNum; j++)
                {
                    map[i][lidx-j] = 1;
                }
            }
        }
    }
}

void _checkIn()
{
    gtmp = 0, btmp = 0;
    // green
    for(int i=4; i<6; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(map[i][j] == 1)
            {
                gtmp++;
                break;
            }
        }
    }

    for(int i=4; i<6; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(map[j][i] ==1)
            {
                btmp++;
                break;
            }
        }
    }
}

void _move()
{
    if(gtmp == 1)
    {
        for(int i=8; i>=5; i--)
        {
            for(int j=0; j<4; j++)
            {
                map[i+1][j] = map[i][j];
            }
        }

        for(int j=0; j<4; j++)
        {
            map[5][j] = 0;
        }
    }
    else if(gtmp == 2)
    {
        for(int i=7; i>=4; i--)
        {
            for(int j=0; j<4; j++)
            {
                map[i+2][j] = map[i][j];
            }
        }

        for(int i=4; i<6; i++)
        {
            for(int j=0; j<4; j++)
            {
                map[i][j] = 0;
            }
        }
    }

    if(btmp == 1)
    {
        for(int i=8; i>=5; i--)
        {
            for(int j=0; j<4; j++)
            {
                map[j][i+1] = map[j][i];
            }
        }

        for(int j=0; j<4; j++)
        {
            map[j][5] = 0;
        }
    }
    else if(btmp == 2)
    {
        for(int i=7; i>=4; i--)
        {
            for(int j=0; j<4; j++)
            {
                map[j][i+2] = map[j][i];
            }
        }

        for(int i=4; i<6; i++)
        {
            for(int j=0; j<4; j++)
            {
                map[j][i] = 0;
            }
        }        
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int turn = 0;
    while(1)
    {
        if(turn == N) break;
        turn++;
        cin>>ct>>cy>>cx;

        _slide();

        while(1)
        {
            _checkFull();
            if(bq.empty() && gq.empty()) break;

            _down();
        }

        _checkIn();
        _move();

        cout<<"\n";
        _print();
    }

    int tnum = 0;
    for(int i=4; i<10; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(map[i][j] == 1) tnum++;
            if(map[j][i] == 1) tnum++;
        }
    }

    cout<<res<<"\n";
    cout<<tnum<<"\n";

    return 0;
}