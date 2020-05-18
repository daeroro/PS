#include <iostream>

using namespace std;

int T;
int D, W, K, tres = D + 1;
bool map[13][20], tmap[13][20];
int chk[13];

bool _isTestPass()
{
    /*
    cout<<"test\n";
    for(int i=0; i<D; i++)
    {
        for(int j=0; j<W; j++)
        {
            cout<<tmap[i][j]<<' ';
        }
        cout<<"\n";
    }
    */

    for(int i=0; i<W; i++)
    {
        bool flag = 0;
        int cnum = 1;
        int cc = tmap[0][i];
        for(int j=1; j<D; j++)
        {
            if(cc == tmap[j][i])
            {
                cnum++;
            }
            else
            {
                cnum = 1;
                cc = tmap[j][i];   
            }

            if(cnum >= K)
            {
                flag = 1;
                //cout<<cnum<<' ';
            }
        }

        if(flag == 0) return 0; 
    }

    return 1;
}

void _select(int st, int cidx, int ma)
{
    if(st == ma)
    {
        for(int i=0; i<D; i++)
        {
            for(int j=0; j<W; j++)
            {
                tmap[i][j] = map[i][j];
            }
        }

        for(int i=0; i<D; i++)
        {
            if(chk[i] == 1)
            {
                for(int j=0; j<W; j++)
                {
                    tmap[i][j] = 0;
                }
            }
            else if(chk[i] == 2)
            {
                for(int j=0; j<W; j++)
                {
                    tmap[i][j] = 1;
                }
            }
        }

        if(_isTestPass())
        {
            if(tres > st) tres = st;
        }

        return;
    }

    for(int i=cidx+1; i<D; i++)
    {
        if(chk[i] == 0)
        {
            // 1 : 'A', 2 : 'B'
            for(int j=1; j<3; j++)
            {
                chk[i] = j;
                _select(st+1, i, ma);

                if(tres <= D) return;
                chk[i] = 0;
            }
        }
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
        for(int i=0; i<13; i++)
        {
            chk[i] = 0;
            for(int j=0; j<20; j++)
            {
                map[i][j] = 0;
                tmap[i][j] = 0;
            }
        }

        cin>>D>>W>>K;
        for(int i=0; i<D; i++)
        {
            for(int j=0; j<W; j++)
            {
                cin>>map[i][j];
                tmap[i][j] = map[i][j];
            }
        }
        tres = D+1;
        if(_isTestPass())
        {
            cout<<'#'<<st+1<<" 0\n";
            continue;
        }

        for(int i=1; i<=K; i++)
        {
            //cout<<"tres "<<tres<<"\n";
            _select(0, -1, i);
            //cout<<"trest "<<tres<<"\n";
            if(tres <= D) break;
        }

        cout<<'#'<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}