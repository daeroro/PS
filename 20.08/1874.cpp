#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v, s;
vector<char> c;
int snum, inum, cnum;

int main(void)
{
    cin>>N;
    int tmp;
    bool flag = 0;
    for(int i=0; i<N; i++)
    {
        cin>>tmp;
        v.push_back(tmp);        
    }
    inum = 0;
    cnum = 2;

    s.push_back(1);
    snum = s.back();
    c.push_back('+');
    while(cnum <= N)
    {
        if(s.empty())
        {
            //cout<<"1st\n";
            s.push_back(cnum);
            c.push_back('+');
            cnum++;
            continue;
        }

        snum = s.back();
        if(snum < v[inum])
        {
            //cout<<"2nd snum : "<<snum<<' '<<v[inum]<<"\n";
            s.push_back(cnum);
            c.push_back('+');
            cnum++;
        }
        else if(snum == v[inum])
        {
            //cout<<"3rd\n";
            s.pop_back();
            c.push_back('-');
            inum++;
        }
        else
        {
            //cout<<"4th\n";
            s.pop_back();
            c.push_back('-');
        }
    }

    while(!s.empty())
    {
        snum = s.back();
        if(snum == v[inum])
        {
            s.pop_back();
            c.push_back('-');
            inum++;
        }
        else
        {
            break;
        }
    }

    if(inum != N) cout<<"NO\n";
    else
    {
        for(int i=0; i<(int)c.size(); i++)
        {
            cout<<c[i]<<"\n";
        }
    }
    

    return 0;
}