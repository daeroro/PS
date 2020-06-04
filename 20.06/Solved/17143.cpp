#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct pos {
    int r, c, s, d, z;
};

int R, C, M, res;
deque<struct pos> dq;
int map[101][101];

int yadd[5] = {0, -1, 1, 0, 0};
int xadd[5] = {0, 0, 0, 1, -1};

void _catchShark(int curC)
{
    int tnum;
    for(int i=1; i<=R; i++)
    {
        if(map[i][curC]>0)
        {
            tnum = map[i][curC];
            res += dq[tnum].z;
            dq[tnum].z = -1;

            break;
        }
    }
}

void _moveShark()
{
    memset(map, 0, sizeof(map));
    int tnum;
    struct pos cPos;
    for(int i=1; i<=M; i++)
    {
        if(dq[i].z != -1)
        {
            if(dq[i].d <= 2)
            {
                tnum = (dq[i].s %(2*(R-1)));
            }
            else if(dq[i].d > 1)
            {
                tnum = (dq[i].s %(2*(C-1)));
            }

            cPos = dq[i];
            for(int j=0; j<tnum; j++)
            {
                cPos.r += yadd[cPos.d];
                cPos.c += xadd[cPos.d];

                if(cPos.r<1 || cPos.r >R || cPos.c <1 || cPos.c >C)
                {
                    cPos.r -= 2*yadd[cPos.d];
                    cPos.c -= 2*xadd[cPos.d];

                    switch(cPos.d)
                    {
                        case 1:
                            cPos.d = 2;
                        break;

                        case 2:
                            cPos.d = 1;
                        break;

                        case 3:
                            cPos.d = 4;
                        break;

                        case 4:
                            cPos.d = 3;
                        break;
                    }
                }
            }

            if(map[cPos.r][cPos.c] == 0)
            {
                map[cPos.r][cPos.c] = i;
                dq[i] = cPos;
            }
            else
            {
                int tidx = map[cPos.r][cPos.c];
                if(dq[tidx].z < dq[i].z)
                {
                    dq[tidx].z = -1;
                    map[cPos.r][cPos.c] = i;
                    dq[i] = cPos;
                }
                else
                {
                    dq[i].z = -1;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C>>M;
    struct pos tPos;
    dq.push_back({0, 0, 0, 0, -1});
    for(int i=0; i<M; i++)
    {
        cin>>tPos.r>>tPos.c>>tPos.s>>tPos.d>>tPos.z;
        dq.push_back(tPos);
        map[tPos.r][tPos.c] = i+1;
    }

    for(int i=1; i<=C; i++)
    {
        /*
        cout<<i<<"\n";
        for(int j=1; j<=R; j++)
        {
            for(int k=1; k<=C; k++)
            {
                cout<<map[j][k]<<' ';
            }
            cout<<"\n";
        }
        */
        _catchShark(i);
        _moveShark();
        /*
        cout<<i<<"\n";
        for(int j=1; j<=R; j++)
        {
            for(int k=1; k<=C; k++)
            {
                cout<<map[j][k]<<' ';
            }
            cout<<"\n";
        }
        */
    }

    cout<<res<<"\n";

    return 0;
}