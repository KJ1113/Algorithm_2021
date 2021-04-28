#include <iostream>
#include <vector> 
using namespace std;
int map[10][10];
vector <pair<int,int> > node_list;
void show(){
    for(int i = 0 ; i < 9;i ++){
        for(int j =0; j < 9 ;j++){
            cout << map[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool check(int Y , int X){
    int cY = (Y/3) * 3;
    int cX = (X/3) * 3;
    for(int i = 0 ; i < 9 ;i++){
        if(X == i) continue;
        if(map[Y][i] == map[Y][X]) return false; 
    }
    for(int i = 0 ; i < 9 ;i++){
        if(Y == i) continue;
        if(map[i][X] == map[Y][X]) return false; 
    }
    for(int i = cY ; i< cY+3 ; i++){
        for(int j = cX ; j < cX+3 ; j++ ){
            if( (Y == i && X == j) ) continue;
            if(map[i][j] == map[Y][X]) return false; 
        }
    }
    return true;
}
void DFS( int idx ,int cnt){
    if(cnt == node_list.size()){
        show();
        exit(0);
    }
    else{
        int Y = node_list[idx].first;
        int X = node_list[idx].second;
        
        for(int i = 1 ; i <= 9 ; i++){
            map[Y][X] = i;
            if( check (Y ,X )) DFS(idx + 1 , cnt + 1);
            map[Y][X] = 0;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0 ; i < 9;i ++){
        for(int j =0; j < 9 ;j++){
            cin >> map[i][j];
            if(map[i][j] == 0) node_list.push_back({i,j});
        }
    }
    DFS(0,0);
    return 0;
}