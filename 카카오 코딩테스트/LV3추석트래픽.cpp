#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int time_table[86500000];
void init(string str){
    string HH = str.substr(11,2);
    string MM = str.substr(14,2);
    string SS = str.substr(17,6);
    
    string tmpRunTime = str.substr(24);
    string runTime;
    for(int i = 0 ; i < tmpRunTime.size()-1 ;i++){
        runTime += tmpRunTime[i];
    }
    
    int H = (stod(HH) * 3600) * 1000;
    int M = (stod(MM) * 60) * 1000; 
    int S = (stod(SS)) * 1000;
    int R = stod(runTime) * 1000;
    
    //cout <<H+M+S-R+2  << " "<<H+ M +S<<endl;
    int sTime = H+M+S-R+2;
    int eTime = H+M+S+1000;

    if(H+M+S-R+1 < 0) sTime=0;
    for(int s = sTime ; s <= eTime; s++){
        time_table[s] ++;
    }
}
int solution(vector<string> lines) {
    int answer = 0;
    for(int i  = 0 ; i < lines.size() ;i++){
        init(lines[i]);
    }
    for(int s = 0 ; s < 86500000; s++){
        answer = max(answer,time_table[s]);
    }
    return answer;
}