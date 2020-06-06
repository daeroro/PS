#include <iostream>
#include <cstring>

using namespace std;

struct pos{
    int y, x;
};

int R, C, T;
int map[2][51][51];
int _cur, _next;
struct pos cleaner[2];

int yadd[4] = {-1, 1, 0, 0};
int xadd[4] = {0, 0, -1, 1};

void _move(struct pos stt, struct pos fin, int dir, int _map)
{
    int tnum;
    switch(dir)
    {
        case 0:
            tnum = abs(stt.y-fin.y);
            for(int i=0; i<tnum; i++)
            {
                map[_map][stt.y+i][stt.x] = map[_map][stt.y+i+1][stt.x];
            }
        break;

        case 1:
            tnum = abs(stt.y- fin.y);
            //cout<<"tnum "<<tnum<<"\n";
            for(int i=0; i<tnum; i++)
            {
                //cout<<"cPos "<<stt.y+i<<' '<<stt.x<<"\n";
                //cout<<"nPos "<<stt.y+i-1<<' '<<stt.x<<"\n";
                map[_map][stt.y-i][stt.x] = map[_map][stt.y-i-1][stt.x];
            }
        break;

        case 2:
            tnum = abs(stt.x-fin.x);
            for(int i=0; i<tnum; i++)
            {
                map[_map][stt.y][stt.x+i] = map[_map][stt.y][stt.x+i+1];
            }
        break;

        case 3:
            tnum = abs(stt.x-fin.x);
            for(int i=0; i<tnum; i++)
            {
                map[_map][stt.y][stt.x-i] = map[_map][stt.y][stt.x-i-1];
            }
        break;
    }
}

void _workCleaner(int _map)
{
    _move({cleaner[0].y, cleaner[0].x}, {0, 0}, 1, _map);
    _move({0, 0}, {0, C-1}, 2, _map);
    _move({0, C-1}, {cleaner[0].y, C-1}, 0, _map);
    _move({cleaner[0].y, C-1}, {cleaner[0].y, cleaner[0].x}, 3, _map);

    map[_map][cleaner[0].y][cleaner[0].x] = 0;
    map[_map][cleaner[0].y][cleaner[0].x+1] = 0;

    _move({cleaner[1].y, cleaner[1].x}, {R-1, 0}, 0, _map);
    _move({R-1, 0}, {R-1, C-1}, 2, _map);
    _move({R-1, C-1}, {cleaner[1].y, C-1}, 1, _map);
    _move({cleaner[1].y, C-1}, {cleaner[1].y, cleaner[1].x}, 3, _map);

    map[_map][cleaner[1].y][cleaner[1].x] = 0;
    map[_map][cleaner[1].y][cleaner[1].x+1] = 0;
}

void _print(int _map)
{
    cout<<"print\n";
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<<map[_map][i][j]<<' ';
        }
        cout<<"\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C>>T;
    int tidx = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>map[0][i][j];
            if(map[0][i][j] == -1)
            {
                cleaner[tidx].y = i;
                cleaner[tidx].x = j;
                tidx++;
            }
        }
    }

    _cur = 1;
    _next = 0;
    struct pos cPos, nPos;
    for(int t=0; t<T; t++)
    {
        _cur = 1-_cur;
        _next = 1-_next;

        memset(map[_next], 0, sizeof(map[_next]));
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(map[_cur][i][j] > 0)
                {
                    cPos = {i, j};
                    int tmp = 0;
                    for(int k=0; k<4; k++)
                    {
                        nPos.y = cPos.y + yadd[k];
                        nPos.x = cPos.x + xadd[k];

                        if(nPos.y < 0 || nPos.y >=R || nPos.x < 0 || nPos.x >=C) continue;
                        if((nPos.y == cleaner[0].y && nPos.x == cleaner[0].x) ||
                         (nPos.y == cleaner[1].y && nPos.x == cleaner[1].x)) continue;

                        tmp++;
                        map[_next][nPos.y][nPos.x] += map[_cur][cPos.y][cPos.x] / 5;
                    }

                    //cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<tmp<<"\n";
                    map[_next][cPos.y][cPos.x] += (map[_cur][cPos.y][cPos.x]- (map[_cur][cPos.y][cPos.x]/5*tmp));
                }
            }
        }

        //_print(_next);

        _workCleaner(_next);

        //_print(_next);
    }

    int tres = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            tres += map[_next][i][j];
        }
    }

    cout<<tres<<"\n";

    return 0;
}