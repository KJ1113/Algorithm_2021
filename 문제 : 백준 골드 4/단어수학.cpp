#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int Alpha[27];
vector <string> word;
bool cmp( int a , int b){
    return a > b;
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N ;i++){
        string a;
        cin >> a;
        word.push_back(a);
    }

    for(int idx =0; idx < word.size(); idx++){
        string V = word[idx];
        int pow = 1;

        for(int i = V.size()-1 ; i >= 0 ; i--){
            int pos = V[i] - 'A';
            Alpha[pos] = Alpha[pos] + pow;
            pow = pow * 10;
        }
    }

    sort(Alpha, Alpha + 26, cmp);
    
    int Answer = 0;
    int Num = 9;
    for (int i = 0; i < 26; i++){
        if (Alpha[i] == 0) break;
        Answer = Answer + (Alpha[i] * Num);
        Num--;
    }
    cout << Answer ;
}