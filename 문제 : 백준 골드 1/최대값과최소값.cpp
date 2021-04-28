#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N , M;
int const MAX = 100001;
int num [100001];
pair<int,int> tree [MAX * 4];
// 세그먼트 트리

pair<int,int>  find(int start , int end , int nodeIdx ,int left ,int right){
    // 범위 벗어남
    if(left > end || right < start) return { 1000000001 , 0} ;
    // 범위에 들어옴
    if ( left <= start && end <= right) return tree[nodeIdx];
    // 한쪽만 만족
    int mid = (start + end) >> 1;
    pair<int,int> leftp = find( start, mid , nodeIdx*2 ,left , right);
    pair<int,int> rightp = find( mid+1, end , nodeIdx*2 +1 ,left , right);

    pair<int,int> tmp;

    tmp.first = min(leftp.first, rightp.first);
    tmp.second = max(leftp.second, rightp.second);

    return tmp;
}
pair<int,int> init(int start , int end , int nodeIdx ){
    if(  start  == end ){
        tree[nodeIdx].first =  num[start];
        tree[nodeIdx].second =  num[start];
        return tree[nodeIdx];
    }
    int mid = (start+end)>>1;
    pair<int,int> left = init(start , mid, nodeIdx*2 );
    pair<int,int> right = init(mid +1, end, nodeIdx*2 + 1 );
    tree[nodeIdx].first = min(left.first, right.first);
    tree[nodeIdx].second =  max(left.second, right.second);
    return tree[nodeIdx];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }
    init( 1 , N , 1 );

    for(int m = 0 ; m < M ; m++){
        int a ,b;
        cin >> a >> b;
        pair<int,int> ans = find(1,N,1,a,b );
        cout << ans.first << " "<<ans.second <<"\n";
    }
    return 0;
}