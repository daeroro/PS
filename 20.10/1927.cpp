#include <iostream>

using namespace std;

long long arr[100001];
int N;

int lidx = 1;
int cNum = 0;

void _insert(long long num)
{
    int tidx = lidx;
    int pidx = tidx;
    arr[tidx] = num;

    while(pidx/2)
    {
        pidx /= 2;

        if(arr[pidx] > arr[tidx])
        {
            long long tmp = arr[pidx];
            arr[pidx] = arr[tidx];
            arr[tidx] = tmp;

            tidx = pidx;
        }
        else
        {
            break;   
        }
    }
    lidx++;
    cNum++;
}

void _delete()
{
    if(cNum == 0) return;

    int tidx = lidx - 1;
    int cidx = 1;
    arr[1] = arr[tidx];
    arr[tidx] = 0;
    tidx = 1;

    while(cidx *2 + 1< lidx)
    {
        cidx *= 2;

        if(arr[cidx] != 0 && arr[cidx] < arr[tidx])
        {
            long long tmp = arr[cidx];
            arr[cidx] = arr[tidx];
            arr[tidx] = tmp;

            tidx = cidx;
        }
        else if(arr[cidx + 1] != 0 && arr[cidx+1]<arr[tidx])
        {
            long long tmp = arr[cidx+1];
            arr[cidx+1] = arr[tidx];
            arr[tidx] = tmp;

            tidx = cidx+1;
        }
        else if(arr[cidx] == 0)
        {
            arr[cidx] = arr[tidx];
            tidx = cidx;
        }
        else if(arr[cidx+1] == 0)
        {
            arr[cidx+1] = arr[tidx];
            tidx = cidx +1;
        }
        else break;
    }

    lidx--;
    cNum--;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long tmp;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>tmp;

        if(tmp)
        {
            _insert(tmp);
        }
        else
        {
            if(cNum == 0) cout<<"0\n";  
            else
            {
                cout<<arr[1]<<"\n";
                _delete();
            }
        }

        //cout<<cNum<<' '<<lidx<<"\n";
    }

    return 0;
}