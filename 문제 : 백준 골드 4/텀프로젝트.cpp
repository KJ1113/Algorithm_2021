#include <iostream>

using namespace std;
int point[100001];
bool vist[100001];
bool done[100001];
int TC , N , sum ;
void DFS(int Num ){
    vist[Num] = true;
    int next = point[Num];
    if(! vist[next] ) {
        DFS(next);
    }
    else{
        if(vist[next] == true &&! done[next] ){ // = if(vist[next] == true  && !done[next])
            int cnt = 1;
            int n = point[Num]; // 현재 검사하고 있는 위치의 사이클 크기  
            while (true){
                if(n == Num) break;
                n = point[n];
                cnt ++ ;
            }
            sum += cnt;
        }
    }
    done[Num] = true; 
}
void init(){
    sum = 0;
    for(int i = 1 ; i <= N ;i++){
        vist[i] = false;
        done[i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> TC;
   
    for(int tc = 0; tc < TC; tc++){
        cin >> N;
        init();
        for(int i = 1; i <= N ; i++){
            cin >> point[i];
        }
        for(int i = 1; i <= N ; i++){
            if(vist[i] == false) DFS(i);
        }
        cout << N - sum <<endl;
    }
    return 0;
}