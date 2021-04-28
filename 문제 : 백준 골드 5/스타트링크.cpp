#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 987654321;
int F, S, G, U, D;
int dir[2];
int push[100001];
int main(){
    cin >> F >> S >> G >> U>> D;
    dir[0] = +U;
    dir[1] = -D;

    for(int i = 1 ; i <= F ;i++){
        push[i] = INF;
    }

    queue <pair<int,int> > q;
    q.push( {S, 0});
    push[S] = 0;
    int time = 0;
    while (!q.empty()){
        int qsize = q.size();
        int curS = q.front().first;
        int curPush = q.front().second;
        q.pop();
        for(int k = 0; k < 2 ;k++){
            int nextS = curS + dir[k];
            int nextPush = curPush +1;
            if(nextS <= 0 || nextS > F) continue;
            if(nextPush < push[nextS]){
                push[nextS] = nextPush;
                q.push({nextS , nextPush});
            }
        }
    }


    if(push[G] == INF){
        cout << "use the stairs" <<endl;
    }
    else{
        cout << push[G] <<endl;
    }
    return 0 ;
}