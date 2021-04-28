#include <iostream>
#include <algorithm>
using namespace std;
int k , height, width;
int ans = -1;
string arr[50];
int main(){
    cin >> height >> width;
    for (int y = 0; y < height; y++){
        cin >> arr[y];
    }
    cin >> k;
    for (int i = 0; i < height; i++){
        int zeroCount = 0;
        for (int h = 0; h < width; h++){
            if (arr[i][h] == '0'){
                zeroCount++;
            }
        }
        int sum = 0;
        if (zeroCount <= k && zeroCount % 2 == k % 2){ // 같은 홀수이거나 , 짝수여야한다.
            for (int y = 0; y < height; y++){
                if (arr[i] == arr[y]){ // 같은 패턴 찾기
                    sum++;
                }
            }
        }
        ans = max(sum, ans);
    }
    cout << ans;
    return 0;
}