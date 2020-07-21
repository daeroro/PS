#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int chk[200001];
vector<pair<int, float> > v;

bool cmp(pair<int, float> a, pair<int, float> b)
{
    if(a.second == b.second)
    {
        if(a.first < b.first) return true;
        else return false;
    }
    else if(a.second > b.second) return true;
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(auto i:stages)
    {
        chk[i]++;
    }

    int sum = chk[N+1];
    for(int i=N; i>=1; i--)
    {
        sum += chk[i];        
        if(sum == 0) v.push_back(make_pair(i, 0.0));
        else v.push_back(make_pair(i, ((float)chk[i]/sum)));
        //cout<<chk[i]<<'/'<<sum<<"\n";
        if(sum == 0) cout<<"0\n";
        else cout<<(float)chk[i]/sum<<"\n";
    }

    sort(v.begin(), v.end(), cmp);

    for(auto input : v)
    {
        cout<<input.first<<' '<<input.second<<"\n";
        answer.push_back(input.first);
    }

    return answer;
}