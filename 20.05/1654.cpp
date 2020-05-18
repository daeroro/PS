#include <iostream>
#include <climits>

using namespace std;

long long N, K, maL = LONG_LONG_MIN, miL = LONG_LONG_MAX;
long long arrK[10000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>K>>N;
    for(int i=0; i<K; i++)
    {
        cin>>arrK[i];
        if(arrK[i] < miL) miL = arrK[i];
        if(arrK[i] > maL) maL = arrK[i];
    }

    long long left, right, mid;
    left = 1, right = miL;

    long long ret = 0;
    while(left <= right)
    {
        long long tsum = 0;
        mid = (long long)(left + right)/2;

        for(int i=0; i<K; i++)
        {
            tsum += (long long)(arrK[i] / mid);
        }

        //cout<<"tsum "<<tsum<<"\n";
        if(tsum >= N)
        {
            if(ret < mid) ret = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        
    }

    cout<<ret<<"\n";

    return 0;
}