#include <string>
#include <iostream>
#include <map>
using namespace std;

// n = 1000 
// n^2���� ����? nlogn�� ����

int main(void) {
	
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		map<int, int> students;
		int childScore;
		int number;
		cin >> number;
		int j = 0;
		while (j++ < 1000) {
			cin >> childScore;
			if (students.find(childScore) != students.end()) {
				// �ش� ������ ������
				students[childScore]++;
				
			}
			else {
				students.insert({ childScore,1 });
			}
		}
		int maxCount = -1;
		int answer = 0;

		for (auto k = students.begin(); k != students.end(); k++) {
			if (maxCount <= k->second) {
				maxCount = k->second;
				answer = k->first;
			}
		}
		cout << "#" << number
			<< " " << answer << '\n';
	}
}

