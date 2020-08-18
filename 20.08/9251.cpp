#include <iostream>
#include <string>

using namespace std;

string A, B;
int map[1001][1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B;

    int iA = A.size();
    int iB = B.size();
    int res = 0;

    for(int i=1; i<=iB; i++)
    {
        for(int j=1; j<=iA; j++)
        {
            if(B[i-1] == A[j-1])
            {
                map[i][j] = map[i-1][j-1] + 1;
            }
            else
            {
                map[i][j] = max(map[i-1][j], map[i][j-1]);
            }
            if(map[i][j] > res) res = map[i][j];            
        }
    }

    cout<<map[iB][iA]<<"\n";

    return 0;
}