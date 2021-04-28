#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> list;
int binarySearch(vector <int> &list , int left, int right ,int target){
    while (left<= right){
       int mid = (left + right) /2;
       if(list[mid] == target){
           return mid;
       }
       else{
           if(list[mid] < target){
               left = mid +1;
           }else{
               right = mid -1;
           }
       }
    }
    return -1;
}

int main(){
    int N, target;
    cin >> N >> target;
    for(int i = 0 ;i < N ; i++){
        int input;
        cin >> input;
        list.push_back(input);
    }
    sort(list.begin(), list.end());
    int ansIndex = binarySearch(list,0,N-1,target);
    
    if(ansIndex == -1){
        cout << "찾을수없습니다." ;
    }
    else{
        cout << ansIndex;
    }
}