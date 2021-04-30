#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int list_key = 0 ;
struct file{
    string HEAD , NUMBER , TAIL , full_Str;
    string realH = "";
    int key , realNum = 0;
    void conversion(){
        for(int i = 0 ; i < HEAD.size() ; i ++){
            if( 'a' <= HEAD[i] && HEAD[i] <= 'z'){
                realH += (HEAD[i] - 32);
            }else{
                realH += HEAD[i];
            }
        }
        realNum = stoi(NUMBER);
    }
};

bool cmp(file A , file B){
    if(A.realH == B.realH){
        if(A.realNum == B.realNum){
            return A.key < B.key;
        }
        return A.realNum < B.realNum;
    }
    return A.realH < B.realH;
}
vector<file>list;
void init_str(string str){
    string tmp;
    string fstr;
    file f;
    int str_cnt = 0;
    for(int i = 0; i < str.size() ;i++){
        if(str_cnt == 0){
            if('0' <= str[i] && str[i] <= '9' ){
                f.HEAD = tmp;
                tmp = "";
                str_cnt = 1;
            }
        }else if(str_cnt == 1){
            if('0' > str[i] || str[i] > '9' ){
                f.NUMBER = tmp;
                tmp = "";
                str_cnt = 2;
            }
        }
        fstr += str[i];
        tmp += str[i];
    }
    
    if(str_cnt == 1){
        f.NUMBER = tmp;
    }else{
        f.TAIL = tmp;
    }
    
    f.full_Str = fstr;
    f.key = list_key;
    list_key++;
    f.conversion();
    list.push_back(f);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int i = 0 ; i < files.size() ;i++ ){
        init_str(files[i]);
    }
    sort(list.begin(), list.end() , cmp);
    for(int i = 0 ; i < list.size() ; i++ ){
        //cout << list[i].key <<endl;
        answer.push_back( list[i].full_Str);
    }
    return answer;
}