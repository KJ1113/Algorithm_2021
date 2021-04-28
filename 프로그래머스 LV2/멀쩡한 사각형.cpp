#include <iostream>
using namespace std;
long long gcd(long long w , long long h){
    int small;
    int big;
    if(w < h){
        small = w;
        big = h;
    }
    else{
        small = h;
        big = w;
    }
    long long gcd = 1;
    for(int num = 1; num <= small; num++){
        if(small%num ==0 && big % num == 0){
            gcd = num;
        }
    }
    return gcd;
}
long long solution(int w,int h) {
    long long W = (long long)w;
    long long H = (long long)h;
    long long WH = W * H;
        
    return WH - (W+H - gcd(W,H));
}

// 대각선의 규칙을 찾는다.
// 대각선에 겹치는 사각형의 수는 W,H의 최대 공약수이다.