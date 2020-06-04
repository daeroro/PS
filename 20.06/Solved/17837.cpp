#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int y, x, d, n;
};
int N, K;
int map[13][13];
struct pos kni[11];

int yadd[5] = {0, 0, 0, -1, 1};
int xadd[5] = {0, 1, -1, 0, 0};

deque<int> kNum[13][13], tq;

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

    struct pos tPos, cPos, nPos;
    for(int i=1; i<=K; i++)
    {
        cin>>tPos.y>>tPos.x>>tPos.d;
        kni[i] = {tPos.y, tPos.x, tPos.d, 0};
        kNum[tPos.y][tPos.x].push_back(i);
    }

    //cout<<"start\n";
    int turn = 0;
    int flag = 0;

    while(1)
    {
        //cout<<"turn "<<turn<<"\n";
        turn++;
        if(turn > 1000)
        {
            cout<<"-1\n";
            return 0;
        }

        for(int i=1; i<=K; i++)
        {
repeat:
            cPos = kni[i];
            /*
            if(turn < 3)
            {
                cout<<"turn "<<turn<<"\n";
                cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.d<<' '<<cPos.n<<"\n";
            }
            */
            nPos.y = cPos.y + yadd[cPos.d];
            nPos.x = cPos.x + xadd[cPos.d];

            if(nPos.y<=0 || nPos.y > N || nPos.x <= 0 || nPos.x > N || map[nPos.y][nPos.x] == 2)
            {
                switch(cPos.d)
                {
                    case 1:
                        cPos.d = 2;
                    break;

                    case 2:
                        cPos.d = 1;
                    break;

                    case 3:
                        cPos.d = 4;
                    break;

                    case 4:
                        cPos.d = 3;
                    break;
                }

                nPos.y = cPos.y + yadd[cPos.d];
                nPos.x = cPos.x + xadd[cPos.d];

                if(map[nPos.y][nPos.x] == 2)
                {
                    kni[i].d = cPos.d;
                }
                else
                {
                    kni[i].d = cPos.d;
                    goto repeat;
                }
                
            }
            else if(map[nPos.y][nPos.x] == 0)
            {
                
                tq.clear();
                int tnum = (int)kNum[cPos.y][cPos.x].size();
                int tn;
                for(int j=kni[i].n; j<tnum; j++)
                {
                    tn = kNum[cPos.y][cPos.x].back();
                    kNum[cPos.y][cPos.x].pop_back();

                    tq.push_back(tn);
                }

                while(!tq.empty())
                {
                    tn = tq.back();
                    tq.pop_back();
                    kNum[nPos.y][nPos.x].push_back(tn);

                    kni[tn].y = nPos.y;
                    kni[tn].x = nPos.x;
                    kni[tn].n = (int)kNum[nPos.y][nPos.x].size() - 1;
                }
               
            }
            else if(map[nPos.y][nPos.x] == 1)
            {
                
                tq.clear();
                int tnum = (int)kNum[cPos.y][cPos.x].size();
                int tn;                
                for(int j=kni[i].n; j<tnum; j++)
                {
                    tn = kNum[cPos.y][cPos.x].back();
                    kNum[cPos.y][cPos.x].pop_back();

                    tq.push_back(tn);
                }

                while(!tq.empty())
                {
                    tn = tq.front();
                    tq.pop_front();
                    kNum[nPos.y][nPos.x].push_back(tn);

                    kni[tn].y = nPos.y;
                    kni[tn].x = nPos.x;
                    kni[tn].n = (int)kNum[nPos.y][nPos.x].size() - 1;
                }
                
            }

            //if(turn < 3)
            //cout<<"cpos "<<i<<" | "<<kni[i].y<<' '<<kni[i].x<<' '<<kni[i].d<<' '<<kni[i].n<<"\n";
            //cout<<kNum[nPos.y][nPos.x].size()<<"\n";
            if((int)kNum[nPos.y][nPos.x].size()>=4)
            {
                flag = 1;
                break;
            }
        }
/*
        if(turn < 3)
        {
            for(int i=1; i<=K; i++)
            cout<<"total "<<i<<" | "<<kni[i].y<<' '<<kni[i].x<<' '<<kni[i].d<<' '<<kni[i].n<<"\n";
        }
*/
        if(flag == 1) break;
        
    }

    cout<<turn<<"\n";

    return 0;
}