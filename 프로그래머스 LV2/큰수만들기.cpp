#include <string>
#include <stack>
#include <algorithm>
using namespace std;
stack <char> s;
string solution(string number, int k) {
    string answer = "";
    int last_idx = 0;
    int endSize = number.size() - k;
    for(int i = 0 ; i < number.size(); i++){
        while(true){
            if(s.empty() ||s.top() >= number[i] || k == 0) break;
            s.pop();
            k--; // k의 수를 줄여준다.
        }
        if (k == 0) break;
        last_idx = i+1;
        s.push(number[i]);
    }
    // 남은 문자 추가하기
    for(int i = last_idx; i < number.size() ;i++){
        s.push(number[i]);
        if(s.size() == endSize ) break;
    }
    //k 만큼 삭제 하지 못했다면
    for(int i = 0 ; i< k; i++){
        s.pop();
    }
    
    while(!s.empty()){
        answer += s.top();
        s.pop();
        if (answer.size() == endSize) break;
    }
    reverse(answer.begin() , answer.end());
    return answer;
}