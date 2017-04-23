#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int day[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};


int judge(int y) {
	if(y % 100 != 0) {
		if(y % 4 == 0) return 1;
	}
	if(y % 100 == 0 && y % 400 == 0) {
		return 1;
	}
	return 0;
}

bool check(int a, int b, int c) {
	int sta = judge(a);
	if(a < 0 || b <= 0 || b > 12 || c < 0) return false;
	if(c > day[sta][b-1]) return false;
	return true;
}

int main() {
	int a, b, c;
	char d, e;
	while(~scanf("%d%c%d%c%d", &a, &d, &b, &e, &c)) {
		if(!check(a, b, c)) {
			puts("invalid input");
			continue;
		}
		int sum = 0;
		int cur = judge(a);
		for(int i = 0; i < b - 1; ++i) {	
			sum += day[cur][i];
		}
		sum += c;
		printf("%d-%d-%d is the No.%d day of %d\n", a, b, c, sum, a);
	}
	return 0;
}