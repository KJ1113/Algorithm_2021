#include <iostream>

using namespace std;
int N ;
void show_ans(int a , int b){
    if(a > b){
        cout << "A" << endl;
    }else{
        cout << "B" << endl;
    }
}
int main(){

    cin >> N ;
    for(int n = 0 ; n < N ; n++){
        int a_list[5] = {0,}, b_list[5] ={0,}; // 별, 동그라미, 네모, 세모를 각각 숫자 4, 3, 2, 1로 표현한다. 
        int a_length , b_length , input; // a 와 b 의 도형 입력 길이

        cin >> a_length;
        for(int i = 0 ; i <  a_length;i++){
            cin >> input;
            a_list[input]++;
        }

        cin >> b_length;
        for(int i = 0 ; i <  b_length; i++){
            cin >> input;
            b_list[input]++;
        }

        if(a_list[4] == b_list[4]){
            if(a_list[3] == b_list[3]){
                if(a_list[2] == b_list[2]){
                    if(a_list[1] == b_list[1]){
                        cout << "D" <<endl;
                    }else{
                        show_ans(a_list[1] , b_list[1]);
                    }
                }else{
                    show_ans(a_list[2] , b_list[2]);
                }
            }else{
                show_ans(a_list[3] , b_list[3]);
            }
        }else{
            show_ans(a_list[4] , b_list[4]);
        }
    }
    return 0;
}