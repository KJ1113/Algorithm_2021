#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<string> strNum[11];
void DFS(string num , int lastNum){
    //int intNum = stoi(num);
    if(num != ""){
        int size = num.size();
        strNum[size].push_back(num);
    }
    for(int i = 0 ; i < lastNum; i++){
        DFS(num + to_string(i) , i);
    }
}
int main(){
    cin >> N;
    DFS("",10);
    int cnt = 0;
    for(int i  =1 ; i < 11; i++){
        for(int j = 0 ; j< strNum[i].size(); j++){
            if(cnt == N ) {
                cout << strNum[i][j] <<endl;
                return 0;
            }
            cnt ++;
        }
    }
    cout << "-1" <<endl;
    return 0;
}