#include <string>
#include <vector>
#include <algorithm>
#define MAX  1e18
using namespace std;

long long solution(int k, vector<int> times) {
    long long answer = 0;
    long long n = k;
    sort(times.begin(), times.end(), greater<int>());
    long long start = 1;
    long long end = times[0] * n;
    answer = MAX;
    while (start <= end) {//mid���� �������� sum���� ū�� ��������  mid���� ����
        long long sum = 0;
        long long  mid = (end + start) / 2;
        for (int i = 0; i < times.size(); i++)sum += mid / times[i];
        if (sum >= n) {
            answer = min(mid, answer);
            end = mid - 1;
        }
        else if (sum < n) start = mid + 1;
    }
    return answer;
}