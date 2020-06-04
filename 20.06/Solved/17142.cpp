#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct pos {
    int y, x, t;
};

int N, M, zNum, vNum, res = 500*500;
int map[50][50], check[50][50];
bool vCheck[10];
int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

deque<struct pos> vq, dq;

void _dfs(int st, int cur)
{
    if(st == M)
    {
        dq.clear();
        memset(check, 0, sizeof(check));
        int tNum = 0;
        struct pos tPos;
        for(int i=0; i<vNum; i++)
        {
            if(vCheck[i] == 1)
            {
                tPos = vq[i];
                check[tPos.y][tPos.x] = 1;

                dq.push_back(tPos);
            }
        }

        struct pos cPos, nPos;
        int tres = 0, flag = 0;
        while(!dq.empty())
        {
            cPos = dq.front();
            dq.pop_front();

            for(int i=0; i<4; i++)
            {
                nPos.y = cPos.y + yadd[i];
                nPos.x = cPos.x + xadd[i];

                if(nPos.y < 0 || nPos.y >= N || nPos.x < 0 || nPos.x >= N)
                    continue;

                if(check[nPos.y][nPos.x] == 0)
                {
                    if(map[nPos.y][nPos.x] == 0)
                    {
                        check[nPos.y][nPos.x] = cPos.t+1;
                        tNum++;

                        nPos.t = cPos.t+ 1;
                        dq.push_back(nPos);
                        if(tres < nPos.t) tres = nPos.t;
                        if(tNum == zNum)
                        {
                            /*
                            for(int k=0; k<vNum; k++) cout<<vCheck[k]<<' ';
                            cout<<"\n";
                            cout<<cPos.t+1<<"\n";

                            for(int k=0; k<N; k++)
                            {
                                for(int l=0; l<N; l++)
                                {
                                    cout<<check[k][l]<<' ';
                                }
                                cout<<"\n";
                            }
                            */
                            flag = 1;
                            goto ret;
                        }                        
                    }
                    else if(map[nPos.y][nPos.x] == 2)
                    {
                        check[nPos.y][nPos.x] = cPos.t+1;

                        nPos.t = cPos.t + 1;
                        dq.push_back(nPos);

                        if(tres < nPos.t) tres = nPos.t;
                    }
                }
            }
        }
ret:

        if(flag == 1 && res > tres) res = tres;

        return;
    }

    for(int i = cur+1; i<vNum; i++)
    {
        if(vCheck[i] == 0)
        {
            vCheck[i] = 1;
            _dfs(st+1, i);

            vCheck[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 0)
            {
                zNum++;
            }
            else if(map[i][j] == 2)
            {
                vq.push_back({i, j, 0});
                vNum++;
            }
        }
    }

    if(zNum == 0)
    {
        cout<<"0\n";
        return 0;
    }

    _dfs(0, -1);

    if(res == 500*500) res = -1;
    cout<<res<<"\n";

    return 0;
}