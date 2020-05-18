#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arrN[500000];

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
    cin>>M;

    sort(arrN, arrN+N);

    for(int i=0; i<N; i++)
    {
        cout<<arrN[i]<<' ';
    }
    cout<<"\n";

    int tmp, tmp2;
    int left, right, mid;
    int sIdx, fIdx;
    for(int i=0; i<M; i++)
    {
        cin>>tmp;
        tmp2 = -1;
        left = 0, right = N-1;
        sIdx = N-1, fIdx = 0;
        while(left<=right)
        {
            mid = (left + right)/2;
            //cout<<left<<' '<<right<<' '<<mid<<"\n";
            if(arrN[mid]==tmp)
            {
                tmp2 = mid;
                sIdx = mid;
                while(arrN[sIdx] == tmp) sIdx--;
                sIdx++;

                break;
            }
            else if(arrN[mid]<tmp) left = mid + 1;
            else
            {
                right = mid - 1;
            }
        }
        if(tmp2 != -1)
        {
            fIdx = tmp2;
            while(arrN[fIdx] == tmp) fIdx++;
            fIdx--;
        }

        //cout<<"tmp "<<tmp<<' '<<sIdx<<' '<<fIdx<<"\n";
        if(sIdx <= fIdx){
            cout<<fIdx-sIdx+1<<' ';
        }
        else
        {
            cout<<"0 ";
        }
        //cout<<"\n";
    }

    return 0;
}