#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<pair<int,int>> answers;
    stack <pair<int,int>> s;
    s.push(make_pair(prices[0], 1));
    
    for(int i = 1 ; i < prices.size() ; i++){
        int cur_price = prices[i];
        int cur_time = i+1;
        while(!s.empty()){
            int pri_price = s.top().first;
            int pri_time = s.top().second;
            if(pri_price > cur_price){
                answers.push_back(make_pair(pri_time , cur_time - pri_time ));
                s.pop();
            }
            else{
                break;
            }
        }
        s.push(make_pair(cur_price, cur_time));
    }
    while(!s.empty()){
        answers.push_back(make_pair(s.top().second,  prices.size() - s.top().second));
        s.pop();
    }
    sort(answers.begin() , answers.end());
    for(int i = 0; i < answers.size(); i++){
        answer.push_back(answers[i].second);
    }
    return answer;
}

//스택을 이용한 문제,  