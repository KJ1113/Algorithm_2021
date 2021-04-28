#include <iostream>
#include <queue>
using namespace std;
int N , M;
int oneNum = 0;
char map[101][101];
bool vist[101][101];
int dir[4][2] = { {1,0}, {-1,0} ,{0,1} ,{0,-1}} ;
struct Node{
    int y , x;
    int cnt = 0;
};
struct compare{
	bool operator()(Node a, Node b){
		return a.cnt > b.cnt;
	}
};
void BFS(){
    priority_queue <Node , vector<Node> , compare> pq;
    Node n;
    n.y = 0;
    n.x = 0;
    pq.push(n);
    vist[0][0] = true;

    while (!pq.empty()){
        int cY = pq.top().y;
        int cX = pq.top().x;
        int Ccnt  =pq.top().cnt;
        pq.pop();

        if(cY == N-1 && cX == M-1){
            cout << Ccnt;
            return;
        }    

        for(int k =0; k < 4; k++){
            int nY = cY + dir[k][0];
            int nX = cX + dir[k][1];
            if(nY < 0 || nX < 0|| nY >=N || nX >= M || vist[nY][nX] == true) continue;
            
            Node n;
            n.y = nY;
            n.x = nX;

            if( map[nY][nX] == '0') n.cnt = Ccnt;
            else n.cnt = Ccnt+1;
            
            pq.push(n);
            vist[nY][nX] = true;
        }
    }
}
int main(){
    cin >> M >> N;
    for(int i = 0 ; i < N; i++){
        cin >> map[i];
    }
    BFS();
    return 0;
}