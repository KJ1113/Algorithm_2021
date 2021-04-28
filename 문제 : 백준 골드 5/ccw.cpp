#include <iostream>
using namespace std;
int input [3][2];
int s ;
int main(){
    for(int k = 0 ; k < 3 ; k++){
        cin >> input[k][0] >> input[k][1];
    }
    s = (input[1][0] - input[0][0] ) * (input[2][1] - input[0][1] ) - (input[1][1] - input[0][1] ) *(input[2][0] - input[0][0] );  
    if(s > 0){
        cout << 1;
    }else if( s == 0 ){
        cout << 0;
    }else{
        cout << -1;
    }
    return 0;
}
