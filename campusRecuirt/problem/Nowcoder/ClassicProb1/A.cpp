//https://www.nowcoder.com/question/next?pid=425653&qid=25285&tid=7720276

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N = 20;
vector<int> g[N];
int sta[1<<N];

class FoldPaper {
public:
    vector<string> foldPaper(int n) {
    	vector<string> ans(0);
    	solve(1, (1<<n)-1, 1, ans);
        // write code here
        return ans;
    }

   	void solve(int l, int r, int sta, vector<string> &ans) {
   		int mid = (l + r) >> 1;
   		if(l < mid) {
   			solve(l, mid - 1, 1, ans);
   		}

   		if(sta) {
   			ans.push_back("down");
   		}
   		else {
   			ans.push_back("up");
   		}

   		if(mid < r ) {
   			solve(mid + 1, r, 0, ans);
   		}
   	}
};

int main() {
	vector<string> ans = FoldPaper().foldPaper(5);
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}