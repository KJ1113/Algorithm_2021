#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map <string,int> dic;
void init(){
    for(int i =0 ;i <= 25 ;i++){
        string str ="";
        str +=  i+65;
        dic.insert({str,i+1});
    }
}
vector<int> solution(string msg) {
    vector<int> answer;
    init();
    
    int curIdx = 0;
    string cur_str = "";
    string pri_str = "";
    
    while(curIdx < msg.size()){
        bool flag = true;
        cur_str = "";
        
        for(int nextIdx = curIdx ; nextIdx < msg.size() ; nextIdx++){ //for문을 돌면서 검색
            pri_str = cur_str;
            cur_str += msg[nextIdx];
            
            if(dic.find(cur_str) == dic.end()){ //사전에 없는 단어라면
                answer.push_back(dic.find(pri_str) -> second ); // 압축 번호 추가
                dic.insert({ cur_str , dic.size() + 1}); // 사전에 추가
                curIdx = nextIdx;
                flag = false;
                break;
            }
        }
        
        if(flag){ // 마지막 msg idx 에 도달 했을때.
            answer.push_back(dic.find(cur_str) -> second );
            break;
        }
    }
    return answer;
}