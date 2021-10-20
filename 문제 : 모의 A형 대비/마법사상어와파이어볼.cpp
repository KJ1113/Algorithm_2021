#include <iostream>
#include <vector>
using namespace std;

int dir[8][2] ={ {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
int N , M , K , ans = 0;
struct fire_ball{
    int  y , x , d , m , s;
};
vector<fire_ball> list;
vector<fire_ball> move_list;
int cnt_map[51][51];
int d_map[51][51][2];
int s_map[51][51];
int m_map[51][51];

void show(){
    for(int i = 0 ; i< N ; i++){
        for(int j =0 ;j <N ;j++){
            cout << cnt_map[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
}
void merge(){

    move_list.clear();
    for(int index = 0 ; index < list.size(); index++){
        fire_ball f = list[index];
        int cY = f.y;
        int cX = f.x;
        if(cnt_map[cY][cX] == 1) move_list.push_back(list[index]);
    }
    for(int i = 0 ; i< N ; i++){
        for(int j =0 ;j <N ;j++){
            int cY = i;
            int cX = j;

            if(cnt_map[cY][cX] >= 2){
                if(m_map[cY][cX]/5 > 0){
                    int new_dir = 0;
                    int new_m = m_map[cY][cX]/5;
                    int new_s = s_map[cY][cX]/cnt_map[cY][cX]; 

                    if(cnt_map[cY][cX] == d_map[cY][cX][1] || cnt_map[cY][cX] == d_map[cY][cX][0]){
                        new_dir = 0;
                    }else{
                        new_dir = 1;
                    }

                    d_map[cY][cX][0] = 0;
                    d_map[cY][cX][1] = 0;

                    for(int k = 0 ; k < 4; k++){
                        fire_ball new_f;
                        new_f.y = cY;
                        new_f.x = cX;
                        new_f.d = new_dir;
                        new_f.m = new_m;
                        new_f.s = new_s;

                        new_dir += 2;

                        if(new_f.d % 2==0) d_map[cY][cX][0]++;
                        else d_map[cY][cX][1]++;
                        move_list.push_back(new_f);
                    }

                    cnt_map[cY][cX] = 4;
                    s_map[cY][cX] = new_s*4;
                    m_map[cY][cX] = new_m*4;
                }else{
                    d_map[cY][cX][1] = 0;
                    d_map[cY][cX][0] = 0;
                    s_map[cY][cX] = 0;
                    m_map[cY][cX] = 0;
                    cnt_map[cY][cX] = 0;
                }
            }
        }
    }
}
void move(){
    for(int index = 0 ; index < list.size(); index++){
        fire_ball f = list[index];
            
        int cY = f.y;
        int cX = f.x;
        int nY = cY;
        int nX = cX;

        nY = (f.y + ( dir[f.d][0] * (f.s % N))) ;
        nX = (f.x + ( dir[f.d][1] * (f.s % N))) ;

        if(nY >= N) nY -= N;
        if(nY < 0) nY +=  N;
        if(nX >= N) nX -= N;
        if(nX < 0) nX +=  N;
        

        cnt_map[nY][nX]++;
        s_map[nY][nX] += f.s;
        m_map[nY][nX] += f.m;

        if(f.d % 2==0) d_map[nY][nX][0]++;
        else d_map[nY][nX][1]++;

        cnt_map[cY][cX]--;
        s_map[cY][cX] -= f.s;
        m_map[cY][cX] -= f.m;

        if(f.d % 2==0) d_map[cY][cX][0]--;
        else d_map[cY][cX][1]--;

        list[index].y = nY;
        list[index].x = nX;
    }
}
void sol(){
    //show();
    //r, c, m, s, d
    for(int k = 0 ; k < K ;k++){
        move();
        merge();
        list.clear();
        list = move_list;
    }
}
int main(){
    cin >> N >> M >> K;
    for(int i = 0 ; i < M ;i++){
        int m ,s ,d;
        fire_ball f;
        cin >> f.y >> f.x >> f.m>> f.s >> f.d;
        f.y--;
        f.x--;
        cnt_map[f.y][f.x]++;
        s_map[f.y][f.x] += f.s;
        m_map[f.y][f.x] += f.m;

        if(f.d % 2==0) d_map[f.y][f.x][0]++;
        else d_map[f.y][f.x][1]++;
        list.push_back(f);
    }
    sol();
    for(int index = 0 ; index < list.size(); index++){
        ans += list[index].m;
    }
    cout << ans;
    return 0;
}