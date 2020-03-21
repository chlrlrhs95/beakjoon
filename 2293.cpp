#include <iostream>
#include <string.h>

using namespace std;

int N, K;
int coin[101];
int cache[10001];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
}

void sol() {
	memset(cache, 0, sizeof(cache));
	cache[0] = 1;

	for (int c = 0; c < N; c++) {
		for (int i = coin[c]; i <= K;) {
			cache[i] += cache[i - coin[c]];
			i++;
		}
	}
	cout << cache[K] << endl;
}

int main() {
	input();
	sol();
	return 0;
}