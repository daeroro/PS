#include <iostream>

using namespace std;

struct pos {
    int n, x;
};

int res;
int Num[10];
int map[4][24] = 
{
    {-1, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 32, 34, 36, 38,
    40, 0, },

    {-1, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 28, 27, 26, 25,
    30, 35, 40, 0},

    {-1, 2, 4, 6, 8,
    10, 12, 14, 16, 18,
    20, 22, 24, 25, 30,
    35, 40, 0, },

    {-1, 2, 4, 6, 8,
    10, 13, 16, 19, 25,
    30, 35, 40, 0, }
};

int check[4][24] = 
{
    {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 9, 
        10, 11, 12, 13, 14,
        15, 16, 17, 18, 19,
        20, 21,
    },
    {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 9,
        10, 11, 12, 13, 14,
        15, 28, 27, 26, 25,
        31, 32, 20,
    },
    {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 9,
        10, 29, 30, 25, 31,
        32, 20,
    },
    {
        0, 1, 2, 3, 4,
        5, 22, 23, 24, 25,
        31, 32, 20,
    }
};

struct pos hr[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
int n[10];

void _dfs(int st, int tsum)
{
    //cout<<"cur "<<st<<' '<<tsum<<"\n";
    if(st == 10)
    {
        if(tsum > res) res = tsum;
        return;
    }

    for(int i=0; i<4; i++)
    {
        if(hr[i].x != -1)
        {
            struct pos tPos = hr[i];
            hr[i].x += Num[st];

            if(hr[i].x >= 24 || map[hr[i].n][hr[i].x] == 0)
            {
                hr[i].x = -1;
            }

            if(hr[i].n == 0)
            {
                switch(hr[i].x)
                {
                    case 5:
                        hr[i].n = 3;
                    break;

                    case 10:
                        hr[i].n = 2;
                    break;

                    case 15:
                        hr[i].n = 1;
                    break;

                    default:
                    break;
                }
            }

            if(hr[i].x != -1)
            {
                bool flag = 0;
                for(int j=0; j<4; j++)
                {
                    if(i!=j)
                    {
                        if(check[hr[i].n][hr[i].x] == check[hr[j].n][hr[j].x])
                        {
                            hr[i] = tPos;
                            flag = 1;
                            break;
                        }
                    }
                }

                if(flag == 1) continue;
                
                n[st] = i;
                //cout<<"cur1 "<<st+1<<' '<<tsum<<' '<<map[hr[i].n][hr[i].x]<<"\n";
                _dfs(st+1, tsum + map[hr[i].n][hr[i].x]);
            }
            else
            {
                n[st] = i;
                //cout<<"cur2 "<<st+1<<' '<<tsum<<"\n";
                _dfs(st+1, tsum);
            }
            hr[i] = tPos;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<10; i++)
    {
        cin>>Num[i];
    }

    _dfs(0, 0);

    cout<<res<<"\n";

    return 0;
}