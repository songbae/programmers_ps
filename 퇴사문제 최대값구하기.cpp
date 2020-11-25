#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

int day;
int max_num = 0;
vector <pair<int, int>> vec;

void DFS(int num, int sum) {
	if (num > day)
		return;

	max_num = max(max_num, sum);
	for (int i = num; i < day; i++)
		DFS(i + vec[i].first, sum + vec[i].second);
}

int main() {
	cin >> day;
	for (int i = 0; i < day; i++) {
		for (int j = 0; j < 2; j++) {
			int time, money;
			cin >> time >> money;
			vec.push_back(make_pair(time, money));
		}
	}

	for (int i = 0; i < day; i++)
		DFS(i + vec[i].first, vec[i].second);

	cout << max_num << endl;
	return 0;
}