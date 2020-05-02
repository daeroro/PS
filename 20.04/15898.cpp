#include <iostream>
#include <deque>

using namespace std;

int N, ttret;
// 'W' = 0, 'R' = 1, 'G' = 2, 'B' = 3, 'Y' = 4
int cmap[5][5], cing[10][4][4], tcmap[5][5];
int imap[5][5], iing[10][4][4], timap[5][5];
bool chk[10];

deque<int> dq;

void dfs2(int st)
{
    if(st == 3)
    {
        int pR = 0, pG = 0, pB = 0, pY = 0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                //cout<<imap[i][j]<<' ';
                switch(cmap[i][j])
                {
                    case 1:
                        pR += imap[i][j];
                    break;

                    case 2:
                        pG += imap[i][j];
                    break;

                    case 3:
                        pB += imap[i][j];
                    break;

                    case 4:
                        pY += imap[i][j];
                    break;
                }
            }
            //cout<<"\n";
        }
        //cout<<pR<<' '<<pB<<' '<<pG<<' '<<pY<<"\n";
        int ttmp = 7*pR + 5*pB + 3*pG + 2*pY;
        //cout<<tmp<<"\n";
/*
        if(dq[0] == 1 && dq[1] == 2 && dq[2] == 0)
        {
        cout<<"cmap\n";            
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<5; j++)
                {
                    cout<<cmap[i][j]<<' ';
                }
                cout<<"\n";
            }
            cout<<"imap\n";
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<5; j++)
                {
                    cout<<imap[i][j]<<' ';
                }
                cout<<"\n";
            }            
            cout<<"t "<<tmp<<"\n";   
        }
        */
        cout<<"ttret "<<ttret<<"\n";
        cout<<ttmp<<"\n";
        if(ttmp > ttret)
        {
            ttret = ttmp;
            //cout<<"change ret "<<ret<<"\n";
            
        }
        return;
    }

    for(int j=0; j<5; j++)
    {
        for(int k=0; k<5; k++)
        {
            tcmap[j][k] = cmap[j][k];
            timap[j][k] = imap[j][k];
        }
    }

    int sy = 0, sx = 0;
    for(int i=0; i<4; i++)
    {
        switch(i)
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

        for(int j=0; j<4; j++)
        {
            switch(j)
            {
                case 0:
                    for(int k=0; k<4; k++)
                    {
                        for(int l=0; l<4; l++)
                        {
                            if(cing[dq[st]][k][l] != 0)
                                cmap[sy+k][sx + l] = cing[dq[st]][k][l];
                            imap[sy+k][sx+l] += iing[dq[st]][k][l];
                            if(imap[sy+k][sx+l] < 0 ) imap[sy+k][sx+l] = 0;
                            else if(imap[sy+k][sx+l] > 9) imap[sy+k][sx+l] = 9;
                        }
                    }
                break;

                case 1:
                    for(int k=0; k<4; k++)
                    {
                        for(int l=0; l<4; l++)
                        {
                            if(cing[dq[st]][k][l] != 0)
                                cmap[sy+l][sx + 4-k] = cing[dq[st]][k][l];
                            imap[sy+l][sx+4-k] += iing[dq[st]][k][l];
                            if(imap[sy+l][sx+4-k] < 0 ) imap[sy+l][sx+4-k] = 0;
                            else if(imap[sy+l][sx+4-k] > 9) imap[sy+l][sx+4-k] = 9;
                        }
                    }
                break;

                case 2:
                    for(int k=0; k<4; k++)
                    {
                        for(int l=0; l<4; l++)
                        {
                            if(cing[dq[st]][k][l] != 0)
                                cmap[sy+4-k][sx + 4-l] = cing[dq[st]][k][l];
                            imap[sy+4-k][sx+4-l] += iing[dq[st]][k][l];
                            if(imap[sy+4-k][sx+4-l] < 0 ) imap[sy+4-k][sx+4-l] = 0;
                            else if(imap[sy+4-k][sx+4-l] > 9) imap[sy+4-k][sx+4-l] = 9;
                        }
                    }                
                break;

                case 3:
                    for(int k=0; k<4; k++)
                    {
                        for(int l=0; l<4; l++)
                        {
                            if(cing[dq[st]][k][l] != 0)
                                cmap[sy+4-l][sx +k] = cing[dq[st]][k][l];
                            imap[sy+4-l][sx+k] += iing[dq[st]][k][l];
                            if(imap[sy+4-l][sx+k] < 0 ) imap[sy+4-l][sx+k] = 0;
                            else if(imap[sy+4-l][sx+k] > 9) imap[sy+4-l][sx+k] = 9;
                        }
                    }                  
                break;
            }

            dfs2(st+1);

            for(int k=0; k<5; k++)
            {
                for(int l=0; l<5; l++)
                {
                    cmap[k][l] = tcmap[k][l];
                    imap[k][l] = timap[k][l];
                }
            }
        }
    }
}

void dfs(int st, int cidx)
{
    if(st == 3)
    {
        /*
        for(int i=0; i<(int)dq.size(); i++)
        {
            cout<<dq[i]<<' ';
        }
        cout<<"\n";
        */
        dfs2(0);
        //cout<<"ret "<<ret<<"\n";
        //cout<<"tret "<<ret<<"\n";
        return;
    }

    for(int i= 0; i<N; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            dq.push_back(i);

            dfs(st+1, i);

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

    cin>>N;
    char tmp;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                cin>>iing[i][j][k];
            }
        }

        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                
                cin>>tmp;
                switch(tmp)
                {
                    // 'W' = 0, 'R' = 1, 'G' = 2, 'B' = 3, 'Y' = 4                    
                    case 'W':
                        cing[i][j][k] = 0;
                    break;

                    case 'R':
                        cing[i][j][k] = 1;
                    break;

                    case 'G':
                        cing[i][j][k] = 2;
                    break;

                    case 'B':
                        cing[i][j][k] = 3;
                    break;

                    case 'Y':
                        cing[i][j][k] = 4;
                    break;
                }
            }
        }

    }

    dfs(0, -1);

    cout<<ttret<<"\n";

    return 0;
}