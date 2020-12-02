#include <string>
#include <vector>
#include<map>
using namespace std;
vector<int>v;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> mp;
    for (auto t : clothes) {
        mp[t[1]] += 1;
    }
    for (auto t = mp.begin(); t != mp.end(); t++) {
        v.push_back(t->second + 1);
    }
    int sum = 1;
    for (auto t : v)sum *= t;
    answer = sum;
    return answer - 1;
}
// ÆÄÀÌ½ã 
def solution(clothes) :
    answer = 1
    hash_map = {}
    for a, i in clothes :
hash_map[i] += 1
for i in list(hash_map.values()) :
    answer *= (i + 1)

    return answer - 1