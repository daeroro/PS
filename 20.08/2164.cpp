#include <iostream>
#include <queue>

using namespace std;

int N, tmp;

deque<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    if(N == 1)
    {
        cout<<"1\n";
        return 0;
    }

    for(int i=1; i<=N; i++)
    {
        q.push_back(i);
    }

    while(1)
    {
        q.pop_front();
        if((int)q.size() == 1) break;
        q.push_back(q.front());
        q.pop_front();
        if((int)q.size() == 1) break;
    }

    cout<<q[0]<<"\n";

    return 0;
}