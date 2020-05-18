#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arrN[500001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>arrN[i];
    }

    sort(arrN, arrN+N);
/*
    for(int i=0; i<N; i++)
        cout<<arrN[i]<<' ';
    cout<<"\n";
*/
    bool flag = 0;
    int tmp, left, right, mid;
    cin>>M;
    for(int i=0; i<M; i++)
    {
        flag = 0;
        cin>>tmp;
        left = 0, right = N-1;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(arrN[mid] == tmp)
            {
                flag = 1;
                break;
            }
            else if(arrN[mid] > tmp)
            {
                right = mid -1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if(flag == 1) cout<<"1 ";
        else cout<<"0 ";
    }

    return 0;
}