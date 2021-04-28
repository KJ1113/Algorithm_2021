#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector <char> input;
int ans = 0; 
string str;
int main(){
    cin >> str;
    for(int i = 0 ; i < str.size(); i++){
        input.push_back(str[i]);
    }
    sort(input.begin() , input.end());
    do{
        bool ok = true;
        char tmp = input[0];
        for(int i = 1 ; i < str.size(); i++ ){
            if(tmp != input[i]){
                tmp = input[i]; 
            }
            else{
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }while (next_permutation(input.begin(), input.end()));
    cout << ans;
    return 0;
}