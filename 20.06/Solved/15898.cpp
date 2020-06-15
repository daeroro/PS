#include <iostream>
#include <deque>

using namespace std;

int N, res;
int ing[10][4][4], eing[10][4][4];
int map[5][5], emap[5][5];

bool chk[10];

deque<int> dq, tq;

void _print()
{
    cout<<"map\n";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<map[i][j]<<' ';
        }
        cout<<"\n";
    }

    cout<<"emap\n";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<emap[i][j]<<' ';
        }
        cout<<"\n";
    }
}

void _updateMap(int ri, int oi, int ni)
{
    int sy, sx;
    switch(oi)
    {
        case 0:
            sy = 0, sx = 0;
        break;

        case 1:
            sy = 0, sx = 1;
        break;

        case 2:
            sy = 1, sx = 0;
        break;

        case 3:
            sy = 1, sx = 1;
        break;
    }

    switch(ri)
    {
        case 0:
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    map[sy+i][sx+j] += ing[ni][i][j];
                    if(map[sy+i][sx+j] < 0 ) map[sy+i][sx+j] = 0;
                    else if(map[sy+i][sx+j] > 9) map[sy+i][sx+j] = 9;
                    
                    if(eing[ni][i][j] > 0)
                    {
                        emap[sy+i][sx+j] = eing[ni][i][j];
                    }
                }
            }        
        break;

        case 1:
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    map[sy+i][sx+j] += ing[ni][j][3-i];
                    if(map[sy+i][sx+j] < 0 ) map[sy+i][sx+j] = 0;
                    else if(map[sy+i][sx+j] > 9) map[sy+i][sx+j] = 9;
                    
                    if(eing[ni][j][3-i] > 0)
                    {
                        emap[sy+i][sx+j] = eing[ni][j][3-i];
                    }
                }
            }         
        break;

        case 2:
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    map[sy+i][sx+j] += ing[ni][3-i][3-j];
                    if(map[sy+i][sx+j] < 0 ) map[sy+i][sx+j] = 0;
                    else if(map[sy+i][sx+j] > 9) map[sy+i][sx+j] = 9;
                    
                    if(eing[ni][3-i][3-j] > 0)
                    {
                        emap[sy+i][sx+j] = eing[ni][3-i][3-j];
                    }
                }
            }         
        break;

        case 3:
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    map[sy+i][sx+j] += ing[ni][3-j][i];
                    if(map[sy+i][sx+j] < 0 ) map[sy+i][sx+j] = 0;
                    else if(map[sy+i][sx+j] > 9) map[sy+i][sx+j] = 9;
                    
                    if(eing[ni][3-j][i] > 0)
                    {
                        emap[sy+i][sx+j] = eing[ni][3-j][i];
                    }
                }
            }         
        break;
    }
}

void _dfs2(int st)
{
    if(st == 3)
    {
        int tres = 0;
        int nR = 0, nB = 0, nG = 0, nY = 0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                switch(emap[i][j])
                {
                    case 1:
                        nY+=map[i][j];
                    break;

                    case 2:
                        nG+=map[i][j];
                    break;

                    case 3:
                        nB+=map[i][j];
                    break;

                    case 4:
                        nR+=map[i][j];
                    break;
                }
            }
        }
        
        tres = 7*nR + 5*nB + 3*nG + 2*nY;
        /*
        if(tres>666)
        {
        cout<<"tres "<<tres<<"\n";
        _print();
        }
        */
        if(tres > res) res = tres;
        return;
    }

    int tmap[5][5] = {0, }, temap[5][5] = {0, };
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            tmap[i][j] = map[i][j];
            temap[i][j] = emap[i][j];
        }
    }

    for(int i = 0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            _updateMap(i, j, tq[st]);
            _dfs2(st+1);

            for(int k=0; k<5; k++)
            {
                for(int l=0; l<5; l++)
                {
                    map[k][l] = tmap[k][l];
                    emap[k][l] = temap[k][l];
                }
            }            
        }
    }
}

void _dfs(int st, int cur)
{
    if(st == 3)
    {
        for(int i=0; i<3; i++)
        {
            tq.clear();
            tq.push_back(dq[i]);
            if(i==0)
            {
                for(int j=0; j<2; j++)
                {
                    if(j==0)
                    {
                        tq.push_back(dq[1]);
                        tq.push_back(dq[2]);

                        _dfs2(0);

                        tq.pop_back();
                        tq.pop_back();
                    }
                    else
                    {
                        tq.push_back(dq[2]);
                        tq.push_back(dq[1]);

                        _dfs2(0);

                        tq.pop_back();
                        tq.pop_back();
                    }
                }
            }
            else if(i==1)
            {
                for(int j=0; j<2; j++)
                {
                    if(j==0)
                    {
                        tq.push_back(dq[0]);
                        tq.push_back(dq[2]);

                        _dfs2(0);

                        tq.pop_back();
                        tq.pop_back();
                    }
                    else
                    {
                        tq.push_back(dq[2]);
                        tq.push_back(dq[0]);

                        _dfs2(0);

                        tq.pop_back();
                        tq.pop_back();
                    } 
                }
            }
            else if(i==2)
            {
                for(int j=0; j<2; j++)
                {
                    if(j==0)
                    {
                        tq.push_back(dq[0]);
                        tq.push_back(dq[1]);

                        _dfs2(0);

                        tq.pop_back();
                        tq.pop_back();
                    }
                    else
                    {
                        tq.push_back(dq[1]);
                        tq.push_back(dq[0]);

                        _dfs2(0);

                        tq.pop_back();
                        tq.pop_back();
                    }
                }
            }            
        }

        return;
    }

    for(int i = cur+1; i<N; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            dq.push_back(i);
            _dfs(st+1, i);
            dq.pop_back();

            chk[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char tmp;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                cin>>ing[i][j][k];
            }
        }
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                cin>>tmp;
                switch(tmp)
                {
                    case 'W':
                        eing[i][j][k] = 0;
                    break;

                    case 'Y':
                        eing[i][j][k] = 1;
                    break;
                    
                    case 'G':
                        eing[i][j][k] = 2;
                    break;

                    case 'B':
                        eing[i][j][k] = 3;
                    break;

                    case 'R':
                        eing[i][j][k] = 4;
                    break;
                }
            }
        }
    }

    _dfs(0, -1);
    cout<<res<<"\n";

    return 0;
}