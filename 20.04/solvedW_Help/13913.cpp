/*
    1. bfs()에서 trace 구하는 방법
    2. 반례 구할 때, 가장 간단한 것부터 생각해보자... 
*/

#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

int N, K, ret = 100000+1;
bool chk[100001];
int parent[100001];

vector<int> tq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;

    chk[N] = 1;
    queue<int>dq;
    dq.push(N);

    int cPos;
    while(!dq.empty())
    {
        cPos = dq.front();
        //cout<<cPos<<"\n";
        dq.pop();

        if(cPos == K)
        {
            int idx = K;
            while(idx != N)
            {
                tq.push_back(idx);
                idx = parent[idx];
            }
            tq.push_back(N);

            cout<<tq.size()-1<<"\n";
            for(int i=(int)tq.size()-1; i>=0; i--)
            {
                cout<<tq[i]<<' ';
            }
            cout<<"\n";
            return 0;
        }

        if((cPos+1) <= 100000 && chk[cPos+1] == 0)
        {
            chk[cPos+1] = 1;
            parent[cPos+1] = cPos;

            dq.push(cPos+1);
        }
        if((cPos-1) >=0 && chk[cPos-1] == 0)
        {
            chk[cPos-1] = 1;
            parent[cPos-1] = cPos;

            dq.push(cPos-1);
        }
        if(2*cPos <= 100000 && chk[2*cPos] == 0)
        {
            chk[2*cPos] = 1;
            parent[2*cPos] = cPos;

            dq.push(2*cPos);
        }        
    }

    return 0;
}