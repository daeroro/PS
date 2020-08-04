#include <iostream>
#include <algorithm>

using namespace std;

struct pos{
    int a, b;
};

int N;
struct pos tie[100];
int len[100];

bool cmp(struct pos a, struct pos b)
{
    if(a.a < b.a) return true;
    else return false;
}

int main(void)
{
    cin>>N;

    struct pos tPos;
    for(int i=0; i<N; i++)
    {
        cin>>tie[i].a>>tie[i].b;
    }

    sort(tie, tie + N, cmp);

    int res = 1;
    int tmp = 0;
    len[0] = 1;
    for(int i=1; i<N; i++)
    {
        tmp = 0;
        for(int j=0; j<i; j++)
        {
            if(tie[j].b < tie[i].b) tmp = max(len[j], tmp);
        }

        len[i] = tmp + 1;
        if(len[i] > res) res = len[i];
    }

    cout<<N-res<<"\n";

    return 0;
}