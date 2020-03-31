#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = -1;
int R, C;
char dia[750][750];
int dirLength[750][750][2];

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int l = 0; l < C; l++) {
			cin >> dia[i][l];
		}
	}
}

//dir방향의 연속된 1의 개수
int dp(int r,int c,int dir) {
	if (r < 0 || r >= R || c < 0 || c >= C) return -1;
	
	int& ret = dirLength[r][c][dir];
	if (ret != INF) return ret;

	if (dia[r][c] == '0') {
		return ret = -1;
	}

	if (dir == 1) {
		ret = dp(r + 1, c + 1, dir) + 1;
	}
	else {
		ret = dp(r + 1, c - 1, dir) + 1;
	}

	return ret;
}

void print(int dir) {
	for (int i = 0; i < R; i++) {
		for (int l = 0; l < C; l++) {
			cout << dirLength[i][l][dir] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void sol() {
	memset(dirLength, INF, sizeof(dirLength));

	//각 점마다 강 방향(남동 : 1, 남서 : 0) 으로의 연속된 1의 개수를 파악.
	for (int i = 0; i < R; i++) {
		for (int l = 0; l < C; l++) {
			for(int dir=0;dir<2;dir++) dp(i, l, dir);
		}
	}
	int maxDiaSize = 0;
	for (int i = 0; i < R; i++) {
		for (int l = 0; l < C; l++) {
			if (dia[i][l] == '0') continue;

			int maxLength = min(dirLength[i][l][0], dirLength[i][l][1]);
			if (maxLength +1 <= maxDiaSize) continue;

			for (int k = maxLength; k >= maxDiaSize; k--) {
				if ((dirLength[i + k][l + k][0] >= k) && (dirLength[i + k][l - k][1] >= k)) {
					maxDiaSize = max(maxDiaSize, k + 1);
					break;
				}
			}
		}
	}
	print(1);
	print(0);
	cout << maxDiaSize << endl;
}

int main() {
	input();
	sol();
	return 0;
}