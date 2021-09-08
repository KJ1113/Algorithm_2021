#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N , M , ans;
int map[21][21];
int dir[4][2] ={ {1,0} , {0,1} , {-1,0} ,{0,-1}};
bool vist[21][21];

void find(int sy , int sx ){

    int size = 1; // 마름모의 크기
    int home_cnt = 0; // 집의 수
   
    for(int i = 0 ; i < N  ; i++){ // 초기화
        for(int j = 0 ; j < N ;j++){
            vist[i][j] = false;
        }
    }

    queue <pair<int,int> > q;
    q.push({sy,sx});
    vist[sy][sx] = true;
    if(map[sy][sx] == 1) home_cnt++;

    while (!q.empty()){

        size ++;
        int qsize = q.size();
        for(int s = 0 ; s < qsize ; s++){
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            for(int k = 0 ; k < 4; k++){
                int ny = cy + dir[k][0];
                int nx = cx + dir[k][1];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(vist[ny][nx]) continue;

                vist[ny][nx] = true;
                q.push({ny,nx});
                if(map[ny][nx] == 1) home_cnt++;
            }
        }

        // 각 사이즈 마다 집 갯수 체크 
        int cost =  (home_cnt*M) -  (size * size + (size - 1) * (size - 1)); 
        if(cost >= 0 ){ // 보안사가 손해를 보지 않는다면
            ans = max(ans , home_cnt);
        }
    }
}
int main(int argc, char** argv){
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        ans = 1;
        cin >> N >> M;

        for(int i = 0 ; i < N  ; i++){
            for(int j = 0 ; j < N ;j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0 ; i < N  ; i++){
            for(int j = 0 ; j < N ;j++){
                find(i,j);
            }
        }
        cout << "#" <<test_case <<" "<<ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}