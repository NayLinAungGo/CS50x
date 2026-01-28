# Week-3 Shorts

* [Call Stacks](#call-stacks)
* [Selection Sort](#selection-sort)
* [Bubble Sort](#bubble-sort)
* [Binary Search](#binary-search)
* [Linear Search](#linear-search)
* [Recursion](#recursion)
	* [Factorial Function](#factorial-function)
* [Merge Sort](#merge-sort)

## Linear Search

The idea of the algorithm is to iterate across the array from left to right,
searching for the specifed element.

In pseudocode:

    Repeat, starting at the first element.
        If the first element is the target, stop.
        Otherwise, move to the next element.

* **Worst-case scenario:** The entire array of *n* elements has to be looked through,
either because the target element is the last element or the array
or doesn't exist in the array at all.
* **Best-case scenario:** The target element is the first element of the array.


## Binary Search

In pseudocode:

    Repeat until the (sub)array is of size 0:
        Calculate the middle point of the current (sub)array
        If the target is at the middle, stop
        Otherwise, if the target is less than what's at the middle, repeat, changing the end point to be just to the left of the middle
        Otherwise, if the target is greater than what's at the middle, repeat, changing the start point to be just right to the middle

* **Wort-case scenario:** The list of *n* elements have to be divided repeatedly
to find the target element,
either because the target element will be found at the end of the last division
or doesn't exist in the array at all
* **Best-case scenario:** The target element is at the midpoint of the full array

Binary search is O(log n) & Ω(1)


## Bubble Sort

In pseudocode:

    Set swap counter to a non-zero value
    Repeat until the swap counter is 0
        Reset swap counter to 0
        Look at each adjacent pair
            If two adjacent elements are not in order swap them and add one to the swap counter

* **Worse-case scenario:** The array is in reverse order
* **Best-case scenario:** The array is perfectly sorted, and no swaps need to be make

Bubble sort is O(n²) & Ω(n)


## Selection Sort

In pseudocode:

    Repeat until no unsorted elemenets remain:
        Search the unsorted part of the data to find the smallest value
        Swap the smallest found value with the first element of the unsorted part

* **Worst-case scenario:** Each of the *n* elements of the array
must be iterated over (to find the smallest unsorted element)
and the process must be repeated *n* times
* **Best-case scenario:** Exactly the same as the worst-case

Selection sort is O(n²) & Ω(n²) and therefore θ(n²)


## Call Stacks

When a function is called,
the system set aside a chunk in memory---called 
**stacked frames** or **function frames**---to do its necessary work.

More than one function's stack frame may exist in memory at a given time.
If `main()` calls `move()`, which then calls `direction()`,
all three functions have open frames.

These frames are arranged in a **stack.**
The frame for the most-recently called function is always on the top of the stack.

When a new function is called, a new frame is **pushed** onto
the top of the stack and becomes the active frame.

When a function finishes its work,
its frame is **popped** off of the stack, and the frame immediately below it
becomes the new, active, function on the top of the stack.


## Recursion

A recursive function is one that, as part of its execution,
invokes itself.

The technique of **recursion** is a very common way to
implement an "elegant" solution.

### Factorial Function

The factorial function (n!) is defined over all positive integers.

*n*! equals all of the positive integers less than or equal to *n*,
multiplied together.

    fact(1) = 1
    fact(2) = 2 * 1
    fact(3) = 3 * 2 * 1
    fact(4) = 4 * 3 * 2 * 1
    fact(5) = 5 * 4 * 3 * 2 * 1
    ...

The mathematical function *n*! shall be defined as `fact(n)`.

    fact(1) = 1
    fact(2) = 2 * fact(1)
    fact(3) = 3 * fact(2)
    fact(4) = 4 * fact(3)
    fact(5) = 5 * fact(4)
    ...
    fact(n) = n * fact(n-1)

This forms the basis for a **recursive definition** of the factorial function.

Every recursive function has two cases that could apply:
* The *base case:* when triggered will terminate the recursive process.
* The *recursive case:* where the recursion will occur.

    int fact(int n)
    {
        // base case
        if (n == 1)
            return 1;

        // recursive case
        else
            return n * fact(n-1);
    }

In general, but no always, recursive functions replace loops
in non-recursive functions.

It's also possible to have more than one base or recursive case.

* **Multiple base cases:** The Fibonacci number sequence is defined as follows:
    * The first element is 0.
    * The second element is 1.
    * The nth element is the sum of the (n-1)th and (n-2)th elements.

* **Multiple recursive cases:** The Collatz conjecture.
    * Applies to positive integers and speculates that
    it is always possible to get "back to 1" if these steps are followed:
        * If n is 1, stop.
        * Otherwise, if n is even, repeat this process on n/2.
        * Otherwise, if n is odd, repeat this process on 3n + 1.


## Merge Sort

In pseudocode:

    Sort the left half of the array (assuming n > 1)
    Sort the right half of the array (assuming n > 1)
    Merge the two halves together

* **Worst-case scenario:** *n* elements up need to be splitted and then recombined,
doubling the sorted subarrays.
* **Best-case scenario:** The array is already sorted.
But the algorithm would still split and recombine it back together.

Merge sort is O(*n log n*) and Ω(*n log n*)
