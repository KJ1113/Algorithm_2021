#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 87654321;
int N  , max_on_cnt , min_line_sum; // 최대 코어수 , 최소 라인수
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int map[22][22];
vector< pair<int,int> > x_list; // 엑시노스 위치

void DFS(int index , int line_sum , int on_cnt){

    if( max_on_cnt <= on_cnt){ // 코어 수가 갱신된다면..?
        if(max_on_cnt == on_cnt){ // 똑같이 max 코어 갯수면 최소값만 갱신 한다. 
            min_line_sum = min(min_line_sum , line_sum);
        }else{
            max_on_cnt = on_cnt;
            min_line_sum = line_sum;
        }  
    }

    for(int i = index ;  i < x_list.size() ; i++){
        
        int cy = x_list[i].first;
        int cx = x_list[i].second;
        //cout << cy <<endl;
        for(int k = 0 ; k < 4 ; k++){
            vector< pair<int,int> > line_list; 
            bool on = false; // 전선이 코어에 닿는지 체크
            int cnt = 0; // 선길이
            int ny = cy;
            int nx = cx;

            while (true){ // 선 연결
                ny = ny + dir[k][0];
                nx = nx + dir[k][1];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N){ on = true; break;} // 선이 연결된다면
                if(map[ny][nx] == 1 || map[ny][nx] == 2) break; // 선이 겹치면 X
                
                cnt++;
                map[ny][nx] = 2;
                line_list.push_back({ny,nx});
            }

            if(on)  DFS(i+1 , line_sum + cnt , on_cnt+1);

            for(int idx = 0 ; idx < line_list.size() ;idx++){ // 원래대로
                map[line_list[idx].first][line_list[idx].second] = 0;
            }
        }
    }
}
int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        max_on_cnt = -1;
        min_line_sum = INF;
        x_list.clear();

        cin >> N;
        for(int i = 0 ; i < N ; i++){
            for(int j =0; j < N ;j++){
                cin >> map[i][j];
                if(i == 0 || j == 0 || i == N-1 || j == N-1 || map[i][j] == 0) continue;
                x_list.push_back({ i, j});
            }
        }
        DFS(0,0,0);
        cout << "#"<<test_case <<" "<<min_line_sum<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}