#include <iostream>
#include <vector>
using namespace std;
int N , M ,tNum , root ,ans = 0;
int parents[51];
vector <int> know_member;
vector <int> party[51];
void init(){
    for(int i = 1 ; i <= N ;i++){
        parents[i] = i;
    }
}
int find(int a ){
    if(parents[a] == a) return parents[a];
    return parents[a] = find(parents[a]);
}
void unionParent(int a ,int b){
    int A = find(a);
    int B = find(b);
    if(A < B) parents[B] = A;
    else parents[A] = B;
}
int main(){
    cin >> N >> M >> tNum;
    init();

    // input && union
    for(int i = 0 ; i < tNum ; i++){
        int input;
        cin >> input;
        know_member.push_back(input);
    }

    for(int tc = 0 ; tc < M ; tc++){
        vector <int> tmp_list;
        int cnt;
        cin >> cnt;
        for(int i = 0 ; i < cnt ;i++){
            int c;
            cin >> c;
            tmp_list.push_back(c);
        }
        int tmp = tmp_list[0];
        for(int i = 1 ; i < tmp_list.size() ;i++){
            unionParent(tmp,tmp_list[i] );
        }
        party[tc] = tmp_list;
    }

    // sol
    for(int tc = 0 ; tc < M ; tc++){
        bool flag =true;
        for(int i = 0 ; i < party[tc].size() ; i ++){
            if(flag == false) break;
            int num = party[tc][i];
            for(int j =0; j< know_member.size() ;j++){
                if(find(know_member[j]) == find (num) ){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans++;
    }
    cout << ans ;
    return 0;
}
