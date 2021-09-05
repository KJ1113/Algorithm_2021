#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
bool vist[6][6];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void init_vist(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            vist[i][j] = false;
        }
    }
}
vector<int> solution(vector<vector<string> > places){
    vector<int> answer;
    for (int i = 0; i < places.size(); i++){
        vector<pair<int, int> > p_list;
        for (int j = 0; j < places[i].size(); j++){
            for (int idx = 0; idx < places[i][j].size(); idx++){
                if (places[i][j][idx] == 'P'){
                    p_list.push_back({j, idx});
                }
            }
        }
        
        bool ok = true;
        for (int idx = 0; idx < p_list.size(); idx++){
            init_vist();
            int py = p_list[idx].first;
            int px = p_list[idx].second;

            queue<pair<int, int> > q;
            q.push({py, px});
            vist[py][px] = true;

            int lenth = 0;
            while (!q.empty()){
                lenth++;
                int qsize = q.size();
                for (int k = 0; k < qsize; k++){
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++){
                        int ny = cy + dir[k][0];
                        int nx = cx + dir[k][1];
                        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || vist[ny][nx])
                            continue;

                        if (places[i][ny][nx] == 'O'){
                            q.push({ny, nx});
                            vist[ny][nx] = true;
                        }
                        else if (places[i][ny][nx] == 'P'){
                            ok = false;
                            break;
                        }else{ // X
                            continue;
                        }
                    }
                }
                if (ok == false || lenth == 2) break;
            }
            if (ok == false) break;
        }
        if (ok) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}