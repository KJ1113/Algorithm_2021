#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1000001;
int N;
int parents[MAX];
void BFS(int a){
    queue <int > q;
    q.push(a);
    
    while (!q.empty()){
        int curNum = q.front();
        q.pop();

        if(curNum == 1){
            int tmpNum = curNum;
            vector<int> v;
            while (true){
                v.push_back(tmpNum);
                if(tmpNum == N) break;
                tmpNum = parents[tmpNum];
            }
            cout << v.size()-1 << endl;
            for(int i = v.size()-1 ; i >= 0 ;i --){
                cout << v[i]<<" ";
            }
            return;
        }else{
            int nextNum;
            if(curNum % 3 == 0){
                nextNum = curNum / 3;
                if(parents[nextNum] == 0){
                    parents[nextNum] = curNum;
                    q.push(nextNum);
                }  
            }

            if(curNum % 2 ==0){
                nextNum = curNum / 2;
                if(parents[nextNum] == 0){
                    parents[nextNum] = curNum;
                    q.push(nextNum);
                }
            }

            if(curNum - 1 > 1){
                nextNum = curNum - 1;
                if(parents[nextNum] == 0){
                    parents[nextNum] = curNum;
                    q.push(nextNum);
                }
            }
        }
    }
}
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    BFS(N);

    return 0 ;
}