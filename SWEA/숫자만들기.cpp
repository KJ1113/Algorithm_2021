///////////////////////////////////////////////////
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 12345678;

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int min_res = INF;
        int max_res = -INF;
        int N ,p , m , t ,d ; // + - * /
        cin >> N >> p >> m >> t >> d;

        vector<int> num;
        vector<char> op;

        for(int i = 0 ; i < N ;i++){
            int input;
            cin >> input;
            num.push_back(input);
        }

        for(int i = 0  ; i < p ; i ++){
            op.push_back('+');
        }

        for(int i = 0  ; i < m ; i ++){
            op.push_back('-');
        }

        for(int i = 0  ; i < t ; i ++){
            op.push_back('*');
        }

        for(int i = 0  ; i < d ; i ++){
            op.push_back('/');
        }
        sort(op.begin() ,op.end());

        do{
            int res = num[0];
            
            for(int i = 1 ; i <= op.size() ;i++){
                
                if(op[i-1] == '+')
                    res +=  num[i];
                if(op[i-1] == '-')
                    res -= num[i];
                if(op[i-1] == '*')
                    res *= num[i];
                if(op[i-1] == '/')
                    res /= num[i];
            }
            min_res = min(res, min_res);
            max_res = max(res, max_res);

        }while (next_permutation(op.begin() ,op.end()));

        cout << "#" << test_case <<" "<<max_res - min_res << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}