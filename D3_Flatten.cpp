#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findIndexMax(vector<int> blocks) {
	int max = blocks[0];
	int answer = 0;
	for (int i = 1; i < blocks.size(); i++) {
		if (max < blocks[i]) {
			max = blocks[i];
			answer = i;
		}
	}
	return answer;
}

int findIndexMin(vector<int> blocks) {
	int min = blocks[0];
	int answer = 0;
	for (int i = 1; i < blocks.size(); i++) {
		if (min > blocks[i]) {
			min = blocks[i];
			answer = i;
		}
	}
	return answer;
}

int solution(vector<int> blocks, int dumpCount) {
	int maxIndex, minIndex;
	for (int i = 0; i < dumpCount; i++) {
		maxIndex = findIndexMax(blocks);
		minIndex = findIndexMin(blocks);
		
		if (blocks[maxIndex] - blocks[minIndex] <= 1) break;
		
		blocks[maxIndex]--;
		blocks[minIndex]++;
	}
	return blocks[findIndexMax(blocks)] - blocks[findIndexMin(blocks)];
}

int main(void) {
	int dumpCount;
	for (int testCase = 1; testCase <= 10; testCase++) {
		cin >> dumpCount;
		vector<int> blocks(100);
		for (int i = 0; i < blocks.size(); i++) {
			cin >> blocks[i];
		}
		cout << '#' << testCase << " " <<solution(blocks,dumpCount) << endl;
	}
}