#include <iostream>
#include <vector>

#define LEN_MAX 11
#define N_MAX 10010
#define NODE_MAX N_MAX * LEN_MAX

using namespace std;

vector<string> str_list;
int N , N_Idx ;
char Phone[N_MAX][LEN_MAX];

struct TRIE{
    bool Finish;
    TRIE *Node[LEN_MAX]; // 11 인 이유는 1 ~ 10 이기 떄문

    void Insert(char *Str);
    bool Call(char *Str);
};
TRIE *Root , Nodepool[NODE_MAX];
TRIE *Nodeset(){
    TRIE *NewNode = &Nodepool[N_Idx++]; 
    NewNode -> Finish = false;

    for(int i = 0; i < LEN_MAX; i++) NewNode -> Node[i] = NULL;
    return NewNode;
}

void TRIE :: Insert(char *Str){
    if(*Str == NULL){
        Finish = true;
        return;
    }

    int Cur = *Str - '0';
    if(Node[Cur] == NULL) Node[Cur] = Nodeset();
    Node[Cur] -> Insert(Str + 1);
}
bool TRIE:: Call(char *Str){
    if(*Str == NULL) return true;
    if(Finish == true) return false;

    int Cur = *Str -'0';
    return Node[Cur] -> Call(Str+1);
}
void Input(){
    cin >> N;
    for(int i = 0 ; i< N ; i++) cin >> Phone[i];
}
void Solution(){
    
}

int main(){
    int tc;
    cin >> tc;
    for(int tast_case = 0 ; tast_case < tc ;tast_case++){
        str_list.clear();

        string input;
        cin >> input;
        str_list.push_back(input);


    }

    return 0;
}