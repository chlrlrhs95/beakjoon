#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

#define INF 987654321

using namespace std;

int N, M, T;
int castle[100][100];
int dist[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int l = 0; l < M; l++) {
			cin >> castle[i][l];
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0,0));

	memset(dist, -1, sizeof(dist));
	dist[0][0] = 0;
	int ret = INF;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[y][x];
		q.pop();

		if (x == M - 1 && y == N - 1) {
			return min(d,ret);
		}

		if (castle[y][x] == 2) {
			ret = d + abs(N - 1 - y) + abs(M - 1 - x);
		}

		for (int dir = 0; dir < 4; dir++) {
			if (x + dx[dir] < 0 || y + dy[dir] < 0 || x + dx[dir] >= M || y + dy[dir] >= N) continue;
			if (castle[y + dy[dir]][x + dx[dir]] == 1) continue;
			if (dist[y + dy[dir]][x + dx[dir]] != -1) continue;

			q.push(make_pair(x + dx[dir], y + dy[dir]));
			dist[y + dy[dir]][x + dx[dir]] = d + 1;
		}
	}
	return ret;
}

int main() {
	input();
	int ret = bfs();
	if (ret <= T) cout << ret;
	else cout << "Fail";
	return 0;
}