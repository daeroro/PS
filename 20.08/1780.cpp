#include <iostream>

using namespace std;

#define MAX_NUM 3*3*3*3*3*3*3

int map[MAX_NUM][MAX_NUM];
int n1, n2, n3;
int N;

void _check(int a, int b, int c, int d, int n)
{
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<"\n";
    int tmp = map[a][c];
    bool flag = 0;

    for(int i=a; i<b; i++)
    {
        for(int j=c; j<d; j++)
        {
            if(map[i][j] != tmp)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1) break;
    }

    if(flag == 1)
    {
        _check(a, a+n/3, c, c+ n/3, n/3);
        _check(a, a+n/3, c+n/3, c+2*n/3, n/3);
        _check(a, a+n/3, c+2*n/3, c+n, n/3);

        _check(a+n/3, a+2*n/3, c, c+n/3, n/3);
        _check(a+n/3, a+2*n/3, c+n/3, c+2*n/3, n/3);
        _check(a+n/3, a+2*n/3, c+2*n/3, c+n, n/3);

        _check(a+2*n/3, a+n, c, c+n/3, n/3);
        _check(a+2*n/3, a+n, c+n/3, c+2*n/3, n/3);
        _check(a+2*n/3, a+n, c+2*n/3, c+n, n/3);
    }
    else
    {
        switch(tmp)
        {
            case -1: n1++;
            break;

            case 0 : n2++;
            break;

            case 1: n3++;
            break;
        }
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

    _check(0, N, 0, N, N);

    cout<<n1<<"\n"<<n2<<"\n"<<n3<<"\n";

    return 0;
}