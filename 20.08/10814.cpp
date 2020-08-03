#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct pos{
    int idx;
    int age;
    string name;
};

bool cmp(struct pos a, struct pos b)
{
    if(a.age == b.age)
    {
        if(a.idx < b.idx) return true;
        else return false;
    }
    else if(a.age < b.age) return true;
    else return false;
}

vector<struct pos> v;

int main(void)
{
    cin>>N;
    struct pos tPos;
    for(int i=0; i<N; i++)
    {
        cin>>tPos.age>>tPos.name;
        tPos.idx = i;

        v.push_back(tPos);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<N; i++)
    {
        cout<<v[i].age<<' '<<v[i].name<<"\n";
    }

    return 0;
}