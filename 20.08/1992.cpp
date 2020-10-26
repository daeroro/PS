#include <iostream>

using namespace std;

int N;
char map[65][65];

void _check(int sy, int ey, int sx, int ex)
{
    char cur = map[sy][sx];
    bool flag = 0;

    for(int i=sy; i<ey; i++)
    {
        for(int j=sx; j<ex; j++)
        {
            if(cur != map[i][j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1) break;
    }

    if(flag)
    {
        cout<<'(';
        _check(sy, (sy+ey)/2, sx, (sx+ex)/2);
        _check(sy, (sy+ey)/2, (sx+ex)/2, ex);
        _check((sy+ey)/2, ey, sx, (sx+ex)/2);
        _check((sy+ey)/2, ey, (sx+ex)/2, ex);
        cout<<')';
    }
    else
    {
        cout<<cur;
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
        cin>>map[i];
    }
#if 0
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
#endif
    _check(0, N, 0, N);

    return 0;
}