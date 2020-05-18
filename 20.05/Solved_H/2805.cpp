#include <iostream>

using namespace std;

long long N, M, maxT, ret;
long long tree[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>tree[i];
        if(maxT < tree[i]) maxT = tree[i]; 
    }

    long long left = 0, right = maxT;
    long long mid = (left + right) / 2;

    while(left <= right)
    {
        mid = (left + right) /2;
        long long sum = 0;

        for(long long i=0; i<N; i++)
        {
            if(tree[i] > mid)
                sum += (tree[i] - mid);
        }

        //cout<<"l r m s "<<left<<' '<<right<<' '<<mid<<' '<<sum<<"\n";
        if(sum >= M)
        {
            if(ret < mid)
            {
                ret = mid;
            }
            
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout<<mid<<"\n";

    return 0;
}