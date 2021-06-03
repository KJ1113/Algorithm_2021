#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N , M , K;
int m_map[51][51];
int s_map[51][51];
int cnt_map[51][51];
int Dnum_map[51][51][2];
int ans = 0;
int dir[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
struct Fireball{
    int Y , X ;
    int m , d , s; // 질량 , 방향 , 속력
};
vector <Fireball> fireBall_list;
void move(){
    for(int idx = 0 ; idx < fireBall_list.size(); idx++){
        int curY = fireBall_list[idx].Y;
        int curX = fireBall_list[idx].X;
        int curM = fireBall_list[idx].m;
        int curS = fireBall_list[idx].s;
        int curD = fireBall_list[idx].d;
       
        m_map[curY][curX] -= curM;
        s_map[curY][curX] -= curS;
        Dnum_map[curY][curX][curD%2] --; // 짝수면 0 홀수면 1
        cnt_map[curY][curX]--;

        int nextY = curY + dir[curD][0] * (curS % N);
        int nextX = curX + dir[curD][1] * (curS % N);
        if (nextY >= N) nextY -= N;
		if (nextX >= N) nextX -= N;
		if (nextY < 0) nextY += N;
		if (nextX < 0) nextX += N;
        
        fireBall_list[idx].Y = nextY;
        fireBall_list[idx].X = nextX;
        m_map[nextY][nextX] += curM;
        s_map[nextY][nextX] += curS;
        cnt_map[nextY][nextX]++;
        Dnum_map[nextY][nextX][curD%2] ++; // 짝수면 0 홀수면 1
    }
}
void div(){
    vector <Fireball> tmp_list;
    for(int idx = 0 ; idx < fireBall_list.size(); idx++){
        int curY = fireBall_list[idx].Y;
        int curX = fireBall_list[idx].X;
        if(cnt_map[curY][curX] == 1){
            tmp_list.push_back(fireBall_list[idx]);
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ;j++){
            if(cnt_map[i][j] >= 2){ 
                int dir_one[4]= {1,3,5,7};
                int dir_two[4]= {0,2,4,6};
                int cnt = cnt_map[i][j];
                int m = m_map[i][j];
                int s = s_map[i][j];
                int d1 = Dnum_map[i][j][0];
                int d2 = Dnum_map[i][j][1];

                cnt_map[i][j] = 0;
                m_map[i][j] = 0 ;
                s_map[i][j] = 0 ;
                Dnum_map[i][j][0] = 0;
                Dnum_map[i][j][1] = 0;

                for(int k = 0 ; k < 4; k++){
                    Fireball f;
                    f.Y = i;
                    f.X = j;
                    f.m = m/5;
                    f.s = s/cnt;

                    if(d1 > 0 && d2 > 0){
                        f.d = dir_one[k];
                    }else{
                        f.d = dir_two[k];
                    }

                    if(f.m > 0 ){
                        m_map[i][j] += f.m;
                        s_map[i][j] += f.s;
                        Dnum_map[i][j][f.d%2] ++; // 짝수면 0 홀수면 1
                        cnt_map[i][j] ++;
                        tmp_list.push_back(f);
                    }
                }
            }
        }
    }
    fireBall_list = tmp_list;
}
void sol(){
    move();
    div();
}
void sum_ans(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ;j++){
            ans += m_map[i][j];
        }
    }
}
int main(){
    cin >> N >> M >> K;
    for(int i = 0 ; i < M; i++){
        Fireball b;
        cin >> b.Y >> b.X >> b.m >> b.s >> b.d;
        b.Y--;
        b.X--;
        s_map[b.Y][b.X] += b.s;
        m_map[b.Y][b.X] += b.m;
        cnt_map[b.Y][b.X]++;
        Dnum_map[b.Y][b.X][b.d%2] ++;
        fireBall_list.push_back(b);
    }
    for(int k = 0 ; k < K ;k ++){
        sol();
    }
    sum_ans();
    cout <<ans ;
    return 0;
}