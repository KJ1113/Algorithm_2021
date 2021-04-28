#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <pair<int,int>> q; 
    
    for(int i = 0 ; i < speeds.size(); i++){
        q.push(pair<int,int>( progresses[i] ,speeds[i]));
    }
    
    while(!q.empty()){
        int qsize = q.size();
        int ends = 0;
        bool top = true;
        for(int i =0; i < qsize ; i++){
            int prosses = q.front().first;
            int speed = q.front().second;
            q.pop();
            if(prosses+speed >= 100 && top == true   ){
                ends ++;
            }
            else{
                top = false;
                q.push(pair<int,int>(prosses+speed,speed));
            }
        }
        
        if(ends > 0 ){
            answer.push_back(ends);
        }
    }
    return answer;
}

// 규칙)
// 주어진 progresses 마다 하루마다 작업 속도가 다르다.
// rpegresse 가 작업률이 100 이상이 되면 배포한다.
// 100 이 된 작업물들은 해당날짜에 한꺼번에 배포된다.

// 풀이)
// 큐에 작업물과 작업속도를 입력한다.
// 큐를 순환하면서 작업량을 더해준다. (qsize 를 통하여 날짜 구분)
// 작업량이 100이상이면 완료된 작업물수 (ends 증가) 증가
// qsize for문이 끝난다면 벡터에 완료된 작업물 추가.
// 큐가 소멸할떄 까지 반복.