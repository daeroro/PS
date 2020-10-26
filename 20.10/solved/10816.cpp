#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v;

int _find_s(int num)
{
    int st = 0, en = N;
    int idx = -1;
    while(st < en)
    {
       int mid = (st+en)/2;

       if(v[mid] < num)
       {
           st = mid + 1;
       }
       else if(v[mid] > num)
       {
           //idx = mid;
           en = mid;
       }
       else
       {
           idx = mid;
           en = mid;
       }
       
    }

    return idx;
}

int _find_e(int num)
{
    int st = -1, en = N-1;
    int idx = -1;
    while(st < en)
    {
        //cout<<st<<' '<<en<<"\n";
       int mid = (st+en+1)/2;

       if(v[mid] > num)
       {
            en = mid -1;
       }
       else if(v[mid] < num)
       {
           //idx = mid;
           st = mid;
       }
       else
       {
           idx = mid;
           st = mid;
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
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
/*
    for(int i=0; i<N; i++)
        cout<<v[i]<<' ';
    cout<<"\n";
*/
    cin>>M;
    
    for(int i=0; i<M; i++)
    {
        cin>>tmp;
        int st = _find_s(tmp);
        int en = _find_e(tmp);

        if(st != -1)
        {
            cout<<en - st +1<<' ';
        }
        else
        {
            cout<<0<<' ';
        }
        
    }
    cout<<"\n";

    return 0;
}