#include <iostream>
#include <cstring>
#include <algorithm>

#define MAXN 16
#define NOANSWER 987654321
#define NOINSTALL 51
using namespace std;

int N;//발전소 개수
int weight[MAXN][MAXN];//발전소간의 재시작 비용.
int cache[1 << MAXN][MAXN];
char c[MAXN];
int P;

int input(int &plant) {
	int num = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int l = 0; l < N; l++) {
			cin >> weight[i][l];
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		if (c[i] == 'Y') {
			plant |= (1 << i);
			num++;
		}
	}
	cin >> P;
	return num;
}

int install(int plant,int next) {
	int MIN = NOINSTALL;
	for (int i = 0; i < N; i++) {
		if (plant & (1 << i)) {
			MIN = weight[i][next] < MIN ? weight[i][next] : MIN;
		}
	}
	return MIN;
}

int sol(int plant,int num) {
	if (num >= P) {
		return 0;
	}

	int& ret = cache[plant][num];
	if (ret != -1) return ret;

	ret = NOANSWER;
	for (int i = 0; i < N; i++) {
		if (plant & (1 << i)) continue;

		int cost = install(plant, i);
		if (cost == NOINSTALL) continue;
		ret = min(ret,cost + sol(plant | (1 << i), num + 1));
	}
	return ret;
}

int main() {
	int plant = 0;
	int num = input(plant);
	memset(cache, -1, sizeof(cache));
	int ans=sol(plant, num);
	if (ans == NOANSWER) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}