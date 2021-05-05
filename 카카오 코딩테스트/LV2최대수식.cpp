#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
vector <string> expess;
void init(string expression){
    string tmp = "";
    for(int i = 0 ;  i < expression.size() ; i++){
        if(expression[i] == '-' || expression[i] =='*' || expression[i] == '+'){
            string t ="";
            t += expression[i];
            expess.push_back(tmp);
            expess.push_back(t);
            tmp = "";
        }else{
            tmp += expression[i];
        }
    }
    expess.push_back(tmp);
}
long long get_res(string cur_op , vector <string> &tmp_express , int idx ){
    long long res = 0;
    if (cur_op == "+"){
        res = stol(tmp_express[idx - 1]) + stol(tmp_express[idx + 1]);
    }
    else if (cur_op == "-"){
        res = stol(tmp_express[idx - 1]) - stol(tmp_express[idx + 1]);
    }
    else{
        res = stol(tmp_express[idx - 1]) * stol(tmp_express[idx + 1]);
    }
    return res;
}
void sol(){
    //1. 중복
    vector<string> op_list = { "*", "+", "-"};
    sort(op_list.begin(), op_list.end());
    do{
        vector<string> tmp_express;
        tmp_express = expess;

        for (int op_idx = 0; op_idx < 3; op_idx++){
            string cur_op = op_list[op_idx];
            while (true){
                bool noExpress = true;
                for (int idx = 0; idx < tmp_express.size(); idx++){
                    if (tmp_express[idx] == cur_op){
                        vector<string> tmp_tmp_express;
                        long long res = get_res( cur_op , tmp_express, idx);
                        

                        for (int i = 0; i < idx - 1; i++){
                            tmp_tmp_express.push_back(tmp_express[i]);
                        }
                        tmp_tmp_express.push_back(to_string(res));
                        for (int i = idx + 2; i < tmp_express.size(); i++){
                            tmp_tmp_express.push_back(tmp_express[i]);
                        }

                        tmp_express.clear();
                        tmp_express = tmp_tmp_express;
                        noExpress = false;
                        break;
                    }
                }
                if (noExpress)
                    break;
            }
        }
    } while (next_permutation(op_list.begin(), op_list.end()));
}
long long solution(string expression) {
    long long answer = 0;
    init(expression);
    sol();
    return answer; 
}