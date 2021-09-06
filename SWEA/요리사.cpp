#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N ,ans = -1;
int map[16][16];
bool vist[16];
void DFS( int index ,int cnt ){
    if(cnt == N/2){
        int s1 =0 ;
        int s2 =0 ;
        vector<int> list;
        vector<int> list2;
        for(int idx = 0 ; idx < N; idx++){
            if(vist[idx]) list.push_back(idx);
            else list2.push_back(idx);

            //if(vist[idx]) cout << idx <<" ";
        }
        //cout <<endl;

        for(int idx = 0 ; idx < list.size() ;idx++){
            for(int jdx = 0 ;jdx < list.size() ; jdx++ ){
                if(idx == jdx) continue;
                s1 += map[list[idx]][list[jdx]];
            }
        }

        for(int idx = 0 ; idx < list2.size() ;idx++){
            for(int jdx = 0 ;jdx < list2.size() ; jdx++ ){
                if(idx == jdx) continue;
                s2 += map[list2[idx]][list2[jdx]];
            }
        }
        //cout << s1 << " " <<s2 <<endl;
        ans = min(ans,abs(s1-s2));

    }else{
        for(int i = index ; i < N ;i++){
            if(vist[i]) continue;
            vist[i] = true;
            DFS(i+1 , cnt+1 );
            vist[i] =false;
        }
    }
}
int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        ans = 1234567;
        cin >> N ;
        for(int i = 0 ; i  < N ;i++){
            for(int j = 0 ; j < N ;j++){
                cin >> map[i][j];
            }
        }

        DFS(0,0);

        cout << "#"<< test_case<<" "<<ans << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}