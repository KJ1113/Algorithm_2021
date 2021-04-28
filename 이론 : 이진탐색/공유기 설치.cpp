#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, C ;
vector<int> home_list;
int binary_search(vector<int>list , int minSize , int maxSize , int target_cnt){
    int ans = -1;
    while (minSize <= maxSize){
        int mid = (minSize + maxSize) /2; // mid 는 공유기 사이의 거리
        int stand = list[0];
        int cnt = 1;
        for(int i = 1 ; i< list.size(); i++){
            if(mid <= list[i]-stand){ //mid 만큼의 거리가 된다면 해당지점에 공유기 설치하고 cnt 증가
                cnt++;
                stand = list[i];
            }
        }
        if(cnt < target_cnt){ // 공유기수 늘리기
            maxSize = mid - 1;
        }
        else{ // 공유기 수 줄이기
            minSize = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> C;
    for(int i =0; i< N;i++){
        int input;
        cin >> input;
        home_list.push_back(input);
    }
    sort(home_list.begin(),home_list.end());
    int left  = 1;
    int right = home_list[N-1]-home_list[0];
    cout << binary_search(home_list,left,right,C);
    return 0;
}