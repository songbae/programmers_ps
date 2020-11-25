#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m, k;
bool check[31][11][11];
int ans = 4;
bool move() {
	bool ok = false;
	for(int i=1; i<=n; i++){
		int cur = i;
		for (int j = 1; j <= k; j++) {
			if (check[j][cur][cur - 1])cur--;
			else if (check[j][cur][cur + 1])cur++;
	}
		if (cur == i)continue;
		else {
			ok = true;
			break;
		}
	}
	if (!ok)return true;
	else return false;

}
void choose(int num,int indexa, int indexb, int target) {
	if (num == target) {
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j <= n+1; j++) {
				if (check[i][j][j + 1])cout << "1"<<" ";
				else cout << "0"<<" ";
			}
			cout << endl;
		}
		cout << endl;
		if (move()) {
			cout << num;
			exit(0);
		}
		return;
	}
	for (int i = indexa; i <= k; i++) {
		for (int j = indexb; j <= n; j++) {
			if (check[i][j][j] || check[i][j][j+2])continue;
			check[i][j][j+1] = true;
			choose(num + 1, i, j, target);
			check[i][j][j+1] = false;
		}
		indexb = 1;
	}
}
int main() {
	cin >> n >> m >> k;
	for (; m--;) {
		int a, b; cin >> a >> b;
		check[a][b][b+1] = true;
	}
	for (int i = 0; i <= 3; i++)choose(0,1,1,i);
	
	cout << "-1";
}