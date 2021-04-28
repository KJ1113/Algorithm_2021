#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
vector <pair <int, int > > v;
const int INF = 987654321;
int N ;
int dp[501][501];
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({ a , b });
    }
    for(int i = 0 ; i < v.size()-1 ;i++){
        dp[i][i+1] = v[i].first * v[i].second * v[i+1].second;
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ;j < N ;j++){
            cout << dp[i][j] <<" ";
        }
        cout<<endl;
    }

    
    
    for(int k = 2 ; k < N ; k++){
        for(int start = 0; start < N - k; start++){
            int end = start + k;
            for(int mid = start ; mid < end; mid ++){
                int tmp = v[start].first * v[mid+1].first * v[end].second;
                dp[start][end] = min( dp[start][end], dp[start][mid]+ dp[mid+1][end] + tmp ); 
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ;j < N ;j++){
            cout << dp[i][j] <<" ";
        }
        cout<<endl;
    }

}