#include <iostream>
#include <cmath>

using namespace std;

char map[3000][3000];

void init(int N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            map[i][j] = ' ';
        }
    }
}

void solve(int N, int y, int x)
{
    if(N==1)
    {
        map[y][x] = '*';
        return;
    }

    int cN = N/3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==1 && j==1)
            {
                continue;
            }
            else
            {
                solve(cN, y + (i*cN), x + (j*cN));
            }
        }
    }
}

int main(void)
{
    int N;
    cin>>N;
    
    init(N);
    solve(N, 0, 0);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }

    return 0;
}