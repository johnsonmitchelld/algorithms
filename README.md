# Algorithms Curriculum

## Haseeb Qureshi's [Programming Interview Study Guide](https://haseebq.com/how-to-break-into-tech-job-hunting-and-interviews/)

### Data Structures
First and foremost, work through the Princeton algorithms course. You should follow along and implement as much as you can. Along the way, also implement all these major data structures. (Many of these are not explicitly covered in the course—implement them on your own). Know all of the time complexities for their basic operations. It helps to visually intuit them. Look at images. Draw them out on paper/whiteboard.

- Linked List
- Dynamic array, implemented with a ring buffer (use a statically sized array underneath the hood)
- Hash set
- Hash map (with chaining)
- Binary heap (without decrease-key; know that Fibonacci heaps exist and know their guarantees)
- Binary search tree (doesn’t need to be self-balancing; know that self-balancing trees exist and know their guarantees)
- Prefix tree (a.k.a. trie)
- Suffix tree (don’t worry about compression, just build a dumb version; know that Ukkonen’s algorithm exists and learn its guarantees)
- An object-oriented adjacency list for graphs

### Algorithms

Implement this subset of the most common algorithms. Know the time complexities and space complexities of all of these algorithms (cheat-sheet). Know the difference between amortized, average, and worst-case time guarantees.

- Binary search (implement it both iteratively and recursively)
- Randomized quicksort (pay extra attention to the partition subroutine, as it’s useful in a lot of places)
- Mergesort
- Breadth-first search in a graph
- Depth-first search in a graph (augment it to detect cycles)
- Tree traversals (pre-order, in-order, post-order)
- Topological sort (using Tarjan’s algorithm)
- Dijkstra’s algorithm (without decrease-key)
- Longest common subsequence (using dynamic programming with matrices)
- Knapsack problem (also dynamic programming)
- Do at least one or two problems where you BFS or DFS through a matrix.

Once you finish these you should have a decent grounding in algorithms and data structures. Read through the entirety of Algorithm Design Manual to solidify your understanding. Implement anything that you find sufficiently interesting.

A few points of interest: 
- learn about heap sort, but don’t bother coding it. Know that it’s O(1) space but practically very slow due to cache-inefficiency. 
- Learn about quickselect and median-of-medians. Code them if you want.

### Computer Architecture

Learn the basics of bit manipulation. Be able to explain what AND, OR, and XOR do. Know what a signed integer is. Know that there are 8 bits in a byte. Know what assembly is (from a high level), and get a sense of the basic operations that hardware exposes. This awesome video about the inner workings of the original Game Boy covers just about all you need to know.

Read about caches and cache efficiency. Know what a cache miss is. Know that reading from registers is lightning-fast, reading from the various caches is pretty fast, reading from memory is slow, and that reading from the hard disk is abysmally slow.

Read how to implement an LRU cache, and then actually write one that gets and sets in worst-case O(1) time. This is a weirdly common interview problem.

### Databases

Learn about SQL databases. Learn how to design a SQL database schema; it comes up in interviews often. Read about ACID, the CAP theorem, and BASE (you don’t need to memorize the terms, just understand the concepts at a high level.) Understand why joins can become unscalable. Learn the basics of NoSQL databases.

### Web Development

Learn what happens when you type a URL into your browser and press enter. Be comfortable talking about DNS lookups, the request-response cycle, HTTP verbs, TCP vs UDP, and how cookies work. Shows up all the time in interviews.

Learn the standard ways to speed up a slow website. This includes a lot of things like adding database indices to optimize common queries, better caching, loading front-end assets from a CDN, cleaning up zombie listeners, etc. Also an interview classic, pretty rabbit-holey.