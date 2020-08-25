#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        q.push(i);
    }

    int tmp;
    cout<<'<';
    while(!q.empty())
    {
        if((int)q.size() == 1)
        {
            cout<<q.front()<<">\n";
            break;
        }
                
        for(int i=0; i<K; i++)
        {
            tmp = q.front();
            q.pop();

            if(i == K-1)
            {
                cout<<tmp<<", ";
            }
            else
            {
                q.push(tmp);   
            }
        }


    }

    return 0;
}