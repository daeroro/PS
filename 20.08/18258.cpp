#include <iostream>
#include <string>

using namespace std;

int num[2000002];
struct queue{
    int front, back;
};
int N, tnum;
string st;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    struct queue q = {0, 0};

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>st;
        if(st == "push")
        {
            cin>>tnum;
            num[q.back] = tnum;
            q.back++;
        }
        else if(st == "pop")
        {
            if(q.front == q.back) cout<<"-1\n";
            else
            {
                cout<<num[q.front]<<"\n";
                q.front++;
            }
        }
        else if(st == "size")
        {
            cout<<q.back-q.front<<"\n";
        }
        else if(st == "empty")
        {
            if(q.front == q.back) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(st == "front")
        {
            if(q.front == q.back) cout<<"-1\n";
            else
            {
                cout<<num[q.front]<<"\n";   
            }
        }
        else if(st == "back")
        {
            if(q.front == q.back) cout<<"-1\n";
            else
            {
                cout<<num[q.back-1]<<"\n";
            }
        }
    }

    return 0;
}