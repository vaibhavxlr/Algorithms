#include <bits/stdc++.h>

using namespace std;



int main() {
	long long n;
	cin >> n;

	long long sum = n * (n + 1);
	sum /= 2;

	long long actualSum = 0;
	for(int i = 0; i < n - 1; i++) {
		long long temp;
		cin >> temp;
		actualSum += temp;
	}

	cout << sum - actualSum << endl;
}