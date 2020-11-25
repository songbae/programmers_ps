#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX 1000000001
using namespace std;
vector<int>ans;
bool search(int mid, int n) {// ��ü�� Ž���ϸ鼭 n���� ���� ������ �����ϴ��� ���ϴ��� �˻� 
    int t = n;
    vector<int>temp = ans;
    for (int i = 0; i < temp.size() - 1; i++) {
        if (temp[i] <= mid) {
            t--;
            temp[i + 1] += temp[i];
        }
    }
    if (t < 0) return false;// ���� flase�� ���� �ٿ����Ѵ�
    return true;// true�� ���� �ø���.
}
int solution(int distance, vector<int> rocks, int n) {
    int answer = distance;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    for (int i = 0; i < rocks.size(); i++) {
        int x;
        if (i == 0)x = rocks[i] - 0;
        else x = rocks[i] - rocks[i - 1];
        ans.push_back(x);// x�� ������ ������ �Ÿ� 
    }
    ans.push_back(MAX);//���� ó���� �����Ƽ� �ƹ����̳� �ڿ��߰� 
    int st = 0;
    int ed = distance;
    //�ð����⵵ O(n*logn)
    while (st <= ed) {//�̺�Ž������ �����ϴ� ���� ���ϱ� 
        int mid = (st + ed) / 2;
        if (!search(mid, n)) {
            answer = min(answer, mid);
            ed = mid - 1;
        }
        else st = mid + 1;
    }
    return answer;
}