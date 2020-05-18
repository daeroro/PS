#include <iostream>
#include <deque>

using namespace std;

struct pos {
    int y, x, n, d;
};

int N, K;
int map[13][13];
struct pos horse[11];

deque<int> qmap[13][13];

int yadd[5] = {0, 0, 0, -1, 1};
int xadd[5] = {0, 1, -1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }

    int ty, tx, td;
    for(int i=1; i<=K; i++)
    {
        cin>>ty>>tx>>td;
        horse[i] = {ty, tx, 0, td};
        qmap[ty][tx].push_back(i);
    }

    int ret = 0;
    struct pos nPos, tPos;
/*    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<qmap[i][j].size()<<' ';
        }
        cout<<"\n";
    }
    cout<<"\n";
*/    

    while(1)
    {
        ret++;
        int flag = 0;
        for(int i=1; i<=K; i++)
        {
repeat: 
            nPos.y = horse[i].y + yadd[horse[i].d];
            nPos.x = horse[i].x + xadd[horse[i].d];

            // 파란, 
            if(nPos.y <= 0 || nPos.y > N || nPos.x <= 0 || nPos.x > N || map[nPos.y][nPos.x] == 2)
            {
                switch(horse[i].d)
                {
                    case 1:
                        horse[i].d = 2;
                    break;

                    case 2:
                        horse[i].d = 1;
                    break;

                    case 3:
                        horse[i].d = 4;
                    break;

                    case 4:
                        horse[i].d = 3;
                    break;
                }

                nPos.y = horse[i].y + yadd[horse[i].d];
                nPos.x = horse[i].x + xadd[horse[i].d];

                if(nPos.y<= 0 || nPos.y > N || nPos.x <= 0 || nPos.x > N || map[nPos.y][nPos.x] == 2) continue;
                else goto repeat;

            }
            else if(map[nPos.y][nPos.x] == 0)
            {
                deque<int> tq;
                int tidx;
                int tnum = (int)qmap[horse[i].y][horse[i].x].size() - horse[i].n;
                for(int j=0; j<tnum; j++)
                {
                    tidx = qmap[horse[i].y][horse[i].x].back();
                    qmap[horse[i].y][horse[i].x].pop_back();

                    tq.push_front(tidx);
                }

                int cIdx = (int)qmap[nPos.y][nPos.x].size();
                for(int j=0; j<tnum; j++)
                {
                    tidx = tq.front();
                    tq.pop_front();

                    qmap[nPos.y][nPos.x].push_back(tidx);
                    horse[tidx] = {nPos.y, nPos.x, cIdx + j, horse[tidx].d};
                }

                //cout<<"t cnt "<<qmap[nPos.y][nPos.x].size()<<"\n";
            }
            else
            {
                int tidx;
                int tnum = (int)qmap[horse[i].y][horse[i].x].size() - horse[i].n;
                int cIdx = (int)qmap[nPos.y][nPos.x].size();
                for(int j=0; j<tnum; j++)
                {
                    tidx = qmap[horse[i].y][horse[i].x].back();
                    qmap[horse[i].y][horse[i].x].pop_back();

                    qmap[nPos.y][nPos.x].push_back(tidx);
                    horse[tidx] = {nPos.y, nPos.x, cIdx + j, horse[tidx].d};
                }
            }
            if((int)qmap[nPos.y][nPos.x].size() >= 4)
            {
                flag = 1;
                break;                
            }
        }
        if(flag == 1) break;
/*
    if(ret<8)
    {
        cout<<"cnt "<<ret<<"\n";
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                cout<<qmap[i][j].size()<<' ';
            }
            cout<<"\n";
        }
        cout<<"\n";

        for(int i=1; i<=K; i++)
        {
            cout<<"horse num"<<i<<' '<<horse[i].y<<' '<<horse[i].x<<' '<<horse[i].n<<' '<<horse[i].d<<"\n";
        }
    }    
*/    
        if(ret > 1000)
        {
            ret = -1;
            break;
        }
    }

    cout<<ret<<"\n";

    return 0;
}