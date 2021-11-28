#include <iostream>
#include <queue>
using namespace std;
int N ;
int map[21][21];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0}} ;
void show(){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            cout << map[i][j] <<" ";
        }
        cout <<endl;
    }
}
void makeMap(){
    queue< pair< pair<int,int> , int > > q;
    q.push({ {0,0},0} );
    q.push({ {0,N-1},1} );
    q.push({ {N-1,N-1},2} );
    q.push({ {N-1,0},3} );

    int cnt = 0;
    while (!q.empty()) {
        cnt ++;
        int qsize = q.size();
        for(int qs = 0 ; qs < qsize; qs++){
            
            int cy = q.front().first.first;
            int cx = q.front().first.second;
            int cd = q.front().second;
            q.pop();
            
            map[cy][cx] = cnt;
            //cout << cy << " "<<cx <<endl;

            int ny = cy + dir[cd][0];
            int nx = cx + dir[cd][1];
            int nd = cd;

            if(map[ny][nx] != 0){
                nd++;
                if(nd == 4){
                    nd = 0;
                }
                ny = cy + dir[nd][0];
                nx = cx + dir[nd][1];
            }

            if(ny == N/2 && nx == N/2){
                continue;
            }else{
                q.push({{ny,nx} ,nd});
            }
        }
        show();
        cout <<endl;
    }
}

int main(){
    show();
    cin >> N;
    makeMap();
    
    return 0;
}