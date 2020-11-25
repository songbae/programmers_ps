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
void prime(int T) {// 소수 미리 찾아놓기 에라토네스체
    for (int i = 2; i * i < pow(10, T); i++) {
        for (int j = i; j < pow(10, T); j += i) {
            if (check[i])break;
            if (j != i && j % i == 0)check[j] = true;
        }
    }
}
void dfs(int num, int target) {//조합으로 모든수 찾기 
    if (num == target) {
        string s = "";
        for (auto p : ans)s += to_string(p);
        cout << stoi(s) << " " << answer << " ";
        if (!check[stoi(s)]) {//소수일때 
            if (!m.count(stoi(s))) {//같은값을 추가했는지 안했는지 검사 
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
    prime(Size);//소수를 어디까지 찾을 지
    for (int i = 0; i < numbers.size(); i++)v.push_back(numbers[i] - '0');
    for (int i = 1; i <= numbers.size(); i++)dfs(0, i);//조합하기
    return answer;
}