#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer;
bool visited[1000000][11]; // 0 ~ 999999, 교환 횟수 최대 10

void dfs(string s, int count) {
	if (count == 0) {
		answer = max(answer, stoi(s));
		return;
	}
	if (visited[stoi(s)][count]) return;
	visited[stoi(s)][count] = true;

	int len = (int)s.length();
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			swap(s[i], s[j]);
			dfs(s, count- 1);
			swap(s[i], s[j]);
		}
	}
}
int main(void) {
	int T;
	cin >> T;

	for (int testCase = 1; testCase <= T; ++testCase) {
		string s;
		int count;
		cin >> s >> count;
		
		answer = 0;
		for (int i = 0; i < 1000000; i++) {
			for (int j = 0; j < 11; j++) {
				visited[i][j] = false;
			}
		}
		dfs(s, count);
		cout << '#' << ' ' << testCase<<' '<<answer << endl;
	}
	return 0;
}

//123
//321