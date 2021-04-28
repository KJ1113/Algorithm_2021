#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int INF = 999999;
int graph[201][201];
void init(int N ,vector<vector<int>> &fares){
    for (int i = 0; i <= N; i++) {
        fill(graph[i], graph[i] + 201, INF);
    }
    for(int i = 0 ;i< fares.size() ;i++){
        int y = fares[i][0];
        int x = fares[i][1];
        graph[y][x] = fares[i][2];
        graph[x][y] = fares[i][2];
    }
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= N;j++){
            if(i==j) graph[i][j] =0; 
        }
    }
}
void floyd(int N ){
    for(int k = 1; k<= N ;k++){
        for(int i = 1; i <= N;i++){
            for(int j = 1; j <= N;j++){
                graph[i][j]  = min ( graph[i][j] , graph[i][k] + graph[k][j]);   
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    init(n,fares);
    floyd(n);
    int ans = graph[s][a] + graph[s][b];
    for(int i = 1 ; i<= n ;i++){
        if(i != s ){
             ans = min(ans , graph[s][i] + graph[i][a] + graph[i][b] );
        }
    }
    return ans;
}