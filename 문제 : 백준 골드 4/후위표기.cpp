#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){ //동급+나보다 높은 순위는 아래에 위치 할수없음. ex) *+++ O , **++ X [ 1티어 : ) 2티어 : * /  3티어 : +,- 4 티어: ( ]
    string input ="";
    string output ="";
    stack <char> s;
    cin >> input;

    for(int i = 0; i < input.size() ;i++ ){
        if( 65 <= input[i] && input[i] <= 90){
            output+= input[i];
        }
        else{
            if(input[i] == '('){
                s.push(input[i]);
            }
            else if(input[i] == ')'){
                while (!s.empty() && s.top() != '('){
                    output+= s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                if(input[i] == '*' || input[i] == '/'){
                    while (!s.empty() && (s.top() == '*' || s.top() == '/') ) {
                        output+= s.top();
                        s.pop();
                    }
                }
                else{
                    while (!s.empty() && s.top() != '(') {
                        output+= s.top();
                        s.pop();
                    }
                }
                s.push(input[i]);
            }
        }
    }
    while (!s.empty()){
        output+= s.top();
        s.pop();
    }
    cout << output <<endl;
    return 0;
}