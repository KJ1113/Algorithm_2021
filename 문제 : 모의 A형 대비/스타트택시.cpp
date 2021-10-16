#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 98765432;
int N , M , L ;
int cY , cX ;
int map[21][21];
int tmp_map[21][21];
bool vist[21][21];
int dir[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
vector < pair <pair<int,int> , pair <int,int> > > people_list;
void init(){
    for(int i =0; i < N ;i++){
        for(int j = 0 ; j < N; j++){
            tmp_map[i][j] = INF;
            if(tmp_map[i][j] == 1) {
                vist[i][j] = true;
            }else{
                vist[i][j] = false;
            }
        }
    }
}
void show(){
    for(int i =0; i < N ;i++){
        for(int j = 0 ; j < N; j++){
            if(tmp_map[i][j] != INF) cout << tmp_map[i][j] <<" ";
            else cout << "I ";
        }
        cout <<endl;
    }
    cout <<endl;
}
int main(){
    cin >> N >> M >> L;
    for(int i =0; i < N ;i++){
        for(int j = 0 ; j < N; j++){
            cin >> map[i][j];
        }
    }
    cin >> cY >> cX;
    cY--;
    cX--;

    for(int i =0 ; i < M ; i++){
        int a , b, c, d;
        cin >> a >> b >> c >> d;
        people_list.push_back({ {a-1,b-1} , {c-1,d-1} });
    }

    bool flag = true;
    while (true){
        
        init();
        int cnt = 0;
        queue< pair<int,int> > q;
        q.push({cY, cX});
        vist[cY][cX]= true;
        tmp_map[cY][cX] =0;
        while (!q.empty()){
            int qsize = q.size();
            cnt++;
            for(int qs = 0 ; qs < qsize; qs ++){
                int cY = q.front().first;
                int cX = q.front().second;
                q.pop();

                for(int k = 0 ; k < 4;k++){
                    int nY = cY + dir[k][0];
                    int nX = cX + dir[k][1];

                    if(map[nY][nX] == 1 || vist[nY][nX]) continue;
                    if(nY < 0 || nX < 0 || nY >= N || nX >= N) continue;
                    tmp_map[nY][nX] = cnt; 
                    vist[nY][nX] = true;
                    q.push({nY,nX});
                }
            }
        }
        //cout << cY << cX <<endl;
        //cout << "택시 -> 승객" <<endl;
        //show();

        int min_length = INF; // 최소거리
        int sY , sX , eY ,eX;
        int del_index = -1;
        for(int index = 0 ; index < people_list.size(); index++){
            int y = people_list[index].first.first;
            int x = people_list[index].first.second;
            if( min_length >= tmp_map[y][x]){
                if(min_length == tmp_map[y][x]){
                    if(y < sY ){
                        sY = y;
                        sX = x;
                        eY = people_list[index].second.first;
                        eX = people_list[index].second.second;
                        min_length = tmp_map[y][x];
                        del_index = index;
                    }else{
                        if(y == sY && x < sX){
                            sY = y;
                            sX = x;
                            eY = people_list[index].second.first;
                            eX = people_list[index].second.second;
                            min_length = tmp_map[y][x];
                            del_index = index;
                        }
                    }
                }else{
                    sY = y;
                    sX = x;
                    eY = people_list[index].second.first;
                    eX = people_list[index].second.second;
                    min_length = tmp_map[y][x];
                    del_index = index;
                }
            }
        }

        if(L - min_length < 0 || del_index == -1 ) {
            flag = false;
            break;
        }
        
        init();
        q.push({sY, sX});
        cnt = 0;
        vist[sY][sX]= true;
        tmp_map[cY][cX] =0;
        while (!q.empty()){
            int qsize = q.size();
            cnt++;
            for(int qs = 0 ; qs < qsize; qs ++){
                int cY = q.front().first;
                int cX = q.front().second;
                q.pop();
                for(int k = 0 ; k < 4;k++){
                    int nY = cY + dir[k][0];
                    int nX = cX + dir[k][1];
                    if(map[nY][nX] == 1 || vist[nY][nX]) continue;
                    if(nY < 0 || nX < 0 || nY >= N || nX >= N) continue;

                    tmp_map[nY][nX] = cnt; 
                    vist[nY][nX] = true;
                    q.push({nY,nX});
                }
            }
        }
        //cout <<  "승객 -> 도착지" <<endl;
        //show();

        vector < pair <pair<int,int> , pair <int,int> > > tmp_people_list;
        if(L - min_length - tmp_map[eY][eX] < 0 || tmp_map[eY][eX]  == INF ) {
            flag = false;
            break;
        }else{
            for(int index = 0 ; index < people_list.size(); index++){
                if(index != del_index) tmp_people_list.push_back(people_list[index]);
            }

            L = L - min_length + tmp_map[eY][eX];
            people_list = tmp_people_list;
            cY = eY;
            cX = eX;
        }
        if(people_list.size() == 0 ) break;
    }

    if(flag) cout << L ;
    else cout << -1;
    
    return 0;
}