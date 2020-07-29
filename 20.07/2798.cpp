#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int N, M, tres;
int card[100];
bool chk[100];

void _dfs(int st, int cur)
{
    if(st == 3)
    {
        /*
        for(int i=0; i<N; i++)
        {
            cout<<chk[i]<<' ';
        }
        cout<<"\n";
        */
        int tnum = 0;
        for(int i=0; i<3; i++)
        {
            tnum += v[i];
        }
        if(tnum <= M)
        {
            if(tres < tnum)
                tres = tnum;
        }        
        return;
    }

    for(int i=cur+1; i<N; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            v.push_back(card[i]);

            _dfs(st+1, i);

            v.pop_back();
            chk[i] = 0;
        }
    }
}

int main(void)
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>card[i];
    }

    _dfs(0, -1);

    cout<<tres<<"\n";

    return 0;
}