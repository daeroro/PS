#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos{
    int y, x;
};

struct pos2{
    int y, x, c, p;
};

int T;
int M, A, tres;
int _move[2][100];

struct pos P[2] = {{1, 1}, {10, 10}};
struct pos2 bc[8];

int yadd[5] = {0, -1, 0, 1, 0};
int xadd[5] = {0, 0, 1, 0, -1};

bool operator<(struct pos2 a, struct pos2 b)
{
    if(a.p < b.p) return 1;
    else return 0;
}

void _chargeCheck()
{
    priority_queue<struct pos2> pq[2];    

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<A; j++)
        {

            int ty = (int)abs(P[i].y - bc[j].y);
            int tx = (int)abs(P[i].x - bc[j].x);
            //tmp += abs(P[j].x - bc[i].x);
            if(ty+tx <= bc[j].c)
            {
                pq[i].push(bc[j]);
            }
        }
    }
    int ta = (int)pq[0].size();
    int tb = (int)pq[1].size();
    //cout<<"pq num "<<ta<<' '<<tb<<"\n";
    int ma, mb;

    if(ta == 0 && tb == 0)
    {
        ma = 0;
        mb = 0;
    }
    else if(ta == 0 && tb > 0)
    {
        ma = 0;
        mb = pq[1].top().p;
    }
    else if(ta > 0 && tb == 0)
    {
        ma = pq[0].top().p;
        mb = 0;
    }
    else if(ta == 1 && tb == 1)
    {
        ma = pq[0].top().p;
        mb = pq[1].top().p;
        if(pq[0].top().y == pq[1].top().y && pq[0].top().x == pq[1].top().x)
        {
            mb = 0;
        }
    }
    else
    {
        ma = pq[0].top().p;
        mb = pq[1].top().p;
        //cout<<"tma tmb "<<ma<<' '<<mb<<"\n";
        if(pq[0].top().y == pq[1].top().y && pq[0].top().x == pq[1].top().x)
        {
            //cout<<"check\n";
            pq[0].pop();
            pq[1].pop();

            if(pq[0].empty())
            {
                mb = pq[1].top().p;
            }
            else if(pq[1].empty())
            {
                ma = pq[0].top().p;
            }
            else
            {
                if(pq[0].top().p > pq[1].top().p)
                {
                    ma = pq[0].top().p;
                }
                else
                {
                    mb = pq[1].top().p;   
                }
            }
        }
    }

    tres += (ma + mb);
    //cout<<"tres "<<tres<<' '<<ma<<' '<<mb<<' '<<"\n";
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st = 0; st<T; st++)
    {
        tres = 0;
        P[0].y = 1;
        P[0].x = 1;
        P[1].y = 10;
        P[1].x = 10;
        memset(_move, 0, sizeof(_move));
        memset(bc, 0, sizeof(bc));

        cin>>M>>A;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<M; j++)
            {
                cin>>_move[i][j];
            }
        }

        struct pos2 tPos;
        for(int i=0; i<A; i++)
        {
            cin>>tPos.x>>tPos.y>>tPos.c>>tPos.p;
            bc[i] = tPos;
        }

        _chargeCheck();
        for(int i=0; i<M; i++)
        {
            //cout<<"time "<<i+1<<"\n";

            P[0].y += yadd[_move[0][i]];
            P[0].x += xadd[_move[0][i]];

            P[1].y += yadd[_move[1][i]];
            P[1].x += xadd[_move[1][i]];

            _chargeCheck();
        }

        cout<<'#'<<st+1<<' '<<tres<<"\n";

    }

    return 0;
}