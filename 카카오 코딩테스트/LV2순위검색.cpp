#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> qu;
vector<int> answer;
vector <int> dp[3][2][2][2];
void init_info(string str){ // 쿼리 분리
    string tmp = "";
    vector<string> in;
    for(int i = 0; i < str.size() ;i++){
        if(str[i] == ' '){
            in.push_back(tmp);
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    in.push_back(tmp);
    
    int zero = 0  , one = 0 , two = 0, three =0; //인덱스 설정  
    if(in[0] == "java"){
        zero = 0 ;
    }else if(in[0] == "cpp"){
        zero = 1;
    }else{
        zero = 2;
    }
    
    if(in[1] == "backend"){
        one = 0;
    }else{
        one = 1;
    }

    if(in[2] == "junior"){
        two = 0;
    }else{
        two = 1;
    }

    if(in[3] == "chicken"){
        three = 0;
    }else{
        three = 1;
    }
    dp[zero][one][two][three].push_back(stoi(in[4]));
    //cout<<stoi(in[4]) <<endl;
}
void init_query(string str){ // 쿼리 분리
    string tmp = "";
    for(int i = 0; i < str.size() ;i++){
        if(str[i] == ' '){
            if(tmp != "and"){ // 넣을수있는 조건이면
                qu.push_back(tmp);
            }
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    qu.push_back(tmp);
}
void find_querry(){
    int ai , bi , aj , bj , ak, bk, al, bl; //인덱스 범위설정  
    
    if(qu[0] == "java"){
        ai  = 0 , bi = 0;
    }else if(qu[0] == "cpp"){
        ai  = 1 , bi = 1;
    }else if (qu[0] == "python"){
        ai  = 2 , bi = 2;
    }else{
        ai  = 0 , bi = 2;
    }
    
    if(qu[1] == "backend"){
        aj = 0 , bj = 0;
    }else if(qu[1] == "frontend") {
        aj = 1 , bj = 1;
    }else{
        aj = 0 , bj = 1;
    }
    
    if(qu[2] == "junior"){
        ak = 0 , bk = 0;
    }else if(qu[2] == "senior") {
        ak = 1 , bk = 1;
    }else{
        ak = 0 , bk = 1;
    }
    
    if(qu[3] == "chicken"){
        al = 0 , bl = 0;
    }else if(qu[3] == "pizza"){
        al = 1 , bl = 1;
    }else{
        al = 0 , bl = 1;
    }
    
    int cnt = 0;
    //cout <<"q : " <<bi << bj << bk << bl <<endl;
    for(int i  = ai ; i <= bi ; i++){
        for(int j = aj ; j <= bj; j++){
            for(int k = ak ; k <= bk; k++){
                for(int l = al ; l <= bl ; l++){
                    if(dp[i][j][k][l].size() == 0 ) continue;
                    
                    if(qu[4] == "-"){
                        cnt += dp[i][j][k][l].size();
                    }else{ // 이분탐색
                        //val가 처음 발견되는 값반환
                        vector<int>::iterator leftIndex = lower_bound(dp[i][j][k][l].begin(), dp[i][j][k][l].end(), stoi(qu[4])); 
                        cnt +=  dp[i][j][k][l].size() - ( leftIndex - dp[i][j][k][l].begin() );
                    }
                }
            }
        }
    }
    answer.push_back(cnt);
}
vector<int> solution(vector<string> info, vector<string> query) {
    // 1. info dp에 입력
    for(int i = 0 ; i < info.size() ; i++){
        init_info(info[i]);
    }
    // 2. 이분탐색을 위해 정렬
    for(int ai  = 0; ai <= 2 ; ai++){
        for(int aj = 0 ; aj <= 1; aj++){
            for(int ak = 0 ; ak <= 1; ak++){
                for(int al = 0 ; al <= 1 ; al++){
                    sort(dp[ai][aj][ak][al].begin() , dp[ai][aj][ak][al].end() );
                }
            }
        }
    }
    // 3. 쿼리를 나눈후 이분탐색을 통해 범위 크기 구하기
    for(int i = 0 ; i < query.size() ; i++){
        init_query(query[i]);

        find_querry();

        qu.clear();
    }
    return answer;
}