#include <iostream>
#include <queue>
using namespace std;

int N , M , K;
int dir[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}}; // 동 서 남 북
int map[22][22];
int memoMap[22][22];

int res = 0 ;
int diceY = 0 , diceX = 0;
int curDir = 1;
int dice[7] = {0, 6, 5, 1 , 2, 4, 3};

void moveDice(int dir){
    int tmpDice[7] = {0,0,0,0,0,0,0};
    if(dir == 1){ // 동

        tmpDice[1] = dice[6];
        tmpDice[2] = dice[2];
        tmpDice[3] = dice[5];

        tmpDice[4] = dice[4];
        tmpDice[5] = dice[1];
        tmpDice[6] = dice[3];

    }else if(dir == 2){ // 서
        tmpDice[1] = dice[5];
        tmpDice[2] = dice[2];
        tmpDice[3] = dice[6];

        tmpDice[4] = dice[4];
        tmpDice[5] = dice[3];
        tmpDice[6] = dice[1];

    }else if(dir == 3){ // 남
        tmpDice[1] = dice[2];
        tmpDice[2] = dice[3];
        tmpDice[3] = dice[4];

        tmpDice[4] = dice[1];
        tmpDice[5] = dice[5];
        tmpDice[6] = dice[6];

    }else{
        tmpDice[1] = dice[4];
        tmpDice[2] = dice[1];
        tmpDice[3] = dice[2];

        tmpDice[4] = dice[3];
        tmpDice[5] = dice[5];
        tmpDice[6] = dice[6];
    }

    for(int num = 1; num <= 6; num++){
        dice[num] = tmpDice[num];
    }
}
int BFS(int y , int x){
    int sum = map[y][x];
    bool vist[22][22]; 
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j< M ;j++){
            vist[i][j] = false;
        }
    }

    queue<pair<int,int> > q;
    queue<pair<int,int> > sum_list;
    vist[y][x] =true;
    sum_list.push({y,x});
    q.push({y,x});

    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int k = 1; k <= 4; k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
        
            if( nextY < 0 || nextX < 0 || nextY >= N || nextX >= M ||vist[nextY][nextX] == true) continue;
            if(map[nextY][nextX] != map[y][x]) continue;
            vist[nextY][nextX] = true;
            q.push({nextY,nextX});

            sum_list.push({nextY,nextX});
            sum += map[nextY][nextX];
        }
    }

    while (!sum_list.empty()){
        int curY = sum_list.front().first;
        int curX = sum_list.front().second;
        sum_list.pop();
        memoMap[curY][curX] = sum;
    }
    return sum;
}
int main(){
    cin >> N  >> M >> K;
    for(int i = 0 ; i < N ;i++){
        for(int j =0 ;j < M ;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0 ; i < K ;i++){
        // 1 이동
        moveDice(curDir);
        diceY = diceY + dir[curDir][0];
        diceX = diceX + dir[curDir][1];
        
        //2. 합 구하기
        if(memoMap[diceY][diceX] == 0){
            memoMap[diceY][diceX] = BFS(diceY,diceX);
        }
        res += memoMap[diceY][diceX];

        // 3. 이동방향 정하기
        int A = dice[1];
        int B = map[diceY][diceX];

        if(A > B ){
            if(curDir == 1) curDir = 3;
            else if(curDir == 2) curDir = 4;
            else if(curDir == 3) curDir = 2;
            else if(curDir == 4) curDir = 1;
        }else if(A < B){
            if(curDir == 1) curDir = 4;
            else if(curDir == 2) curDir = 3;
            else if(curDir == 3) curDir = 1;
            else if(curDir == 4) curDir = 2;
        }else{
            curDir = curDir;
        }

        int nextY = diceY + dir[curDir][0];
        int nextX = diceX + dir[curDir][1];

        if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= M ){ // 갈수없다면 반대 방향으로
            if(curDir == 1) curDir = 2;
            else if(curDir == 2) curDir = 1;
            else if(curDir == 3) curDir = 4;
            else if(curDir == 4) curDir = 3;
        }
    }
    cout << res << endl;
    return 0;
}