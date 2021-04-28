#include<string>
#include <iostream>

using namespace std;

bool solution(string s){
    int left = 0;
    int right =0;
    
    for(int i =0; i <s.size();i++){
        if(s[i] == '('){
            left++;
        }
        else{
            right++;
        }
        if(left==right){
            if(s[i] == '(') return false;
        }
    }
    if(left==right){
        if(s[s.size()-1] == '(') return false;
    }
    else{
        return false;
    }
    return true;
}



bool solution(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        if (n < 0)
            return false;
        if (s[i] == '(')
            n++;
        else if (s[i] == ')')
            n--;
    }
    return n == 0;
}