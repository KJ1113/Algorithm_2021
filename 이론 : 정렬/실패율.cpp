#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, float> A, pair<int, float> B) {
    if (A.second == B.second) {
        return A.first < B.first;
    }
    else {
        return A.second > B.second;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> list(N);
    vector<pair<int, float>> cnt_list;

    for (int i = 0; i < stages.size(); i++) {
        int index = stages[i] - 1;
        if (index != N) {
            list[index]++;
        }
    }

    int pass_cnt = 0;
    int people_cnt = stages.size();

    for (int i = 0; i < list.size(); i++) {
        float cal;
        if (people_cnt == pass_cnt) {
            cal = 0;
        }
        else {
            cal = (float)list[i] / (people_cnt - pass_cnt);
        }
        cnt_list.push_back(make_pair(i + 1, cal));
        pass_cnt += list[i];
    }

    sort(cnt_list.begin(), cnt_list.end(), cmp);
    for (int i = 0; i < cnt_list.size(); i++) {
        answer.push_back(cnt_list[i].first);
    }

    return answer;
}