#include <iostream>
#include <algorithm>
using namespace std;
int N,M ;
int main(){
    cin >> N >> M;
    int big , small;
    int sliceFood = N % M;
    if(N > M ){
        big  = N;
        small = M;
    }
    else{
        big  = N;
        small = M;
    }
    int gcd = 1;
    for(int i = 1 ; i <= small; i++){
        if(big% i == 0 && small % i ==0){
            gcd = i;
        }
    }
    cout << M - gcd  <<endl;
    return 0;
}