#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;
int graph[101][101];
int n,m;
void init(){
    // 모든 지점간의 거리값을 INF 로 초기화
    for (int i = 0; i < 101; i++) {
        fill(graph[i], graph[i] + 101, INF);
    }

    // 자기자신을 갈수없으므로 0 으로 초기화
    for(int a= 1; a <=n ;a++){
        for(int b= 1; b <=n ;b++){
            if(a==b) graph[a][b] =0;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i =0 ; i<m ;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(c < graph[a][b]) graph[a][b] = c;
    }
    for(int k= 1; k <=n ;k++){
        for(int a= 1; a <=n ;a++){
            for(int b= 1; b <=n ;b++){
                graph[a][b] = min (graph[a][b],graph[a][k]+ graph[k][b] );
            }
        }
    }
    for(int a= 1; a <=n ;a++){
        for(int b= 1; b <=n ;b++){
            if (graph[a][b] == INF) {
                cout << 0 << ' ';
            }
            // 도달할 수 있는 경우 거리를 출력
            else {
                cout << graph[a][b] << ' ';
            }
        }
        cout<<"\n";
    }
    return 0;
}