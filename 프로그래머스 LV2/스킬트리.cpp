#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
bool skill_ok[27];
map<char,int> skill_set;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i =0; i< skill.size() ;i++){
        skill_set.insert({skill[i],i});
    }
    for(int i =0 ; i <skill_trees.size() ; i++ ){
        bool flag = true;
        fill_n(skill_ok,skill.size() ,false);
        
        for(int idx = 0 ; idx < skill_trees[i].size() ;idx++){
            char c = skill_trees[i][idx];
            if(skill_set.find(c) != skill_set.end()){
                int index = skill_set.find(c) -> second;
                if(index == 0){
                    skill_ok[index] = true;
                }
                else{
                    if(skill_ok[index-1] == false){
                        flag = false;
                        break;
                    }
                    skill_ok[index] = true;
                }
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}