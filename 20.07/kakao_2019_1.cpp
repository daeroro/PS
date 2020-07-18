#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int bnum = (int)board.size();
    int mnum = (int)moves.size();
    int tn;
    deque<int> dq;

    for(int i=0; i<mnum; i++)
    {
        tn = moves[i];
        for(int j=0; j<bnum; j++)
        {
            if(board[j][tn-1])
            {
                dq.push_back(board[j][tn-1]);

                board[j][tn-1] = 0;

                if(dq.size()>=2)
                {
                    cout<<dq[dq.size()-1]<<' '<<dq[dq.size()-2]<<"\n";
                }

                if((int)dq.size()>=2 && dq[dq.size()-1] == dq[dq.size()-2])
                {
                    dq.pop_back();
                    dq.pop_back();

                    answer+=2;
                }
            }
        }
    }

    return answer;
}