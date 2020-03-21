#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

pair<int, int> start;
vector<pair<int, int>> gift;
char classRoom[50][50];
int dist[50][50][4][2][2];

// 0:³² 1:ºÏ 2:µ¿ 3:¼­
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M;


void input() {
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int l = 0; l < M; l++) {
			cin >> classRoom[i][l];
			if (classRoom[i][l] == 'S') {
				start.first = l;
				start.second = i;
			}
			else if (classRoom[i][l] == 'C') {
				if (cnt != 0) {
					classRoom[i][l] = 'D';
				}
				cnt++;
			}
		}
	}
}

struct Info {
	int x;
	int y;
	int dir;
	int isC;
	int isD;
};

int bfs() {
	queue<Info> q;
	memset(dist, -1, sizeof(dist));

	for (int dir = 0; dir < 4; dir++) {
		q.push({start.first,start.second,dir,0,0});
		dist[start.second][start.first][dir][0][0] = 0;
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int isC = q.front().isC;
		int isD = q.front().isD;
		int d = dist[y][x][dir][isC][isD];
		q.pop();

		
		if (isC & isD) {
			return dist[y][x][dir][isC][isD];
		}

		for (int next = 0; next < 4; next++) {
			int nx = x + dx[next];
			int ny = y + dy[next];
			int NisC = isC;
			int NisD = isD;
			if (dir == next) continue;
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (dist[ny][nx][next][isC][isD] != -1) continue;
			if (classRoom[ny][nx] == '#') continue;
		
			if (NisC != 1 && classRoom[ny][nx] == 'C') {
				NisC = 1;
			}else if(NisD != 1 && classRoom[ny][nx] == 'D') {
				NisD = 1;
			}
			q.push({ nx,ny,next,NisC,NisD });
			dist[ny][nx][next][NisC][NisD] = d + 1;
		}
	}
	return -1;
}

int main() {
	input();
	int ret = bfs();
	cout << ret << endl;
	return 0;
}