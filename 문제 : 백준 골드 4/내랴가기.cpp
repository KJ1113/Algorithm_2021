#include <iostream>
#include <algorithm>
using namespace std;
int N , cnt = 0;
int priDp[2][3],curDp[2][3];
int a ,b, c;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> priDp[0][0] >> priDp[0][1] >> priDp[0][2];
    priDp[1][0] = priDp[0][0];
    priDp[1][1] = priDp[0][1];
    priDp[1][2] = priDp[0][2];

    while (cnt != N-1){
        
        cin >> a >> b >> c;

        curDp[0][0] = min(priDp[0][0]+ a, priDp[0][1]+ a );
        curDp[1][0] = max(priDp[1][0]+ a, priDp[1][1]+ a );

        curDp[0][1] = min(priDp[0][1]+ b, min ( priDp[0][0]+ b , priDp[0][2]+ b ));
        curDp[1][1] = max(priDp[1][1]+ b, max ( priDp[1][0]+ b , priDp[1][2]+ b ));

        curDp[0][2] = min(priDp[0][2]+ c, priDp[0][1]+ c );
        curDp[1][2] = max(priDp[1][2]+ c, priDp[1][1]+ c );

        priDp[0][0] = curDp[0][0];
        priDp[0][1] = curDp[0][1];
        priDp[0][2] = curDp[0][2];

        priDp[1][0] = curDp[1][0];
        priDp[1][1] = curDp[1][1];
        priDp[1][2] = curDp[1][2];
        cnt++;
    }
    cout << max(priDp[1][0] , max (priDp[1][1] ,priDp[1][2] ) ) << " " << min( priDp[0][0], min(priDp[0][1],priDp[0][2]) );
    return 0;
}