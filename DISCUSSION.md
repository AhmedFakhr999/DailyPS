# Discussion — Light, More Light

Idea

- A number has an odd number of divisors iff it is a perfect square. Divisors come in pairs (d, n/d); pairs collapse only when d == n/d, i.e., when n is a perfect square.

Recommended implementation

- For each input `n > 0`, compute `r = (long long) floor(sqrt(n))` and check `r*r == n`. Print `yes` for true, `no` otherwise.

Why this is better

- Counting divisors by iterating to `n` (or even to `sqrt(n)` with awkward checks) is slower and unnecessary. The integer-square-root check is constant time per query.

Edge cases

- `0` is the terminator and should not be processed.
- `1` is a perfect square (answer `yes`).

Limits & notes

- If inputs can be up to 2^63-1, ensure `r*r` does not overflow (use 128-bit where available). For typical competitive problems inputs fit in 32-bit or 64-bit; casting and long long arithmetic is sufficient.
