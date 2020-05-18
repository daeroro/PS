#include <iostream>

using namespace std;

int N, M, tSum, ma, ret;
int arrN[100000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>arrN[i];
        tSum += arrN[i];
        if(ma < arrN[i]) ma = arrN[i];
    }

    cin>>M;
    if(tSum <= M)
    {
        cout<<ma<<"\n";
        return 0;
    }

    int tsum = 0;
    int left = 0, right = ma, mid = 0;
    while(left <= right)
    {
        tsum = 0;
        mid = (left+right)/2;

        for(int i=0; i<N; i++)
        {
            if(arrN[i] > mid) tsum += mid;
            else tsum += arrN[i];
        }

        if(tsum <= M)
        {
            if(ret < mid) ret = mid;
            left = mid + 1;
        }
        else right = mid-1;
    }

    cout<<ret<<"\n";

    return 0;
}