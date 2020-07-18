#include <string>
#include <vector>
#include <cstring>
#include <deque>
#include <iostream>

using namespace std;
deque<int> tq[501];
bool chk[100001];

vector<int> solution(string s) {
    vector<int> answer;

    int ssize = (int)s.size();
    const char * st = s.c_str();
    const char * fs, *ls;
    int flag = 0, dnum = 0;

    deque<int> dq;

    for(int i=0; i<ssize; i++)
    {
        switch(st[i])
        {
            case '{':
                fs = &st[i+1];
                flag++;
            break;

            case '}':
                flag--;
                if(flag == 1)
                {
                    char tmp[7];
                    int len;
                    ls = &st[i];
                    
                    len = ls - fs;
                    strncpy(tmp, fs, len);
                    tmp[len] = '\0';
                    
                    dq.push_back(atoi(tmp));
                    //cout<<atoi(tmp)<<"\n";

                    int tn = (int)dq.size();
                    for(int i=0; i<tn; i++)
                    {
                        tq[tn].push_back(dq[i]);
                    }
                    dq.clear();
                    dnum++;
                }
                
            break;

            case ',':
                if(flag == 2)
                {
                    char tmp[7];
                    int len;
                    ls = &st[i];
                    
                    len = ls - fs;
                    strncpy(tmp, fs, len);
                    tmp[len] = '\0';
                    
                    dq.push_back(atoi(tmp));
                    //cout<<atoi(tmp)<<"\n";
                }
                fs = &st[i+1];
            break;
        }
    }

    for(int i=1; i<=dnum; i++)
    {
        int qnum = (int)tq[i].size();
        for(int j=0; j<qnum; j++)
        {
            if(chk[tq[i][j]]==0)
            {
                chk[tq[i][j]] = 1;
                answer.push_back(tq[i][j]);
            }
        }
    }

    return answer;
}