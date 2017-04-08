#include <iostream>
using namespace std;

class Test {
public:
	static int x;
	Test(int i = 0) {
		x = i + x;
	}
	int GetNum() {
		return Test::x + 7;
	}
};

int Test::x = 33;

int main() {
	Test test;
	cout << test.GetNum() << endl;
	return 0;
}