#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int>q;
queue<pair<int, int>>q1;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    for (auto T : truck_weights)q.push(T);
    int time = 1;
    int cur_w = q.front();
    q1.push({ bridge_length,q.front() });
    q.pop();
    while (!q.empty()) {
        int W = q.front();
        int T = q1.front().first;
        int T_w = q1.front().second;
        if (T == time) {
            q1.pop();
            cur_w -= T_w;
        }
        if (cur_w + W <= weight) {
            q.pop();
            cur_w += W;
            q1.push({ time + bridge_length,W });
        }
        time++;
    }
    answer = time + bridge_length;
    return answer;
}