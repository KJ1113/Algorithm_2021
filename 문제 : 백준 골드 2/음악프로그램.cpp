#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N , M ;
int indgree[1001];
vector <int> list[1001];
vector <int> res;
void sol(){
    queue <int> q;
    for(int i = 1 ; i <= N; i++){
        if(indgree[i] == 0 ){
            q.push(i);
        }
    }
    while (!q.empty()){
        int curNum = q.front();
        q.pop();
        res.push_back(curNum);
        for(int i = 0 ; i < list[curNum].size(); i++){
            int nextNum = list[curNum][i];
            indgree[nextNum] --;
            if(indgree[nextNum] == 0){
                q.push(nextNum);
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < M ;i++){
        int size = 0 , root , next;
        cin >> size;
        cin >> root;
        for(int j = 1 ; j < size ;j++){
            cin >> next;
            list[root].push_back(next);
            indgree[next]++;
            root = next;
        }
    }
    
    sol();
    if(res.size() != N){ // 사이클이 발생하면 res 사이즈 != N 이다
        cout << 0;
    }else{
        for(int i = 0 ; i < res.size(); i++){
            cout << res[i] << "\n";
        }
    }
    return 0;
}