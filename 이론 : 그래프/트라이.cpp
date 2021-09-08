
#include <iostream>
#include <vector>

#define LEN_MAX 11
#define N_MAX 10010
#define NODE_MAX N_MAX * LEN_MAX

using namespace std;

struct TRIE
{
    bool Finish;
    TRIE *Node[26];
    TRIE() 
    { 
        Finish = false;  
        for (int i = 0; i < 26; i++) Node[i] = NULL;
    }
    void Insert(char *Str);
    bool Find(char *Str);
    void IsSorting(TRIE *N, char Str[], int Idx);
};

void TRIE :: Insert(char *Str)
{
    if (*Str == NULL)
    {
        Finish = true;
        return;
    }
 
    int Cur = *Str - 'A';
    if (Node[Cur] == NULL) Node[Cur] = new TRIE();
    Node[Cur]->Insert(Str + 1);
};
bool TRIE :: Find(char *Str)
{
    if (*Str == NULL)
    {
        if (Finish == true) return true;
        return false;
    }
    int Cur = *Str - 'A';
    if (Node[Cur] == NULL) return false;
    return Node[Cur]->Find(Str + 1);
};
void TRIE :: IsSorting(TRIE *N, char Str[], int Idx)
{
    if (N->Finish == true) cout << Str << endl;
    for (int i = 0; i < 26; i++)
    {
        if (N->Node[i] != NULL)
        {
            char C = i + 'A';
            Str[Idx] = C;
            N->IsSorting(N->Node[i], Str, Idx + 1);
        }
    }
};
 
int main(void)
{
    TRIE *Root = new TRIE();
    char *String[5];
    String[0] = "ZYX";
    String[1] = "BCG";
    String[2] = "ABC";
    String[3] = "BDE";
    String[4] = "ABCD";
 
    for (int i = 0; i < 5; i++)
    {
        Root->Insert(String[i]);
    }
 
    for (int i = 0; i < 26; i++)
    {
        if (Root->Node[i] != NULL)
        {
            char Str[5] = { NULL };
            Str[0] = i + 'A';
            Root->IsSorting(Root->Node[i], Str, 1);
        }
        
    }
}
