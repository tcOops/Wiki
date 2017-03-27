#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 0.1;
pair<double, double> p[3];
double z[3];

int main() {
	while(~scanf("%lf%lf%lf", &p[0].first, &p[0].second, &z[0])) {
		for(int i = 1; i < 3; ++i) {
			scanf("%lf%lf%lf", &p[i].first, &p[i].second, &z[i]);
		}

		double x, y;
		scanf("%lf %lf", &x, &y);
		double dx = x - p[0].first;
		double dy = y - p[0].second;

		double d1 = p[1].first - p[0].first;
		double d2 = p[1].second - p[0].second;
		double d3 = p[2].first - p[0].first;
		double d4 = p[2].second - p[0].second;
		if(fabs(d1*d4 - d2*d3) < eps) {
			printf("-1\n");
			continue;
		}

		double r = (d1*d4) - (d2*d3);
		double ansX = d4/r*dx + (-1.0*d3)/r*dy;
		double ansY = d1/r*dy + (-1.0*d2)/r*dx;
		//printf("%lf %lf\n", ansX, ansY);
		if(ansX < 0 || ansX > 1.0 || ansY < 0 || ansY > 1.0 || (ansX + ansY) > 1.0) {
			printf("-1\n");
			continue;
		}
		double ans = z[0] + ansX*(z[1] - z[0]) + ansY*(z[2] - z[0]);
		printf("%.2lf\n", ans);
	}
	return 0;
}