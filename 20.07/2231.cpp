#include <iostream>

using namespace std;

int N, res = 1000001;

int main(void)
{
    cin>>N;

    for(int i=N; i>=1; i--)
    {
        int tnum = i;
        int tres = i;
        while(tnum)
        {
            tres += tnum % 10;
            tnum /= 10;
        }

        if(tres == N && res > i)
        {
            res = i;
        }

        //cout<<i<<' '<<tres<<"\n";
    }

    if(res == 1000001) res = 0;
    cout<<res<<"\n";

    return 0;
}