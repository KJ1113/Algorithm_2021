#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
int N , M ;
int arr[100001];
int ans = INF;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < N ;i++){
        cin >> arr[i];
    }
    int low =0 , high = 0;
    int sum = arr[0];


    while (low<= high && high < N){
        if(sum < M ){
            high++;
            sum += arr[high];
        }
        else if(sum == M ){
            ans = min(ans , high - low +1);
            high++;
            sum += arr[high];
        }
        else{ // sum > M
            ans = min(ans , high - low +1);
            sum -= arr[low];
            low++;
        }
    }
    
    if(ans == INF){
        cout << 0;
    }
    else{
        cout << ans;
    }
    return 0;
}