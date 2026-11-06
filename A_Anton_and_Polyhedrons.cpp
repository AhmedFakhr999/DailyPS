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
    int n;
    cin>> n;
    int totalFaces = 0;
    for(int l=0;l<n;l++){
        string s;
        cin>> s;
        if(s == "Tetrahedron") totalFaces += 4;
        else if(s == "Cube") totalFaces += 6;
        else if(s == "Octahedron") totalFaces += 8;
        else if(s == "Dodecahedron") totalFaces += 12;
        else if(s == "Icosahedron") totalFaces += 20;
    }
    cout << totalFaces << '\n';
}

int main(){
    fasttoo;
    solve();
}