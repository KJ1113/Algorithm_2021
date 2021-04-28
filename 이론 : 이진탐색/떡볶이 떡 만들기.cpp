#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> list ;
int N, M , ans, MaxDDuck = 0;
int binary_search(vector<int> arr , int target , int start ,int end){
    while (start <= end){
        int mid = (start + end) /2 ;
        int total = 0 ;
        for(int i =0 ;i < list.size() ;i++){
            if(list[i] > mid){
                total+= list[i] - mid;
            }
        }
        if (total == target){
            return mid;
        }
        else if(total< target){
            end = mid -1;
        }
        else {
            start = mid+1;
        }
    }
    return -1;
}
int main(){
    cin >> N >> M;
    for(int i =0; i< N ;i++){
        int input;
        cin >> input;
        list.push_back(input);
        MaxDDuck = max(input,MaxDDuck);
    }
    ans = binary_search(list,M,0,MaxDDuck);
    cout << ans;
    return 0;
}