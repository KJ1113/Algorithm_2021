#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string solution(int n) {
    string answer = "";
    int num = n;
    while(true){
        int mod = num % 3;
        num = num/3;
        if(mod == 1){
            answer += '1';
        }
        else if(mod ==2){
            answer += '2';
        }
        else{
            answer += '4';
            if(num != 0){
                num -= 1;
            }
        }
        if(num == 0 ) break;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

// 3진법을 이용하되. 나머지가 3일 경우 -1 을 시켜줘서 0을 방지한다.