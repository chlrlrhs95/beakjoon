#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N;
int ans = 987654321;
int number[1000000];

void input() {
	cin >> N;
	memset(number, -1, sizeof(number));
}

int sol() {
	queue<int> q;

	number[N] = 0;
	q.push(N);

	while(!q.empty()){
		int p = q.front();
		q.pop();
		int cnt = number[p];

		//cout << "number is " << p << "    & count is " << cnt << endl;
		if (p == 1) {
			return number[p];
		}

		if (p % 3 == 0) {
			if (number[p / 3] == -1) {
				//cout << "push " << p / 3 << " | cnt is " << cnt + 1 << endl;
				number[p / 3] = cnt + 1;
				q.push(p / 3);
			}
		}if (p % 2 == 0) {
			if (number[p / 2] == -1) {

				//cout << "push " << p / 2 << " | cnt is " << cnt + 1 << endl;
				number[p / 2] = cnt + 1;
				q.push(p / 2);
			}
		}
		if (number[p - 1] == -1) {

			//cout << "push " << p-1 << " | cnt is " << cnt + 1 << endl;
			number[p - 1] = cnt + 1;
			q.push(p - 1);
		}
		//cout << endl;
	}
}


int main() {
	input();
	cout << sol() << endl;
	return 0;
}