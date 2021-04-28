#include <iostream>
using namespace std;
long dp[201][201];
int main(){
    int N,K,mod=1000000000;
    cin>>N>>K;
    
    //dp[k][n]=k개 더해서 n나오는 경우의 수
    for(int n=0;n<=N;n++){
        dp[1][n]=1; //0,1,2,3,...N
    }
    
    for(int k=2;k<=K;k++){
        for(int n=0;n<=N;n++){
            for(int l=0;l<=n;l++){
                dp[k][n]+=dp[k-1][l];
            }
            dp[k][n]%=mod;
        }
    }
    
    cout<<dp[K][N]<<endl;
    
    return 0;
}