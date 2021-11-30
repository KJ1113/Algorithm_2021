#include <iostream>
#include <vector>
using namespace std;

struct belt{
    int pos;
    int next_idx;
    int A;
    bool robot = false;
};
int N , K;
vector<belt> belt_list;

int main(){
    cin >> N >> K;
    for(int i = 1 ; i <= N * 2 ; i++){
        belt b;
        cin >> b.A;
        b.pos = i;
        b.next_idx = i+1;
        if(b.pos == 2* N) b.next_idx = 0;
        belt_list.push_back(b);
    }

    int time = 0;
    int first_idx = 0;
    int move_start_idx = 0;
    
    while (true){
        time ++;
        // 1. 회전 and 로봇 삭제
        for(int idx = 0; idx < belt_list.size(); idx++){
            if(belt_list[idx].pos == 2*N){
                first_idx = idx;
                belt_list[idx].pos = 1;

            }else{
                belt_list[idx].pos++;
                if(belt_list[idx].pos == N) belt_list[idx].robot = false;
                if(belt_list[idx].pos == N-1) move_start_idx = idx;
            }

            belt_list[idx].next_idx = idx+1;
            if(idx ==belt_list.size()-1) belt_list[idx].next_idx = 0;
        }

        // 2. 로봇 이동 (순서대로)
        while (true){
            int idx = move_start_idx;
            if(belt_list[idx].robot){
                int nextIdx = belt_list[idx].next_idx;

                if(belt_list[nextIdx].robot == false && belt_list[nextIdx].A != 0 ){

                    belt_list[idx].robot = false;
                    belt_list[nextIdx].robot = true;

                    // 내구도 감소
                    belt_list[nextIdx].A--;

                    // 로봇 삭제
                    if(belt_list[nextIdx].pos == N) belt_list[nextIdx].robot = false;
                }
            }
            if(belt_list[idx].pos == 1) break;

            move_start_idx --;
            if(move_start_idx == -1 ) move_start_idx = (2*N) -1;
        }

        // 3. 로봇 올림
        if(belt_list[first_idx].robot == false &&belt_list[first_idx].A != 0){
            belt_list[first_idx].robot =true;
            belt_list[first_idx].A--;
        }

        // 종료 검사
        int zero_A_cnt = 0;
        for(int idx = 0; idx < belt_list.size(); idx++){
            if(belt_list[idx].A == 0) zero_A_cnt++;
        }
        if(zero_A_cnt >= K) break;
    }
    cout << time;
    return 0;
}