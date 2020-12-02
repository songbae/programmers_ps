#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int>M;
vector<vector<pair<int, int>>>v;
vector<pair<int, string>>most_album;
vector<vector<pair<int, int>>>ans;
bool cmp(pair<int, string>a, pair< int, string>b) {
    return a.first > b.first;
}
bool cmp1(pair<int, int>a, pair<int, int>b) {
    if (a.first == b.first)return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for (int i = 0; i < plays.size(); i++)M[genres[i]] += plays[i];
    for (auto T : M)most_album.push_back({ T.second,T.first });
    sort(most_album.begin(), most_album.end(), cmp);
    ans.resize(most_album.size());
    for (int i = 0; i < most_album.size(); i++) for (int j = 0; j < plays.size(); j++) if (genres[j] == most_album[i].second)
        ans[i].push_back({ plays[j],j });
    for (int i = 0; i < ans.size(); i++) sort(ans[i].begin(), ans[i].end(), cmp1);
    for (int i = 0; i < ans.size(); i++)for (int j = 0; j < 2 && j < ans[i].size(); j++)
        answer.push_back(ans[i][j].second);
    return answer;
}