#include <iostream>

using namespace std;

int N;
int num[1001];
int len[1001];

int main(void)
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>num[i];
    }

    int res = 1;
    len[0] = 1;
    //cout<<1<<' ';
    for(int i=1; i<N; i++)
    {
        int tmp = 0;
        for(int j=0; j<i; j++)
        {
            if(num[i] > num[j]) max(tmp, len[j]);
        }
        len[i] = tmp + 1;

        if(res < len[i]) res = len[i];
    }
    //cout<<"\n";

    cout<<res<<"\n";

    return 0;
}