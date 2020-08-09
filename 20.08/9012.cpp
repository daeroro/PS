#include <iostream>
#include <string>

using namespace std;

int T;

int main(void)
{
    int tnum;
    bool flag = 0;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        string st;
        cin>>st;
        tnum = 0;
        flag = 0;
        for(int j=0; j<(int)st.size(); j++)
        {
            if(st[j] == '(') tnum++;
            else tnum--;

            if(tnum < 0)
            {
                flag = 1;
                break;
            }
        }

        if(!flag && !tnum) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}