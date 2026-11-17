# Binary Search

Problem-solving lecture notes + my homework solutions.

---

## 1. The big idea

> Most binary search problems are on a **monotonic function**, not just on a sorted array.

### Monotonic function

A function `F` is monotonic if it is **entirely non-decreasing** or **entirely non-increasing**.

```
non-decreasing:  F(1) <= F(2) <= F(3) <= ...
non-increasing:  F(1) >= F(2) >= F(3) >= ...
```

- A **sorted array** (even with duplicates) is a non-decreasing function: `F(i) = a[i]`.
- A **yes/no question** that flips only once is monotonic too:

```
index:      0  1  2  3  4  5  6
possible(): F  F  F  T  T  T  T      <- binary search finds the first T
```

So the real question is: **"is there a `possible(x)` that is `false ... false true ... true` (or the opposite)?"** If yes, binary search works, even if you don't have an array.

> **Tip:** `possible()` is sometimes **complex** (a loop, a greedy, a simulation). That's fine. Total time = `O(log(range) * cost of possible())`.

---

## 2. My reference template (integers)

"Find the **first** index where the condition is true", with one extra variable `ans`, and **without stopping** when `mid == target`:

```cpp
int l {}, r {sz - 1}, mid, ans {-1};
while (l <= r) {
    mid = l + (r - l) / 2;           // safe: no overflow like (l + r) / 2
    if (k <= possible(mid, nums))     // possible(mid)?
        ans = mid, r = mid - 1;      // yes: remember it, try to find a better (smaller) one
    else
        l = mid + 1;                 // no: go right
}
// ans = first index where possible() is true (-1 if there is none)
```

The mirror version, "the **last** index where the condition is true":

```cpp
int l {}, r {n - 1}, ans {-1};
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (possible(mid))
        ans = mid, l = mid + 1;      // yes: remember it, try to find a bigger one
    else
        r = mid - 1;
}
```

| I want | `possible` is true | on true | on false |
|--------|--------------------|---------|----------|
| **first** true | `F F F T T T` | `ans = mid, r = mid - 1` | `l = mid + 1` |
| **last** true | `T T T F F F` | `ans = mid, l = mid + 1` | `r = mid - 1` |

- Time: `O(log n)` calls to `possible()`.
- Equivalent to `lower_bound` / `upper_bound` in C++.

---

## 3. Binary search on real numbers

**Example:** `f(x) = 4x^7 + 3x^5 - 1000`. For which `x` is `f(x) = 0`?

> **Before writing the code, make sure the function is monotonic** on the range you search. Here `f` is increasing for `x >= 0`, `f(0) < 0` and `f(3) > 0`, so there is exactly one root in `[0, 3]`.



```cpp
double f(double x) {
    return 4 * pow(x, 7) + 3 * pow(x, 5) - 1000;
}

double binary_search_eps(double EPS = 1e-9) {
    double start = 0, end = 3;
    while (end - start > EPS) {
        double mid = start + (end - start) / 2;
        if (f(mid) < 0.0)
            start = mid;
        else
            end = mid;
    }
    return start;
}
```

Result: **x = 2.1541074609...**

### Observations

- With integers we write `l = mid + 1` or `r = mid - 1`. With **real numbers we don't**: `+1` is a huge jump, so we write `start = mid` / `end = mid`.
- We **can't compare doubles exactly**, so we use a very small value called **EPSILON (EPS)** to stop.
- You may see a note like: *"The answer should be with an absolute error of at most 10^-9."*
  - They check `fabs(your_answer - their_answer) <= 1e-9`.
  - So use **`EPS = 1e-10` or smaller**.

### The common way: loop a fixed number of iterations

```cpp
double binary_search_iter() {
    double start = 0, end = 3;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = start + (end - start) / 2;
        if (f(mid) < 0.0)
            start = mid;
        else
            end = mid;
    }
    return start;
}
```

Why most people prefer it:

- Each iteration **halves** the range, so 100 iterations shrink it by `2^100`. That is more than any precision you need.
- It **can't loop forever**. The `while (end - start > EPS)` version can: when the numbers are large (like `1e9`), the gap between two neighbour doubles is bigger than a tiny EPS, `mid` rounds to `start` or `end`, and the range stops shrinking. (I tested it: with values around `1e9` and `EPS = 1e-9` the loop never ended.)

| | `while (end - start > EPS)` | `for (iter < 100)` |
|---|---|---|
| Stops when | the range is small enough | after a fixed number of steps |
| Risk | infinite loop for large values / tiny EPS | none |
| Common? | less | **more** |

> Naming note: don't call your function `binary_search` if you write `using namespace std;`. `std::binary_search` already exists, which can cause a name clash.

---

## 4. Homework solutions

| # | Problem | Idea (what is monotonic?) | Solution |
|---|---------|---------------------------|----------|
| 1 | [LeetCode 34 - Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | first true + last true on a sorted array | [leetcode-34.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-34.cpp) |
| 2 | [LeetCode 436 - Find Right Interval](https://leetcode.com/problems/find-right-interval/) | sort by start, then lower bound | [leetcode-436.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-436.cpp) |
| 3 | [LeetCode 611 - Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) | sort, then binary search the third side | [v1](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-611.cpp), [v2](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-611-v2.cpp) |
| 4 | [LeetCode 441 - Arranging Coins](https://leetcode.com/problems/arranging-coins/) | coins needed for `k` rows grows with `k` | [leetcode-441.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-441.cpp) |
| 5 | [LeetCode 1283 - Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) | a bigger divisor gives a smaller sum | [leetcode_1283.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode_1283.cpp) |
| 6 | [LeetCode 1482 - Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | more days means more bouquets | [leetcode-1482.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-1482.cpp) |
| 7 | [LeetCode 475 - Heaters](https://leetcode.com/problems/heaters/) | nearest heater to each house | [leetcode-475.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-475.cpp) |
| 8 | [LeetCode 1060 - Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/) | missing numbers up to index `i` never decrease (my template above) | [leetcode-1060-v2.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-1060-v2.cpp) |
| 9 | [LeetCode 668 - Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) | count of numbers `<= x` grows with `x` | [leetcode-668.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-668.cpp) |
| 10 | [LeetCode 69 - Sqrt(x)](https://leetcode.com/problems/sqrtx/) | `mid * mid <= x` is true then false | [leetcode-69.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/leetcode/leetcode-69.cpp) |
| 11 | [SPOJ - PIE](https://www.spoj.com/problems/PIE/) | binary search on **real** numbers (the pie size) | [spoj-pie.cpp](https://github.com/yahyahasan5555/PS/blob/main/online-judges/misc/spoj-pie.cpp) |

---

## 5. Checklist before writing the code

1. What am I searching on? (an index, a value, a real number)
2. Is there a `possible(x)` that flips **only once**? (monotonic)
3. Do I want the **first** true or the **last** true?
4. What are the **bounds** (`l`, `r`), and is the answer inside them? What if there is no answer?
5. Integers -> `l <= r` with `mid + 1` / `mid - 1`. Real numbers -> 100 iterations with `start = mid` / `end = mid`.
6. Use `long long` if `possible()` sums or multiplies big values.

---

## Summary

- Binary search works on **any monotonic function**, not only on sorted arrays.
- `possible()` can be complex. Time = `O(log(range) * cost of possible())`.
- Integer template: keep `ans`, move `r = mid - 1` (first true) or `l = mid + 1` (last true).
- Real numbers: no `+1/-1`, compare with `EPS` (`1e-10` or smaller when the error is `1e-9`), or **just loop 100 times**.
