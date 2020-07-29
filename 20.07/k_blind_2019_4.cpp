#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int ln = 1, rn = 100000000;
    int fnum = (int)food_times.size();
    long long ck;

    while(ln <= rn)
    {
        int mid = (ln + rn) /2;
        ck = 0;
        for(int i=0; i<fnum; i++)
        {
            if(food_times[i] <= mid)
            {
                ck += (long long)food_times[i];
            }
            else
            {
                ck += (long long)mid;
            }
        }

        if(ck == k) break;
        else if(ck < k)
        {
            if((k-ck) > (long long)fnum) rn = mid - 1;
            else ln = mid + 1;
        }
        else rn = mid - 1;

        cout<<mid<<' '<<ck<<' '<<k<<"\n";
    }

    int idx;
    if((k - ck) == 0) answer = 1;
    else
    {
        long long tn = k-ck;
        if(tn >= (long long)fnum) answer = -1;
        else
        {
            idx = 0;
            while(tn)
            {
                if(food_times[idx] > ck)
                {
                    tn--;
                }
                idx++;
            }
            answer = idx;            
        }
    }
    
    return answer;
}