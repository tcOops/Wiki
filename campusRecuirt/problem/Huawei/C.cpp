#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct card {
	int num, type;
	bool operator< (const card & rhs) const {
		return num < rhs.num;
	}
}c[5];

int get(string a) {
	if(a[0] >= '0' && a[0] <= '9') {
		int s = 0, idx = 0;
		int n = a.size();
		while(idx < n) {
			s = s*10 + a[idx] - '0';
			++idx;
		}
		return s;
	}

	if(a[0] == 'J') return 11;
	if(a[0] == 'Q') return 12;
	if(a[0] == 'K') return 13;
	if(a[0] == 'A') return 14;
	return -1;
}

int fun2(string b) {
	if(b[0] == 'H') return 0;
	if(b[0] == 'S') return 1;
	if(b[0] == 'C') return 2;
	if(b[0] == 'D') return 3;
	return -1;
}

bool T1() {
	sort(c, c + 5);
	for(int i = 1; i < 5; ++i) {
		if(c[i].type != c[i-1].type) return false;
	}
	if(c[4].num == 14) {
		if((c[0].num == 2) && (c[1].num == 3) && (c[2].num == 4) && (c[3].num == 5)) return true;
		else if((c[0].num == 10) && (c[1].num == 11) && (c[2].num == 12) && (c[3].num == 13)) return true;
		else return false;
	}
	else {
		for(int i = 1; i < 5; ++i) {
			if(c[i].num != c[i-1].num + 1) {
				return false;
			}
		}
		return true;
	}

	return true;
}

bool T2() {
	if((c[0].num == c[1].num) && (c[1].num == c[2].num) &&  (c[2].num == c[3].num)) return true;
	if((c[3].num == c[4].num) && (c[1].num == c[2].num) &&  (c[2].num == c[3].num)) return true;
	return false;
}

bool T3() {
	if((c[0].num == c[1].num) && (c[1].num == c[2].num) &&  (c[3].num == c[4].num)) return true;
	if((c[0].num == c[1].num) && (c[4].num == c[3].num) &&  (c[2].num == c[3].num)) return true;
	return false;
}

bool T4() {
	for(int i = 1; i < 5; ++i) {
		if(c[i].type != c[i-1].type) return false;
	}
	return true;
}

bool T5() {
	if(c[4].num == 14) {
		if((c[0].num == 2) && (c[1].num == 3) && (c[2].num == 4) && (c[3].num == 5)) return true;
		else if((c[0].num == 10) && (c[1].num == 11) && (c[2].num == 12) && (c[3].num == 13)) return true;
		else return false;
	}
	else {
		for(int i = 1; i < 5; ++i) {
			if(c[i].num != c[i-1].num + 1) {
				return false;
			}
		}
		return true;
	}
	
	return true;
}

bool T6() {
	for(int i = 0; i < 3; ++i) {
		if((c[i].num == c[i+1].num) && (c[i+1].num == c[i+2].num)) return true;
	}
	return false;
}

int solve() {
	if(T1()) return 1;
	if(T2()) return 2;
	if(T3()) return 3;
	if(T4()) return 4;
	if(T5()) return 5;
	if(T6()) return 6;
	return 7;
}

int main() {
	string a, b;

	while(cin >> a >> b) {
		int idx = 0;
		int x = get(a), y = get2(b);
		c[idx].num = x, c[idx].type = y;
		++idx;

		for(int i = 0; i < 4; ++i) {
			cin >> a >> b;
			x = get(a), y = get2(b);
			c[idx].num = x, c[idx].type = y;
			++idx;
		}
		printf("%d\n", solve());
	}
	return 0;
}