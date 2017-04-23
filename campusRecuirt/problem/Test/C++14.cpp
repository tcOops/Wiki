#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    Node() {
        ++cur, num += cur;
    }
    
    static void reset() {
    	cur = 0, num = 0;    
    }
    
    static int getSum() {
        return num;
    }
    
private:
    static int num;
    static int cur;
};

//int Node::num = 0;
//int Node::cur = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Node::reset();
        
        Node *p = new Node[n];
        delete []p;
        
        return Node::getSum();
    }

};

int main() {
	Node::reset();
	
	return 0;
}