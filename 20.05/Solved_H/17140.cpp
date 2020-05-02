#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int x, n;
};

int R, C, K, curR, curC;
int A[105][105];

priority_queue<struct pos> pq;

bool _isCorrect()
{
    //cout<<"cur "<<A[R][C]<<"\n";
    if(A[R][C] == K) return 1;
    else return 0;
}

bool operator<(struct pos a, struct pos b)
{
    if(a.n == b.n)
    {
        if(a.x > b.x) return 1;
        else return 0;
    }
    else if(a.n > b.n) return 1;
    else return 0;
}

void calR()
{
    for(int i=1; i<=curR; i++)
    {
        int chk[105] = {0, };
        int tA[105] = {0, };

        for(int j=1; j<=curC; j++)
        {
            //cout<<"A "<<A[i][j]<<"\n";
            chk[A[i][j]] += 1;
        }
        for(int j=1; j<=100; j++)
        {
            if(chk[j] > 0)
            {
                pq.push({j, chk[j]});
            }
        }

        //cout<<pq.size()<<"\n";
/*
        struct pos t;
        while(!pq.empty())
        {
            t = pq.top();
            pq.pop();

            cout<<t.x<<' '<<t.n<<"\n";
        }
*/
        struct pos tPos;
        int tnum = 1, tidx = 1;

        while(!pq.empty() && tnum <= 50)
        {
            tPos = pq.top();
            pq.pop();
            //cout<<tPos.x<<' '<<tPos.n<<"\n";

            tA[tidx++] = tPos.x;
            tA[tidx++] = tPos.n;

            tnum++;
        }

        if(curC < tidx-1) curC = tidx-1;
        //else if(tidx-1 < 3 ) curC = tidx-1;

        for(int j=1; j<=curC; j++)
        {
            A[i][j] = tA[j];
        }

        while(!pq.empty()) pq.pop();
        
    }
}

void calC()
{
    for(int i=1; i<=curC; i++)
    {
        int chk[105] = {0, };
        int tA[105] = {0, };

        for(int j=1; j<=curR; j++)
        {
            chk[A[j][i]] += 1;
        }
        for(int j=1; j<=100; j++)
        {
            if(chk[j] > 0)
            {
                pq.push({j, chk[j]});
            }
        }

        struct pos tPos;
        int tnum = 1, tidx = 1;

        while(!pq.empty() && tnum <= 50)
        {
            tPos = pq.top();
            pq.pop();

            tA[tidx++] = tPos.x;
            tA[tidx++] = tPos.n;

            tnum++;
        }

        if(curR < tidx-1) curR = tidx-1;
        //else if(tidx -1 < 3) curR = tidx-1;

        for(int j=1; j<=curR; j++)
        {
            A[j][i] = tA[j];
        }

        while(!pq.empty()) pq.pop();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C>>K;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cin>>A[i][j];
        }
    }

    curR = 3, curC = 3;
    int ret = 0;
    
    while(!_isCorrect())
    {
        if(curR >= curC) calR();
        else calC();

        ret++;

        if(ret > 100)
        {
            ret = -1;
            break;
        }
/*
    for(int i=1; i<=curR; i++)
    {
        for(int j=1; j<= curC; j++)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"cur ret "<<ret<<" R, C"<<curR<<' '<<curC<<"\n";        
*/
    }
    

    //calR();



    cout<<ret<<"\n";

    return 0;
}