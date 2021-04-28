#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> word[10001];
vector<string> rev_word[10001];
string val_one;
string val_two;
void replace(string word){
    val_one ="";
    val_two ="";
    for (int j = 0; j < word.size(); j++){
        if (word[j] == '?'){
            val_one += 'a';
            val_two += 'z';
        }
        else{
            val_one += word[j];
            val_two += word[j];
        }
    }
}
int binary_search(vector<string> &words ){
    vector<string>::iterator lefttIndex = lower_bound(words.begin(),words.end(),val_one); //val 이상의 값(cnt) 반환
    vector<string>::iterator rightIndex = upper_bound(words.begin(),words.end(),val_two); //val 초과 값(cnt) 반환
    return rightIndex - lefttIndex;
}
void init(vector<string> words){
    
    for(int i = 0 ; i< words.size();i++){
        string str = words[i];
        int size = str.size();
        word[size].push_back(str);
        
        reverse(str.begin(), str.end());
        rev_word[size].push_back(str);
    }
}
void list_sort(){
    for (int i = 0; i < 10001; i++) {
        sort(word[i].begin(), word[i].end());
        sort(rev_word[i].begin(), rev_word[i].end());
    }
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    init(words);
    list_sort();
    for(int i =0 ; i< queries.size(); i++){
        string q = queries[i];
        int size = q.size();
        int res = 0;
        if(queries[i][0]!= '?'){ // 문자로 시작된다면
            replace(queries[i]);
            res = binary_search(word[size]);
        }
        else{
            reverse(q.begin(),q.end());
            replace(q);
            res = binary_search(rev_word[size]);
        }
        answer.push_back(res);
    }
    return answer;
}