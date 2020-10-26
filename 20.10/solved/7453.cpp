#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V[4], sumA, sumB;

int _find_s(int num)
{
    int st = 0, en = N*N;
    int idx = -1;
    while(st<en)
    {
        int mid = (st+en)/2;

        if(sumA[mid] < num)
        {
            st = mid + 1;
        }
        else
        {
            if(sumA[mid] == num) idx = mid;
            en = mid;   
        }
    }

    return idx;
}

int _find_e(int num)
{
    int st = -1, en = N*N-1;
    int idx = -1;
    while(st<en)
    {
        int mid = (st+en+1)/2;

        if(sumA[mid] > num)
        {
            en = mid - 1;
        }
        else
        {
            st = mid;
            if(sumA[mid] == num) idx = mid;
        }
    }

    return idx;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int tmp;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<4; j++)
        {   
            cin>>tmp;
            V[j].push_back(tmp);
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            sumA.push_back(V[0][i]+V[1][j]);
            sumB.push_back(V[2][i]+V[3][j]);
        }
    }

    sort(sumA.begin(), sumA.end());

    long long res = 0;
    int t1, t2;

    for(int i=0; i<(int)sumB.size(); i++)
    {
        //cout<<_find(0-sumB[i])<<"\n";
        t1 = _find_s(0-sumB[i]);
        t2 = _find_e(0-sumB[i]);

        //cout<<sumB[i]<<' '<<0-sumB[i]<<' '<<t1<<' '<<t2<<"\n";
        if(t1 != -1)
        {
            //cout<<sumB[i]<<' '<<t1<<' '<<t2<<"\n";
            res += (t2 - t1 + 1);
        }
    }

    cout<<res<<"\n";

    return 0;
}