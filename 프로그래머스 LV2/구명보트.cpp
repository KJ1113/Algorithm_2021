#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp (int a , int b){
    return a > b;
}
int solution(vector<int> people, int limit) {
    int rest , ans = 0;
    int sel_cnt = 0;
    int last_idx = people.size()-1;
    int people_cnt = people.size();
    sort(people.begin() , people.end(),cmp);
    
    //1. 내림차순으로 정렬후 가장 앞뒤를 묶어서 배로 보낸다
    //2. limit/2 보다 작으면 나머지 남은 인원은 모두 2명씩 배에 탈수있다.
    //3. 남은 인원을 계산하여 추가.
    for(int i = 0; i< people.size(); i++){
        if(people[i] <= limit/2) break;
        
        if(people[i] + people[last_idx] <= limit){ // 2개 선택 가능 할때
            sel_cnt++;
            last_idx--;
        }
        sel_cnt++;
        ans++;
    }
    
    rest = people_cnt-sel_cnt;
    if(rest % 2 ==1) rest = rest +1;
    ans += rest/2;
    return ans;
}