#include <iostream>
#include <queue>
using namespace std;
int N , M;
int map[101][101];
int dir[4][2] = { {1,0}, {0,1} ,{-1,0} ,{0,-1}};
bool vist[101][101];

vector <pair <int,int> > del_list;
vector <pair <int,int> > c_list;
void init(){
    for(int i = 0 ; i < N ; i++){
        for(int j =0; j < M ;j++){
            vist[i][j] = false;
        }
    }
}
void del(){
    for(int i = 0; i < del_list.size() ;i++){
        int cY = del_list[i].first;
        int cX = del_list[i].second;
        map[cY][cX] = 0;
    }
    del_list.clear();
}
void make_del(){
    vector <pair <int,int> > tmp_list;
    for(int i = 0; i < c_list.size() ;i++){
        int cY = c_list[i].first;
        int cX = c_list[i].second;

        if(map[cY][cX] == 1){
            int airNum = 0;
            for(int k =0; k < 4 ;k++){
                int nY = cY + dir[k][0];
                int nX = cX + dir[k][1];
                if(nY < 0 || nX < 0 || nY >= N || nX >= M || map[nY][nX] == 1) continue; 

                if(map[nY][nX] == 0 && vist[nY][nX] == true ){
                    airNum++;
                }
            }

            if(airNum >= 2){
                del_list.push_back({cY,cX});
            }else{
                tmp_list.push_back({cY,cX});
            }
        }
        else{
            tmp_list.push_back({cY,cX});
        }
    }
    c_list.clear();
    c_list = tmp_list;
}
void BFS(int y , int x){
    queue <pair <int, int> > q;
    q.push( { y,x});
    vist[y][x] = true;

    while (!q.empty()){
        int cY = q.front().first;
        int cX = q.front().second;
        q.pop();

        for(int k =0; k < 4 ;k++){
            int nY = cY + dir[k][0];
            int nX = cX + dir[k][1];
            if(nY < 0 || nX < 0 || nY >= N || nX >= M || vist[nY][nX] || map[nY][nX] == 1 ) continue; 

            if(map[nY][nX] == 0 ){
                q.push( { nY,nX});
                vist[nY][nX] = true;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j =0; j < M ;j++){
            cin >> map[i][j];
            if(map[i][j] == 1) {
                c_list.push_back({i,j});
            }
        }
    }

    int time = 0 ;
    while (true){
        BFS(0,0);
        make_del();

        if(del_list.size() == 0 ){
            cout << time;
            break;
        }
        time++;
        del();
        init();
    }
    return 0;
}