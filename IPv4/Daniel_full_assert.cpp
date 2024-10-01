#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << "\n"
using i64 = long long;
using u32 = unsigned int;

static constexpr int MAX_Q = 1e5;
static constexpr int MAX_BITS = 32;
static constexpr int MAX_VAL = 2 * MAX_BITS * MAX_Q;

int cnt[MAX_VAL];
int nxt[MAX_VAL][2];

int main() {
	int Q;
	cin >> Q;
	assert(1 <= Q && Q <= MAX_Q);

	auto getTokens = [&](const string& str) {
		vector <int> tokens;
		int number = 0;
		for (char ch : str) {
			if (ch == '.' || ch == '/') {
				tokens.push_back(number); 
				number = 0;
			}
			else {
				number = number * 10 + (ch - '0');
			}
		}
		tokens.push_back(number);
		return tokens;
	};

	int root = 0, tag = 0;
	auto addTrie = [&](u32 val, int sgn, int steps) {
		int now = root;
		int bit_pos = MAX_BITS - 1;
		for (int step = 0; step < steps; step++) {
			int bit = ((1ll << bit_pos) & val) ? 1 : 0;
			if (nxt[now][bit] == 0)
				nxt[now][bit] = ++tag; 
			now = nxt[now][bit];
			bit_pos--;
		}
		cnt[now] += sgn;
	};

	auto queryTrie = [&](u32 val) {
		int now = root;
		int bit_pos = MAX_BITS - 1;
		for (int step = 0; step < MAX_BITS; step++) {
			int bit = ((1ll << bit_pos) & val) ? 1 : 0;
			if (nxt[now][bit] == 0)
				return false;
			now = nxt[now][bit];
			if (cnt[now] > 0)
				return true;
			bit_pos--;
		}
		return false;
	};

	while (Q--) {
		int type;
		string str;
		cin >> type >> str;
		vector <int> tokens = getTokens(str);
		u32 ip = 0;
		assert(tokens.size() >= 4);
		static const int BYTE = 8;
		for (int i = 0; i < 4; i++) {
			assert(tokens[i] < (1 << BYTE));
			ip = ip * (1ll << BYTE) + tokens[i];
		}
		if (type == 3) {
			assert(tokens.size() == 4);
			if (queryTrie(ip)) {
				cout << "Da\n";
			}
			else {
				cout << "Nu\n";
			}
		}
		else {
			int sgn = (type == 1) ? +1 : -1;
			assert(tokens.size() == 5);
			int subnet_mask = tokens.back();
			assert(subnet_mask > 0 && subnet_mask <= MAX_BITS);
			addTrie(ip, sgn, subnet_mask);
		}
	}
    return 0;
}
