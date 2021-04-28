#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N , target;
vector <int> list;

int countByRange(vector<int>& v, int leftValue, int rightValue) {
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue); //val를 초과하는 값반환
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue); //val가 처음 발견되는 값반환
    return rightIndex - leftIndex;
}
int main(){
    cin >> N >> target;
    for(int i= 0 ; i < N; i++){
        int x;
        cin >> x;
        list.push_back(x);
    }
    sort(list.begin() , list.end() );
    cout << countByRange(list, target ,target);

    return 0;
}