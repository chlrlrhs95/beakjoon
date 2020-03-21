#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector< pair<int, int> > v;

void input() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
}

bool compare(pair<int, int>v1, pair<int, int> v2) {
	if (v1.second != v2.second) return v1.second < v2.second;
	else return v1.first < v2.first;
}


int sol() {
	int num = 0;
	int ending = 0;
	sort(v.begin(), v.end(),compare);
	for (unsigned int i = 0; i < v.size(); i++) {
		if (ending <= v[i].first) {
			ending = v[i].second;
			num++;
		}
	}
	return num;
}

int main() {
	input();
	cout << sol() << endl;
	return 0;
}