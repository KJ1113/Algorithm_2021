#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector <int> button;
string number;
bool vist[10];
bool Possible[1000001];
int brokens;
void DFS(string num , int maxsize){
    if(num.size() > maxsize){
        return;
    }
    else{
        for(int idx = 0 ; idx < 10; idx++){
            if(vist[idx]) continue;
            string input = num + to_string(idx);
            if(input.size() <= maxsize ){
                 Possible[stoi(input)] = true;
            }
            DFS(input , maxsize);
        }
    }
}
int main(){
    for(int i = 0 ; i < 10 ;i ++){
        button.push_back(i);
    }
    cin >> number >> brokens;
    int onlyClick = abs(stoi(number)-100);
    int findNum = stoi(number);

    for(int i =0; i < brokens;i++){
        int idx;
        cin >> idx;
        vist[idx] = true;
    }
    DFS("",number.size()+1);
    
    if(Possible[findNum] == false) { // 번호조합만으로 만들수없을떄
        int ansNum = 1000000;
        int ansNum2 = 1000000;
        for(int i = findNum ; i <= 1000000;i++){
            if (Possible[i] ){
                ansNum = i;
                break;
            }
        }
        for(int i = findNum ; i >= 0;i--){
           if (Possible[i] ){
                ansNum2 = i;
                break;
            }
        }
        if(ansNum2 == 1000000 && ansNum == 1000000){
            cout << onlyClick;
        }
        else{
            int a = to_string(ansNum).size()+abs(ansNum - stoi(number)); // 채널이동 + 위아래버튼 클릭수
            int b = to_string(ansNum2).size()+abs(ansNum2 - stoi(number));
            int buttonClick = min( a,b );
            cout << min(buttonClick, onlyClick);
        }        
    }
    else{ // 번호조합으로 만들수있을떄
        int buttonClick = number.size();
        cout << min(onlyClick ,buttonClick); // 버튼만 눌렀을떄 채널이동보다 빠를수있다.
    }
    return 0;
}
