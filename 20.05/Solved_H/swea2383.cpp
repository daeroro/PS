#include <iostream>
#include <deque>
#include <queue>

using namespace std;

struct pos{
    int y, x, n, t;
};

int T, N, tres = 10000000;
int step[2];
int map[10][10];
bool chk[10];

deque<struct pos> mq, sq, tq[2];
priority_queue<struct pos> pq[2];

bool operator<(struct pos a, struct pos b)
{
    if(a.n>=b.n) return 1;
    else return 0;
}

void _dfs(int st, int cur, int ma)
{
    if(st == ma)
    {
        /*
        for(int i=0; i<ma; i++)
        {
            cout<<chk[i]<<' ';
        }
        cout<<"\n";
        */
        tq[0].clear();
        tq[1].clear();
        while(!pq[0].empty()) pq[0].pop();
        while(!pq[1].empty()) pq[1].pop();
        struct pos cPos;
        int tmp;
        for(int i=0; i<ma; i++)
        {
            cPos = mq[i];

            if(chk[i] == 0)
            {
                tmp = abs(cPos.y-sq[0].y) + abs(cPos.x - sq[0].x);
                pq[0].push({cPos.y, cPos.x, tmp, -1});
            }
            else
            {
                tmp = abs(cPos.y-sq[1].y) + abs(cPos.x - sq[1].x);
                pq[1].push({cPos.y, cPos.x, tmp, -1});
            }
        }
        /*cout<<"pq\n";
        while(!pq[0].empty())
        {
            cPos = pq[0].top();
            pq[0].pop();

            cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.n<<' '<<cPos.t<<"\n";
        }
        
        cout<<"pq\n";
        cout<<pq[0].size()<<' '<<pq[1].size()<<"\n";
        */
        //cout<<"=====================\n";
        int ttime = 0;
        int tnum = 0;
        while(1)
        {

            ttime++;         

            for(int i=0; i<(int)tq[0].size(); i++)
            {
                cPos = tq[0][i];
                if(cPos.n == cPos.t)
                {
                    tq[0].pop_front();
                    tnum++;
                    //cout<<ttime<<" cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.n<<' '<<cPos.t<<"\n";
                    i--;
                }
                else
                {
                    tq[0][i].t++;
                }
            }

            for(int i=0; i<(int)tq[1].size(); i++)
            {
                cPos = tq[1][i];
                if(cPos.n == cPos.t)
                {
                    tq[1].pop_front();
                    tnum++;
                    //cout<<ttime<<" cPos.. "<<cPos.y<<' '<<cPos.x<<' '<<cPos.n<<' '<<cPos.t<<"\n";
                    i--;
                }
                else
                {
                    tq[1][i].t++;
                }                
            }
            while(!pq[0].empty())
            {
                cPos = pq[0].top();
                if(ttime == cPos.n && (int)tq[0].size()<3)
                {
                    pq[0].pop();
                    tq[0].push_back({cPos.y, cPos.x, step[0], 0});
                }
                else if(ttime > cPos.n && (int)tq[0].size()<3)
                {
                    pq[0].pop();
                    tq[0].push_back({cPos.y, cPos.x, step[0],1});
                }                
                else break;
            }
            
            while(!pq[1].empty())
            {
                cPos = pq[1].top();
                if(ttime == cPos.n && (int)tq[1].size()<3)
                {
                    pq[1].pop();
                    tq[1].push_back({cPos.y, cPos.x, step[1], 0});
                }
                else if(ttime > cPos.n && (int)tq[1].size()<3)
                {
                    pq[1].pop();
                    tq[1].push_back({cPos.y, cPos.x, step[1], 1});
                }                
                else break;
            }

            //cout<<ttime<<" pq "<<pq[0].size()<<' '<<pq[1].size()<<" tq "<<tq[0].size()<<' '<<tq[1].size()<<"\n";

            if(tnum == ma) break;            
            //if(ttime == 10) break;
        }
/*        
        cout<<ttime<<"\n";
        for(int i=0; i<ma; i++)
        {
            cout<<chk[i]<<' ';
        }
        cout<<"\n";        
*/
        if(tres > ttime)
        {

            tres = ttime;
        }
        
        return;
    }

    for(int i=cur+1; i<ma; i++)
    {
        for(int j=1; j>=0; j--)
        {
            int tmp = chk[i];
            chk[i] = j;
            _dfs(st+1, i, ma);
            chk[i] = tmp;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st = 0; st<T; st++)
    {
        cin>>N;
        tres = 10000000;
        mq.clear();
        sq.clear();
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>map[i][j];
                if(map[i][j] == 0) continue;
                else if(map[i][j] == 1)
                {
                    mq.push_back({i, j, 0, 0});
                }
                else
                {
                    sq.push_back({i, j, map[i][j], 0});
                }
            }
        }
        step[0] = map[sq[0].y][sq[0].x];
        step[1] = map[sq[1].y][sq[1].x];

        _dfs(0, -1, (int)mq.size());
        cout<<'#'<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}
