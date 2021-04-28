#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>>list;
int N ,ans = 0; 
void sol(int curday, int sum){
    if(curday > N) return;
    for(int day = curday ; day < N ;day++){
        sol( list[day].first + day,list[day].second+sum);       
    }
    ans = max(ans,sum);
}
int main(){
    int T , P ;
    cin >> N;
    for(int i = 0; i < N ; i++){
        cin >> T >> P;
        list.push_back({T,P});
    }
    sol(0,0);
    cout << " 답 : "<< ans;
    return 0;
}