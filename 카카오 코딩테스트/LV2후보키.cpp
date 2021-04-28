#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
bool vist[10];
int answer;
int Max_col , Max_row;
set <string> super_key; // 슈퍼키
set<string> del_list; // 삭제되는 슈퍼키
vector <string> comb;

void cob(vector<vector<string>> relation){
    vector<int>list; //검사리스트 
    string key ="";
    set <string> s;
    
    // 선택된 속성은 1 , 아니라면 0 인 문자열 생성
    for(int i = 0 ; i < Max_col ;i++){
        if(vist[i]) {
            list.push_back(i);
            key += '1';
        }else{
            key += '0';
        }
    }
    
    // 유일성을 만족하는지 검사 
    for(int i = 0 ; i < Max_row ;i++){
        string tmp = "";
        for(int k = 0 ; k < list.size(); k++){
            int j = list[k];
            tmp += relation[i][j];
        }
        
        if(s.find(tmp) == s.end()){
            s.insert(tmp);
        }else{
            return;
        }
    }
    
    // 유일성을 만족하고 해당 조합이 만들어진적 없다면 슈퍼키에 추가
    if(super_key.find(key) == super_key.end()){
        comb.push_back(key);
        super_key.insert(key);
    }
}
void DFS(int max , int cnt , int index , vector<vector<string>> relation){
    if(max == cnt){
        cob(relation); // 유일성을 만족하는지 체크하고 만족하면 슈퍼키 집합에 추가
    }else{
        for(int i = index ; i < Max_col; i ++){
            if(vist[i]) continue; //  선택된키면 패스
            vist[i] = true;
            DFS( max , cnt+1, index+1 ,relation);
            vist[i] = false;
        }
    }
}
void select(vector<vector<string>> relation){ // 선택갯수별 조합
    for(int max_cnt = 1 ; max_cnt <= Max_col ;max_cnt++){ 
        DFS(max_cnt , 0 , 0 , relation);
    }
}
int solution(vector<vector<string>> relation) {
    Max_col = relation[0].size();
    Max_row = relation.size();
    select(relation);
    
    
    for(int i = 0 ; i < comb.size() ; i++){
        // 해당조합이 삭제예정인 조합이면 패스
        if(del_list.find(comb[i]) != del_list.end()) continue;
        
        // 선택된 속성수 카운트
        int sel_cnt = 0;
        string curStr = comb[i];
        for(int idx = 0 ; idx < comb[i].size(); idx++){
            if(comb[i][idx] == '1') sel_cnt++;
        }
        
        // 최소성 검사 
        for(int j = 0 ; j  < comb.size()  ;j++){
            if(i == j) continue; // 같은 idx 는 패스
            int same_cnt = 0;
            for(int k = 0 ; k < comb[j].size() ;k++){
                if(comb[i][k] == '1' && comb[j][k] == '1'){
                    same_cnt ++;
                }
            }
            if(same_cnt == sel_cnt) del_list.insert(comb[j]);
        }
    }
    
    // 전체 슈퍼키set.size() - 삭제된 슈퍼키set.size()
    return super_key.size() - del_list.size();
}