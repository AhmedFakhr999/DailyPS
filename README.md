# Light, More Light — Solution (C++)

Problem: Determine for each input integer whether it is a perfect square. Input ends with `0`.

File

- `Light_more_light.cpp`

Input

- A sequence of non-negative integers, one per line. `0` terminates input and is not processed.

Output

- For every input number (except the terminating `0`) print `yes` if the number is a perfect square, otherwise print `no`.

Solution (brief)

- Observation: A positive integer has an odd number of divisors exactly when it is a perfect square. Use integer square root check: compute `r = (long long) floor(sqrt(n))` and check `r*r == n`.

Complexity

- Time: O(1) per input number (one `sqrt` and multiplication).
- Space: O(1).

Compile & run

- Compile (Windows / Linux):

```
g++ -std=c++17 "Light_more_light.cpp" -O2 -o Light_more_light.exe
```

- Run:

```
./Light_more_light.exe
```

Sample
Input:

```
1
2
3
4
0
```

Output:

```
yes
no
no
yes
```

Notes

- This repository contains a straightforward C++ solution; consider replacing a divisor-count implementation with the integer-sqrt check for speed and simplicity.
