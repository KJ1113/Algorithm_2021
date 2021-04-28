#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
map<string ,int > m;
vector<pair<string , int> > course_cnt [11] ;
bool vist[11];
bool cmp(pair<string , int> A , pair<string , int> B){
    return A.second > B.second;
}
void comb(int index , int cnt , int max , string &order){
    if(cnt==max){
        string str ="";
        for(int i = 0 ; i < order.size() ; i++){
            if(vist[i]) str += order[i];
        }
        if(m.find(str) == m.end()){
            m.insert({str,1});
        }
        else{
            m.find(str)->second++;
        }
    }
    else{
        for(int i = index ; i < order.size() ; i++){
            if(vist[i]) continue;
            vist[i] = true;
            comb(i+1,cnt+1,max,order);
            vist[i] = false;
        }
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 손님별 주문의 모든 경우의 수 체크
    for(int i =0; i < orders.size() ; i++ ){
        sort(orders[i].begin(), orders[i].end());
        for(int k = 0; k< course.size();k++){
            int size = course[k];
            memset(vist,false,sizeof(vist));
            if(size <= orders[i].size()){
                comb(0,0,size,orders[i]);
            }
            else{
                break;
            }
        }
    }

    // 2회 이상 주문된 조합 찾기
    map<string, int>::iterator itr;
    for(itr = m.begin() ; itr != m.end() ; itr ++ ){
        string str = itr-> first;
        int cnt = itr -> second;
        int size = str.size();
        if (cnt > 1) course_cnt[size].push_back({str,cnt});
        //cout << str<<" " << cnt<<endl;
    }
    
    // "추가하고 싶어하는 코스요리의 갯수" 찾기
    for(int k = 0; k< course.size();k++ ){ 
        int size = course[k];
        sort(course_cnt[size].begin() , course_cnt[size].end(),cmp);
        int max_cnt = course_cnt[size][0].second; // 가장많이 주문된 조합의 횟수
        
        for(int i = 0; i <course_cnt[size].size() ; i++){
            if(course_cnt[size][i].second== max_cnt){
                answer.push_back(course_cnt[size][i].first);
            }
            else {
                break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}