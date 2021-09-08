#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100;
int map[MAX][MAX];
bool visted[MAX][MAX];
int N, M, R, C, T;
int dir[4][2] = { {-1,0} ,{1,0}, {0,-1} ,{0,1} };
int ans = 0;
bool checkGo(int input, int i)
{
    if (input == 1)
    {
        return true;
    }
    else if (input == 2)
    {
        if (i == 0 || i == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (input == 3)
    {
        if (i == 2 || i == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (input == 4)
    {
        if (i == 0 || i == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (input == 5)
    {
        if (i == 1 || i == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (input == 6)
    {
        if (i == 1 || i == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (i == 0 || i == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool checkIn(int checkblock, int inputdir)
{
    if (inputdir == 0)
    {
        //cout << "checkblock : "<< checkblock;
 
        if (checkblock == 1 || checkblock == 2 || checkblock == 5 || checkblock == 6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (inputdir == 1)
    {
        if (checkblock == 1 || checkblock == 2 || checkblock == 4 || checkblock == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (inputdir == 2)
    {
        if (checkblock == 1 || checkblock == 3 || checkblock == 4 || checkblock == 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (checkblock == 1 || checkblock == 3 || checkblock == 6 || checkblock == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool sizeCheck(int  y, int x)
{
    if (y < 0 || y >= N || x < 0 || x >= M)
    {
        return false;
    }
    return true;
}
void BFS(int startY, int startX){

    int realT = 1;
    queue <pair <int, int>> q;
    q.push({startY, startX});
 
    visted[startY][startX] = true;
    while (!q.empty()){
        int sz = q.size();
        for (int size = 0; size < sz; size++){
            ans++;
            int cony = q.front().first;
            int conx = q.front().second;
            q.pop();
 
            for (int i = 0; i < 4; i++){
                if (checkGo(map[cony][conx], i)){

                    int nextY = cony + dir[i][0];
                    int nextX = conx + dir[i][1];
 
                    if (sizeCheck(nextY, nextX) && map[nextY][nextX] != 0){
                        if (visted[nextY][nextX] == false) { 
 
                            if (checkIn(map[nextY][nextX], i) == true) // 갈수있다면
                            {
                                visted[nextY][nextX] = true;
                                q.push(pair <int, int >(nextY, nextX));
                            }
                        }
 
                    }
                }
            }
        }
 
        if (realT == T)
        {
            break;
        }
        realT++;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int TC;
    scanf("%d", &TC);
 
    for (int testcase = 0; testcase < TC; testcase++){
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &T);
 
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                scanf("%d", &map[i][j]);
                visted[i][j] = false;
            }
        }
        BFS(R, C);
        printf("#%d %d\n", testcase + 1, ans);
        ans = 0;
    }
    return 0;
}