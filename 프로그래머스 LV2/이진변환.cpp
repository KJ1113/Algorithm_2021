#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int trs_cnt =0;
int del_cnt =0;
string tenTotwo(int size){
    int num = size;
    int mod;
    string ans =""; 
    while(true){
        if(num == 1){
            ans += '1';
            break;
        }
        mod = num%2;
        num = num/2;
        ans += to_string(mod);
        
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> solution(string s) {
    while(true){
        if(s == "1") break;
        trs_cnt++;
        int one_cnt = 0;
        for(int i = 0 ;i <s.size() ;i++){
            if(s[i]=='1'){
                one_cnt++;
            }else{
                del_cnt++;
            }
        }
        s = tenTotwo(one_cnt);
    }
    
    
    vector<int> answer(2);
    answer[0] = trs_cnt;
    answer[1] = del_cnt;
    return answer;
}