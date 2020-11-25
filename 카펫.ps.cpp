#include <string>
#include <vector>
#include <math.h>
using namespace std;
vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	for (int i = 1; i <= sqrt(yellow); i++) {
		if (yellow % i == 0) {
			int k = yellow / i;
			if (brown == i * 2 + k * 2 + 4) {
				answer.push_back(k + 2);
				answer.push_back(i + 2);
			}
		}
	}
	return answer;
}