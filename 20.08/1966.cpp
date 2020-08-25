#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int n;
    bool f;
};

int T, N, M;
int res;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    int tmp;
    for(int i=0; i<T; i++)
    {
        queue<struct pos> q;
        priority_queue<int> pq;
        res = 0;
        cin>>N>>M;
        for(int j=0; j<N; j++)
        {
            cin>>tmp;
            if(j == M)
            {
                q.push({tmp, 1});
                pq.push(tmp);
            }
            else
            {
                q.push({tmp, 0});
                pq.push(tmp);   
            }
        }

        struct pos tmp;
        while(1)
        {
            tmp = q.front();
            //cout<<tmp.n<<' '<<pq.top()<<"\n";
            if(tmp.n == pq.top())
            {
                if(tmp.f == 0)
                {
                    q.pop();
                    pq.pop();
                    res++;
                }
                else
                {
                    res++;
                    break;
                }
            }
            else
            {
                q.pop();
                q.push(tmp);   
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}