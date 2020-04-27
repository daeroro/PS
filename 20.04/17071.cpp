#include <iostream>
#include <deque>

using namespace std;

struct pos{
    int cur, t;
};

int N, K, ret = 500001;
int sTime[500001];
deque<struct pos> dq;

int add[3] = {-1, 1, 0};

void _bfs()
{
    struct pos cPos, nPos;
    while(!dq.empty())
    {
        cPos = dq.front();
        dq.pop_front();
        //cout<<cPos.cur<<' '<<cPos.t<<"\n";

        for(int i=0; i<3; i++)
        {
            nPos.cur = cPos.cur + add[i];
            if(i == 2)
                nPos.cur = 2*cPos.cur;

            if(nPos.cur < 0 || nPos.cur > 500000 || sTime[nPos.cur] != -1)
                continue;
            
            sTime[nPos.cur] = cPos.t + 1;
            //cout<<"push "<<nPos.cur<<' '<<cPos.t+1<<"\n";
            dq.push_back({nPos.cur, cPos.t + 1});
        }
    }
}

void _check()
{
    int cur = K;
    int time = 0;

    while(cur <= 500000)
    {
        //cout<<cur<<' '<<time<<' '<<sTime[cur]<<"\n";
        if(abs(sTime[cur]-time)%2 == 0)
        {
            int tmp;
            if(time <= sTime[cur])
            {
                tmp = sTime[cur] - time;
                tmp *= 2;
            }
            else tmp = 0;
            if(ret > time + tmp) ret = time + tmp;
        }
        time++;
        cur += time;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=0; i<=500000; i++)
        sTime[i] = -1;
    
    sTime[N] = 0;
    dq.push_back({N, 0});

    _bfs();

    _check();

    if(ret == 500001) cout<<"-1\n";
    else cout<<ret<<"\n";

    return 0;
}