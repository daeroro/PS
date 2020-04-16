#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

struct pos{
    int y, x, n;
};

int W, H, ret = 500;
char map[21][21];
int tmap[21][21];
int dist[21][21];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

int permu[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void dfs(int mIdx, int cur, int st, int num)
{
    if(st == (mIdx-1))
    {
        if(ret > num) ret  = num;
        return;
    }

    for(int i=1; i<mIdx; i++)
    {
        if(dist[cur][i] != 0)
            dfs(mIdx, i, st+1, num+dist[cur][i]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        struct pos rb;
        struct pos sq[11];
        ret = 500;

        cin>>W>>H;
        if(W==0 && H==0) break;

        for(int i=0; i<21; i++)
        {
            for(int j=0; j<21; j++)
            {
                map[i][j] = 0;
                tmap[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        int idx = 1;
        for(int i=0; i<H; i++)
        {
            for(int j=0; j<W; j++)
            {
                cin>>map[i][j];
                if(map[i][j] == 'o')
                {
                    rb.y = i;
                    rb.x = j;
                    rb.n = 0;
                    sq[0] = {i, j, 0};
                    map[i][j] = '.';
                }
                else if(map[i][j] == '*')
                {
                    sq[idx] = {i, j, 0};
                    tmap[i][j] = idx++;
                }
            }
        }

        deque<struct pos> dq;
        for(int i=0; i<idx; i++)
        {
            bool chk[20][20] = {0, };
            chk[sq[i].y][sq[i].x] = 1;
            dq.push_back(sq[i]);

            struct pos cPos, nPos;
            while(!dq.empty())
            {
                cPos = dq.front();
                dq.pop_front();

                for(int j=0; j<4; j++)
                {
                    nPos.y = cPos.y + yadd[j];
                    nPos.x = cPos.x + xadd[j];

                    if(nPos.y < 0 || nPos.y >= H || nPos.x < 0 || nPos.x >= W)
                        continue;
                    if(chk[nPos.y][nPos.x] == 0)
                    {
                        if(map[nPos.y][nPos.x] == '.')
                        {
                            chk[nPos.y][nPos.x] = 1;
                            dq.push_back({nPos.y, nPos.x, cPos.n +1});
                        }
                        else if(map[nPos.y][nPos.x] == '*')
                        {
                            chk[nPos.y][nPos.x] = 1;
                            dq.push_back({nPos.y, nPos.x, cPos.n +1});

                            dist[i][tmap[nPos.y][nPos.x]] = cPos.n +1;
                        }
                    }
                }
            }
        }
/*
        for(int i=0; i<idx; i++)
        {
            for(int j=0; j<idx; j++)
            {
                cout<<dist[i][j]<<' ';
            }
            cout<<"\n";
        }
*/
        //dfs(idx, 0, 0, 0);

        //cout<<"idx "<<idx<<"\n";
        if(idx == 1)
        {
            cout<<"0\n";
            continue;
        }
        vector<int> v(idx-1);
        for(int i=0; i<idx-1; i++)
        {
            v[i] = i+1;
        }
        int tmp, first, second;
        do{
            /*
            for(int i=0; i<idx-1; i++)
            {
                cout<<v[i]<<' ';
            }
            cout<<"\n";
            */
            tmp = 0;
            first = v[0];
            for(int i=1; i<idx-1; i++)
            {
                tmp += dist[first][v[i]];
                first = v[i];
            }
            tmp += dist[0][v[0]];
            if(tmp != 0)
            {
                if(tmp < ret) ret = tmp;
            }

        }while(next_permutation(v.begin(), v.end()));

        if(ret == 500) ret = -1;
        cout<<ret<<"\n";
    }

    return 0;
}