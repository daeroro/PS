#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool map[10][10];
bool chk[10][10];

struct pos{
    int y, x;
};

deque<struct pos> dq;
vector<int> v;

int yadd[4] = {0, 0, -1, 1};
int xadd[4] = {-1, 1, 0, 0};

void _bfs()
{
    int tmp = 1;
    struct pos cPos, nPos;

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
            if(map[nPos.y][nPos.x] && !chk[nPos.y][nPos.x])
            {
                chk[nPos.y][nPos.x] = 1;
                tmp++;
                dq.push_back(nPos);

                //cout<<nPos.y<<' '<<nPos.x<<"\n";
            }
        }        
    }

    v.push_back(tmp);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    //cout<<N<<"\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] && !chk[i][j])
            {
                dq.clear();
                chk[i][j] = 1;
                struct pos tPos = {i, j};
                dq.push_back(tPos);

                _bfs();
            }
        }
    }

    sort(v.begin(), v.end());

    cout<<v.size()<<"\n";
    for(int i=0; i<(int)v.size(); i++)
        cout<<v[i]<<' ';
    cout<<"\n";

    return 0;
}