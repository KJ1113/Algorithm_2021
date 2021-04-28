#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue <int> prq;
    queue <pair <int ,int >> outputlist;
    for(int i =0 ;i < priorities.size() ; i++ ){
        prq.push( priorities[i]);
        outputlist.push (pair <int ,int >( priorities[i], i ));
    }
    int answer = 1;
    while (!outputlist.empty()){
        if(outputlist.front().first == prq.top() ){
            if(location == outputlist.front().second){
                break;
            }
            else{
                answer++;
            }
            prq.pop();
        }
        else{
            outputlist.push (pair <int ,int >( outputlist.front().first, outputlist.front().second ));
        }
        outputlist.pop();
    }
    return answer;
}
// 규칙 )
// 1 .맨앞의 인쇄물을 꺼낸다.
// 2. 나머지인쇄물중 가장 중요도가 높다면 인쇄, 아니라면 맨뒤로 보낸다.
// 풀이 )
// 1. queue 에 집어넣는다. <문서중요도, 검사전 location>
// 2. 큐를 순환하면 서 2.조건에 맞다면 인쇄하고 몇번째 인쇄물인지 기록.
// 3. location 과 최초 인쇄물 순서가 일치한다면 ans return 