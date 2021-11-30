#include <iostream>
#include <vector>
using namespace std;
int N , M , K;
int dir[8][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

int fire_ball_cnt[51][51];
int fire_ball_s[51][51]; // 합쳐진 속도
int fire_ball_m[51][51]; // 합쳐진 질량
int fire_ball_dir[51][51][2]; // 합쳐지는 방향
bool new_fire_ball[51][51]; // 중복 체크

struct FireBall{
    int y , x , m , s, d;
};

vector<FireBall> f_list;
vector<FireBall> f_move_list;

int main(){
    cin >> N >> M >> K;
    for(int i = 0 ; i < M; i++){
        FireBall f;
        cin >> f.y >> f.x >> f.m >> f.s >> f.d;
        f.y --;
        f.x --;
        f_list.push_back(f);

        fire_ball_cnt[f.y][f.x]++;
        fire_ball_s[f.y][f.x] += f.s;
        fire_ball_m[f.y][f.x] += f.m;

        if(f.d %2 == 0) fire_ball_dir[f.y][f.x][0]++;
        else fire_ball_dir[f.y][f.x][1]++;
    }

    for(int k = 0 ; k < K ;k++){
        // 1. 이동
        f_move_list.clear(); // 이동할 위치를 저장할곳

        for(int idx = 0 ; idx < f_list.size(); idx++){

            FireBall f = f_list[idx];
            //cout << "이동전 : " << f.y << " " << f.x << f.d <<endl;
    
            fire_ball_cnt[f.y][f.x]--;
            fire_ball_s[f.y][f.x] -= f.s;
            fire_ball_m[f.y][f.x] -= f.m;

            if(f.d %2 == 0) fire_ball_dir[f.y][f.x][0]--;
            else fire_ball_dir[f.y][f.x][1]--;

            // 이동 시간 줄이는 공식
            f.y  = (f.y + (f.s * dir[f.d][0])) % N;
            f.x  = (f.x + (f.s * dir[f.d][1])) % N;

	    	if (f.y < 0) f.y += N;
		    if (f.x < 0) f.x += N;

            fire_ball_cnt[f.y][f.x]++;
            fire_ball_s[f.y][f.x] += f.s;
            fire_ball_m[f.y][f.x] += f.m;

            if(f.d %2 == 0) fire_ball_dir[f.y][f.x][0]++;
            else fire_ball_dir[f.y][f.x][1]++;
            
            if(new_fire_ball[f.y][f.x] ==false){
                new_fire_ball[f.y][f.x] = true;
                f_move_list.push_back(f);
            }
        }
        
        // 2. 조건에 따른 처리
        vector<FireBall> new_f_list;
        for(int idx = 0 ; idx < f_move_list.size(); idx++){
            FireBall f = f_move_list[idx];
            new_fire_ball[f.y][f.x] =false;

            if(fire_ball_cnt[f.y][f.x] == 1){
                new_f_list.push_back(f);
                continue;
            }

            int m = fire_ball_m[f.y][f.x]/5;
            int s = fire_ball_s[f.y][f.x]/fire_ball_cnt[f.y][f.x];
            
            FireBall new_f;
            int new_d;

            if(fire_ball_dir[f.y][f.x][0] == 0 || fire_ball_dir[f.y][f.x][1] == 0){
                new_d = 0;
            }else{
                new_d = 1;
            }

            fire_ball_m[f.y][f.x] = 0;
            fire_ball_s[f.y][f.x] = 0;
            fire_ball_cnt[f.y][f.x] = 0;
            fire_ball_dir[f.y][f.x][0] = 0;
            fire_ball_dir[f.y][f.x][1] = 0;

            new_f.y = f.y;
            new_f.x = f.x;
            new_f.s = s;
            new_f.m = m;

            if(m ==0) continue;

            for(int num = 0 ; num < 4 ; num++){
                new_f.d = new_d;
                fire_ball_cnt[f.y][f.x]++;
                fire_ball_s[f.y][f.x] += s;
                fire_ball_m[f.y][f.x] += m;

                if(new_d % 2 == 0) fire_ball_dir[f.y][f.x][0]++;
                else fire_ball_dir[f.y][f.x][1]++;

                new_f_list.push_back(new_f);
                new_d+=2;
            }
        }
        f_list = new_f_list;
    }

    int res = 0; 
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ;j++){
            res += fire_ball_m[i][j];
        }
    }
    cout << res;
    return 0;
}