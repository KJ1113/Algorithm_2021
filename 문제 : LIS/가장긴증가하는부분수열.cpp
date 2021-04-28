#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> list;
int N , ans = -1;
void binarySearch(int num){
    int left = 0;
    int right = list.size()-1; 
    while (left < right){
        int mid = (left + right) /2;
        if(list[mid] >= num){ //right 인덱스를 줄여가며 (같거나큰수) 중 가장 작은수를 찾는다.
            right = mid;
        }else{
            left = mid+1;
        }
    }
    list[right] = num;
}
int main(){
    cin >> N;
    for(int curIdx = 0 ; curIdx < N ;curIdx++){
        int input;
        cin >> input;
        if(curIdx == 0 ) {
            list.push_back(input);
        }
        else{
            if(list[list.size()-1] >= input){
                binarySearch(input);
            }
            else{
                list.push_back(input);
            }
        }
    }
    cout<< list.size();
    return 0;
}