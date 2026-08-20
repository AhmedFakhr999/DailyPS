#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <vector>


const long long Maxy=1e6;

#define fasttoo                                                                \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define ll long long

using namespace std;
#define el '\n'

const int MAX_SIZE = 1e3;
char arr[MAX_SIZE][MAX_SIZE];
const int INF = 1e9;
int visit[MAX_SIZE][MAX_SIZE] = {
    0}; // Ensure visit is initialized and globally accessible
vector<pair<pair<int, int>, int>> res;
int n, m;
const int sz = 1e6 + 10;
bool composite[sz + 1];
vector<int> prime; 
vector<bool>seive_prime(Maxy,true);
vector<bool>linear_prime(Maxy,true);
vector<ll>spf(Maxy);
int main(){
    fasttoo
  int x;
	cin >> x;
	
	while (x != 0) {
		int count = 0;
		for (int i = 1; i <= x; i++) {
			if (x % i == 0)
				count++;

		}
		if (count % 2 == 0)
			cout << "no\n";
		else

			cout << "yes\n";
		cin >> x;





	}

		return 0;
    
}