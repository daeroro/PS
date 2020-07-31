#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > v;

int main(void)
{
    cin>>N;
    int tw, th;
    for(int i=0; i<N; i++)
    {
        cin>>tw>>th;
        v.push_back(make_pair(tw, th));
    }

    for(int i=0; i<N; i++)
    {
        int cw = v[i].first, ch = v[i].second;
        int tnum = 0;
        for(int j=0; j<N; j++)
        {
            if(cw < v[j].first && ch < v[j].second) tnum++;
        }

        cout<<tnum+1<<' ';
    }
    cout<<"\n";

    return 0;
}