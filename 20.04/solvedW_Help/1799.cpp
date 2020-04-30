/*
1. 시간복잡도 구하기
- 초과하면 주어진 것들을 나눌 수 있는 방법을 생각해보기

2. dfs시 초기 조건 생각하기
*/

#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x;
};

int N, ret[2], dnum[2];
bool map[10][10];
bool chk1[2][22], chk2[2][22];

deque<struct pos> dq[2];

void _dfs(int st, int idx, int sel)
{
    //cout<<"st "<<st<<' '<<tq.size()<<"\n";
    if(st >= (int)dq[sel].size())
    {
        ret[sel] = st;
        return;
    }
    if(st > ret[sel])
    {
        ret[sel] = st;
    }

    for(int i=idx+1; i<dnum[sel]; i++)
    {
        int c1 = dq[sel][i].y+ dq[sel][i].x;
        int c2 = dq[sel][i].y + (N-1 - dq[sel][i].x);

        if(chk1[sel][c1] == 0 && chk2[sel][c2] == 0)
        {
            chk1[sel][c1] = 1;
            chk2[sel][c2] = 1;       

            _dfs(st+1, i, sel);

            chk1[sel][c1] = 0;
            chk2[sel][c2] = 0;
        }
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
            if(map[i][j] == 1)
            {
                if((i+j)%2 == 0)
                    dq[0].push_back({i, j});
                else
                    dq[1].push_back({i, j});
            }
        }
    }

    dnum[0] = (int)dq[0].size();
    dnum[1] = (int)dq[1].size();
    //cout<<"num "<<dnum[0]<<' '<<dnum[1]<<"\n";
    _dfs(0, -1, 0);
    _dfs(0, -1, 1);

    //cout<<ret[0]<<' '<<ret[1]<<"\n";
    cout<<ret[0]+ret[1]<<"\n";

    return 0;
}