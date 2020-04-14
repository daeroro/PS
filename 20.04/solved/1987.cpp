#include <iostream>

using namespace std;

int R, C, ret = 1;
char map[20][20];
int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

void _dfs(int cy, int cx, int st, unsigned int flag)
{
    int ny, nx, tflag = 0;
    for(int i=0; i<4; i++)
    {
        ny = cy + yadd[i];
        nx = cx + xadd[i];

        if(ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        if(((flag >> (map[ny][nx] - 'A')) & 0x1) == 0)
        {
            tflag = 1;
            unsigned int tmp = flag;
            tmp |= 1 << (map[ny][nx] - 'A');

            _dfs(ny, nx, st+1, tmp);
        }
    }

    if(tflag == 0)
    {
        if(st > ret) ret = st;
        return;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>map[i][j];
        }
    }

    unsigned int tmp = 1 << (map[0][0] - 'A');
    _dfs(0, 0, 1, tmp);

    cout<<ret<<"\n";

    return 0;
}