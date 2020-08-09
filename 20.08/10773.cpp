#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> v;

int main(void)
{
    cin>>K;
    int tmp;
    for(int i=0; i<K; i++)
    {
        cin>>tmp;
        if(tmp) v.push_back(tmp);
        else
        {
            v.pop_back();
        }
    }

    int sum = 0;
    for(int i=0; i<(int)v.size(); i++)
    {
        sum += v[i];
    }

    cout<<sum<<"\n";

    return 0;
}