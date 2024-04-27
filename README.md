# L0S2
Identify the Algorithm:
First, understand the high-level algorithm used in the code. Is it a sorting algorithm, searching algorithm, or something else? Knowing the algorithm type is crucial.

Count Basic Operations:
Look for loops (iterations) in the code. These are often the primary contributors to time complexity.
Count the number of times each loop runs based on the input size (usually denoted as n).
Pay attention to nested loops (loops within loops). Each nested loop adds another layer of complexity.

Analyze Loops:
For each loop, determine how many iterations it performs based on the input size.
Common loop types and their time complexities:
Constant Time (O(1)): Operations that take the same amount of time regardless of input size (e.g., array access, arithmetic operations).
Linear Time (O(n)): A loop that runs once for each element in the input (e.g., iterating through an array).
Quadratic Time (O(n^2)): Nested loops where each loop runs n times (e.g., bubble sort).
Logarithmic Time (O(log n)): Algorithms that divide the input in half at each step (e.g., binary search).
Linearithmic Time (O(n log n)): Common in efficient sorting algorithms (e.g., merge sort, quicksort).

Combine Loops:
If there are multiple loops, add their complexities together.
For example, if you have an outer loop running n times and an inner loop running m times, the combined complexity is O(nm).
Ignore Constants and Lower-Order Terms:
Drop constant factors (e.g., 2n becomes n) and ignore lower-order terms (e.g., n^2 + 3n becomes n^2).
Focus on the dominant term—the one that grows fastest with input size.
Final Complexity:
Express the overall time complexity using Big O notation (e.g., O(n), O(n^2), etc.).
Remember that analyzing time complexity is about understanding how the algorithm scales, not about measuring actual execution time. It helps you choose the most efficient algorithm for a given problem. 🚀

If you have a specific code snippet you’d like me to analyze, feel free to share it, and I’ll walk you through the process!