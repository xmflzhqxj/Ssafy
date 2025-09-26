#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long solution(vector<int> money) {
	int count = 0;
	long long purchase, earn;
	purchase = earn = 0L;
	long long maxProfit = 0;

	for (int i = money.size() - 1; 0 <= i; i--) {
		if (maxProfit <= money[i]) {
			maxProfit = money[i];
		}
		else {
			purchase += money[i];
			earn += maxProfit;
		}
	}
	return earn - purchase;
}
int main(void) {
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int N;
		cin >> N;
		vector<int> money(N);
		for (int i = 0; i < money.size(); i++) {
			cin >> money[i];
		}
		cout << '#' << t << ' ' << solution(money) << endl;
	}
	return 0;
}