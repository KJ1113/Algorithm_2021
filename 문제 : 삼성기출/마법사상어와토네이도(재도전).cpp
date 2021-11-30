#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int dir[4][2] ={ {0,1},{1,0},{0,-1} ,{-1,0}};
int move_dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int dir_map[501][501];
int send_map[501][501];
int move_map[501][501];
vector< pair <int,int> > pos;

int up_ratio[9][3] ={ {-2,0,5}, {-1,-1,10}, {-1,1,10},{0,-2,2},{0,-1,7}, {0,1,7},{0,2,2}, {1,-1,1},{1,1,1}};
int down_ratio[9][3] ={ {2,0,5}, {-1,-1,1}, {-1,1,1},{0,-2,2},{0,-1,7}, {0,1,7},{0,2,2}, {1,-1,10},{1,1,10}};
int left_ratio[9][3] ={ {0,-2, 5},{-1,-1,10},{-1,0,7},{-1,1,1},{-2,0,2} , {1,-1,10},{1,0,7},{1,1,1},{2,0,2}};
int right_ratio[9][3] ={ {0,2, 5},{-1,-1,1},{-1,0,7},{-1,1,10},{-2,0,2} , {1,-1,1},{1,0,7},{1,1,10},{2,0,2}};


void makeMap(){

    int mdir = 0;
    int number = N*N;
    int mY = 0;
    int mX = 0;
    while (true){
        if(number ==0) break;
        move_map[mY][mX] = number;
        dir_map[mY][mX] = mdir;
        

        int nextY = mY + dir[mdir][0];
        int nextX = mX + dir[mdir][1];

        if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N || move_map[nextY][nextX] != 0 ) {
            mdir ++;
            if(mdir == 4) mdir =0;
        }
        mY= mY + dir[mdir][0];
        mX= mX + dir[mdir][1];

        pos.push_back({mY,mX});
        number--;
    }  
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ;j++){
            cin >> send_map[i][j];
        }
    }

    makeMap();
    cout <<endl;

    int res = 0;

    for(int i = pos.size()-2; i >= 0 ; i--){ //(0,1) 까지
        int k = dir_map[pos[i].first][pos[i].second];
        int nY = pos[i].first + move_dir[k][0];
        int nX = pos[i].second + move_dir[k][1];

        cout << pos[i].first << " "<<pos[i].second << " "<< k <<endl;
        // cout << nY << " "<<nX << " "<< k <<endl;
        // cout <<endl;

        int sum = 0; 
        for(int d = 0 ; d < 9; d++){
            int nnY = 0;
            int nnX = 0;
            int ratio = 0;

            if(k == 0){ // 왼
                nnY = nY + left_ratio[d][0];
                nnX = nX + left_ratio[d][1];
                ratio = left_ratio[d][2] ;

            }else if(k == 1){ // 위
                nnY = nY + up_ratio[d][0];
                nnX = nX + up_ratio[d][1];
                ratio = up_ratio[d][2];

            }else if(k == 2){ // 오
                nnY = nY + right_ratio[d][0];
                nnX = nX + right_ratio[d][1];
                ratio = up_ratio[d][2];

            }else{ // 아래
                nnY = nY + down_ratio[d][0];
                nnX = nX + down_ratio[d][1];
                ratio = down_ratio[d][2];
            }

            int tmp = ratio * send_map[nY][nX] / 100;
            sum += tmp;

            if(nnY < 0 || nnX < 0 || nnY >= N || nnX >= N){ // 밖으로 나감
                res += tmp;
            }else{
                send_map[nnY][nnX] += tmp;
            }
        }

        int nnY = 0;
        int nnX = 0;

        if(k == 0){ // 왼
            nnY = nY + 0;
            nnX = nX + -1;

        }else if(k == 1){ // 위
            nnY = nY + -1;
            nnX = nX + 0;

        }else if(k == 2){ // 오
            nnY = nY + 0;
            nnX = nX + 1;

        }else{ // 아래
            nnY = nY + 1;
            nnX = nX + 0;
        }

        if(nnY < 0 || nnX < 0 || nnY >= N || nnX >= N){ // 밖으로 나감
            res += (send_map[nY][nX] - sum);
        }else{
            send_map[nnY][nnX] += send_map[nY][nX] - sum;
        }
        send_map[nY][nX] = 0;

        

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ;j++){
                cout<< send_map[i][j]<<" ";
            }
            cout << endl;
        }
        cout << nnY << " "<<nnX <<endl;
        cout<< res<< endl;
        cout<< endl;
    }

    cout << res ;




    return 0;
}