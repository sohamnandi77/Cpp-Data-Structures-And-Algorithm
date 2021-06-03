## Data Structure and Algorithms Problems

<p align = "center">

<img src = "https://i.ibb.co/Bn4S3Fk/A-Little-Progress-Each-Day-Adds-Up-to-Big-Result.jpg" width = 320px height = 320px>

</p>
    
<hr/>

## Introduction

Data structures & Algorithms are an essential part of programming. It comes under the fundamentals of computer science. It gives us the advantage of writing better and efficient code in less time. It is a key topic when it comes to Software Engineering interview questions so as developers, we must have knowledge of Data Structure and Algorithms

:star2: Star it | :fork_and_knife:Fork it | :handshake: Contribute to it!

**Note: I tried to provide the Brute Force and Optimized soluton for each question. If you feel to optimize any solution futher or give some suggestion, Pull Requests are always welcome.**

<hr/>

**Sorry Links Have not been updated yet!**

## Data Structures and Algorithms

Data structure is a way or a format how your data is stored in memory for effecient usage and retrieval.

<h3>Arrays</h3>
<details>
<summary>Problems</summary>

| Topics / Questions                                                             | Code / Comments                                                                                                                                                                                                                                                                                                                                                                                   |
| ------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Check if the Array is Sorted either in strictly Increasing or decreasing order | [O(n) Solution](Array/01.%20IsSorted.cpp)                                                                                                                                                                                                                                                                                                                                                         |
| Reverse The Array                                                              | [O(n) Solution](Array/02.%20ReverseTheArray.cpp)                                                                                                                                                                                                                                                                                                                                                  |
| Left Rotate Array By 1 place                                                   | [O(n) Solution](Array/03.%20LeftRotateBy1Place.cpp)                                                                                                                                                                                                                                                                                                                                               |
| Left Rotate Array By D place                                                   | [O(n) Solution](Array/04.%20LeftRotateByDPlace.cpp) (<b>This concept can be used with strings as well</b>)                                                                                                                                                                                                                                                                                        |
| Remove Duplicates from the Array                                               | [O(n^2) Solution](Array/05.%20RemoveDuplicates) <br> [O(n) Solution](Array/03.%20RemoveDuplicates)                                                                                                                                                                                                                                                                                                |
| Move All the Zeros To the end of the Array                                     | [O(n^2) Solution](Array/06.%20MoveZerosToEnd) <br> [O(n) Solution](Array/04.%20MoveZerosToEnd)                                                                                                                                                                                                                                                                                                    |
| Leaders In Array                                                               | [O(n^2) Solution](Array/07.%20LeadersInArray.cpp) <br> [O(n) Solution](Array/07.%20LeadersInArray.cpp)                                                                                                                                                                                                                                                                                            |
| Frequencies In sorted Array                                                    | [O(n) Solution](Array/08.%20FrequenciesInSortedArray.cpp)                                                                                                                                                                                                                                                                                                                                         |
| Frequencies of Limited Range Array                                             | [O(nlog(n)) Solution](Array/09.%20FrequenciesOfLimitedRangeArray.cpp)                                                                                                                                                                                                                                                                                                                             |
| Maximum Consecutive 1s                                                         | [O(n) Solution](Array/10.%20MaximumConsecutive1s.cpp)                                                                                                                                                                                                                                                                                                                                             |
| Minimum Consecutive Flips                                                      | [O(n) Solution](Array/11.%20MinimumConsecutiveFlips.cpp)                                                                                                                                                                                                                                                                                                                                          |
| Print All Subarrays                                                            | [O(n^2) Solution](Array/12.%20PrintAllSubarrays.cpp)                                                                                                                                                                                                                                                                                                                                              |
| Print All Subsequences                                                         | [O(n^2) Solution](Array/13.%20PrintAllSubsequences.cpp)                                                                                                                                                                                                                                                                                                                                           |
| Rearrange Array Alternately in Min Max Form                                    | [O(n) Solution](Array/Rearranging/01.%20RearrangeArrayAlternatelyInMaxMinForm.cpp) (<b> Quotient Remainder Concept</b>)                                                                                                                                                                                                                                                                           |
| Rearrange an Array                                                             | [O(n) Solution](Array/Rearranging/02.%20RearrangeAnArray.cpp) (<b> Quotient Remainder Concept</b>)                                                                                                                                                                                                                                                                                                |
| Find Repeating Element                                                         | [Time : O(n) / Space: O(n) Solution](Array/Rearranging/03.%20FindRepeatingElement.cpp) <br> [Time : O(n) / Space: O(1) Solution](Array/Rearranging/03.%20FindRepeatingElement.cpp) (<b> Slow and Fast Pointer</b>)                                                                                                                                                                                |
| Two Repeated Element                                                           | [Time : O(n) / Space: O(1) Solution](Array/Rearranging/04.%20TwoRepeatedElements.cpp) (<b> Using Negative Flag</b>) <br> [Time : O(n) / Space: O(1) Solution](Array/Rearranging/04.%20TwoRepeatedElements.cpp) (<b> Quotient Remainder Concept</b>)                                                                                                                                               |
| Smallest Positive Missing Number                                               | [Time : O(nlog(n)) / Space: O(1) Solution](Array/Rearranging/05.%20SmallestPositiveMissingNumber.cpp) <br> [Time : O(n) / Space: O(n) Solution](Array/Rearranging/05.%20SmallestPositiveMissingNumber.cpp) (<b> Array as Index sorting or using a hashmap</b>) <br> [Time : O(n) / Space: O(1) Solution](Array/Rearranging/05.%20SmallestPositiveMissingNumber.cpp) (<b> Using Negative Flag</b>) |
| Find All Repeated and Missing Number                                           | [Time : O(n) / Space: O(1) Solution](Array/Rearranging/06.%20FindAllRepeatedAndMissingNumber.cpp) (<b> <a href="https://www.youtube.com/playlist?list=PL_z_8CaSLPWdJfdZHiNYYM46tYQUjbBJx">Swap Sort<a></b>)                                                                                                                                                                                       |
| Maximum Subarray Sum (Kadane's Algorithm)                                      | [O(n^2) Solution](Array/Kadane's%20Algorithm/01.%20MaximumSubarraySum.cpp) <br> [O(n) Solution](Array/Kadane's%20Algorithm/01.%20MaximumSubarraySum.cpp) (<b>Kadane's Algorithm</b> )                                                                                                                                                                                                             |
| Print Maximum Subarray Sum                                                     | [O(n) Solution](Array/Kadane's%20Algorithm/02.%20PrintMaximumSubarraySum.cpp) (<b>Kadane's Algorithm</b> )                                                                                                                                                                                                                                                                                        |
| Maximum Difference Problem                                                     | [O(n^2) Solution](Array/Kadane's%20Algorithm/03.%20MaximumDifferenceProblem.cpp) <br> [O(n) Solution](Array/Kadane's%20Algorithm/03.%20MaximumDifferenceProblem.cpp) (<b>Kadane's Algorithm</b> )                                                                                                                                                                                                 |
| Longest Even Odd Subarray                                                      | [O(n^2) Solution](Array/Kadane's%20Algorithm/04.%20LongestEvenOddSubarray.cpp) <br> [O(n) Solution](Array/Kadane's%20Algorithm/04.%20LongestEvenOddSubarray.cpp) (<b>Kadane's Algorithm</b> )                                                                                                                                                                                                     |
| Print Longest Even Odd Subarray                                                | [O(n) Solution](Array/Kadane's%20Algorithm/05.%20PrintLongestEvenOddSubarray.cpp) (<b>Kadane's Algorithm</b> )                                                                                                                                                                                                                                                                                    |
| Maximum Circular Subarray Sum                                                  | [O(n) Solution](Array/Kadane's%20Algorithm/06.%20MaximumCircularSumSubarray.cpp) (<b>Kadane's Algorithm</b> )                                                                                                                                                                                                                                                                                     |
| Majority Element - 1                                                           | [O(n^2) Solution](Array/Moore's%20Voting%20Algorithm/01.%20MajorityElement-1.cpp) <br> [O(n) Solution](Array/Moore's%20Voting%20Algorithm/01.%20MajorityElement-1.cpp) (<b>Moore's Voting Algorithm</b> )                                                                                                                                                                                         |
| Majority Element - 2                                                           | [O(n^2) Solution](Array/Moore's%20Voting%20Algorithm/02.%20MajorityElement-2.cpp) <br> [O(n) Solution](Array/Moore's%20Voting%20Algorithm/02.%20MajorityElement-2.cpp) (<b>Boyer Moore's Voting Algorithm</b> )                                                                                                                                                                                   |
| More Than n/k Occurences                                                       |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Maximum Index                                                                  |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Stock Buy and Sell - 1                                                         |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Stock Buy and Sell - 2                                                         |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Trapping RainWater                                                             |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Count 1s in a Sorted Array                                                     |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Maximum Length Biotonic Subarray                                               |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Maximum Sum of K Consecutive Elements                                          |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Find Subarray of Given Sum                                                     |                                                                                                                                                                                                                                                                                                                                                                                                   |
| N-bonacci Numbers                                                              |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Prefix Sum                                                                     |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Find Equilibrium Point                                                         |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Maximum Occuring Element                                                       |                                                                                                                                                                                                                                                                                                                                                                                                   |
| Split Array in 3 equal parts                                                   |                                                                                                                                                                                                                                                                                                                                                                                                   |

</details>

<h3>Searching</h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<h3><a href="https://github.com/sohamnandi77/Cpp-Data-Structures-And-Algorithm/blob/master/Sorting/README.md">Sorting</a></h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<h3><a href="">Matrix</a></h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<h3><a href="">Hashing</a></h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<h3><a href="">Strings</a></h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<h3><a href="">Recursion</a></h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<h3><a href="">Backtracking</a></h3>

<details>

| Topics / Questions                | Code / Comments |
| --------------------------------- | --------------- |
| Linear Search                     |                 |
| Binary Search - Recursive         |                 |
| Binary Search - Iterative         |                 |
| First Index Of Number - Recursive |                 |
| First Index Of Number - Iterative |                 |
| Last Index Of Number - Recursive  |                 |
| Last Index Of Number - Iterative  |                 |

</details>

<!-- ## Algorithms

An algorithm is a set of instructions that are used to accomplish a task, such as finding the largest number in a list, removing all the red cards from a deck of playing cards, sorting a collection of names, figuring out an average movie rating from just your friend's opinion

Algorithms are not limited to computers. They are like a set of step-by-step instructions or an even a recipe, containing things you need, steps to do, the order to do them, conditions to look for, and expected results. -->
