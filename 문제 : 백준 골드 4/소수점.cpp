#include <iostream>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
int TC , numOne , numTwo;
const int MAX = 10001;
int check[MAX];
int cache[MAX];
int ans = -1;
void eratos(){
    for(int i = 1; i <= MAX ;i++){
        check[i] = i;
    }
    for(int i = 2 ; i <= MAX ; i++){
        if(check[i] == 0) continue;

        for(int j = i*2 ; j <= MAX ; j+=i ){
            check[j] = 0;
        }
    }
}
void BFS(){
    for(int i = 1 ; i <= MAX;i++){
        cache[i] = -1;
    }
    queue<int> q;
    q.push(numOne);
    cache[numOne] = 0;

    while (!q.empty()){
        int curNum = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            string strCurNum = to_string(curNum);
            for(int j = 0 ; j < 10 ; j++){
                strCurNum[i] = j + '0';
                int nextNum = stoi(strCurNum);
                if(nextNum >= 1000 && check[nextNum] !=0 && cache[nextNum] == -1){
                    cache[nextNum] = cache[curNum] + 1;
                    q.push(nextNum);
                }
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    eratos();
    cin >> TC;
    for(int tc =0 ; tc < TC; tc++){
        cin >> numOne >> numTwo;
        BFS();
        if(cache[numTwo] == -1){
            cout << "Impossible\n"; 
        }
        else{
            cout << cache[numTwo] <<"\n";
        }
    }
    return 0;
}