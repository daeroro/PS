#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, tsum, tmi = 4000, tma = -4000;

vector<int> v;
map<int, int> m;
map<int, int>::iterator it;
priority_queue<pair<int, int> > pq;

bool operator<(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
    {
        if(a.first>b.first) return true;
        else return false;
    }
    else if(a.second < b.second) return true;
    else return false;
}

int main(void)
{
    cin>>N;
    int tn;
    for(int i=0; i<N; i++)
    {  
        cin>>tn;
        v.push_back(tn);
        tsum += tn;
        m[tn]++;

        if(tn < tmi) tmi = tn;
        if(tn > tma) tma = tn;
    }

    sort(v.begin(), v.end());

    float mean;
    mean = (float)tsum / (float)N;

    for(it = m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<' '<<it->second<<"\n";
        //pq.push(make_pair(it->first, it->second));
    }

/*
    int tf = pq.top().first;
    int ts = pq.top().second;
    pq.pop();
    int tff = pq.top().first;
    int tss = pq.top().second;

    cout<<tf<<' '<<ts<<"   "<<tff<<' '<<tss<<"\n";
*/
    cout<<round(mean)<<"\n";
    cout<<v[N/2]<<"\n";

    if(ts == tss) cout<<tff<<"\n";
    else cout<<tf<<"\n";

    cout<<tma-tmi<<"\n";

    return 0;
}