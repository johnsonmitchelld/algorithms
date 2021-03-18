# Interview Problem Solutions

## LeetCode

### LC146: LRU Cache

### CTCI 1.1 / [LC 217](https://leetcode.com/problems/contains-duplicate/) Contains Duplicate

Question: Given a string (or an array of integers), determine if there are any duplicate characters (or values).

Answer: Initialize a hashmap, then iterate through the array/string. For every array element or character, check to see if the it already exists as a key in the hashmap. If it does not, add it to the hashmap. If it does, return true. Once the loop has completed, if no duplicates have been found, return false.

Analysis: Use a hashmap to check if an element exists in a set in constant time. Overall runtime is O(n), where n is the string or the array length. This is optimal, since we must examine every element of the string or array at least once.

For the string version, we have more options for representing the collection of already-checked characters. A char array of length R will work, where R is the radix, or the size of the character set used. The string type used (ASCII or Unicode) will have a large impact on the size of this array.

If you can't use additional data structures, you can compare every element to every other element in O(n^2) time. If you can modify the input array, you can sort it, then iterate directly through and check for adjacent duplicates. You'll have to choose a sorting algorithm carefully - some string algorithms work in O(n) time, but may require extra space.

### CTCI 1.2 / [LC 567](https://leetcode.com/problems/permutation-in-string/) String Permutations

Question: Given two strings, write a method to decide if one is a permutation of the other.

Answer: The CTCI and LeetCode versions of this question are asking different things. The CTCI version asks if one string *is* a permutation of the other; the LeetCode version asks if one string *contains* a permutation of the other. This is an important difference.

For the CTCI version, there are two potential solutions: sort the strings and compare them, or count the occurrences of each character in each string and compare the character counts. 

For the LeetCode version, we can use a variation on the CTCI solution. Create the character count array, but only for a window in the larger string that is the same size as the smaller string. Then, compare the counts for each window of that size in the larger string. The character count can be updated by simply decrementing the count for the character that is leaving the window as it slides and incrementing the character that enters the window.

Analysis: this solution works in O(n), where n is the length of the longer string. This is because adjusting the character count is a constant time operation.

### CTCI 1.3: URLify

Question: Write a method to replace all spaces in a string with %20.

Answer: Maintain a read pointer and a write pointer for the string. Start the read pointer at the back of the input string and the write pointer at the back of the "real" string, including the extra characters. Then iterate backwards through the string, copying each character to the back of the string until a space is encountered. When a space is encountered, copy the sequence %20 (in reverse, of course) instead of the space, then decrement the read and write pointers accordingly.

Analysis: This solution should work in O(n), where n is the final length of the string.

### CTCI 1.4: Palindrome Permutation

Question: Given a string, write a function to check if it is a permutation of a palindrome.

Answer: Iterate through the string and count the occurrence of each character in an array. In a palindrome, at most one character can occur an odd number of times (if the word contains an odd number of characters) and at least zero characters can occur an odd number of times (if the word contains an even number of characters). Then, iterate through the array and count the number of characters which occur an **odd** number of times. If the number is more than zero for an even-length word or more than one for an odd-length word, return false. Otherwise return true.

Analysis: O(n). The character count takes time linear in the length of the input string, and counting the odd numbered characters takes constant time (the alphabet only has 26 characters no matter the length of the input string).

### CTCI 1.5: One Away

Question: Given two strings, write a function to check if they are zero or one edit away.

Answer: This is a variation on edit distance, which is a classic dynamic programming problem. However, because we only need to know if the edit distance is above a threshold, not its exact value, we don't need to use dynamic programming to find the minimum edit distance. Instead, we can just iterate through the string and compare each character. If more than one is not the same, return false. Otherwise, return true. We can also implement a check at the beginning of the method to evaluate whether the lengths of each string are within one character of each other. If not, we can return false right away because there must be more than one non-matching character.

Analysis: O(n). This solution requires us to check characters until we find at least two that are different, meaning that its runtime is at most proportional to the length of the strings. Average time will be shorter, since we can terminate early as soon as we realize the edit distance is greater than one.

This problem is interesting, because it is a variation on a dynamic programming problem that can be solved without dynamic programming. **Watch out for this in interviews.**

### CTCI 2.2 / [LC 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

Question: Given the head of a linked list, remove the nth node from the end of the list and return its head.

Answer: Iterate through the list once to find its length, then subtract `n` from the length of the list to find the index of the element to be removed. Iterate through the list from the beginning again until you find that element and remove it.

Analysis: O(n) time, O(1) space.

### CTCI 2.7 / [LC 160](https://leetcode.com/problems/intersection-of-two-linked-lists/)

Question: Given two singly linked lists, determine if the two lists intersect. If so, return the intersecting node.

Answer: Iterate through both lists until you arrive at the last node. If they are the same, the lists intersect. To find the intersection, determine the length of each list (you can do this by counting the nodes traversed in the previous step). Then, find the difference between the two lengths, and skip that many nodes in the longer list. Finally, iterate through both lists again (the shorter from the beginning and the longer starting after the skipped node) until you find the first intersecting node.

Analysis: This whole process should run in O(n) time.

### CTCI 3.2 / [LC 155](https://leetcode.com/problems/min-stack/) Min Stack

Question: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Answer: A key insight here is that the min element does not need to be **removed** in constant time, only accessed. So, in addition to the standard stack, keep a second stack with the current min element and its position in the array. Since the min of the stack at any given time is the min of all elements below the top, pop the top off the min element stack whenever you pop that element from the main stack. The next element in the min stack will thus be the min value of the remaining elements before the most recent min was added.

Analysis: All operations occur in O(1) time and O(n) space. In the worst-case space scenario, where elements are added to the stack in decreasing order, the space requirement will double because the min value stack will contain all the same elements of the full stack. However, this still nets us O(n) space.

### CTCI 4.2 / [LC 108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) Convert Sorted Array to BST

