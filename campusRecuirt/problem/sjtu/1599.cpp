#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e6 + 10;
char stk[N];
bool sta[N];

int main() {
	int n;
	scanf("%d", &n);
	int top = 0;
	for(int i = 0; i < n; ++i) {
		int type;
		char op[3];
		scanf("%d", &type);
		if(type == 1) {
			scanf("%s", op);
			if(op[0] == '(' || op[0] == '[' || op[0] == '{') {
				sta[top] = false;
				stk[top++] = op[0];
			}
			else {
				stk[top] = op[0];
				if(top == 0) {
					sta[top++] = false;
					continue;
				}
				if(op[0] == ')') {
					if(stk[top-1] == '(') {
						if(top == 1) {
							sta[top] = true;
						}
						else {
							sta[top] = sta[top-2];
						}
					}
					else {
						sta[top] = false;
					}
				}
				else if(op[0] == ']') {
					if(stk[top-1] == '[') {
						if(top == 1) {
							sta[top] = true;
						}
						else {
							sta[top] = sta[top-2];
						}
					}
					else {
						sta[top] = false;
					}
				}
				else {
					if(stk[top-1] == '{') {
						if(top == 1) {
							sta[top] = true;
						}
						else {
							sta[top] = sta[top-2];
						}
					}
					else {
						sta[top] = false;
					}
				}
				++top;
			}		
		}
		else if(type == 2) {
			if(top) --top;
		}
		else if(type == 3) {
			if(top) {
				printf("%c\n", stk[top-1]);
			}
		}
		else {
			if(top == 0) {
				puts("YES");
			}
			else if(sta[top-1]) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}
	}
	return 0;
}