#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , map[21][21];
int empty_map[21][21];
int fc_map[21][21];
bool vist[21][21];
int dir[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
vector < vector<int> > child;
void check_Friend(int child_idx){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++ ){
            int curY = i ;
            int curX = j ;
            int c_cnt = 0 , e_cnt = 0 ; // 인접친구들의수 , 비어있는 칸수
            if(map[i][j]==0) {
                vist[i][j] = true;
            }
            else {
                vist[i][j] = false;
                continue;
            }

            for(int k = 0 ; k < 4 ;k++){
                int nextY = curY + dir[k][0];
                int nextX = curX + dir[k][1];
                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
                if(map[nextY][nextX] == 0){
                    e_cnt++;
                    continue;
                }else{
                    for(int fn = 1; fn < 5; fn++){
                        int c_Friend =  child[child_idx][fn];
                        if(map[nextY][nextX] == c_Friend) {
                            c_cnt++;
                            break;
                        }
                    }
                }
            }
            empty_map[curY][curX] = e_cnt;
            fc_map[curY][curX] = c_cnt;
        }
    }
}
bool cmp(pair<int , pair <int,int > > A , pair<int , pair <int,int > > B){
    if(A.first == B.first){
        if(A.second.first == B.second.first){
            return A.second.second < B.second.second;
        }
        return A.second.first < B.second.first;
    }
    return A.first > B.first;
}
void get_pos(int num){
    vector<pair<int , pair <int,int > > > empty_list;
    int max_f = -1;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++ ){
            if(vist[i][j] == true) max_f = max(max_f,fc_map[i][j]);
        }
    }
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++ ){
            if(max_f == fc_map[i][j] && vist[i][j] == true){
                empty_list.push_back( { empty_map[i][j], {i,j}});
            }
        }
    }
    sort(empty_list.begin() , empty_list.end() , cmp);
    int posY = empty_list[0].second.first;
    int posX = empty_list[0].second.second;
    map[posY][posX] = num;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++ ){
            vist[i][j] = false;
            empty_map[i][j] = 0;
            fc_map[i][j] = 0;
        }
    }
}
int cal_point(){
    int sum = 0;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++ ){
            int num = map[i][j];
            int cnt = 0 ;
            for(int idx = 0 ;idx < child.size(); idx++){
                if(num == child[idx][0]){
                    int curY = i;
                    int curX = j;
                    
                    for(int k = 0 ; k<4;k++){
                        int nextY = curY + dir[k][0];
                        int nextX = curX + dir[k][1];
                        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;

                        for(int fn = 1; fn < 5; fn++){
                            if(child[idx][fn] == map[nextY][nextX]){
                                
                                cnt++;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        
            if(cnt == 0)sum += 0;
            else if(cnt == 1 )sum += 1;
            else if(cnt == 2) sum += 10;
            else if(cnt == 3) sum += 100;
            else sum += 1000;
        }
    }
    return sum;
}
void sol(){
    for(int idx = 0 ; idx < child.size() ;idx++){
        check_Friend(idx);
        get_pos(child[idx][0]);
    }
    cout << cal_point();
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N*N ;i++){
        int num , fa;
        vector <int> tmp;
        cin >> num;
        tmp.push_back(num);
        for(int j = 0 ; j < 4; j++){
            cin >> fa;
            tmp.push_back(fa);
        }
        child.push_back(tmp);
    }
    sol();
    return 0 ;
}