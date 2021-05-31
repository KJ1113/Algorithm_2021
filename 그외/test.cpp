#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> list;


int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N;i++){
        int n ;
        cin >> n;
        list.push_back(n);
    }
    sort(list.begin(),list.end());
    int ans = 99999;
    do{
        ans = min( ans ,abs(list[0]- list[1]) + abs(list[1]-list[2]) + abs(list[2]-list[0]));
    }while (next_permutation(list.begin() , list.end() ));
    cout << ans <<endl;


    sort(list.begin(),list.end());
    cout << abs(list[0]- list[1]) + abs(list[1]-list[2]) + abs(list[2]-list[0]);
}