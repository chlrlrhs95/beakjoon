#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, testCase;
char arr[10][10];
int cache[11][1<<10];
vector<pair<int, int>> sets;//상태와 그상태에 앉은 학생 수,

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int l = 0; l < M; l++) {
			cin >> arr[i][l];
		}
	}
}

bool breakChair(int y, int state) {
	for (int x = 0; x < M; x++) {
		if (state & (1 << x)) {
			if (arr[y][x] == 'x') return false;

		}
	}
	return true;
}

bool isPossible(int now, int next) {
	if (now & (1 << 0)) {
		if ( next & (1 << 1)) return false;
	}
	for (int i = 1; i < M-1; i++) {
		if (now & (1 << i)) {
			if ((next & 1<<(1 + i)) || (next & 1<<(i-1))) return false;
		}
	}
	if (now & (1 << M-1)) {
		if (next & (1 << (M-2))) return false;
	}
	return true;
}

int dfs(int y,pair<int,int> state) {
	if (y == 0) {
		return state.second;
	}

	int& ret = cache[y][state.first];
	if (ret != -1) return ret;

	for (unsigned int next = 0; next < sets.size(); next++) {
		if (!isPossible(state.first, sets[next].first)) continue;
		if (!breakChair(y-1, sets[next].first)) continue;

		ret = max(ret, dfs(y - 1, sets[next])+state.second);
	}

	return ret;
}

/*row에 놓일 수 있는 상태의 집합*/
void makeSets(int idx, int state) {
	if (idx == M) return;

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (state & (1 << i)) cnt++;
	}
	sets.push_back(make_pair(state, cnt));

	if (!(state & (1 << idx))) makeSets(idx + 1, state + (1 << (idx+1)));
	
	makeSets(idx + 1, state);
}

void sol() {
	memset(cache, -1, sizeof(cache)); sets.clear();
	makeSets(0, 0); makeSets(0, 1);
	cout<<dfs(N, make_pair(0,0))<<endl;
}

int main() {
	cin >> testCase;
	while (testCase--) {
		input();
		sol();
	}
	return 0;
}
