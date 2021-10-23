#include <iostream>
#include <vector>
using namespace std;
int N , M , ans = 0 ;
int map[51][51];
int dir [9][2] = { {0,0} ,{0,-1},{-1,-1},{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1} };
bool make_c[51][51];
vector< pair<int,int> > list;
void move( int move_d , int move_s){

    for(int index = 0 ; index < list.size(); index++){
        int cY = list[index].first;
        int cX = list[index].second;

        int nY = cY + (dir[move_d][0] * (move_s%N));
        int nX = cX + (dir[move_d][1] * (move_s%N));

        if(nY < 0) nY += N;
        if(nY >= N) nY -= N;
        if(nX < 0) nX += N;
        if(nX >= N) nX -= N;

        list[index].first = nY;
        list[index].second = nX;
        map[nY][nX] ++;
        make_c[nY][nX] = true;
    }

    vector< pair< pair<int,int>  , int > > sum_list;
    for(int index = 0 ; index < list.size(); index++){
        int cY = list[index].first;
        int cX = list[index].second;
        int cdir = 2;
        int sum =0 ;

        for(int k = 0 ; k < 4 ; k++){
            int nY = cY + dir[cdir][0];
            int nX = cX + dir[cdir][1];
            cdir += 2;
            if(nY < 0 || nX < 0 || nY >= N || nX >= N) continue;
            if(map[nY][nX] > 0 ) sum++;

        }
        sum_list.push_back({ { cY, cX } ,sum });
    }

    for(int i = 0 ; i < sum_list.size() ;i++){
        int y = sum_list[i].first.first;
        int x = sum_list[i].first.second;
        map[y][x] += sum_list[i].second;
    }

    vector< pair<int,int> > tmp_list;
    for(int i = 0 ; i < N;i++){
        for(int j = 0 ; j < N ; j++){
            if(make_c[i][j] == false){
                if(map[i][j] >= 2 ){
                    map[i][j] -= 2;
                    tmp_list.push_back({i,j});
                }
            }else{
                make_c[i][j] = false;
            }
        }
    }
    list = tmp_list;
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N;i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }

    list.push_back({N-1,1});
    list.push_back({N-2,1});
    list.push_back({N-1,0});
    list.push_back({N-2,0});

    for(int i = 0 ; i < M ;i++){
        int move_d , move_s;
        cin >> move_d >> move_s;
        move(move_d , move_s);
    }

    for(int i = 0 ; i < N;i++){
        for(int j = 0 ; j < N ; j++){
            ans += map[i][j];
        }
    }
    cout << ans ;
    return 0;
}