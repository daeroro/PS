#include <iostream>
#include <cmath>

using namespace std;

int T;
int K, tnum, tdir;
int map[5][8];
int mloc[5];
int rot[5];

bool _check(int fir, int sec, int cur, int next, int dir)
{
    //rot[fir] = dir;
    if(map[fir][cur] != map[sec][next])
    {
        rot[sec] = 0-dir;
        return 1;
    }
    return 0;
}

void _rotation(int tnum, int tdir)
{
    for(int i=0; i<5; i++) rot[i] = 0;
    switch(tnum)
    {
        case 1:
            rot[1] = tdir;
            if(_check(1, 2, (mloc[1]+2)%8, (mloc[2]+6)%8, tdir))
            {
                if(_check(2, 3, (mloc[2]+2)%8, (mloc[3]+6)%8, 0-tdir))
                {
                    _check(3, 4, (mloc[3]+2)%8, (mloc[4]+6)%8, tdir);
                }
            }
        break;

        case 2:
            rot[2] = tdir;
            _check(2, 1, (mloc[2]+6)%8, (mloc[1]+2)%8, tdir);
            if(_check(2, 3, (mloc[2]+2)%8, (mloc[3]+6)%8, tdir))
            {
                _check(3, 4, (mloc[3]+2)%8, (mloc[4]+6)%8, 0-tdir);
            }
        break;

        case 3:
            rot[3] = tdir;
            _check(3, 4, (mloc[3]+2)%8, (mloc[4]+6)%8, tdir);
            if(_check(3, 2, (mloc[3]+6)%8, (mloc[2]+2)%8, tdir))
            {
                _check(2, 1, (mloc[2]+6)%8, (mloc[1]+2)%8, 0-tdir);
            }
        break;

        case 4:
            rot[4] = tdir;
            if(_check(4, 3, (mloc[4]+6)%8, (mloc[3]+2)%8, tdir))
            {
                if(_check(3, 2, (mloc[3]+6)%8, (mloc[2]+2)%8, 0-tdir))
                {
                    _check(2, 1, (mloc[2]+6)%8, (mloc[1]+2)%8, tdir);
                }
            }
        break;
    }

    for(int i=1; i<5; i++)
    {
        if(rot[i] == 1)
        {
            mloc[i] = (mloc[i] + 7) % 8;
        }
        else if(rot[i] == -1)
        {
            mloc[i] = (mloc[i] + 1) % 8;
        }
    }
    //for(int i=1; i<5; i++) cout<<mloc[i]<<' ';

    //cout<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st = 0; st<T; st++)
    {
        cin>>K;
        for(int i=1; i<5; i++)
        {
            mloc[i] = 0;
            for(int j=0; j<8; j++)
            {
                cin>>map[i][j];
            }
        }

        for(int i=0; i<K; i++)
        {
            cin>>tnum>>tdir;

            _rotation(tnum, tdir);
        }
        int tres = 0;
        for(int i=1; i<5; i++)
        {
            tres += map[i][mloc[i]] * pow(2, i-1);
            //cout<<map[i][mloc[i]] * pow(2, i-1)<<' ';
        }
        //cout<<"\n";

        cout<<'#'<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}