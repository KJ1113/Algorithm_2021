#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> num_list;
int main(){
    int N;
    cin >> N;
    for(int i = 0 ;i < N ; i++){
        int a;
        cin >> a;
        num_list.push_back(a);
    }
    sort(num_list.begin(), num_list.end());

    int sum = 0 ;
    for(int idx = 0 ; idx < N; idx ++){
        if(sum + 1 >= num_list[idx] ) {
            sum = num_list[idx] + sum;
        }else{
            break;
        }
    }
    cout << sum+1;
    return 0;
}