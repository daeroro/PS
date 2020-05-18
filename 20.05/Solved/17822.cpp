#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, n;
};

int N, M, T;
int xi, di, ki;

deque<int> dq[51];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tnum;
    cin>>N>>M>>T;
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>tnum;
            dq[i].push_back(tnum);
        }
    }

    while(T--)
    {
        cin>>xi>>di>>ki;
        for(int i=1; i<=N; i++)
        {
            if(i%xi == 0)
            {
                if(di == 0)
                {
                    for(int j=0; j<ki; j++)
                    {
                        tnum = dq[i].back();
                        dq[i].pop_back();

                        dq[i].push_front(tnum);
                    }
                }
                else
                {
                    for(int j=0; j<ki; j++)
                    {
                        tnum = dq[i].front();
                        dq[i].pop_front();

                        dq[i].push_back(tnum);
                    }
                }
            }
        }

        bool flag = 0;
        bool chk[51][50] = {0, };
        struct pos cPos, nPos, tPos;
        deque<struct pos> tq, eq;
        for(int i=1; i<=N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(chk[i][j] == 0 && dq[i][j] != 0)
                {
                    chk[i][j] = 1;
                    tq.push_back({i, j, dq[i][j]});
                    eq.push_back({i, j, dq[i][j]});

                    while(!tq.empty())
                    {
                        cPos = tq.front();
                        tq.pop_front();

                        for(int k=0; k<4; k++)
                        {
                            nPos.y = cPos.y + yadd[k];
                            nPos.x = (cPos.x + xadd[k] + M) % M;

                            if(nPos.y < 1 || nPos.y > N) continue;

                            if(chk[nPos.y][nPos.x] == 0 && dq[nPos.y][nPos.x] == cPos.n)
                            {
                                flag = 1;
                                chk[nPos.y][nPos.x] = 1;
                                tq.push_back({nPos.y, nPos.x, cPos.n});
                                eq.push_back({nPos.y, nPos.x, cPos.n});
                            }
                        }
                    }

                    if((int)eq.size() > 1)
                    {
                        while(!eq.empty())
                        {
                            tPos = eq.front();
                            eq.pop_front();

                            dq[tPos.y][tPos.x] = 0;
                        }
                    }
                    else
                    {
                        eq.pop_front();
                    }
                }
            }
        }

        if(flag == 0)
        {
            float tsum = 0, tidx = 0;;
            for(int i=1; i<=N; i++)
            {
                for(int j=0; j<M; j++)
                {
                    if(dq[i][j] != 0)
                    {
                        tsum += (float)dq[i][j];
                        tidx++;
                    }
                }
            }

            tsum /= (float)tidx;
            //cout<<"tsum "<<tsum<<"\n";
            for(int i=1; i<=N; i++)
            {
                for(int j=0; j<M; j++)
                {
                    if((float)dq[i][j] > tsum) dq[i][j]--;
                    else if(dq[i][j] > 0 && (float)dq[i][j] < tsum) dq[i][j]++;
                }
            }
        }
/*
        cout<<N<<' '<<M<<"\n";
        for(int i=1; i<=N; i++)
        {
            for(int j=0; j<M; j++)
            {
                cout<<dq[i][j]<<' ';
                //ret += dq[i][j];
            }
            cout<<"\n";
        }      
        cout<<"\n"; 
*/
    }

    int ret = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<M; j++)
        {
            //cout<<dq[i][j]<<' ';
            ret += dq[i][j];
        }
        //cout<<"\n";
    }

    cout<<ret<<"\n";
    return 0;
}