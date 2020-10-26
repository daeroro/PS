#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int K, L, res;
vector<int> v, d;
map<int, int> m;
map<int, int>::iterator it;
set<int> s;
set<int>::iterator sit;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp;
    cin>>K;
    cin>>L;

    cin>>tmp;
    v.push_back(tmp);
    
    for(int i=1; i<L; i++)
    {
        cin>>tmp;
        v.push_back(tmp);
        d.push_back(abs(tmp-v[i-1]));
        m[abs(tmp-v[i-1])]++;
    }

    bool flag = 0;
    for(int i = 0; i<(int)d.size(); i++)
    {
        //cout<<d[i]<<' '<<m[d[i]]<<"\n";
        //cout<<it->first<<' '<<it->second<<"\n";

        if(m[d[i]]>=K)
        {
            if(flag == 0)
            {
                flag = 1;
                res+=2;
            }
            else if(flag == 1)
            {
                res+=1;
            }
        }
        else
        {
            flag = 0;
        }
        //cout<<"flag "<<flag<<' '<<res<<"\n";
    }

    cout<<L-res<<"\n";

    return 0;
}