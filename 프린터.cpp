#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
deque<int>dq;
queue<pii>q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    for (int i = 0; i < size; i++) {
        dq.push_back(priorities[i]);
        q.push({ priorities[i],i });
    }
    sort(dq.begin(), dq.end(), greater<int>());
    answer = 1;
    while (!q.empty()) {
        int p = dq.front();
        auto [a, b] = q.front();
        q.pop();
        if (p == a && b == location)break;
        if (p == a) {//둘이 같을때만 시간++
            dq.pop_front();
            answer++;
        }
        else q.push({ a,b });
    }

    return answer;
}