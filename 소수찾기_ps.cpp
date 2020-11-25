#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;
vector<int>v;
bool check[10000000] = { true,true, };
bool check1[8];
map<int, int>m;
vector<int>ans;
int answer = 0;
void prime(int T) {// �Ҽ� �̸� ã�Ƴ��� ������׽�ü
    for (int i = 2; i * i < pow(10, T); i++) {
        for (int j = i; j < pow(10, T); j += i) {
            if (check[i])break;
            if (j != i && j % i == 0)check[j] = true;
        }
    }
}
void dfs(int num, int target) {//�������� ���� ã�� 
    if (num == target) {
        string s = "";
        for (auto p : ans)s += to_string(p);
        cout << stoi(s) << " " << answer << " ";
        if (!check[stoi(s)]) {//�Ҽ��϶� 
            if (!m.count(stoi(s))) {//�������� �߰��ߴ��� ���ߴ��� �˻� 
                m[stoi(s)]++;
                answer++;
            }
        }
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (check1[i])continue;
        check1[i] = true;
        ans.push_back(v[i]);
        dfs(num + 1, target);
        check1[i] = false;
        ans.pop_back();
    }
}
int solution(string numbers) {
    int Size = numbers.size();
    prime(Size);//�Ҽ��� ������ ã�� ��
    for (int i = 0; i < numbers.size(); i++)v.push_back(numbers[i] - '0');
    for (int i = 1; i <= numbers.size(); i++)dfs(0, i);//�����ϱ�
    return answer;
}