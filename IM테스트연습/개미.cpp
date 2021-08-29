#include <iostream>

using namespace std;
int dir[4][2] = { {1,1}, {-1,1}, {-1,-1}, {1,-1}};
int main(){
    // x , y
    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    p += t;
    q += t;

    p = p % (2 * w); // x 축 이동거리 
    q = q % (2 * h);

    if(w < p ){
        p = 2*w - p;
    }
    if(h < q ){
        q = 2*h - q;
    }
    cout << p << " " << q <<endl;
    
    

    return 0 ;
}