#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

struct pos{
    int z, y, x, n;
};

int ret = 10*10*10;
bool map[5][5][5];
bool tmap[5][5][5];

struct pos stt = {0, 0, 0, 0};
struct pos fin = {4, 4, 4, 0};

int zadd[6] = {0, 0, 0, 0, -1, 1};
int yadd[6] = {0, 0, -1, 1, 0, 0};
int xadd[6] = {-1, 1, 0, 0, 0, 0};


void _dfs(int st, int * arr)
{
    if(st == 5)
    {
        /*
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                for(int k=0; k<5; k++)
                {
                    cout<<tmap[i][j][k];
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
        \*/
        bool chk[5][5][5] = {0, };
        deque<struct pos> dq;

        struct pos cPos, nPos;
        if(tmap[4][4][4] == 0) return;
        if(tmap[0][0][0] == 1)
        {
            dq.push_back(stt);
            chk[stt.z][stt.y][stt.x] = 1;
        }

        while(!dq.empty())
        {
            cPos = dq.front();
            dq.pop_front();

            for(int j=0; j<6; j++)
            {
                nPos.z = cPos.z + zadd[j];
                nPos.y = cPos.y + yadd[j];
                nPos.x = cPos.x + xadd[j];

                if(nPos.z < 0 || nPos.z >= 5 || nPos.y < 0 || nPos.y >= 5 || nPos.x < 0 || nPos.x >=5)
                    continue;
                
                if(nPos.z == 4 && nPos.y == 4 && nPos.x == 4)
                {
                    if(ret > cPos.n + 1) ret = cPos.n +1;
                    continue;
                }

                if(chk[nPos.z][nPos.y][nPos.x] == 0 && tmap[nPos.z][nPos.y][nPos.x] == 1)
                {
                    chk[nPos.z][nPos.y][nPos.x] = 1;
                    dq.push_back({nPos.z, nPos.y, nPos.x, cPos.n +1});
                }
            }
        }

        return;
    }

    for(int i=0; i<4; i++)
    {
        switch(i)
        {
            case 0:
                for(int j=0; j<5; j++)
                {
                    for(int k=0; k<5; k++)
                    {
                        tmap[st][j][k] = map[arr[st]][j][k];
                    }
                }
            break;
            case 1:
                for(int j=0; j<5; j++)
                {
                    for(int k=0; k<5; k++)
                    {
                        tmap[st][j][k] = map[arr[st]][4-k][j];
                    }
                }
            break;
            case 2:
                for(int j=0; j<5; j++)
                {
                    for(int k=0; k<5; k++)
                    {
                        tmap[st][j][k] = map[arr[st]][4-j][4-k];
                    }
                }
            break;
            case 3:
                for(int j=0; j<5; j++)
                {
                    for(int k=0; k<5; k++)
                    {
                        tmap[st][j][k] = map[arr[st]][k][4-j];
                    }
                }
            break;
        }

        if(st == 0 && tmap[0][0][0] == 0) continue;
        if(st == 4 && tmap[4][4][4] == 0) continue;
        _dfs(st+1, arr);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
            {
                cin>>map[i][j][k];
            }
        }
    }

    int idx[5] = {0, 1, 2, 3, 4};
    do{
        //for(int i=0; i<5; i++)
        //    cout<<idx[i];
        //cout<<"\n";
        _dfs(0, idx);
    }
    while(next_permutation(idx, idx+5));

    if(ret == 10*10*10) ret = -1;
    cout<<ret<<"\n";

    return 0;
}