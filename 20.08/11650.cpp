#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct pos{
    int y, x;
};

vector<struct pos> v;

bool cmp(struct pos a, struct pos b)
{
    if(a.x == b.x)
    {
        if(a.y < b.y) return true;
        else return false;
    }
    else if(a.x < b.x) return true;
    else return false;
}

int main(void)
{
    cin>>N;
    struct pos tPos;
    for(int i=0; i<N; i++)
    {
        cin>>tPos.x>>tPos.y;
        v.push_back({tPos.y, tPos.x});
        //cout<<tPos.x<<' '<<tPos.y<<"\n";
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<N; i++)
    {
        cout<<v[i].x<<' '<<v[i].y<<"\n";
    }

    return 0;
}