# Insertion Sort

Insertion sort builds the sorted array **one element at a time**, the same way you sort playing cards in your hand.

It is based on the **incremental** technique: keep a sorted prefix, then insert the next element into the right place inside it.

## How it works

1. The first element alone is already a sorted prefix.
2. Take the next element (the **key**).
3. Shift every bigger element in the prefix one step to the right.
4. Drop the key into the gap.
5. Repeat until the end of the array.

Trace on `[5, 2, 4, 1]` (brackets = sorted prefix):

```
[5] 2 4 1      key = 2  ->  shift 5          ->  [2 5] 4 1
[2 5] 4 1      key = 4  ->  shift 5          ->  [2 4 5] 1
[2 4 5] 1      key = 1  ->  shift 5, 4, 2    ->  [1 2 4 5]
```

## Complexity

| Case    | Time     | When                  |
|---------|----------|-----------------------|
| Best    | `O(n)`   | already sorted        |
| Average | `O(n²)`  | random order          |
| Worst   | `O(n²)`  | reversed order        |
| Space   | `O(1)`   | always (extra memory) |

The number of shifts equals the number of **inversions** (pairs that are out of order), so the running time is `O(n + inversions)`. A sorted array has 0 inversions, and a reversed one has the maximum, `n(n-1)/2`.

## Testing with different inputs

| Input                           | Effect on running time                                                                                          |
|---------------------------------|-----------------------------------------------------------------------------------------------------------------|
| Odd / even size                 | No difference.                                                                                                  |
| Duplicate vs. unique values     | Equal values are not inversions, so duplicates tend to reduce the work. Unique values give more possible shifts. |
| Sorted / almost sorted / random | The closer to ascending order, the closer to the best case, `O(n)` for a sorted array.                          |

## Properties

- **Comparison-based:** it only decides by comparing two elements.
- **In-place:** it needs only `O(1)` extra memory.
- **Stable:** equal elements keep their original relative order (thanks to the strict `>` in the shifting loop).
- **Online:** it can sort a list as it receives it (streams).
- **Adaptive:** it runs faster the closer the input is to sorted.