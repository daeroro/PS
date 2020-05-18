#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arrN[100001], tM;

bool _bSearch(int left, int right, int fnum)
{
    while(left <= right)
    {
        int mid = (left+right)/2;

        if(arrN[mid] == fnum) return 1;
        else if(arrN[mid] < fnum) left = mid +1;
        else right = mid - 1;
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0; i<N; i++) cin>>arrN[i];
    sort(arrN, arrN+N);

    cin>>M;
    for(int i=0; i<M; i++){
        cin>>tM;

        cout<<_bSearch(0, N-1, tM)<<"\n";
    }

    return 0;
}