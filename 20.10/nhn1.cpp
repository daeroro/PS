#include <iostream>
#include <sstream>

using namespace std;

int Num[30];
bool chk[30];
char Pos[30];

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
    for(int i=0; i<numOfQuickPlayers; i++)
    {
        chk[namesOfQuickPlayers[i] - 'A'] = 1;
    }

    for(int i=0; i<numOfAllPlayers-1; i++)
    {
        Pos[i] = 'B' + i;
    }

    char cSeeker = 'A';
    int cPos = 0;
    Num[cSeeker - 'A']++;

    for(int i=0; i<numOfGames; i++)
    {
        int tPos = cPos;
        char tmp = cSeeker;

        cPos = (cPos + numOfMovesPerGame[i] + 100*(numOfAllPlayers-1)) % (numOfAllPlayers-1);

        if(chk[Pos[cPos] - 'A'])
        {
            Num[cSeeker - 'A']++;
        }
        else
        {
            cSeeker = Pos[cPos];
            Num[cSeeker - 'A']++;

            Pos[cPos] = tmp;
        }
			
    }

    for(int i=0; i<numOfAllPlayers-1; i++)
    {
        cout<<Pos[i]<<' '<<Num[Pos[i] - 'A']<<"\n";
    }
	cout<<cSeeker<<' '<<Num[cSeeker - 'A']<<"\n";
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}