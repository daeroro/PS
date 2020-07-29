#include <iostream>
#include <deque>

using namespace std;

int N, rNum;
deque<pair<int, int> > dq;

void _move(int from, int to, int mid, int num)
{
    if(num == 1)
    {
        rNum++;
        dq.push_back(make_pair(from, to));
        return;
    }

    _move(from, mid, to, num-1);
    dq.push_back(make_pair(from, to));
    rNum++;
    _move(mid, to, from, num-1);
}

int main(void)
{
    cin>>N;

    _move(1, 3, 2, N);

    cout<<rNum<<"\n";
    int tnum = (int)dq.size();
    for(int i=0; i<tnum; i++)
    {
        cout<<dq[i].first<<' '<<dq[i].second<<"\n";
    }

    return 0;
}