#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;
set<long long > st;

int main() {
	long long id;
	while(~scanf("%lld", &id)) {
		if(id == 0) break;
		st.insert(id);
	}
	printf("%lu\n", st.size());
	return 0;
}