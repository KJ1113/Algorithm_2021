#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , M;
vector <int> list;

int main(){
    cin >> N >> M;
    list.push_back(-1);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N ; j++){
            list.push_back( i*j );
        }
    }
    sort(list.begin() , list.end());
    for(int i = 1 ; i < list.size() ; i++){
        cout << list[i] <<" ";
    }
    cout<<endl;
    cout << list[M] <<endl;

    

    return 0;
}
