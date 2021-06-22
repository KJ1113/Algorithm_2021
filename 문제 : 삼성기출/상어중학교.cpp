#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N , M ;
int map[21][21];
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}};
bool vist[21][21];
vector< vector<pair<int,int> > > g_list;
bool cmp(vector<pair<int,int> > A  , vector<pair<int,int> > B){
    if( A.size() == B.size()){
        return A[0].first > B[0].first;
        if(A[0].first == B[0].first){
            return A[0].second > B[0].second;
        }
    }
    return A.size() > B.size();
}
void init(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ;j++){
            vist[i][j] = false;
        }
    }
}
void findGroup(int Y , int X){
    queue< pair<int,int> > q;
    vector< pair<int,int> > g;
    int curC = map[Y][X];
    q.push({Y,X});
    g.push_back({Y,X});
    vist[Y][X] = true;
    
    while (q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int k = 0 ; k < 4 ;k++){
            int nextY = curY + dir[k][0];
            int nextX = curX + dir[k][1];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || vist[nextY][nextX]) continue;
            if(map[nextY][nextX] == curC || map[nextY][nextX] == 0){
                g.push_back({nextY, nextX});
                q.push({nextY, nextX});
                vist[nextY][nextX] = true;
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ;j++){
            if(map[i][j] == 0 ) vist[i][j] = false;
        }
    }

    if(g.size() >= 2){
        g_list.push_back(g);
    }
}
int main(){
    cin >> N >> M;
    for(int i  =0 ; i < N ;i++){
        for(int j =0; j < N ;j++){
            cin >> map[i][j];
        }
    }

    while(true){
        init();
        g_list.clear();
        for(int i = 0 ; i < N ; i++){
            for(int j = 0; j < N ;j++){
                if(vist[i][j] == false && map[i][j] != -1 && map[i][j] != 0) {
                    findGroup(i,j);
                }
            }
        }
        sort(g_list.begin(), g_list.end() , cmp);
        cout << g_list[0].size() <<endl;
        break;
    }

    return 0;
}