#include <iostream>
#include <queue>
using namespace std;

int N; 
char map[101][101];
char Cmmap[101][101];
bool vist[101][101];
bool cmvist[101][101];

int dir[4][2] = { {1,0}, {0,1}, {-1,0} ,{0,-1}};
int noCm =0;
int yesCm=0;
void noCm_BFS(int y, int x){
    queue <pair <int,int> > q;
    q.push( {y,x});
    vist[y][x] =true;
    char mycolor = map[y][x];

    while (!q.empty()){
        int curY = q.front().first; 
        int curX = q.front().second;
        q.pop();

        for(int k =0; k < 4 ;k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N || vist[nextY][nextX]) continue;
            if(mycolor == map[nextY][nextX]){
                vist[nextY][nextX] = true;
                q.push({nextY , nextX});
            }
        }
    }
}


void Cm_BFS(int y, int x){
    queue <pair <int,int> > q;
    q.push( {y,x});
    cmvist[y][x] =true;
    char mycolor = Cmmap[y][x];

    while (!q.empty()){
        int curY = q.front().first; 
        int curX = q.front().second;
        q.pop();

        for(int k =0; k < 4 ;k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N || cmvist[nextY][nextX]) continue;
            if(mycolor == Cmmap[nextY][nextX]){
                cmvist[nextY][nextX] = true;
                q.push({nextY , nextX});
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> map[i];
        for(int j = 0; j < N ;j++){
            if(map[i][j] == 'G'){
                Cmmap[i][j] = 'R';
            }
            else{
                Cmmap[i][j] = map[i][j];
            }
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ;j < N;j++){
            if(vist[i][j] == false){
                noCm_BFS(i,j);
                noCm++;
            }
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ;j < N;j++){
            if(cmvist[i][j] == false){
                Cm_BFS(i,j);
                yesCm++;
            }
        }
    }
    cout << noCm<<" "<< yesCm  <<endl;
    return 0;
}
