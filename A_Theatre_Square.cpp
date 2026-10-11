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

    ll n,m, a , s ,z; 
    cin>> n>> m >> a ; 
    // first we have to see if the width of rectangle will be fit for the square 

    if(n%a==0){
        s=n/a;
    }else{
        s=(n/a)+1;
    }

   //now for the lenght
   
   if(m%a==0){
    z=m/a;
   }else{
    z=(m/a)+1;
   }

   cout<<z*s<<endl;
   cout.flush();
}

int main(){
    fasttoo; 
    solve();
}