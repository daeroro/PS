#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string st;

int main(void)
{
    cin>>st;
    int slen = st.length();
    const char * cst = st.c_str();
    bool flag = 0;

    for(int i=0; i<slen-1; i++)
    {
        if(cst[i] != '1' || cst[i] != '2')
        {
            flag = 1;
            break;
        }

        if(cst[i] == '1' && cst[i+1] != '2')
        {
            flag = 1;
            break;
        }
    }

    if(cst[slen-1] != '1' || cst[slen-1] != '2') flag = 1;

    if(flag == 1) cout<<"false\n";
    else cout<<"true\n";

    return 0;
}