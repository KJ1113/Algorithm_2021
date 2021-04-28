#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
bool p_vist[100001];
bool m_vist[100001];
vector <int> p_num;
vector <int> m_num;
int main(){
    cin >> N;
    for(int i = 1 ; i <= N ;i++){
        int a;
        cin >> a;
        if(a <= 0){
            m_num.push_back(a);
        }else{
            p_num.push_back(a);
        }
    }
    sort(p_num.begin() , p_num.end());
    sort(m_num.begin() , m_num.end());

    int sum = 0;
    if(p_num.size() > 0 ){
        for(int i = p_num.size()-1 ; i >= 1 ;i--){
            if(p_vist[i] == false){
                if(p_num[i] * p_num[i-1] > p_num[i] + p_num[i-1]  ){
                    p_vist[i] = true;
                    p_vist[i-1] = true;
                    sum += p_num[i] * p_num[i-1];
                }else{
                    sum += p_num[i];
                }
            }
        }
        if( p_num.size() > 0 && p_vist[0] == false){
            sum = sum + p_num[0];
        }
    }

    if(m_num.size() > 0 ){
        for(int i = 0 ; i < m_num.size()-1; i++){
            if(m_vist[i] == false){
                if(m_num[i] * m_num[i+1] > m_num[i] + m_num[i+1]){
                    m_vist[i] = true;
                    m_vist[i+1] = true;
                    sum += m_num[i] * m_num[i+1];
                }else{
                    sum += m_num[i];
                }
            }
        }
        if(m_num.size() > 0 &&  m_vist[m_num.size()-1] == false){
            sum = sum + m_num[m_num.size()-1];
        }
    }
    cout << sum ;
    return 0;
}