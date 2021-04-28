#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , M ;
vector <int >crane;
vector <int> boxs;
bool cmp(int a , int b){
    return a > b;
}
int sol(){
    int time = 0;
    while (true){
        if(boxs.size() == 0) break; // 박스모두 삭제하면 끝
        for(int idx = 0; idx < crane.size() ;idx++){
            for(int i = 0  ; i < boxs.size(); i++){
                if( boxs[i] <= crane[idx] ){
                    boxs.erase(boxs.begin() + i);
                    break;
                }
            }
        }
        time++;
    }
    return time;
}
void input(){
    cin >> N;
    for(int i = 0; i < N ; i++){
        int input;
        cin >> input;
        crane.push_back(input);
    }
    cin >> M;
    for(int i = 0; i < M ; i++){
        int input;
        cin >> input;
        boxs.push_back(input);
    }
    sort(crane.begin(),crane.end(),cmp);
    sort(boxs.begin(),boxs.end(),cmp);
}
int main(){
    input();
    if(boxs[0] > crane[0]){
        cout << -1;
    }
    else{
        cout << sol();
    }
    return 0;
}