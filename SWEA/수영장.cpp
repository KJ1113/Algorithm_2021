
#include <iostream>
#include <iostream>
using namespace std;
int ans = 0 ;
int cost[4];
int month[13][4];

void dfs(int m , int sum ){
    if (m > 12){
        ans = min(ans , sum);
    }else{
        dfs( m + 1 , sum + month[m][1] );
        dfs( m + 1 , sum + month[m][2] );
        dfs( m + 3 , sum + month[m][3] );
    }
}
int main(int argc, char** argv){
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        ans = 12345678;
        cin >> cost[0] >> cost[1] >> cost[2] >>cost[3];
        for(int i = 1 ; i <= 12 ;i++){
            cin >> month[i][0];
        }

        for(int i = 1 ; i <= 12 ;i++){
            month[i][1] = cost[0] * month[i][0];
            month[i][2] = cost[1];
            month[i][3] = cost[2];
        }
        dfs(1,0);
        cout << "#" <<test_case <<" "<<min( ans , cost[3]) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}