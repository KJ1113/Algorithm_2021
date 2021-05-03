#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int num, x , y;
};
bool cmp (node A , node B){
    return A.x < B.x;
}
bool vist[10001];
vector <int> pre_list;
vector <int> post_list;
vector <node> list;
void init(vector<vector<int>> &nodeinfo){
    for(int i = 0 ; i < nodeinfo.size();i ++){
        node n;
        n.num = i+1;
        n.x = nodeinfo[i][0];
        n.y = nodeinfo[i][1];
        list.push_back(n);
    }
    sort(list.begin() , list.end(), cmp);
} 
void preOrder(int idx , int left , int right){
    
    pre_list.push_back(list[idx].num);
    
    vist[idx] = true;
    int max_left_idx  = -1;
    int max_right_idx = -1;
    int max_left = -1 , max_right  = -1;
    
    // 왼쪽 탐색
    for(int i = left; i < idx ;i++ ){
        if(vist[i] == false && list[idx].y > list[i].y && max_left < list[i].y){
            max_left = list[i].y;
            max_left_idx = i;
        }
    }
    // 오른쪽 탐색
    for(int i = idx+1 ; i< right;i++){
        if( vist[i] == false && list[idx].y > list[i].y && max_right < list[i].y){
            max_right = list[i].y;
            max_right_idx = i;
        }
    }
    
    if(max_left_idx != -1)  preOrder(max_left_idx,left,idx);       
    if(max_right_idx != -1) preOrder(max_right_idx,idx-1,right);
    
    post_list.push_back(list[idx].num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    //1. x 축 기준으로 정렬
    init(nodeinfo);
    
    //2. root 찾기
    int root = -1;
    int max_LV = -1;
    for(int i = 0 ; i < list.size() ;i++){
        if(max_LV < list[i].y){
            max_LV = list[i].y;
            root = i;
        }
    }
    
    //3. 전위 순회 하면서 pre_list , post_list 채워 넣기
    preOrder(root , 0 , list.size());
    answer.push_back(pre_list);
    answer.push_back(post_list);
    
    return answer;
}