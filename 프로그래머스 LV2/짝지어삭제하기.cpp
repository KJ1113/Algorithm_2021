#include <iostream>
#include<string>
using namespace std;

int solution(string s){
    int answer = 0;
    
    while(true){
        int s_size = s.size();
        string tmp ="";
        tmp += s[0];
        for(int i = 1; i <s.size(); i++){
            if(tmp[tmp.size()-1] == s[i]){
                int last_idx = tmp.size()-1;
                tmp.erase(tmp.begin()+last_idx ,tmp.end());
            }else{
                tmp += s[i];
            }
        }
        
        if(tmp==""){
            return 1;
        }
        if(tmp.size() == s.size()){
            return 0;
        }else{
            s = tmp;
        }
    }

    return answer;
}