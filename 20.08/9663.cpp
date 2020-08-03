#include <iostream>

using namespace std;

int N, res;

bool chk[4][30];

void _go(int st, int cy, int cx)
{
    //cout<<"st "<<st<<' '<<cy<<' '<<cx<<"\n";
    if(st == N-1)
    {
        res++;
        return;
    }

    int ty = cy + 1;

    for(int tx= 0; tx <N; tx++)
    {
        if(chk[1][tx]) continue;
        if(chk[2][ty+tx]) continue;
        if(chk[3][N-ty+tx]) continue;

        bool tmp[3] = {chk[1][tx], chk[2][ty+tx], chk[3][N-ty+tx]};

        chk[1][tx] = 1;
        chk[2][ty+tx] = 1;
        chk[3][N-ty+tx] = 1;

        _go(st+1, ty, tx);

        chk[1][tx] = tmp[0];
        chk[2][ty+tx] = tmp[1];
        chk[3][N-ty+tx] = tmp[2];
    }
    
}

int main(void)
{
    cin>>N;

    for(int i=0; i<N; i++)
    {
        chk[0][0] = 1;
        chk[1][i] = 1;
        chk[2][i] = 1;
        chk[3][N+i] = 1;

        _go(0, 0, i);

        chk[0][0] = 0;
        chk[1][i] = 0;
        chk[2][i] = 0;
        chk[3][N+i] = 0;

        //cout<<"out\n";
    }

    cout<<res<<"\n";

    return 0;
}