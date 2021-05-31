#include <iostream>
#include <vector>
using namespace std;
int N;
int inputY , inputX , inputT; 
int map[10][10];
int Tcnt ,point = 0; 

void show(){
    for(int i = 0 ; i < 10 ;i ++){
        for(int j = 0 ; j < 10 ;j++){
            if(j >= 4 && i >= 4){
                cout <<  "  ";
            }else{
                cout << map[i][j] << " ";
            }
        }
        cout <<endl;
    }
    cout <<endl;
}
void move(vector< pair<int,int> > &mlist){

    if(inputT == 1){
        for(int idx = 0 ; idx < mlist.size(); idx++){
            int curX = mlist[idx].second;
            int curY = mlist[idx].first;
            // 빨간색으로 이동
            bool greenflag =false;
            for(int nY = 5 ; nY < 10; nY++){
                if(map[nY][curX] == 1){
                    map[nY-1][curX] = 1;
                    greenflag = true;
                    break;
                }
            }
            if(greenflag == false)  map[9][curX] = 1;
            // 파랑색으로 이동
            bool blueflag =false;
            for(int nX = 5 ; nX < 10; nX++){
                if(map[curY][nX] == 1){
                    map[curY][nX-1] = 1;
                    blueflag = true;
                    break;
                }
            }
            if(blueflag==false)  map[curY][9] = 1;
        }
    }else if(inputT == 2){
        int curX = mlist[1].second;
        int curY = mlist[1].first;
        bool greenflag =false;
        for(int nY = 5 ; nY < 10; nY++){
            if(map[nY][curX-1] == 1 || map[nY][curX] == 1){
                map[nY-1][curX-1] = 1;
                map[nY-1][curX] = 1;
                greenflag = true;
                break;
            }
        }
        if(greenflag == false){
            map[9][curX-1] = 1;
            map[9][curX] = 1;
        }

        bool blueflag =false;
        for(int nX = 6 ; nX < 10; nX++){
            if(map[curY][nX] == 1) {
                map[curY][nX-2] = 1;
                map[curY][nX-1] = 1;
                blueflag = true;
                break;
            }
        }
        if(blueflag == false){
            map[curY][8] = 1;
            map[curY][9] = 1;
        }
    }else{
        int curX = mlist[1].second;
        int curY = mlist[1].first;
        bool greenflag =false;
        for(int nY = 5 ; nY < 10; nY++){
            if(map[nY][curX] == 1){
                map[nY-1][curX] = 1;
                map[nY-2][curX] = 1;
                greenflag = true;
                break;
            }
        }
        if(greenflag == false){
            map[8][curX] = 1;
            map[9][curX] = 1;
        }

        bool blueflag =false;
        for(int nX = 5 ; nX < 10; nX++){
            if(map[curY][nX] == 1 || map[curY-1][nX] == 1) {
                map[curY-1][nX-1] = 1;
                map[curY][nX-1] = 1;
                blueflag = true;
                break;
            }
        }
        if(blueflag == false){
            map[curY-1][9] = 1;
            map[curY][9] = 1;
        }
    }
}
void red_init(vector< pair<int,int> > &mlist){
    for(int idx = 0 ; idx < mlist.size() ;idx++){
        map[mlist[idx].first][mlist[idx].second] = 0;
    }
}
void del_map(){
    // 아래
    for(int i = 6 ; i < 10 ;i++){
        int cnt = 0 ;
        for(int j =0; j < 4 ;j++){
            if(map[i][j] == 1) cnt ++;
        }
        if(cnt == 4){
            point ++;
            for(int j =0; j < 4 ;j++){
                map[i][j] = 0;
            }

            for(int ri = i-1; ri >= 4; ri--){
                for(int j =0; j < 4 ;j++){
                    map[ri+1][j] = map[ri][j];
                }
            }
        }
    }
    
    for(int i = 6 ; i < 10 ;i++){
        int cnt = 0 ;
        for(int j =0; j < 4 ;j++){
            if(map[j][i] == 1) cnt ++;
        }
        if(cnt == 4){
            point ++;
            for(int j =0; j < 4 ;j++){
                map[j][i] = 0;
            }
            for(int ri = i-1 ; ri >= 4; ri--){
                for(int j =0; j < 4 ;j++){
                    map[j][ri+1] = map[j][ri];
                }
            }
        }
    }
}
void checkPlace(){
    // 옆
    while (true){
        bool flag = true;
        for(int i = 0 ; i < 4 ;i++){
            for(int j = 4; j < 6 ; j++){
                if(map[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            break;
        }else{
            for(int i = 9 ; i >= 4 ;i--){
                for(int j = 0; j < 4 ; j++){
                    map[j][i] = map[j][i-1];
                }
            }

        }
    }

    // 아래 
    while (true){
        bool flag = true;
        for(int i = 4 ; i < 6 ;i++){
            for(int j = 0; j < 4 ; j++){
                if(map[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            break;
        }else{
            for(int i = 9 ; i >= 4 ;i--){
                for(int j = 0; j < 4 ; j++){
                    map[i][j] = map[i-1][j];
                }
            }
        }
    } 
}
void checkMap(){
    for(int i = 0 ; i < 10 ;i ++){
        for(int j = 0 ; j < 10 ;j++){
            if(map[i][j] ==1){
                Tcnt ++;
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        cin >> inputT >> inputY >> inputX;
        vector< pair<int,int> > mlist;
        mlist.push_back({inputY,inputX});
        if(inputT == 2){
            mlist.push_back({inputY,inputX+1});
        }else if(inputT == 3){
            mlist.push_back({inputY+1,inputX});
        }
        move(mlist); 
        del_map();
        checkPlace();
    }
    checkMap();
    cout << point << endl;
    cout << Tcnt << endl;
    return 0 ;
}