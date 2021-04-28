#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
string input , bstr , ans ="";
stack <char> s;
int main(){
    cin >> input >> bstr;
    reverse(bstr.begin(), bstr.end()); // 검사를위해 문자를 뒤집어준다.

    for(int idx = 0; idx < input.size() ;idx++){
        s.push(input[idx]);
        if(s.top() == bstr[0] ){ // 폭탄 문자 마지막과 같다면
            string tmp = "";
            if (s.size() < bstr.size() ) continue; // 검사를 할수없는 경우 (스택의 크기가 폭발문자열보다 작을때)

            for(int i = 0 ; i < bstr.size() ;i++){
                tmp += s.top();
                s.pop();
            }

            if(tmp != bstr){ // 폭발 문자열이 아니라면 스택에 다시 넣어야함
                for(int i = tmp.size()-1 ; i >= 0 ;i--){
                    s.push(tmp[i]);
                }
            }
        }
    }

    while (!s.empty()){
        ans += s.top();
        s.pop();
    }


    if(ans.empty()){
        cout << "FRULA";
    }else{
        reverse(ans.begin() , ans.end());
        cout << ans ;
    } 
    return 0;
}