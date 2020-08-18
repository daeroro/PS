#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define RoundOff(x, dig) (floor((x)*pow(10, dig) + 0.5) / pow(10, dig))

using namespace std;
int N, mi = 4000, ma = -4000;
int tpr[8005];

struct pos{
    int num, t;
};

vector<int> v;
vector<struct pos> v2;

bool cmp(int a, int b)
{
    if(a < b) return true;
    else return false;
}

bool cmp2(struct pos a, struct pos b)
{
    if(a.t == b.t)
    {
        if(a.num > b.num) return true;
        else return false;
    }
    else if(a.t < b.t) return true;
    else return false;
}

int main(void)
{
    int tmp;
    double tsum=0.0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>tmp;
        v.push_back(tmp);
        tsum += (float)tmp;
        tpr[tmp+4000]++;
        if(tmp > ma) ma = tmp;
        if(tmp < mi) mi = tmp;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=mi; i<=ma; i++)
    {
        if(tpr[i+4000])
        {
            v2.push_back({i, tpr[i+4000]});
        }
    }

    sort(v2.begin(), v2.end(), cmp2);
    struct pos t1 = v2.back();
    v2.pop_back();

    struct pos t2 = {0, 0};
    if(!v2.empty()) t2 = v2.back();

    cout<<round(tsum/(double)N)<<"\n";
    cout<<v[N/2]<<"\n";
    if(t1.t == t2.t) cout<<t2.num<<"\n";
    else cout<<t1.num<<"\n";
    cout<<ma-mi<<"\n";

    return 0;
}