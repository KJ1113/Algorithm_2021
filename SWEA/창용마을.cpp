#include<iostream>
#include <set>
#include <vector>
using namespace std;
int N , M; //사람수와 서로알고있는 사람 수
bool vist [1001];
vector <int> my_Ne_list [1001];

void DFS(int num ){
    vist[num] = true;
    for(int idx = 0 ; idx < my_Ne_list[num].size() ;idx++){

        int next = my_Ne_list[num][idx];
        if(vist[next] == false){
            DFS(next);
        }
    }
}
int main(int argc, char** argv){
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int ans = 0;

        cin >> N >> M;
        for(int num = 1; num <= N ;num++){
            my_Ne_list[num].clear();
            vist[num] =false;
        }

        for(int i = 0 ; i < M  ;i++){
            int a , b;
            cin >> a >> b;
            my_Ne_list[a].push_back(b);
            my_Ne_list[b].push_back(a);
        }

        for(int num = 1; num <= N ;num++){
            if(vist[num] == false){
                DFS(num);
                ans ++;
            }
        }
        if(M==0) ans = N;


        cout <<"#"<<test_case<<" "<<ans <<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}