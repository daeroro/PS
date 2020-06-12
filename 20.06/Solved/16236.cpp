#include <iostream>
#include <deque>
#include <cstring>
#include <queue>

using namespace std;

struct pos{
    int y, x, s, t, n;
};

struct pos2{
    int y, x, t;
};

int N;
int map[20][20];
int check[20][20];

struct pos bs;
deque<struct pos2> dq;
priority_queue<struct pos2> pq;

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

bool operator<(struct pos2 a, struct pos2 b)
{
    if(a.t == b.t)
    {
        if(a.y == b.y)
        {
            if(a.x>b.x) return 1;
            else return 0;
        }
        else if(a.y > b.y) return 1;
        else return 0;
    }
    else if(a.t > b.t)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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
            if(map[i][j] == 9)
            {
                bs = {i, j, 2, 0, 0};
                map[i][j] = 0;
            }
        }
    }

    struct pos2 cPos, nPos;
    int res = 0;
    while(1)
    {
        //cout<<"bs "<<bs.y<<' '<<bs.x<<' '<<bs.s<<' '<<bs.n<<' '<<bs.t<<"\n";
        memset(check, 0, sizeof(check));
        while(!pq.empty())
        {
            pq.pop();
        }

        dq.push_back({bs.y, bs.x, 0});
        check[bs.y][bs.x] = 1;
        
        while(!dq.empty())
        {
            cPos = dq.front();
            //cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.t<<' '<<map[cPos.y][cPos.x]<<"\n";
            dq.pop_front();

            for(int i=0; i<4; i++)
            {
                nPos.y = cPos.y + yadd[i];
                nPos.x = cPos.x + xadd[i];

                if(nPos.y < 0 || nPos.y >=N || nPos.x < 0 || nPos.x >= N)
                    continue;
                if(check[nPos.y][nPos.x] == 0)
                {
                    if(map[nPos.y][nPos.x] == 0 || map[nPos.y][nPos.x] == bs.s)
                    {
                        check[nPos.y][nPos.x] = 1;
                        nPos.t = cPos.t + 1;
                        dq.push_back(nPos);
                    }
                    else if(map[nPos.y][nPos.x] < bs.s)
                    {
                        //cout<<"push "<<nPos.y<<' '<<nPos.x<<"\n";
                        check[nPos.y][nPos.x] = 1;
                        nPos.t = cPos.t + 1;
                        pq.push(nPos);
                    }
                }
            }
        }

        if((int)pq.size() == 0)
        {
            break;
        }
        else
        {
            //cout<<"size "<<pq.size()<<"\n";
            struct pos2 tPos;
            tPos = pq.top();

            map[tPos.y][tPos.x] = 0;

            bs.y = tPos.y;
            bs.x = tPos.x;
            bs.t += tPos.t;
            bs.n++;
            if(bs.s == bs.n)
            {
                bs.n = 0;
                bs.s++;
            }            
        }
    }

    cout<<bs.t<<"\n";

    return 0;
}