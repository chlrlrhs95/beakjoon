#include <iostream>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int R, C;
char arr[25][25];
pair<int, int> moscow, zagrav, ep;
int visit[25][25];

// 0 : ³² , 1: ºÏ, 2:¼­ ,3:µ¿
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

map<int,char> ItoA;
map<char, int> AtoI;

void init() {
	ItoA.insert(make_pair(0b0011, '|'));
	ItoA.insert(make_pair(0b1100, '-'));
	ItoA.insert(make_pair(0b1111,'+'));
	ItoA.insert(make_pair(0b1001,'1'));
	ItoA.insert(make_pair(0b1010,'2'));
	ItoA.insert(make_pair(0b0110,'3'));
	ItoA.insert(make_pair(0b0101,'4'));

	AtoI.insert(make_pair('|',0b0011));
	AtoI.insert(make_pair('-',0b1100 ));
	AtoI.insert(make_pair('+',0b1111 ));
	AtoI.insert(make_pair('1',0b1001 ));
	AtoI.insert(make_pair('2',0b1010 ));
	AtoI.insert(make_pair('3',0b0110 ));
	AtoI.insert(make_pair('4',0b0101 ));

	memset(visit, 0, sizeof(visit));
	for (int dir = 0; dir < 4; dir++) {
		int nx = moscow.first + dx[dir];
		int ny = moscow.second + dy[dir];
		if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
		if (arr[ny][nx] == '.') continue;
		
		visit[moscow.second][moscow.first] += 1 << dir;
		if (dir % 2 == 1) {
			visit[ny][nx] += 1 << (dir - 1);
		}
		else if (dir % 2 == 0) {
			visit[ny][nx] += 1 << (dir + 1);
		}
		moscow = make_pair(nx, ny);
		break;
	}
}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int l = 0; l < C; l++) {
			cin >> arr[i][l];
			if (arr[i][l] == 'M') {
				moscow = make_pair(l, i);
			}
		}
	}
}

void bfs(pair<int,int> s) {
	queue<pair<int, int>> q;
	q.push(s);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		char c = arr[y][x];
		q.pop();

		//cout << x << ' ' << y << ' '<<c<<endl;
		if (c == '.') {
			ep = make_pair(x, y);
			break;
		}
		
		vector<int> v;
		if (c == '|') {
			v.push_back(0);
			v.push_back(1);
		}

		else if (c == '-') {
			v.push_back(2);
			v.push_back(3);
		}

		else if (c == '+') {
			v.push_back(0);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
		}

		else if (c == '1') {
			v.push_back(0);
			v.push_back(3);
		}

		else if (c == '2') {
			v.push_back(1);
			v.push_back(3);
		}

		else if (c == '3') {
			v.push_back(1);
			v.push_back(2);
		}

		else if (c == '4') {
			v.push_back(0);
			v.push_back(2);
		}

		for (int i = 0; i < v.size();i++) {
			int dir = v[i];
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (visit[y][x] & (1 << dir)) continue;

			if (dir % 2 == 1) {
				visit[ny][nx] += 1 << (dir - 1);
			}
			else if (dir % 2 == 0) {
				visit[ny][nx] += 1 << (dir + 1);
			}
			visit[y][x] += 1 << dir;
			q.push(make_pair(nx, ny));
		}
	}
}

void sol() {
	init();
	bfs(moscow);
	visit[ep.second][ep.first] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = ep.first + dx[dir];
		int ny = ep.second + dy[dir];
		if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
		if (arr[ny][nx] == '.' || arr[ny][nx] == 'M' || arr[ny][nx] == 'Z') continue;

		int dirToMe;
		if (dir % 2 == 0) {
			dirToMe = dir + 1;
		}
		else {
			dirToMe = dir - 1;
		}
		if (AtoI.find(arr[ny][nx])->second & (1 << dirToMe)) visit[ep.second][ep.first] += (1 << dir);
	}
	cout << ep.second + 1 << ' '<< ep.first + 1 <<' '<<ItoA.find(visit[ep.second][ep.first])->second << endl;
}

int main() {
	input();
	sol();
	return 0;
}