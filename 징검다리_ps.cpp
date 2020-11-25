#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX 1000000001
using namespace std;
vector<int>ans;
bool search(int mid, int n) {// 전체를 탐색하면서 n개를 빼도 조건을 만족하는지 안하는지 검사 
    int t = n;
    vector<int>temp = ans;
    for (int i = 0; i < temp.size() - 1; i++) {
        if (temp[i] <= mid) {
            t--;
            temp[i + 1] += temp[i];
        }
    }
    if (t < 0) return false;// 값이 flase면 값을 줄여야한다
    return true;// true면 값을 올린다.
}
int solution(int distance, vector<int> rocks, int n) {
    int answer = distance;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    for (int i = 0; i < rocks.size(); i++) {
        int x;
        if (i == 0)x = rocks[i] - 0;
        else x = rocks[i] - rocks[i - 1];
        ans.push_back(x);// x는 돌멩이 사이의 거리 
    }
    ans.push_back(MAX);//끝값 처리가 귀찮아서 아무값이나 뒤에추가 
    int st = 0;
    int ed = distance;
    //시간복잡도 O(n*logn)
    while (st <= ed) {//이분탐색으로 만족하는 조건 구하기 
        int mid = (st + ed) / 2;
        if (!search(mid, n)) {
            answer = min(answer, mid);
            ed = mid - 1;
        }
        else st = mid + 1;
    }
    return answer;
}