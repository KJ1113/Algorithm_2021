#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string input_one;
string input_two;
int ans = 0;
int DP[1001][1001];
int main(){
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
    cout << DP[input_one.size()][input_two.size()];
    return 0;
}