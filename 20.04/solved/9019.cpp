/*
string 사용 시 (+ "abc") 활용하기
*/

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

struct pos{
    int num;
    string pnt;
};

int T, A, B;
char nm[4] = {'D', 'S', 'L', 'R'};

deque<struct pos> dq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct pos cPos, nPos;

    cin>>T;
    for(int i=0; i<T; i++)
    {
        bool chk[10000] = {0, };
        bool flag = 0;
        dq.clear();
        cin>>A>>B;

        chk[A] = 1;
        dq.push_back({A, ""});
        
        while(!dq.empty())
        {
            cPos = dq.front();
            //cout<<"cPos "<<cPos.num<<"\n";
            dq.pop_front();

            int tn, ta;
            for(int j=0; j<4; j++)
            {
                switch(j)
                {
                    case 0:
                        tn = (2*cPos.num) % 10000;
                    break;
                    case 1:
                        tn = cPos.num -1;
                        if(tn < 0) tn = 9999;
                    break;
                    case 2:
                        ta = cPos.num / 1000;
                        tn = (cPos.num - ta * 1000) * 10 + ta;
                    break;
                    case 3:
                        ta = cPos.num % 10;
                        tn = (cPos.num / 10) + ta * 1000;
                    break;
                }

                if(tn == B)
                {
                    string out = cPos.pnt +nm[j];
                    cout<<out<<"\n";
                    flag = 1;
                    break;
                }

                if(chk[tn] == 0)
                {
                    chk[tn] = 1;
                    dq.push_back({tn, cPos.pnt + nm[j]});
                }
            }
            if(flag == 1) break;
        }
    }

    return 0;
}