#include <iostream>

using namespace std;

int N, res1, res2;
int map[128][128];

void _div(int sy, int sx, int ey, int ex)
{
    bool flag = 0;
    int check = map[sy][sx];

    for(int i=sy; i<ey; i++)
    {
        for(int j=sx; j<ex; j++)
        {
            if(map[i][j] != check)
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag)
    {
        _div(sy, sx, (sy+ey)/2, (sx+ex)/2);
        _div((sy+ey)/2, (sx+ex)/2, ey, ex);
        _div(sy, (sx+ex)/2, (sy+ey)/2, ex);
        _div((sy+ey)/2, sx, ey, (sx+ex)/2);
    }
    else if(check)
    {
        //cout<<sy<<' '<<sx<<' '<<ey<<' '<<ex<<' '<<"res1 "<<res1+1<<"\n";
        res1++;
    }
    else
    {
        //cout<<sy<<' '<<sx<<' '<<ey<<' '<<ex<<' '<<"res2 "<<res2+1<<"\n";        
        res2++;
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
        }
    }

    _div(0, 0, N, N);

    cout<<res2<<"\n";
    cout<<res1<<"\n";

    return 0;
}