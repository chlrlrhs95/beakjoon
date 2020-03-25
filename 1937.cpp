#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[500][500];
int cache[500][500];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int l = 0; l < N; l++) {
			cin >> arr[i][l];
		}
	}

}

int dfs(int x,int y) {
	
	int &ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
	
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (arr[y][x] >= arr[ny][nx]) continue;

		int next = dfs(nx, ny);
		ret = max(ret, next+1);
	}

	return ret;
}

void sol() {
	memset(cache, -1, sizeof(cache));
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int l = 0; l < N; l++) {
			ret = max(dfs(l, i),ret);
		}
	}
	cout << ret << endl;
}

int main() {
	input();
	sol();
	return 0;
}