#include <iostream>
#include <cstring>

using namespace std;

char arr[8][8];
int state[8];
int dx[9] = { 0,1,1,1,0,-1,-1,-1,0 };
int dy[9] = { -1,-1,0,1,1,1,0,-1,0 };

void input() {
	memset(state, 0, sizeof(state));
	for (int i = 0; i < 8; i++) {
		for (int l = 0; l < 8; l++) {
			cin >> arr[i][l];
			if (arr[i][l] == '#') {
				state[i] += (1 << (7-l));
			}
		}
	}

}

int downWall() {
	int temp = state[7];
	for (int i = 7; i > 0; i--) {
		state[i] = state[i - 1];
	}
	state[0] = 0;
	return temp;
}

void upWall(int s7) {
	for (int i = 0; i <7; i++) {
		state[i] = state[i + 1];
	}
	state[7] = s7;
}

int move(int x, int y, int state[8]) {
	if (state[y] & (1 << (7-x))) {
		return 0;
	}

	if (x == 7 && y == 0) {
		return 1;
	}

	for (int dir = 0; dir < 9; dir++) {
		if (x + dx[dir] < 0 || x + dx[dir] >= 8 || y + dy[dir] < 0 || y + dy[dir] >= 8) continue;
		if (state[y+dy[dir]] & (1<<(7-x-dx[dir]))) continue;

		int s7=downWall();
		if (move(x + dx[dir], y + dy[dir], state)==1) {
			return 1;
		}
		upWall(s7);
	}

	return 0;
}


void playgame() {
	cout<<move(0,7,state)<<endl;
}

int main() {
	input();
	playgame();
	return 0;
}