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

void solve(){
 
    ll n ; 
    cin>> n; 
    if(n%2==0){
        cout<<n/2<<endl;
    }else{
        cout<<((n-1)/2)-n<<endl;
    }
}


int main(){
    fasttoo;
    solve();
}