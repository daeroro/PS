#include <iostream>
#include <cstring>

using namespace std;

struct pos{
    int y, x, n, d;
};

int map[4][4], res;
struct pos fs[17];
struct pos sk;

int yadd[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int xadd[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void _swap(int a, int b)
{
    int tmp;
    struct pos tPos;

    tmp = map[fs[a].y][fs[a].x];
    map[fs[a].y][fs[a].x] = map[fs[b].y][fs[b].x];
    map[fs[b].y][fs[b].x] = tmp;

    tPos.y = fs[a].y;
    tPos.x = fs[a].x;

    fs[a].y = fs[b].y;
    fs[a].x = fs[b].x;

    fs[b].y = tPos.y;
    fs[b].x = tPos.x;
}

void _print(int st)
{
    cout<<"cur st sk "<<st<<' '<<sk.y<<' '<<sk.x<<' '<<sk.d<<' '<<res<<"\n";
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<'('<<map[i][j]<<", "<<fs[map[i][j]].d<<") ";
        }
        cout<<"\n";
    }
}

void _move()
{
    struct pos cPos, nPos;
    int td, tn;
    for(int i=1; i<=16; i++)
    {
        if(fs[i].d != -1)
        {
            cPos = fs[i];
            for(int j=1; j<=8; j++)
            {
                td = (cPos.d + j -1 <= 8) ? cPos.d + j-1 : (cPos.d+j-1)%8;
                nPos.y = cPos.y + yadd[td];
                nPos.x = cPos.x + xadd[td];

                if(nPos.y < 0 || nPos.y >= 4 || nPos.x < 0 || nPos.x >= 4 
                || (sk.y == nPos.y && sk.x == nPos.x)) continue;

                if(map[nPos.y][nPos.x] == 0)
                {
                    map[cPos.y][cPos.x] = 0;
                    map[nPos.y][nPos.x] = i;
                    fs[i].y = nPos.y;
                    fs[i].x = nPos.x;
                    fs[i].d = td;
                    break;
                }
                else if(map[nPos.y][nPos.x] > 0)
                {
                    tn = map[nPos.y][nPos.x];
                    fs[i].d = td;
                    _swap(i, tn);
                    break;
                }       
            }
        }
        /*
        if(res<8)
        {
        cout<<"i "<<i<<"\n";
        _print();
        }
        */
    }
}

void _dfs(int st, int tres)
{
    _move();
    //_print(st);

    int tmap[4][4] = {0, };
    struct pos tfs[17] = {0, }, tsk, nPos;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            tmap[i][j] = map[i][j];
        }
    }

    for(int i=1; i<=16; i++)
    {
        tfs[i] = fs[i];
    }
    tsk = sk;

    for(int i=1; i<=3; i++)
    {
        nPos.y = sk.y + i*yadd[sk.d];
        nPos.x = sk.x + i*xadd[sk.d];

        if(nPos.y < 0 || nPos.y >= 4 || nPos.x < 0 || nPos.x >= 4) break;
        else if(map[nPos.y][nPos.x] == 0) continue;
        else if(map[nPos.y][nPos.x] > 0)
        {
            int tn = map[nPos.y][nPos.x];

            sk.y = nPos.y;
            sk.x = nPos.x;
            sk.d = fs[tn].d;
            if(tres+tn > res) res = tres + tn;
            fs[tn].d = -1;
            map[nPos.y][nPos.x] = 0;

            _dfs(st+1, tres+tn);

            for(int j=0; j<4; j++)
            {
                for(int k=0; k<4; k++)
                {
                    map[j][k] = tmap[j][k];
                }
            }

            for(int j=1; j<=16; j++)
            {
                fs[j] = tfs[j];
            }
            sk = tsk;
        }
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tn, td;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>tn>>td;
            fs[tn] = {i, j, tn, td};
            map[i][j] = tn;
        }
    }

    sk = {0, 0, -1, fs[map[0][0]].d};
    //cout<<"start sk.d "<<sk.d<<"\n";
    res += map[0][0];
    fs[map[0][0]].d = -1;
    map[0][0] = 0;
    
    _dfs(1, res);

    cout<<res<<"\n";

    return 0;
}