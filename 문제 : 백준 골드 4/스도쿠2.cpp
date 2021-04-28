#include <iostream>
#include <vector>
using namespace std;
char map[9][9];
vector <pair<int,int> > list;
bool check(int y , int x , char checkNum){
    int checkY = (y/3) * 3 ;
    int checkX = (x/3) * 3 ;
    for(int i = 0 ; i < 9 ; i++){
        if( map[i][x] == checkNum ) return false;
    }
    for(int i = 0 ; i < 9 ; i++){
        if(map[y][i] == checkNum ) return false;
    }
    for(int i = checkY ; i < checkY + 3;i++){
        for(int j = checkX ; j < checkX + 3 ; j++){
            if( map[i][j] ==  checkNum) return false;
            
        }
    }
    return true;
}
void show(){
    for(int i = 0 ; i < 9;i++){
        for(int j = 0 ; j< 9 ; j++){
            cout<< map[i][j];
        }
        cout<<endl;
    }
}

void DFS(int idx ,int cnt ){
    if(cnt == list.size()){
        show();
        exit(0);
    }
    int y = list[idx].first;
    int x = list[idx].second;
    for(int n = 1 ; n <= 9 ; n++){
        if(check( y , x , to_string(n)[0] )){
            map[y][x] = to_string(n)[0];
            DFS(idx + 1 , cnt +1);
            map[y][x] = '0';
        }
    }
}
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0 ; i < 9;i++){
        cin >> map[i];
        for(int j = 0 ; j < 9 ; j++){
            if(map[i][j] == '0'){
                list.push_back( {i,j});
            }
        }
    }
    DFS(0,0);
    return 0;
}