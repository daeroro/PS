#include <iostream>
#include <vector>

using namespace std;

int V, E;
int s, m, e;
bool chk[10001][10001];
vector<int> ver[10001];
int D[10001][10001];

int _find(int stt, int fin)
{
    //cout<<stt<<' '<<fin<<"\n";
    if(stt == fin) return 1;
    if(D[stt][fin]) return D[stt][fin];

    int tnum = (int)ver[fin].size();
    for(int i=0; i<tnum; i++)
    {
        D[stt][fin] = (D[stt][fin] + _find(stt, ver[fin][i]))%10007;
    }
    return D[stt][fin];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>V>>E;
    cin>>s>>m>>e;
    int stt, fin;
    for(int i=0; i<E; i++)
    {
        cin>>stt>>fin;

        chk[stt][fin] = 1;
        ver[fin].push_back(stt);
    }

    //_find(s, m);
    cout<<(_find(s, m)*_find(m, e))%10007<<"\n";

    return 0;
}