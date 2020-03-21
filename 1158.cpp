#include<iostream>
#include <list>
using namespace std;

int N, K;
list<int> survivor;
list<int> killed;

void input() {
	cin >> N >> K;
}

ostream& operator<<(ostream& os, list<int> l) {
	list<int>::iterator it = l.begin();
	os << "<" << *it;
	it++;
	for (; it != l.end(); ++it) {
		os << ", " << *it;
	}
	os << ">";
	return os;
}

void init() {
	for (int i = 1; i <= N; i++) {
		survivor.push_back(i);
	}
}

void sol(int n) {
	init();
	list<int>::iterator kill = survivor.begin();

	while (n > 0) {
		for (int i = 0; i < K - 1; i++) {
			kill++;
			if (kill == survivor.end()) kill = survivor.begin();
		}

		killed.push_back(*kill);
		kill = survivor.erase(kill);
		n--;
		if (survivor.end() == kill) kill = survivor.begin();
	}
}


int main() {
	input();
	init();
	sol(N);
	cout << killed << endl;
	
	return 0;
}