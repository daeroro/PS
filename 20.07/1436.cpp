#include <iostream>

using namespace std;

int N, res;

int main(void)
{
    cin>>N;

    int cnum = 666;
    bool flag = 0;
    while(N)
    {
        int tmp = cnum;
        flag = 0;
        while(tmp)
        {
            if(tmp % 1000 == 666) flag = 1;
            tmp /= 10;
        }
        if(flag == 1) N--;
        res = cnum;
        cnum++;
    }

    cout<<res<<"\n";

    return 0;
}