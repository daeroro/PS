#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;

vector<int> v;

int main(void)
{
    cin>>N;
    int tnum;
    for(int i=0; i<N; i++)
    {
        char ch[10];
        cin>>ch;
        if(!strcmp(ch, "push"))
        {
            cin>>tnum;
            v.push_back(tnum);
        }
        else if(!strcmp(ch, "pop"))
        {
            if((int)v.size())
            {   
                tnum = v.back();
                v.pop_back();
                cout<<tnum<<"\n";

            }
            else
            {
                cout<<"-1\n";
            }
        }
        else if(!strcmp(ch, "size"))
        {
            cout<<v.size()<<"\n";
        }
        else if(!strcmp(ch, "empty"))
        {
            if((int)v.size()) cout<<"0\n";
            else cout<<"1\n";
        }
        else
        {
            if((int)v.size()) cout<<v.back()<<"\n";
            else cout<<"-1\n";    
        }
        
        //cout<<ch<<"\n";
    }

    return 0;
}