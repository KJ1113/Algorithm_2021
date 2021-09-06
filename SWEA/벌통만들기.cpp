#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , M , C; // 벌통의 갯수 , 최대 채취 양
int map[11][11];
bool vist[11][11];
bool v_vist[6];
int res = -1 , ans = -1 ;
void choice(int idx ,int cnt , int max_cnt ,vector<pair<int,int> > &v ){
    if(max_cnt == cnt){
        int sum = 0;
        int pow_res = 0;
        for(int i = 0 ; i < v.size() ;i++){
            if(v_vist[i]){
                sum += map[v[i].first][v[i].second];
                pow_res += map[v[i].first][v[i].second] * map[v[i].first][v[i].second];
            }
        }
        if(sum <= C){
            res = max(res ,pow_res );
        }
    }else{
        for(int i = idx; i < v.size(); i++){
            if(v_vist[i]) continue;
            v_vist[i] = true;
            choice(i +1 , cnt+1 , max_cnt , v);  
            v_vist[i] = false;
        }
    }
}
void DFS(int cnt , vector<pair<int,int> > &v){
    if(cnt == 2){
        int sum_res = 0;
        for(int idx = 0 ; idx < v.size() ;idx++){
            vector<pair<int,int> > v2;
            res = -1;
            int y = v[idx].first;
            int x = v[idx].second;
            for(int c = 0 ; c < M ;c++){
                v2.push_back({ y ,x+c });
            }
            for(int max_cnt = 1 ; max_cnt <= M ; max_cnt++){
                choice(0,0,max_cnt,v2);
            }
            sum_res+=res;
        }
        ans = max(ans , sum_res);
    }else{
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < N ; j ++){
                bool ok = true;

                for(int x = j ; x < j + M ;x++){
                    if(x >= N || vist[i][x] ) {
                        ok = false;
                        break;
                    }
                }

                if(ok == false) continue;

                for(int x = j ; x < j + M ;x++){
                    vist[i][x] = true;
                }
                v.push_back({i,j});
                DFS(cnt+1 , v);
                v.pop_back();

                for(int x = j ; x < j + M ;x++){
                    vist[i][x] = false;
                }
            }
        }
    }
}
int main(int argc, char** argv){
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        ans = -1;
        cin >> N >> M >> C ;
        for(int i = 0 ; i < N ; i ++){
            for(int j = 0 ; j < N ; j ++){
                cin >> map[i][j];
            }
        }
        vector<pair<int,int> > v ;
        DFS(0,v );
        cout << "#" << test_case<<" " <<ans <<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}