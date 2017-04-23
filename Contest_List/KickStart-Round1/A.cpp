#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int r[22];

int main() {
	r[1] = 1, r[2] = 2;
	int sum = 3;
	for(int i = 3; i < 22; ++i) {
		r[i] = sum;
		sum += r[i];
	}

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int x = 0, ly = 0, ry = 0, gap = 0;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			
			if(x >= x1 && x <= x2) {
				if(gap == 0) {
					if(ly >= y1 && ly <= y2) ++ans;
				}
				else {
					int ll = ly, rr = ry;
					if(ll < y1) {
						ll = y1;
					}
					if(rr > y2) {
						rr = y2;
					}
					if(ll <= rr) {
						if(i != 0) {
							ans += (rr - ll) / gap;
							if((ll - y1)%gap == 0) {
								++ans;
							}
						}
						else {
							ans += (rr - ll) / (gap + 1);
							if((ll - y1) % (gap + 1) < gap - 1) {
								ans += 1;
							}
							else if((ll - y1) % (gap + 1) == gap - 1) {
								ans += 2;
							} 
							if((rr - y1) % (gap + 1) == 1) {
								ans += 1;
							}
							else if((rr - y1) % (gap + 1) >= gap - 1) {
								ans += 2;
							}
						}
					}
				}
			}

			x += r[n-i];
			gap = r[n-i]<<1;
			ly -= r[n-i], ry += r[n-i];
		}
		printf("%d\n", ans);
	}
	return 0;
}