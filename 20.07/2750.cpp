#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

void _swap(int i1, int i2)
{
    int tmp = v[i1];
    v[i1] = v[i2];
    v[i2] = tmp;
}

int main(void)
{
    cin>>N;
    int tnum;
    for(int i=0; i<N; i++)
    {
        cin>>tnum;
        v.push_back(tnum);
    }

    for(int i=0; i<N; i++)
    {
        for(int j = i+1; j<N; j++)
        {
            if(v[i] > v[j]) _swap(i, j);           
        }
    }

    for(int i=0; i<N; i++) cout<<v[i]<<"\n";

    return 0;
}