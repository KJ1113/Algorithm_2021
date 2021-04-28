#include <iostream>
#include <vector>
using namespace std;
long long  N ;
int ans = 0;
bool num [4000001];
vector<int> Num;
void atos(){
    for(long long  i = 2 ; i <= N; i++){
        if(num[i]) continue;
        for(long long  j = i * 2 ;j <= N ; j = j + i){
            num[j] = true;
        }
    }
    for(int i = 2 ; i <= N ; i++){
        if(num[i] == false) {
            Num.push_back(i);
        }
    }
}
int main(){
    cin >> N;
    atos();
    for(int idx = 0 ; idx < Num.size(); idx++){
        int sum = 0;
        for(int i = idx; i < Num.size() ; i ++){
            sum += Num[i];
            if (N < sum) break;
            if (N == sum) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0 ;
}