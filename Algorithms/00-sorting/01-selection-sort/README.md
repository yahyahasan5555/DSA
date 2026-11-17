# Selection Sort

Selection sort repeatedly **selects the smallest remaining element** and puts it in its final place.

It is based on a simple observation about the sorted array:

- The first element is the minimum of the whole array.
- The second element is the minimum of what remains (the second minimum overall).
- And so on...

So we can build the sorted array from left to right: find the minimum of the unsorted part, swap it to the front of that part, and shrink the unsorted part by one.

## How it works

1. Look at the unsorted part (at the start, the whole array).
2. Find the index of its minimum element.
3. Swap that element with the first element of the unsorted part.
4. The sorted prefix grows by one. Repeat.
5. Stop after `n - 1` rounds, because the last element is automatically the maximum and already in place.

Trace on `[5, 2, 4, 1, 3]` (the bar `|` separates the sorted prefix from the unsorted part):

```
[ | 5 2 4 1 3 ]   min = 1  ->  swap with 5  ->  [ 1 | 2 4 5 3 ]
[ 1 | 2 4 5 3 ]   min = 2  ->  already there ->  [ 1 2 | 4 5 3 ]
[ 1 2 | 4 5 3 ]  min = 3  ->  swap with 4  ->  [ 1 2 3 | 5 4 ]
[ 1 2 3 | 5 4 ]  min = 4  ->  swap with 5  ->  [ 1 2 3 4 | 5 ]
```

## Complexity

|Case|Time|When|
|---|---|---|
|Best|`O(n²)`|any input|
|Average|`O(n²)`|any input|
|Worst|`O(n²)`|any input|
|Space|`O(1)`|always (extra memory)|

Finding each minimum is a full scan of the unsorted part, whatever the order of the values. The number of comparisons is always exactly `n(n-1)/2`.

Selection sort does **at most `n - 1` swaps** (`O(n)` writes), which is much less than insertion sort or bubble sort. That is its one real advantage, and it matters only when writing to memory is expensive.

## Testing with different inputs

|Input|Effect on the number of comparisons|
|---|---|
|Odd / even size|No difference.|
|Duplicate vs. unique values|No difference.|
|Sorted / almost sorted / reversed|No difference. There is no real best or worst case (only the swaps change).|

This is the opposite of 'insertion sort, where a sorted input is the best case (`O(n)`). Selection sort ignores the order of the input, so it is **not adaptive**.

## Properties

- **Comparison-based:** it only decides by comparing two elements.
- **In-place:** it needs only `O(1)` extra memory.
- **Not stable:** the long-distance swap can move an element past an equal one.
- **Not adaptive:** it does the same work on sorted and unsorted input.
- **Not online:** it needs the whole array to find the minimum.

Why it is not stable, with the two equal `2`s labeled `2a` and `2b`:

```
[ 2a, 2b, 1 ]   ->  swap 2a with 1  ->  [ 1, 2b, 2a ]    (2a and 2b changed order)
```