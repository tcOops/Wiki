#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
char op[1010];
vector<int> da, db, dc;
string c[5];

string solve(int r, int num) {
	if(num == 0) {
		if(r == 0) return "***";
		if(r == 1) return "* *";
		if(r == 2) return "* *";
		if(r == 3) return "* *";
		if(r == 4) return "***";
	}
	if(num == 1) {
		return "*";
	}
	if(num == 2) {
		if(r == 0) return "***";
		if(r == 1) return "  *";
		if(r == 2) return "***";
		if(r == 3) return "*  ";
		if(r == 4) return "***";
	}
	if(num == 3) {
		if(r == 0) return "***";
		if(r == 1) return "  *";
		if(r == 2) return "***";
		if(r == 3) return "  *";
		if(r == 4) return "***";
	}
	if(num == 4) {
		if(r == 0) return "* *";
		if(r == 1) return "* *";
		if(r == 2) return "***";
		if(r == 3) return "  *";
		if(r == 4) return "  *";
	}
	if(num == 5) {
		if(r == 0) return "***";
		if(r == 1) return "*  ";
		if(r == 2) return "***";
		if(r == 3) return "  *";
		if(r == 4) return "***";
	}
	if(num == 6) {
		if(r == 0) return "***";
		if(r == 1) return "*  ";
		if(r == 2) return "***";
		if(r == 3) return "* *";
		if(r == 4) return "***";
	}
	if(num == 7) {
		if(r == 0) return "***";
		if(r == 1) return "  *";
		if(r == 2) return "  *";
		if(r == 3) return "  *";
		if(r == 4) return "  *";
	}
	if(num == 8) {
		if(r == 0) return "***";
		if(r == 1) return "* *";
		if(r == 2) return "***";
		if(r == 3) return "* *";
		if(r == 4) return "***";
	}
	if(num == 9) {
		if(r == 0) return "***";
		if(r == 1) return "* *";
		if(r == 2) return "***";
		if(r == 3) return "  *";
		if(r == 4) return "***";
	}
}

string solve1(int r, char op) {
	if(op == '+') {
		if(r == 0) return "   ";
		if(r == 1) return " * ";
		if(r == 2) return "***";
		if(r == 3) return " * ";
		if(r == 4) return "   ";
	}

	if(op == '-') {
		if(r == 2) return "***";
		return "   ";
	}

	if(op == '*') {
		if(r == 0) return "   ";
		if(r == 1) return "* *";
		if(r == 2) return " * ";
		if(r == 3) return "* *";
		if(r == 4) return "   ";
	}

	if(op == '+') {
		if(r == 0) return "   ";
		if(r == 1) return "  *";
		if(r == 2) return " * ";
		if(r == 3) return "*  ";
		if(r == 4) return "   ";
	}

	if(op == '=') {
		if(r == 0) return "    ";
		if(r == 1) return "****";
		if(r == 2) return "    ";
		if(r == 3) return "****";
		if(r == 4) return "    ";
	}
}

int main() {
	gets(op);
	char opc;
	int a = 0, b = 0, idx = 0;
	int n = strlen(op);

	while(op[idx] != ' ') {
		a = a*10 + op[idx] - '0';
		da.push_back(op[idx] - '0');
		++idx;
	}
	++idx;

	opc = op[idx++];
	++idx;

	while(idx < n) {
		b = b*10 + op[idx] - '0';
		db.push_back(op[idx] - '0');
		++idx;
	}

	int Ans;
	bool flag = false;
	if(opc == '+') {
		Ans = a + b;
	}
	if(opc == '-') {
		Ans = a - b;
		if(Ans < 0) {
			Ans = -Ans;
			flag = true;
		}
	}
	if(opc == '*') {
		Ans = a * b;
	}
	if(opc == '/') {
		Ans = a / b;
	}

	while(Ans) {
		dc.push_back(Ans%10);
		Ans /= 10;
	}
	reverse(dc.begin(), dc.end());
	for(int i = 0; i < dc.size(); ++i) {
		//printf("%d ", dc[i]);
	}

	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < da.size(); ++j) {
			//printf("%d ", da[j]);
			c[i] += solve(i, da[j]) + " ";
		}
	//	printf("%c ", opc);
		c[i] += solve1(i, opc) + " ";
		for(int j = 0; j < db.size(); ++j) {
			//printf("%d ", db[j]);
			c[i] += solve(i, db[j]) + " ";
		}
		c[i] += solve1(i, '=');
		if(flag) {
			if(i == 3) {
				c[i] += "***";
			}
		}
		for(int j = 0; j < dc.size(); ++j) {
			//printf("%d ", dc[j]);
			c[i] += " " + solve(i, dc[j]);
		}
	}
	for(int i = 0; i < 5; ++i) {
		cout << c[i] << endl;
	}
	return 0;
}