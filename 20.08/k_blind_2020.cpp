#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

struct pos{
    struct pos * ch[26];
};

struct pos * fword[10001];
struct pos * bword[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    int wlen = words.size();
    for(int i=0; i<wlen; i++)
    {
        char cur[10001];
        strcpy(cur, words[i].c_str());
        int clen = words[i].length();

        if(fword[clen] == NULL)
        {
            fword[clen] = (struct pos *)malloc(sizeof(struct pos));
        }
        if(bword[clen] == NULL)
        {
            bword[clen] = (struct pos *)malloc(sizeof(struct pos));
        }

        struct pos * cpos = fword[clen];
        for(int j=0; j<clen; j++)
        {
            cout<<cur[j]<<' ';
            if(cpos->ch[cur[j]-'a'] == NULL)
            {
                cpos->ch[cur[j]-'a'] = (struct pos*)malloc(sizeof(struct pos));

            }
            cpos = cpos->ch[cur[j]-'a'];            
        }
        cout<<"\n";

        struct pos * ccpos = bword[clen];
        
        for(int j=0; j<clen; j++)
        {
            cout<<cur[clen-1-j]<<' ';
                        
            if(ccpos->ch[cur[clen-1-j]-'a'] == NULL)
            {
                ccpos->ch[cur[clen-1-j]-'a'] = (struct pos *)malloc(sizeof(struct pos));
            }
            ccpos = ccpos->ch[cur[clen-1-j]-'a'];            
            
        }
        cout<<"\n";
        
    }

    int qlen = queries.size();
    for(int i=0; i<qlen; i++)
    {
        char cur[10001];
        strcpy(cur, queries[i].c_str());
        int clen = queries[i].length();

        struct pos * cpos;
        int tnum = 0;
        
        if(cur[0] == '?')
        {
            cpos = bword[clen];
            int idx = clen-1;
            bool flag = 0;
            while(cur[idx] != '?')
            {
                if(cpos->ch[cur[idx]-'a'] != NULL)
                {
                    cpos = cpos->ch[cur[idx]-'a'];
                    idx--;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                for(int j=0; j<26; j++)
                {
                    if(cpos->ch[j] != NULL) tnum++;
                }
                answer.push_back(tnum);
            }
        }
        else
        {
            cpos = fword[clen];
            int idx = 0;
            bool flag = 0;
            while(cur[idx] != '?')
            {
                if(cpos->ch[cur[idx]-'a'] != NULL)
                {
                    cpos = cpos->ch[cur[idx]-'a'];
                    idx++;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                for(int j=0; j<26; j++)
                {
                    if(cpos->ch[j] != NULL) tnum++;
                }
                answer.push_back(tnum);
            }
        }
    }

    return answer;
}