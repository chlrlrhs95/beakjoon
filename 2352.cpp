#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int port[40001];
int C[40001];
int k = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> port[i];
		C[i] = port[i];
	}
}

void LIS() {
	for (int pos = 0; pos < N; pos++) {

		int left = 0, right = k;
		while (left < right) {
			int mid = (left + right) / 2;
			if (C[mid] >= port[pos]) {
				right = mid;
			}
			else if (C[mid] < port[pos]) {
				left = mid + 1;
			}
		}
		C[left] = port[pos];
		if (left == k) k++;
	}
	cout << k << endl;
}

int main() {
	input();
	LIS();
	return 0;
}