#include <iostream>
#include <cstring>
#include <vector>

typedef long long ll;

using namespace std;

int N;
vector<pair<int, pair<int, int> > >adj[10];
ll rat[10];
int selected[10];

int gcd(ll a, ll b) {
    //if a<b => swap
    if (a < b) {
        ll temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void input() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        //비율을 최소단위로 해서 집어넣어줌 만약 8:2 이면 4:1로.
        int g = gcd(p, q);
        p = p / g;
        q = q / g;
        adj[a].push_back(make_pair(b, make_pair(p, q)));
        adj[b].push_back(make_pair(a, make_pair(q, p)));
    }
}

ll dfs(int idx) {
    selected[idx] = 1;
    ll lcm = 1;
    for (unsigned int next = 0; next < adj[idx].size(); next++) {
        if (selected[adj[idx][next].first] == 1) continue;

        ll ret = dfs(adj[idx][next].first);
        ll num2 = adj[idx][next].second.second;
        ll lcm2 = (ret * num2) / gcd(ret, num2);
        ll m = lcm2 / num2;

        ll num = adj[idx][next].second.first * m;
        lcm = (lcm * num) / gcd(lcm, num);
    }
    return lcm;
}

void calc(int idx, ll num) {
    selected[idx] = -1;
    rat[idx] = num;
    for (unsigned int next = 0; next < adj[idx].size(); next++) {
        if (selected[adj[idx][next].first] == -1) continue;

        ll q = adj[idx][next].second.second;
        ll p = adj[idx][next].second.first;
        ll nextNum = (num * q) / p;
        calc(adj[idx][next].first, nextNum);
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        cout << rat[i] << ' ';
    }
}

void sol() {
    memset(selected, -1, sizeof(selected));
    ll ret = dfs(0);
    calc(0, ret);
    print();
}

int main()
{
    input();
    sol();
    return 0;
}