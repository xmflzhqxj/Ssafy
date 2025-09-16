#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M;

int solution(vector<vector<int>> dragonFly) {
	int max = -1;
	for (int i = 0; i <= N-M; i++) {
		for (int j = 0; j <= N-M; j++) {
			int sum = 0;
			for (int a = i; a < M + i; a++) {
				for (int b = j; b < M + j; b++) {
					sum += dragonFly[a][b];
				}
			}
			if (max < sum) max = sum;
		}
	}
	return max;
}
int main(void) {
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		cin >> N >> M;
		vector<vector<int>> dragonFly(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> dragonFly[i][j];
			}
		}
		cout << '#' << t << ' ' << solution(dragonFly) << endl;
	}
}