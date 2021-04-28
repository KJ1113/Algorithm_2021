#include <iostream>
using namespace std;
int N ;
double res =0;
double prob[4];
int dir [4][2] = {{0,1} ,{0,-1}, {1,0}, {-1,0}}; // 동 서 남 북
int map[255][255];
void DFS(int cnt , int curY , int curX , double Probability){
    //cout << Probability<<endl;
    if(cnt == N){
        res += Probability;
        return;
    }
    for(int k = 0; k < 4 ;k++){
        int nextY = curY + dir[k][0];
        int nextX = curX + dir[k][1];
        if(map[nextY][nextX]) continue;
        map[nextY][nextX] = 1;
        DFS(cnt+1 , nextY, nextX , prob[k] * Probability);
        map[nextY][nextX] = 0;
    }
}
int main(){
    cin >> N;
    for(int i = 0 ; i < 4 ;i++){
        cin >> prob[i];
        prob[i] = prob[i] * 0.01;
    }
    map[15][15] = 1;
    DFS(0, 15,15,1);
    cout.precision(10);
    cout << fixed << res << endl;
    return 0;
}