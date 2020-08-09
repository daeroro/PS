#include <iostream>
#include <string>
#include <vector>

using namespace std;

int snum, lnum, cnt;
bool flag;

vector<int> v;

int main(void)
{
    while(1)
    {
        cnt++;
        string st;
        getline(cin, st);
        v.clear();
        //cout<<st<<"\n";
        if(st == ".") break;

        flag = 0;

        for(int i=0; i<(int)st.size(); i++)
        {
            switch(st[i])
            {
                case '(':
                    v.push_back(1);
                    break;
                case '[':
                    v.push_back(2);
                break;

                case ')':
                    if(v.size())
                    {
                        if(v.back() == 1) v.pop_back();
                        else flag = 1;
                    }
                    else
                    {
                        flag = 1;
                    }
                    
                break;

                case ']':
                    if(v.size())
                    {
                        if(v.back() == 2) v.pop_back();
                        else flag = 1;
                    }
                    else
                    {
                        flag = 1;
                    }

                break;
            }
        }
        
        if(!flag && !v.size()) cout<<"yes\n";
        else cout<<"no\n";
    }

    return 0;
}