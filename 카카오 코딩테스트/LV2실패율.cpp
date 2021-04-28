#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> answer;
vector<pair < int , double >> index; 
int dp[501][2];
bool cmp(pair < int , double > a , pair < int , double > b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    
    //1. dp[][0] 은 클리어한 유저수 , dp[][1] 은 도전한 유저수 
    for(int i = 0 ; i < stages.size() ; i++){
        for(int j = 1 ; j <= stages[i] ;j++){
            if( j != stages[i]){
                dp[j][0] ++;
            }
            dp[j][1] ++;
        }
    }
    
    //2. < 번호 , 실패율 > 순으로 입력
    for(int i = 1; i <= N ;i++){
        if(dp[i][1] == 0){
            index.push_back({ i , 0 }); // 분모가 0 일경우
        }else{
            index.push_back({ i ,(double)(dp[i][1]-dp[i][0]) / (double)dp[i][1]  });
        }
    }
    
    //3. 정렬후 answer 배열에 입력
    sort(index.begin(), index.end() ,cmp );
    for(int i = 0 ; i < index.size() ;i++){
        answer.push_back(index[i].first);
    }
    return answer;
}