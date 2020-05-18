#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, k;
};

int T, tres, ma;
int N, M;
int map[20][20];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

deque<struct pos> dq;

void _bfs(int cy, int cx, int mK)
{
    bool chk[20][20] = {0, };
    int tnum = 0;
    if(map[cy][cx] == 1) tnum++;
    chk[cy][cx] = 1;

    dq.push_back({cy, cx, 1});

    struct pos cPos, nPos;
    while(!dq.empty())
    {
        cPos = dq.front();
        //if(tnum > 5)
        //cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.k<<"\n";
        dq.pop_front();

        for(int i=0; i<4; i++)
        {
            nPos.y = cPos.y + yadd[i];
            nPos.x = cPos.x + xadd[i];

            if(nPos.y <0 || nPos.y >= N || nPos.x < 0 || nPos.x >= N) continue;
            if(chk[nPos.y][nPos.x] == 0)
            {
                chk[nPos.y][nPos.x] = 1;
                if(map[nPos.y][nPos.x] == 1) tnum++;

                if(cPos.k+1 < mK)
                {
                    dq.push_back({nPos.y, nPos.x, cPos.k+1});
                }
            }
        }
    }

    int cost = mK*mK+(mK-1)*(mK-1);
    if(tnum * M >= cost)
    {
        /*
        cout<<"cy cx "<<cy<<' '<<cx<<"\n";
        cout<<"cur "<<cost<<' '<<mK<<' '<<tnum*M<<' '<<tnum<<"\n";
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<chk[i][j]<<' ';
            }
            cout<<"\n";
        }
        */
        if(tres < tnum) tres = tnum;
    }
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
        for(int i=0; i<20; i++)
        {
            for(int j=0; j<20; j++)
            {
                map[i][j] = 0;
            }
        }

        cin>>N>>M;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>map[i][j];
            }
        }

        if(M >= 1) tres = 1;

        ma = N%2 == 0 ? N+1 : N;
        for(int i=2; i<=ma; i++)
        {
            for(int j=0; j<N; j++)
            {
                for(int k=0; k<N; k++)
                {
                    _bfs(j, k, i);
                }
            }
        }

        cout<<'#'<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}