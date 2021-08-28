#include <iostream>
using namespace std;
int map[10];
int ans_list[11];
int main(){
    
    for(int i = 0 ; i < 10; i++){
        cin >> map[i];
    }

    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < i+1 ; j++){
            ans_list[i+1] += map[j];
        }
    }

    int ans = ans_list[0];
    int de_point = abs(100 - ans_list[0]);
    for(int i = 0; i < 11 ;i++){
        if( abs(ans_list[i] - 100 ) <= de_point){
            ans = ans_list[i];
            de_point = abs(100 - ans_list[i]);
        }
    }
    cout << ans;

    return 0 ;
}