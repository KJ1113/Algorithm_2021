#include <string>
#include <vector>
#include<cmath>
#include <iostream>
using namespace std;
vector <pair<int,int> > div_list;
void makeDiv(int yellow){
    int sq = sqrt(yellow);
    cout << sq <<endl;
    for(int i =1 ; i <= sq  ;i++){
        if( yellow%i ==0){
            div_list.push_back( { i,yellow/i});
        }
    }
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    makeDiv(yellow);
    for(int i = 0 ; i< div_list.size(); i++){
        int length = div_list[i].second +2; // 가로
        int width = div_list[i].first +2; // 세로
        if (length * width == brown + yellow ){
            answer.push_back(length);
            answer.push_back(width);
            return answer;
        }
    }
    return answer;
}