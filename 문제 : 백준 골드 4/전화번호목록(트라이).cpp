#include<iostream>
#include<string>
 
#define endl "\n"
#define LEN_MAX 11
#define N_MAX 10010
#define NODE_MAX N_MAX * LEN_MAX
using namespace std;
 
struct TRIE
{
    bool Finish;
    TRIE *Node[LEN_MAX];
    
    void Insert(char *Str);
    bool Call(char *Str);
};
 
int N, N_Idx;
char Phone[N_MAX][LEN_MAX];
string Answer;
TRIE *Root, Nodepool[NODE_MAX];
 
TRIE *Nodeset()
{
    TRIE *NewNode = &Nodepool[N_Idx++];
    NewNode->Finish = false;
    for (int i = 0; i < LEN_MAX; i++) NewNode->Node[i] = NULL;
    
    return NewNode;
}
 
void TRIE::Insert(char *Str)
{
    if (*Str == NULL)
    {
        Finish = true;
        return;
    }
 
    int Cur = *Str - '0';
    if (Node[Cur] == NULL) Node[Cur] = Nodeset();
    Node[Cur]->Insert(Str + 1);
}
 
bool TRIE::Call(char *Str)
{
    if (*Str == NULL) return true;
    if (Finish == true) return false;
 
    int Cur = *Str - '0';
    return Node[Cur]->Call(Str + 1);
}
 
void Initialize()
{
    N_Idx = 0;
    Root = Nodeset();
}
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Phone[i];
}
 
void Solution()
{
    for (int i = 0; i < N; i++) Root->Insert(Phone[i]);
    bool Flag = true;
    for (int i = 0; i < N; i++)
    {
        if (Flag == true) Flag = Root->Call(Phone[i]);
        if (Flag == false) break;
    }
 
    if (Flag == true) Answer = "YES";
    else Answer = "NO";
}
 
void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
 
        cout << Answer << endl;
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
