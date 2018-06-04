# LeetCode-Solutions

Solutions for LeetCode Problems

##  Solution Classificaion

### Linked List

解链表问题关键在于灵活创建并使用头尾指针

1. 翻转链表只需`O(n)`时间 + `O(1)`空间

- [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)

### Slide Window

- [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

### Anagrams

- [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/description/)
- [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)


### Palindrom

三类回文问题：

1. 寻找回文串，两种解法
    - 中心扩散
    - 动态规划

- 题目

- [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)
- [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)


### K-Sum

- [1. Two Sum](https://leetcode.com/problems/two-sum/description/)
- [15. 3Sum](https://leetcode.com/problems/3sum/description/)
- [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/description/)
- [18. 4Sum](https://leetcode.com/problems/4sum/description/)

### Divide & Conquer / Decrease & Conquer

- [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/)
- [38. Count and Say](https://leetcode.com/problems/count-and-say/description/)
- [46. Permutations](https://leetcode.com/problems/permutations/description/)
- [47. Permutations II](https://leetcode.com/problems/permutations-ii/description/)
- [78. Subsets](https://leetcode.com/problems/subsets/description/)


### DFS & Backtracking

求深搜与回溯问题的核心在于构建正确的解空间树（决策树），DFS深搜重要三步：

1. choose（set state） 
2. select (递归)
3. unchoose (backtracking, reset state)

重要的有下面几类问题

1. 排列组合问题，区别在于for循环的起始index计算方式，该类问题也可以使用分治法求解（减而治之）
2. N皇后和数独问题，难点在于递归函数的入参设计


- [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/description/)
- [46. Permutations](https://leetcode.com/problems/permutations/description/)
- [47. Permutations II](https://leetcode.com/problems/permutations-ii/description/)
- [51. N-Queens](https://leetcode.com/problems/n-queens/description/)
- [52. N-Queens II](https://leetcode.com/problems/n-queens-ii/)
- [78. Subsets](https://leetcode.com/problems/subsets/description/)
- [77. Combinations](https://leetcode.com/problems/combinations/description/)
- [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)
- [216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/description/)


### Dynamic Programming

- [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)


### BinaryTree

- [144. PreOrderTraversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)
- [145. PostOrderTraversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)
- [94. InOrderTraversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)


### Binary Search

- [34. Search for a Range](https://leetcode.com/problems/search-for-a-range/description/)

### Bitwise

- [29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/submissions/1)