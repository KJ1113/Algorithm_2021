#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int  advTime , time_size , timeTable[370000];
long max_sum = 0 , sum = 0 ; // 누적 합 //long 으로 해야댐

string con_str(int sec){
    int s = (sec)%60; 
    int m = (sec/60)%60;
    int h = (sec/3600);
    
    string str = "";
    if(h < 10) str+='0';
    str+=to_string(h);
    str += ':';
    
    if(m < 10) str+='0';
    str+=to_string(m);
    str += ':';
    
    if(s < 10) str+='0';
    str+=to_string(s);
    return str;
}
long con_sec(string str){
    string H = str.substr(0,2);
	string M = str.substr(3,2);
	string S = str.substr(6,2);
    return (stol(H) * 3600) + (stol(M) * 60) + stol(S);
}
void input_table(string str){
    string timeA , timeB;
    timeA = str.substr(0,8);
    timeB = str.substr(9,8);
    int s = con_sec(timeA);
    int e = con_sec(timeB);
    for(int i = s; i < e; i++){
        timeTable[i] ++;
    }
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    // 1. 모든 로그를 초로 변환후 time table 에 입력
    for(int i = 0 ; i < logs.size() ;i++){
        input_table(logs[i]);
    }
    
    // 2. 재생시간을 초로 변환 
    time_size = con_sec(play_time); // 전체시간
    advTime = con_sec(adv_time); // 광고시간

    int ans = 0; 
    queue<int> q;
    for(int s = 0 ; s < advTime ; s++){
        sum += timeTable[s];
        q.push(timeTable[s]);
    }
    max_sum = sum;
    
    // 3. 투포인터로 누적합 갱신 (하나 뺴고 하나 더하고)
    for(int i=advTime; i < time_size; i++){
        sum += timeTable[i];
        q.push(timeTable[i]);
        sum -= q.front();
        q.pop();
        
        if( sum > max_sum ){
            max_sum = sum;
            ans = i-advTime+1;
        }
    }
    return con_str(ans);
}