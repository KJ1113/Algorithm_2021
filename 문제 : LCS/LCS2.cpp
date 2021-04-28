#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string input_one;
string input_two;
string ans;
int DP[1001][1001];
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> input_one >> input_two;
    for(int i = 1 ; i<= input_one.size(); i++){
        for(int j = 1; j<= input_two.size(); j++ ){
            if(input_one[i-1] == input_two[j-1]){
                DP[i][j] = DP[i-1][j-1] +1; 
            }
            else{
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    int size = DP[input_one.size()][input_two.size()];
    int i = input_one.size();
    int j = input_two.size();
    
    while (i >= 1 && j >= 1){
        if(DP[i][j] == DP[i-1][j]){
			i--;
		}else if(DP[i][j] == DP[i][j-1]){
			j--;
		}else{
			ans += input_one[i-1];	
			i--; j--;
		}
    }
    reverse(ans.begin(), ans.end());
    cout << size <<endl;
    cout << ans ;
    return 0;
}