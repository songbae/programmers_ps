#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    int index = 0;
    while (index < n) {
        for (int i = 0; i < n; i++) {
            progresses[i] += speeds[i];
        }
        if (progresses[index] >= 100) {
            int cnt = 1;
            index++;
            while (index < n && progresses[index] >= 100) {
                index++;
                cnt++;
            }
            answer.push_back(cnt);
        }
    }
    return answer;
}