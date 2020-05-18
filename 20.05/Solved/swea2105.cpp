#include <iostream>

using namespace std;

struct pos{
    int y, x;
};

int T, N, map[20][20], tres;
bool chk[101], mchk[20][20];
struct pos stt;

int yadd[4] = {1, 1, -1, -1};
int xadd[4] = {-1, 1, 1, -1};

void dfs(int st, struct pos cPos, int n[4], int cdir)
{
    //cout<<st<<' '<<cPos.y<<' '<<cPos.x<<' '<<cdir<<' '<<map[cPos.y][cPos.x]<<" | "<<n[0]<<' '<<n[1]<<' '<<n[2]<<' '<<n[3]<<"\n";
    if(n[0] != 0 && n[1] != 0 && cdir == 3 && n[0] == n[2] && n[1] == n[3])
    {
        if(st > tres) tres = st;
        return;
    }

    struct pos nPos;
    if(cdir == 3)
    {
        nPos.y = cPos.y + yadd[cdir];
        nPos.x = cPos.x + xadd[cdir];

        if(nPos.y <0 || nPos.y >= N || nPos.x < 0 ||nPos.x >= N)
            return;
        if(stt.y == nPos.y && stt.x == nPos.x)
        {
            n[cdir]++;
            dfs(st+1, nPos, n, cdir);
            n[cdir]--;
        }             
        if(chk[map[nPos.y][nPos.x]] == 1)
            return;           
        
        if(mchk[nPos.y][nPos.x] == 0)
        {
            mchk[nPos.y][nPos.x] = 1;
            chk[map[nPos.y][nPos.x]] = 1;
            n[cdir]++;
            dfs(st+1, nPos, n, cdir);

            mchk[nPos.y][nPos.x] = 0;
            chk[map[nPos.y][nPos.x]] = 0;
            n[cdir]--;            
        }
    }
    else
    {
        for(int i=cdir; i<cdir+2; i++)
        {
            nPos.y = cPos.y + yadd[i];
            nPos.x = cPos.x + xadd[i];
      //      cout<<cPos.y<<' '<<cPos.x<<" | "<<nPos.y<<' '<<nPos.x<<' '<<mchk[nPos.y][nPos.x]<<"\n";
            if(nPos.y <0 || nPos.y >= N || nPos.x < 0 ||nPos.x >= N)
                continue;
            if(stt.y == nPos.y && stt.x == nPos.x)
            {
                n[i]++;
                dfs(st+1, nPos, n, i);
                n[i]--;
            }                
            if(chk[map[nPos.y][nPos.x]] == 1)
                continue;
            if(cdir == 1 && n[0] == 0) continue;
            
            if(mchk[nPos.y][nPos.x] == 0)
            {
                mchk[nPos.y][nPos.x] = 1;
                chk[map[nPos.y][nPos.x]] = 1;
                n[i]++;

                dfs(st+1, nPos, n, i);

                mchk[nPos.y][nPos.x] = 0;
                chk[map[nPos.y][nPos.x]] = 0;
                n[i]--;                
            }
        }   
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int st =0; st<T; st++)
    {
        tres = 0;
        for(int i=0; i<20; i++)
        {
            for(int j=0; j<20; j++)
            {
                map[i][j] = 0;
            }
        }

        cin>>N;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>map[i][j];
            }
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                int n[4] = {0, };
                chk[map[i][j]] = 1;
                mchk[i][j] = 1;

                stt.y = i, stt.x = j;

                dfs(0, {i, j}, n, 0);

                chk[map[i][j]] = 0;
                mchk[i][j] = 0;
            }
        }

        if(tres == 0) tres = -1;

        cout<<'#'<<st+1<<' '<<tres<<"\n";
    }

    return 0;
}