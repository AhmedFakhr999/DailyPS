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

//here should be the divisor preprocessing (i didn't get it quite yet)
//! do it in notes and here 


void prime_factorization(){

}
void linear_siev(){
  prime[0]=prime[1]=false;
  for(int i=2;i<=Maxy;i++){
    if(prime[i]){
      linear_prime.push_back(i);
      spf[i]=i;//  0 0 2 3 0 0 0
    }
    for(auto p:linear_prime){
      if(i*p>Maxy){
        break;
      }
      prime[i*p]=false;
      spf[i*p]=p;
      if(i%p==0){
        break;
      }
    }

  }
}

void seive(){
  prime[0]=prime[1]=false;
  for(int i=2;i*i<=n;i++){
    if(seive_prime[i]==false){
      continue;
    }
    for(int j = i+i;j<=Maxy;j+=i){
      seive_prime[j]=false;
    }
    //use this function in your solve() in order to know if the prime[n] is prime number or not 
  }
}
void linear_sieve() {//same same but different (the upper one is the opposite, the prime number are false here)
  composite[0] = composite[1] = 1;
  for (int l = 2; l <= sz; ++l) {
    if (!composite[l]) {
      prime.push_back(l);
    }
    for (int j = 0; l < (int)prime.size() && l * prime[j] <= sz; ++j) {
      composite[l * prime[j]] = 1;
      if (l % prime[j] == 0)
        break;
    }
  }
}

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
int nextPrime(int n) {
  if (n <= 1) {
    return 2;
  }
  bool found = false;
  int primenumber = n;
  while (!found) {
    primenumber++;
    if (isPrime(primenumber)) {
      found = true;
    }
  }
  return primenumber;
}
void solve(int n, int m, int r1, int c1, int r2, int c2, char c,
           char arr[][100]) {
  r1--;
  c1--;
  r2--;
  c2--;

  // now i have the matrix filled with dots
  // every n and m but don't goes after the c2 and r2
  for (int l = r1; l < r2; l++) {
    for (int l2 = c1; l2 < c2; l2++) {
      arr[l][l2] = c;
      // el mafroud in hna hatkon el array filled with letter c
    }
  }
  for (int l = 0; l < n; l++) {
    for (int l2 = 0; l2 < m; l2++) {
      cout << arr[l][l2];
    }
    cout << el;
  }
}
bool isPalindrome(const string &s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}

int checkStarts(int row, int column) {
  int right = 0, left = 0, upper = 0, lower = 0;
  int col = column;
  while (col <= m && arr[row][col] == '*') { // 4 5 6 7 8
    right++;
    col++;
  }

  col = column;
  while (col >= 1 && arr[row][col] == '*') { // 4 5 6 7 8
    left++;
    col--;
  }
  int ro = row;
  while (ro >= 1 && arr[ro][column] == '*') {
    upper++;
    ro--;
  }
  ro = row;
  while (ro <= n && arr[ro][column] == '*') {
    lower++;
    ro++;
  }
  
  return min(min(left - 1, right - 1), min(upper - 1, lower - 1));
}
void swap_columns(vector<vector<int>> &arr2d, int x, int y) {
  // Swap the columns at indices x and y in the 2D vector arr2d
  for (int i = 0; i < arr2d.size(); i++) {
    swap(arr2d[i][x], arr2d[i][y]);
  }
}
void swap_rows(vector<vector<int>> &arr2d, int x, int y) {
  // Swap the rows at indices x and y in the 2D vector arr2d
  swap(arr2d[x], arr2d[y]);
}
void get_value(int x, int y, vector<vector<int>> &arr2d) {
  // Get the value at position (x, y) in the 2D vector arr2d
  cout << arr2d[x][y] << endl;
}
ll my_gcd(ll num1, ll num2) { // 10 3

  //
  while (num2 != 0) {
    return my_gcd(num2, num1 % num2);
  }
  return num1;
}
ll my_lcm(ll num1, ll num2) { return (num1 / my_gcd(num1, num2)) * num2; }

string product(const std::string& num1, const std::string& num2) {
   // we have two numbers that will be a string for both 
   // create an array of zeros 
   // then take each element of the vector and store at it the multiplication of both char of the two srings 
   if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.size();
    int n2 = num2.size();
    std::vector<int> result(n1 + n2, 0);
    // 12 12 = 24 
    // 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  
    // Multiply each digit from right to left
    for (int i = n1 - 1; i >= 0; i--) {
        // 12 12 
        // 
        for (int j = n2 - 1; j >= 0; j--) {// 11 11
            
            int mul = (num1[i] - '0') * (num2[j] - '0');
            
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10; // Store single digit
            result[i + j] += sum / 10;     // Carry over to the left
        }
    }
}
// -------------------------Sorting algo-------------------------------
// 1
void bubbleSort(vector<int> &arr) {
  // best : O(n)
  // worst: O(n*2)
  // space: O(1)
  int n = arr.size();
  for (int l = 0; l < n - 1; l++) {
    bool swapped = false;
    for (int j = 0; j < n - l - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}
void merge(vector<int> &arr, int left, int mid, int right) {
  // O(n log n)
  // space: O(n)
  // Assumption: 5 2 4 6 1 3
  // left(5)          right(3)
  // L:
  // R:
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);
  for (int l = 0; l < n1; l++)
    L[l] = arr[left + l];
  for (int l2 = 0; l2 < n2; l2++)
    R[l2] = arr[mid + 1 + l2];
  // L: 5 2 4
  // R:6 1 3
  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(vector<int> &arr, int left, int right) {
  if (left >= right)
    return;

  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}
void quickSort() {}
void selectionSort(vector<int> &arr) {
  int n = arr.size();
  for (int l = 0; l < n - 1; l++) {
    int minIdx = l;
    for (int l2 = l + 1; l < n; l2++) {
      if (arr[l2] < arr[minIdx]) {
        minIdx = l2;
      }
    }
    swap(arr[l], arr[minIdx]);
  }
}

void insertionSort(vector<int> &arr) {
  // 5 2 4 6 1 3
  // key is 2
  // j is 0 so it 5
  // if j >=0 and 5 is > than 2
  // then 2 will be 5
  // j =-1
  // j+1 = key which is 2
  int n = arr.size();
  for (int l = 1; l < n; l++) {
    int key = arr[l];
    int j = l - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
int partition(vector<int> &arr, int low, int high) {
  // 5 2 4 6 1 3
  // pivot is 3
  // i -->[0]
  // if 5 is <=3
  // swap them
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    // pi is partitioning index, str[p] is now at right place
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
int main() {

  fasttoo;
  product();
}