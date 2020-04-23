#include <iostream>
#include <deque>

using namespace std;

struct pos{
    bool cur[3], chk[10];
    int n[3], st[3];
};

int N, K, flag;
int A[10][10];
int hand[3][20];

deque<struct pos> dq;

void _bfs()
{
    struct pos cPos, nPos;
    cPos.cur[0] = 1;
    cPos.cur[1] = 1;
    cPos.cur[2] = 0;
    for(int i=0; i<10; i++)
        cPos.chk[i] = 0;
    cPos.n[0] = 0;
    cPos.n[1] = 0;
    cPos.n[2] = 0;
    cPos.st[0] = 0;
    cPos.st[1] = 0;
    cPos.st[2] = 0;

    dq.push_back(cPos);

    while(!dq.empty())
    {
        cPos = dq.front();
        dq.pop_front();
/*
        //cout<<"st "<<cPos.st<<": ";
        for(int i=0; i<3; i++)
        {
            cout<<cPos.n[i]<<' ';
        }
        cout<<" : ";
        for(int i=0; i<3; i++)
        {
            cout<<cPos.cur[i]<<' ';
        }
        cout<<" : ";
        for(int i=1; i<=N; i++)
        {
            cout<<cPos.chk[i]<<' ';
        }
        cout<<"\n";
*/
        int flag2 = 0;
        for(int i=0; i<3; i++)
        {
            if(cPos.n[i] == K)
            {
                if(i==0)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            break;
        }
        if(flag2 == 1)
        {
            continue;
        }

        if(cPos.cur[0] == 1)
        {
            for(int i=1; i<=N; i++)
            {
                if(cPos.chk[i] == 0)
                {
                    if(cPos.cur[1] == 1)
                    {
                        int tmp = A[i][hand[1][cPos.st[1]]];
                        //cout<<"cur "<<i<<' '<<hand[1][cPos.st]<<' '<<tmp<<"\n";
                        if(tmp == 2)
                        {
                            nPos = cPos;
                            nPos.chk[i] = 1;
                            nPos.n[0]++;
                            nPos.st[0]++;
                            nPos.st[1]++;
                            nPos.cur[1] = 0;
                            nPos.cur[2] = 1;
                            nPos.cur[0] = 1;
                            dq.push_back(nPos);
                        }
                        else
                        {
                            nPos = cPos;
                            nPos.chk[i] = 1;
                            nPos.n[1]++;
                            nPos.st[0]++;
                            nPos.st[1]++;
                            nPos.cur[0] = 0;
                            nPos.cur[2] = 1;
                            nPos.cur[1] = 1;
                            dq.push_back(nPos);   
                        }
                    }
                    else
                    {
                        int tmp = A[i][hand[2][cPos.st[2]]];
                        //cout<<"cur "<<i<<' '<<hand[2][cPos.st]<<' '<<tmp<<"\n";
                        if(tmp == 2)
                        {
                            nPos = cPos;
                            nPos.chk[i] = 1;
                            nPos.n[0]++;
                            nPos.st[0]++;
                            nPos.st[2]++;
                            nPos.cur[2] = 0;
                            nPos.cur[1] = 1;
                            nPos.cur[0] = 1;
                            dq.push_back(nPos);
                        }
                        else
                        {
                            nPos = cPos;
                            nPos.chk[i] = 1;
                            nPos.n[2]++;
                            nPos.st[0]++;
                            nPos.st[2]++;
                            nPos.cur[0] = 0;
                            nPos.cur[1] = 1;
                            nPos.cur[2] = 1;
                            dq.push_back(nPos);   
                        }
                    }
                }
            }            
        }
        else
        {
            int tmp = A[hand[1][cPos.st[1]]][hand[2][cPos.st[2]]];
            //cout<<"cur "<<hand[1][cPos.st]<<' '<<hand[2][cPos.st]<<' '<<tmp<<"\n";
            if(tmp == 2)
            {
                nPos = cPos;
                nPos.n[1]++;
                nPos.st[1]++;
                nPos.st[2]++;
                nPos.cur[2] = 0;
                nPos.cur[0] = 1;
                nPos.cur[1] = 1;
                dq.push_back(nPos);
            }   
            else
            {
                nPos = cPos;
                nPos.n[2]++;
                nPos.st[1]++;
                nPos.st[2]++;
                nPos.cur[1] = 0;
                nPos.cur[0] = 1;
                nPos.cur[2] = 1;
                dq.push_back(nPos);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=1; i<=N;i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>A[i][j];
        }
    }

    for(int i=1; i<3; i++)
    {
        for(int j=0; j<20; j++)
        {
            cin>>hand[i][j];
        }
    }

    _bfs();
    cout<<flag<<"\n";

    return 0;
}