#include <string>
#include <iostream>
#include <map>
using namespace std;

// n = 1000 
// n^2까지 가능? nlogn은 가능

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
				// 해당 점수가 있을때
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

