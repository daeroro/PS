#include <string>
#include <vector>
#include <cstring>
#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

set<int> ts;
set<int>::iterator it2;
set<string> s;
set<string>::iterator it;
deque<int> dq[8], tq;
bool chk[8][8];
int res;

void dfs(int st, int ma)
{
    if(st == ma)
    {
        string tst;
        int tnum = (int)tq.size();
        //sort(tq.begin(), tq.end());
        for(int i=0; i<tnum; i++)
        {
            ts.insert(tq[i]);
        }

        if((int)ts.size() == ma)
        {
            for(it2 = ts.begin(); it2 != ts.end(); it2++)
            {
                char tmp[10];
                sprintf(tmp, "%d", *it2);

                tst += tmp;
            }
            //cout<<tst<<"\n";
            s.insert(tst);
        }
        ts.clear();

        return;
    }

    int tnum = (int)dq[st].size();
    for(int i=0; i<tnum; i++)
    {
        if(chk[st][i] == 0)
        {
            chk[st][i] = 1;
            tq.push_back(dq[st][i]);

            dfs(st+1, ma);

            tq.pop_back();
            chk[st][i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    const char * bst, * ust;
    int unum = (int)user_id.size();
    int bnum = (int)banned_id.size();

    for(int i=0; i<bnum; i++)
    {
        bst = banned_id[i].c_str();
        for(int j=0; j<unum; j++)
        {
            ust = user_id[j].c_str();

            if(banned_id[i].size() == user_id[j].size())
            {
                //cout<<banned_id[i]<<' '<<user_id[j]<<"\n";
                bool flag = 0;
                for(int k=0; k<(int)banned_id[i].size(); k++)
                {
                    if(bst[k] == '*') continue;
                    else if(bst[k] != ust[k])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    dq[i].push_back(j);
                }
            }
        }
    }

    dfs(0, bnum);

    answer = (int)s.size();
    return answer;
}