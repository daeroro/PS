#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nA, nB;
vector<int> A, B, res;

bool _find(int num)
{
    int st = 0, en = nB;
    while(st<=en)
    {
        int mid = (st+en)/2;
        if(B[mid] == num)
        {
            return true;
        }
        else if(B[mid] < num)
        {
            st = mid+1;
        }
        else
        {
            en = mid-1;
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>nA>>nB;
    int tmp;
    for(int i=0; i<nA; i++)
    {
        cin>>tmp;
        A.push_back(tmp);
    }

    for(int i=0; i<nB; i++)
    {
        cin>>tmp;
        B.push_back(tmp);
    }

    sort(B.begin(), B.end());

    for(int i=0; i<nA; i++)
    {
        if(!_find(A[i]))
        {
            res.push_back(A[i]);
        }
    }

    sort(res.begin(), res.end());

    cout<<res.size()<<"\n";
    for(int i=0; i<(int)res.size(); i++)
    {
        cout<<res[i]<<' ';
    }

    return 0;
}