#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

bool cmp(int a, int b)
{
    if(a>b) return true;
    else return false;
}

int main(void)
{
    cin>>N;
    int tmp, num = 0;
    while(N)
    {
        tmp = N%10;
        v.push_back(tmp);
        N/=10;
        num++;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<num; i++)
    {
        cout<<v[i];
    }

    cout<<"\n";

    return 0;
}