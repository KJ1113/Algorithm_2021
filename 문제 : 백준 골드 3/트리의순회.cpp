#include <iostream>
using namespace std;
int N;
int postOrder[100001];
int inOrder[100001];
int idx[100001];

void preOrder(int inS , int inE , int postS, int postE){
    if(inS > inE || postS > postE ) return;

    int root = postOrder[postE];
    cout << root <<" ";
    int now = idx[root];
    int left = now - inS;

    preOrder(inS , now -1 , postS, postS + left-1);
    preOrder(now+1 , inE , postS + left, postE -1);
    
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N ;i++){
        cin >> inOrder[i];
    }
    for(int i = 0 ;i < N ; i++){
        cin >> postOrder[i];
    }
    for(int i = 0; i < N ; i++){
        idx[inOrder[i]] = i;
    }
    preOrder(0 , N-1 , 0, N-1);

    return 0;
}