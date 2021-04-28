#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int Tc , N;
set<string> str_set;
vector<string> list;

void init(){
    str_set.clear();
    list.clear();
}
bool cmp(string a , string b){
    return a.length() < b.length();
}
int main(){
    cin >> Tc;
    for(int tc = 0 ; tc < Tc; tc++){
        cin >> N;
        for(int i = 0 ; i< N ;i++){
            string input;
            cin >> input;
            list.push_back(input);
            //str_set.insert(input);
        }
        sort(list.begin(), list.end(), cmp);
        bool flag = true;
        for(int i = 0; i < list.size() ;i++){
            string tmp = "";
            for(int j = 0 ; j < list[i].size() ;j++){
                tmp+= list[i][j];
                if(str_set.find(tmp) != str_set.end() ) {
                    flag = false;
                    break;
                }  
            }

            if(flag){
                str_set.insert(list[i]);
            }else{
                break;
            }
        }
        if(flag){
            cout<< "YES" <<endl;
        }else{
            cout<< "NO" <<endl;
        }
        init();
    }

}