#include <iostream>

using namespace std;

int T, N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    for(int i=0; i<T; i++)
    {
        int arr[100001] = {0, }, chk[100001] = {0, };        
        cin>>N;
        for(int j=1; j<=N; j++)
        {
            cin>>arr[j];
        }

        for(int j=1; j<=N; j++)
        {
            if(chk[j] == 0)
            {
                int idx = j;
                if(arr[j] == j)
                {
                    chk[j] = 2;
                }
                else
                {
                    //cout<<j<<"\n";
                    while(1)
                    {
                        //cout<<idx<<"\n";
                        if(arr[idx] == idx)
                        {
                            chk[idx] = 2;
                            break;
                        }
                        else if(chk[idx] == 0)
                        {
                            chk[idx] = 1;
                            idx = arr[idx];
                        }
                        else if(chk[idx] == 1)
                        {
                            chk[idx] = 2;
                            idx = arr[idx];
                        }
                        else if(chk[idx] == 2 || chk[idx] == -1)
                            break;
                    }

                    idx = j;
                    while(chk[idx] == 1)
                    {
                        chk[idx] = -1;
                        idx = arr[idx];
                    }
                }
/*
                for(int k=1; k<=N; k++)
                {
                    cout<<chk[k]<<' ';
                }
                cout<<"\n";
                */
            }
        }

        int ret = 0;
        for(int j=1; j<=N; j++)
        {
            if(chk[j] == -1) ret++;
        }
        cout<<ret<<"\n";
    }

    return 0;
}