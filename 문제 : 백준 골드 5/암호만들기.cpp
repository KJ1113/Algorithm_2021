#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int L , C;
char c [5] = {'a', 'e', 'i', 'o', 'u'}; 
vector<char> alpa_list;
set <char> v_list;
void ADFS(int idx ,int cCnt , int vCnt, string str){
    if(L == str.size() ){
        if(cCnt >= 2 && vCnt>= 1){
            cout << str<< endl;
        }
    }
    else{
        for(int i = idx ; i < alpa_list.size() ;i++){
            if(v_list.find(alpa_list[i]) != v_list.end()){
                ADFS(i+1 , cCnt , vCnt+1, str + alpa_list[i]);
            }else{
                ADFS(i+1 , cCnt +1, vCnt, str + alpa_list[i]);
            }
        }
    }
}
void init(){
    for(int i = 0; i < 5 ;i++){
        v_list.insert(c[i]);
    }
    sort(alpa_list.begin(),alpa_list.end());
}
int main(){
    cin >> L >> C;
    for(int i = 0; i < C ;i++){
        char input;
        cin >> input;
        alpa_list.push_back(input);
    }
    init();
    ADFS(0,0,0,"");
    return 0;
}