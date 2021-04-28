#include <iostream>
#include <queue>
using namespace std;
const int INF = 987654321;
int N , K;
int vist[100001];
int p[100001];
int dir[3] = {1, -1 , 2};
vector <int> ans;
void BFS(){
    queue < pair<int,int > > q;
    q.push({N , 0});
    vist[N] = true;

    while (!q.empty()){
        int now = q.front().first;
        int sec = q.front().second;
        int nextPos;
        q.pop();


        if(now == K){
            cout << sec <<endl;
            int curIdx = now;
            while (true){
                if(curIdx == N) break;
                ans.push_back( p[curIdx] );
                curIdx = p[curIdx];
            }
            for(int idx = ans.size() -1 ; idx >= 0 ;idx--){
                cout << ans[idx] <<" ";
            }
            cout << now;
            return;
        }


        for(int k = 0 ; k < 3 ;k++){
            if(k == 2) nextPos = now * dir[k];
            else nextPos = now + dir[k];
            if(nextPos < 0 || nextPos > 100000 || vist[nextPos]) continue;
            p[nextPos] = now;
            vist[nextPos] = true;
            q.push({nextPos , sec+1 });
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    BFS();
    return 0;
}