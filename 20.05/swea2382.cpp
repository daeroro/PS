#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, n, d;
};

int T;
int N, M, K;
int yadd[5] = {0, -1, 1, 0, 0};
int xadd[5] = {0, 0, 0, -1, 1};

deque<struct pos> dq[2];
deque<struct pos> map[100][100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st = 0; st < T; st++)
    {
        dq[0].clear();
        dq[1].clear();
        struct pos tPos;
        int cur = 1, next = 0;
        cin>>N>>M>>K;
        for(int i=0; i<K; i++)
        {
            cin>>tPos.y>>tPos.x>>tPos.n>>tPos.d;
            dq[0].push_back({tPos.y, tPos.x, tPos.n, tPos.d});
        }

        struct pos cPos, nPos;
        int tres = 0;
        for(int i=0; i<M; i++)
        {
            //deque<struct pos> map[100][100];            
            tres = 0;
            cur = 1-cur;
            next = 1-next;
            dq[next].clear();

            for(int j=0; j<(int)dq[cur].size(); j++)
            {
                cPos = dq[cur][j];

                nPos.y = cPos.y + yadd[cPos.d];
                nPos.x = cPos.x + xadd[cPos.d];

                if(nPos.y == 0 || nPos.y == N-1 || nPos.x == 0 || nPos.x == N-1)
                {
                    nPos.n = cPos.n / 2;
                    switch(cPos.d)
                    {
                        case 1:
                            nPos.d = 2;
                        break;

                        case 2:
                            nPos.d = 1;
                        break;

                        case 3:
                            nPos.d = 4;
                        break;

                        case 4:
                            nPos.d = 3;
                        break;
                    }

                    //dq[next].push_back({nPos.y, nPos.x, nPos.n, nPos.d});
                    if(nPos.n > 0)
                        map[nPos.y][nPos.x].push_back({nPos.y, nPos.x, nPos.n, nPos.d});
                    continue;
                }

                nPos.n = cPos.n;
                nPos.d = cPos.d;
                //dq[next].push_back({nPos.y, nPos.x, nPos.n, nPos.d});
                map[nPos.y][nPos.x].push_back({nPos.y, nPos.x, nPos.n, nPos.d});
            }

            //dq[cur].clear();

            for(int j=0; j<N; j++)
            {
                for(int k=0; k<N; k++)
                {
                    switch((int)map[j][k].size())
                    {
                        case 0:
                        break;

                        case 1:
                            //tres += map[i][j][0].n;
                            dq[next].push_back({j, k, map[j][k][0].n, map[j][k][0].d});
                        break;

                        default:
                            int tdir = map[j][k][0].d;
                            int tcur = map[j][k][0].n, tsum = map[j][k][0].n;
                            for(int l=1; l<(int)map[j][k].size(); l++)
                            {
                                tsum += map[j][k][l].n;
                                if(tcur < map[j][k][l].n)
                                {
                                    tcur = map[j][k][l].n;
                                    tdir = map[j][k][l].d;
                                }
                            }

                            //tres += tsum;
                            dq[next].push_back({j, k, tsum, tdir});
                        break;
                    }

                    map[j][k].clear();
                }
            }

            //cout<<dq[cur].size()<<' '<<dq[next].size()<<"\n";
            //cout<<"tres "<<tres<<"\n";
        }

        for(int i=0; i<(int)dq[next].size(); i++)
        {
            tres += dq[next][i].n;
        }
        cout<<'#'<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}