# Count Sort

Count sort sorts by **counting** how many times each value appears, then writing the values back in order.

## What is special about this algorithm?

- It works best when the array values have a **small range**.
- It is **not comparison-based**: it never compares two elements to decide their order. That is why it can beat the `O(n log n)` limit of comparison sorts.

## Procedure

1. Compute the maximum value in the given array.
2. Create a frequency array of `max + 1` cells, and count how many times each value appears.
3. Iterate from index `0` to index `max`. If a value has a frequency, spread it that many times into the array. Going from index `0` up to `max` is what makes the array sorted.

Trace on `[3, 1, 4, 1, 3]` (max = 4):

```
Step 2: count the values

  index:  0  1  2  3  4
  freq:  [0, 2, 0, 2, 1]      (1 appears twice, 3 twice, 4 once)

Step 3: spread them back, from index 0 up to max

  index 1, freq 2  ->  1 1
  index 3, freq 2  ->  1 1 3 3
  index 4, freq 1  ->  1 1 3 3 4        sorted
```

## Complexity

Let `n` be the number of elements and `k` the range of values (`max - min + 1`).

|Case|Time|When|
|---|---|---|
|Best|`O(n + k)`|any input|
|Average|`O(n + k)`|any input|
|Worst|`O(n + k)`|any input|
|Space|`O(k)`|always (the frequency array)|

- Finding the max and counting take `O(n)`. Walking over the frequency array and writing back takes `O(n + k)`.
- If `k` is `O(n)`, the whole sort is **linear**.
- If `k` is much bigger than `n`, it gets slow and memory-hungry. For example, `k` close to `n²` makes it `O(n²)`, and `k` of `10⁹` would need a ~4 GB frequency array just to sort a few numbers.

## Constraints

1. **The range of values (`k`) must be small**, ideally not much larger than `n`. Time and memory both grow with `k`, not only with `n`.
2. **The values must be integers** (or something you can map to integers, like characters or ages). They are used directly as array indexes, so floating-point numbers and strings do not work.
3. **The basic version needs non-negative values**, because a value is used as an index and `freq[-3]` is out of bounds.
4. **What if there are negative values?** Shift everything by the minimum value: store the count of `x` at index `x - min`, and write `index + min` back. The smallest value maps to index `0`, and the array size becomes `max - min + 1`.
5. **The frequency array must fit in memory.** `max + 1` (or `max - min + 1`) can overflow `int`, and a huge range cannot be allocated.
6. **Only the key matters.** The version that rewrites values from counts cannot carry extra data. To sort records (for example people by age), use the stable variant below.

## Testing with different inputs

|Input|Effect on running time|
|---|---|
|Odd / even size|No difference.|
|Many duplicates vs. unique values|Many duplicates with a small range is the ideal case. Unique values with a huge range is the worst use.|
|Sorted / almost sorted / reversed|No difference. The order of the input does not matter (not adaptive).|
|Small range vs. large range|This is what matters: time and memory are `O(n + k)`.|
|Negative values|Fail in the basic version. They need the shift by `min`.|

## Properties

- **Not comparison-based:** it never compares two elements.
- **Not stable:** in this version we lose the original elements and rebuild the values only from their frequencies. (For plain integers equal values look the same, so this only matters for records.)
- **Not adaptive:** the processing flow is the same regardless of the data.
- **Not practical for online processing:** we need to calculate the max value (the whole array) before we start.
- **Not in-place:** it requires `O(k)` extra space for the frequency array.