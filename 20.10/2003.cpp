#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    int tmp;
    for(int i=0; i<N; i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }

    int num = 0;
    int s = 0, e = 0, res = v[0];
    while(s<N)
    {
        if(e == N) e -= 1;
        if(res > M)
        {
            res -= v[s];
            s++;
        }
        else if(res < M)
        {
            e++;
            res += v[e];
            if(e == N-1) break;
        }
        else
        {
            num++;
            res -= v[s];
            s++;   
        }
    }

    cout<<num<<"\n";

    return 0;
}