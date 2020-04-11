#include <iostream>

using namespace std;

int oNum, mNum[6], ret = 25;
bool map[10][10];
int chk[10][10];

bool _check(int cy, int cx, int knum)
{
    if(cy+knum > 10 || cx+knum > 10) return 0;
    for(int i=cy; i<cy+knum; i++)
    {
        for(int j=cx; j<cx+knum; j++)
        {
            if(map[i][j] == 0 || chk[i][j] != 0) return 0;
        }
    }

    return 1;
}

void _dfs(int st, int cy, int cx, int znum)
{
    if(st > ret) return;
    if(znum == oNum)
    {
        cout<<"ret "<<st<<"\n";
        for(int i=1; i<=5; i++) cout<<mNum[i]<<' ';
        cout<<"\n";
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                cout<<chk[i][j]<<' ';
            }
            cout<<"\n";
        }
        if(st < ret) ret = st;

        return;
    }

    for(int i = cy; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(map[i][j] == 1 && chk[i][j] == 0)
            {
                for(int k=5; k>0; k--)
                {
                    if(mNum[k] < 5)
                    {
                        if(_check(i, j, k))
                        {
                            cout<<"st "<<st<<' '<<"check "<<i<<' '<<j<<' '<<k<<' '<<mNum[k]<<' '<<znum+k*k<<"\n";
                            mNum[k]++;

                            for(int ti = i; ti<i+k; ti++)
                            {
                                for(int tj = j; tj<j+k; tj++)
                                {
                                    chk[ti][tj] = k;
                                }
                            }

                            _dfs(st+1, i, j, znum + k*k);

                            for(int ti = i; ti<i+k; ti++)
                            {
                                for(int tj = j; tj<j+k; tj++)
                                {
                                    chk[ti][tj] = 0;
                                }
                            }
                            mNum[k]--;                            
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 1)
            {
                oNum++;
            }
        }
    }

    _dfs(0, 0, 0, 0);

    if(ret == 25) cout<<"-1\n";
    else cout<<ret<<"\n";

    return 0;
}