#include <iostream>
#include <vector>
using namespace std;
int N , ans = 0;
int board[15]; // 어차피 한행에서 하나의 퀸만 둘수있다. 2차원 배열이 필요없음.
bool check(int curY ){
    for(int y = 0; y < curY ; y++){
        if(board[y] == board[curY] || curY - y == abs(board[curY] - board[y])) return false;
        // 같은열  || 같은 대각선 이면 안된다.
    }
    return true;
}
void DFS(int Y  , int cnt ){
    if(cnt == N){
        ans ++;
        return;
    }
    else{
        for(int x = 0; x < N ; x++){
            board[Y] = x;
            if(check(Y)){
                DFS(Y+1 ,cnt+1);
            }
        }
    }
}
int main(){
    cin >> N;
    DFS(0,0);
    cout << ans;
    return 0;
}