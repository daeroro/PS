#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int n;
    int M;
    int D;
    int h;
    int m;
    int s;
};

struct pos cPos;
priority_queue<struct pos> pq;

int solution(int n, vector<string> customers)
{
    int answer = 0;

    for(int i=0; i<(int)customers.size(); i++)
    {
        const char *tmpChar = customers[i].c_str();

        cPos.n = i+1;
        cPos.D = atoi(&tmpChar[0]) * 10 + atoi(&tmpChar[1]);

        cout<<cPos.D;

        pq.pus
    }

    return answer;
}