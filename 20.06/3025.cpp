#include <iostream>

using namespace std;

int R, C, N;
char map[30001][31];
int cx, cy;
int cmax[31];

void _print()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cin>>map[i][j];
        }
    }

    for(int j=1; j<=C; j++)
    {
        for(int i=1; i<=R; i++)
        {
            if(map[i][j] == 'X')
            {
                cmax[j] = i-1;
                break;
            }

            if(cmax[j]==0) cmax[j] = R;
        }
    }
/*
    for(int i=1; i<=C; i++)
    {
        cout<<cmax[i]<<' ';
    }
  
    cout<<"\n";
*/
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>cx;
        int tmp = cx;
        cy = cmax[cx];
        while(1)
        {
            if(tmp!=cx)
            {
                cy = cmax[cx];
                tmp = cx;
            }
            /*
            cout<<"cur "<<i<<' '<<cy<<' '<<cx<<"\n";
            for(int j=1; j<=C; j++)
            {
                cout<<cmax[j]<<' ';
            }
            cout<<"\n";
            */
            if(map[cy+1][cx] == 'X' || cy == R)
            {
                map[cy][cx] = 'O';
                if(cy-1 < cmax[cx])  cmax[cx] = cy-1;
                break;
            }
            else if(map[cy+1][cx] == 'O')
            {
                if(cx-1>0 && map[cy][cx-1] == '.' && map[cy+1][cx-1] == '.')
                {
                    //cout<<"1\n";
                    cx -= 1;
                    cy += 1;

                    if(cy == R)
                    {
                        map[cy][cx] = 'O';
                        break;
                    }
                }
                else if(cx+1<=C && map[cy][cx+1] == '.' && map[cy+1][cx+1] == '.')
                {
                    //cout<<"2\n";
                    cx += 1;
                    cy += 1;

                    if(cy == R)
                    {
                        map[cy][cx] = 'O';
                        break;
                    }
                }
                else
                {
                    //cout<<"3\n";
                    map[cy][cx] = 'O';
                    if(cy-1<cmax[cx]) cmax[cx] = cy-1;
                    break;
                }
                
            }
        }

        //cout<<"cur "<<i<<"\n";
        //_print();
    }

    _print();

    return 0;
}