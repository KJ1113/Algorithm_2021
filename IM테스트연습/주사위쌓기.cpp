#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , ans = -1 ;
int up_down[6] = { 5, 3, 4, 1, 2, 0 };
struct cube{
    int num[6];
    
    int cur_down , cur_up;
};
vector <cube> cube_list;
int main(){

    cin >> N;
    for(int i = 0 ; i < N ;i++){
        cube c;
        for(int idx =0 ; idx < 6;idx++){
            cin >> c.num[idx];
        }
        cube_list.push_back(c);
    }

    for(int d = 0 ; d < 6 ; d++){
        cube_list[0].cur_down = d;
        cube_list[0].cur_up = up_down[d]; // 0 ~ 6 번쨰 모든 경우의 수 체크

        for(int idx = 1 ; idx < cube_list.size() ; idx++){
            int down_num_idx = cube_list[idx-1].cur_up; // 아래쪽 번호 찾기
            int my_down_num = cube_list[idx-1].num[down_num_idx];

            for(int i = 0 ; i < 6 ;i++){
                if(cube_list[idx].num[i] == my_down_num){
                    cube_list[idx].cur_down = i;
                    cube_list[idx].cur_up = up_down[i];
                    break;
                }
            }
        }

        // 모든 주사위의 옆면중 가장 큰수만 더하기
        int sum = 0;
        for(int idx = 0 ; idx < cube_list.size() ; idx++){
            int max_num = -1;
            for(int i = 0 ; i < 6 ;i++){
                if(i == cube_list[idx].cur_up || i == cube_list[idx].cur_down){
                    continue;
                }else{
                    max_num = max(max_num,cube_list[idx].num[i]);
                }
            }
            sum += max_num;
        }
        ans = max(ans , sum);
    }
    cout << ans << endl;
    return 0;
}