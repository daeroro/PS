#include <iostream>

using namespace std;

struct pos{
    int y, x, d;
};

int T;
string order;

int yadd[4] = {0, -1, 0, 1};
int xadd[4] = {1, 0, -1, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int i=0; i<T; i++)
    {
        int ca = 0, cb = 0;
        int ra = 0, rb = 0;

        cin>>order;
        
        int tl = order.size();
        //cout<<"len "<<tl<<"\n";
        struct pos cPos = {0, 0, 1};
        for(int j=0; j<tl; j++)
        {
            if(order[j] == 'F')
            {
                cPos.y += yadd[cPos.d];
                cPos.x += xadd[cPos.d];

                if(cPos.y > ca) ca = cPos.y;
                else if(cPos.y < cb) cb = cPos.y;
                else if(cPos.x > ra) ra = cPos.x;
                else if(cPos.x < rb) rb = cPos.x;
            }
            else if(order[j] == 'B')
            {
                int td = (cPos.d + 2) % 4;
                cPos.y += yadd[td];
                cPos.x += xadd[td];

                if(cPos.y > ca) ca = cPos.y;
                else if(cPos.y < cb) cb = cPos.y;
                else if(cPos.x > ra) ra = cPos.x;
                else if(cPos.x < rb) rb = cPos.x;                
            }
            else if(order[j] == 'L')
            {
                cPos.d = (cPos.d + 1) % 4;
            }
            else if(order[j] == 'R')
            {
                cPos.d = (cPos.d + 3) % 4;
            }

            //cout<<"cPos "<<cPos.y<<' '<<cPos.x<<' '<<cPos.d<<"\n";
            //cout<<"rect "<<ca<<' '<<cb<<' '<<ra<<' '<<rb<<"\n";
        }

        cout<<abs(ca-cb) * abs(ra-rb)<<"\n";
    }

    return 0;
}