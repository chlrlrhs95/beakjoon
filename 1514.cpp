#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int INF = 987654321;
int N;
int locker[100];
int cache[100][10][10][10][2];

inline int moduler(int x) {
	return x > 0 ? x % 10 : (x + 10) % 10;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		locker[i] = atoi(&c);
	}
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		locker[i] -= atoi(&c);
	}

	for (int i = 0; i < N; i++) {
		locker[i] = (locker[i] + 10) % 10;
	}
}

int dp(int n,int v1,int v2,int v3,int d) {
	if (n == N) {
		return 0;
	}

	int& ret = cache[n][v1][v2][v3][d];
	if (ret != -1) return ret;

	//현재 위치의 자물쇠가 맞다면 다음으로 이동.
	if (locker[n] == v1) return ret = min(dp(n + 1, v2, v3, 0, 0), dp(n + 1, v2, v3, 0, 1));

	ret = INF;
	int dir = d == 1 ? 1 : -1;
	for (int i = 1; i <= 3; i++) {
		int diri = i * dir;
		ret = min(ret,dp(n, moduler(v1 + diri), v2, v3, d)+1);
		ret = min(ret,dp(n, moduler(v1 + diri), moduler(v2 + diri), v3, d)+1);
		ret = min(ret,dp(n, moduler(v1 + diri), moduler(v2 + diri), moduler(v3 + diri), d)+1);
	}

	return ret;
}

void sol() {
	memset(cache, -1, sizeof(cache));
	cout<<min(dp(0, 0, 0, 0, 1) , dp(0, 0, 0, 0, 0) )<<endl;
}

int main() {
	input();
	sol();
	return 0;
}