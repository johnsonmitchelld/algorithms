# Interview Prep Curriculum

## Haseeb Qureshi's [Tech Interview Study Guide](https://haseebq.com/how-to-break-into-tech-job-hunting-and-interviews/)

### Data Structures

First and foremost, work through the Princeton algorithms course. You should follow along and implement as much as you can. Along the way, also implement all these major data structures. (Many of these are not explicitly covered in the course—implement them on your own). Know all of the time complexities for their basic operations. It helps to visually intuit them. Look at images. Draw them out on paper/whiteboard.

- Linked List
- [Dynamic array](https://en.wikipedia.org/wiki/Dynamic_array), implemented with a [ring buffer](https://en.wikipedia.org/wiki/Circular_buffer) (use a statically sized array underneath the hood)
- Hash set
- [Hash map](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining_with_linked_lists) (with chaining)
- Binary heap (without decrease-key; know that [Fibonacci heaps](https://en.wikipedia.org/wiki/Fibonacci_heap) exist and know their guarantees)
- Binary search tree (doesn’t need to be self-balancing; know that [self-balancing trees](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree#Implementations) exist and know their guarantees)
- Prefix tree (a.k.a. trie)
- Suffix tree (don’t worry about compression, just build a dumb version; know that [Ukkonen’s algorithm](https://en.wikipedia.org/wiki/Ukkonen%27s_algorithm) exists and learn its guarantees)
- An object-oriented [adjacency list](https://en.wikipedia.org/wiki/Adjacency_list) for graphs

### Algorithms

Implement this subset of the most common algorithms. Know the time complexities and space complexities of all of these algorithms ([cheat-sheet](http://bigocheatsheet.com/)). Know the difference between [amortized, average](https://stackoverflow.com/a/7335098), and worst-case time guarantees.

- Binary search (implement it both iteratively and recursively)
- Randomized quicksort (pay extra attention to the partition subroutine, as it’s useful in a lot of places)
- Mergesort
- Breadth-first search in a graph
- Depth-first search in a graph (augment it to detect cycles)
- Tree traversals (pre-order, in-order, post-order)
- Topological sort (using [Tarjan’s algorithm](https://en.wikipedia.org/wiki/Topological_sorting#Depth-first_search))
- Dijkstra’s algorithm ([without decrease-key](https://stackoverflow.com/questions/9255620/why-does-dijkstras-algorithm-use-decrease-key))
- Longest common subsequence (using dynamic programming with matrices)
- Knapsack problem (also dynamic programming)
- Do at least one or two problems where you BFS or DFS through a matrix.

Once you finish these you should have a decent grounding in algorithms and data structures. Read through the entirety of Algorithm Design Manual to solidify your understanding. Implement anything that you find sufficiently interesting.

A few points of interest: 
- learn about heap sort, but don’t bother coding it. Know that it’s O(1) space but practically very slow due to cache inefficiency.
- Learn about quickselect and median-of-medians. Code them if you want.

### Computer Architecture

Learn the basics of bit manipulation. Be able to explain what AND, OR, and XOR do. Know what a signed integer is. Know that there are 8 bits in a byte. Know what assembly is (from a high level), and get a sense of the basic operations that hardware exposes. This [awesome video](https://www.youtube.com/watch?v=RZUDEaLa5Nw) about the inner workings of the original Game Boy covers just about all you need to know.

Read about caches and cache efficiency. Know what a cache miss is. Know that reading from registers is lightning-fast, reading from the various caches is pretty fast, reading from memory is slow, and that reading from the hard disk is abysmally slow.

From [Hacker News](https://news.ycombinator.com/item?id=22708094): Learn how much slower it is to sum integers in a linked list than an array, and why (vectorized operations?)  CS students should know cache behaviour, SIMD-friendliness, branch prediction, multi-threaded programming, real-time constraints, hardware acceleration, etc. [SIMD processor operations](https://safari.ethz.ch/digitaltechnik/spring2019/lib/exe/fetch.php?media=digitaldesign-2019-lecture20-simd-afterlecture.pdf) allow you to perform the same operation on many values in an array simultaneously. Summing a linked list would require the processor to perform one add operation per element, then one operation to traverse the pointer. A naive implementation of the array sum would require only one add operation per element with no pointer traversal, but a SIMD-capable processor could sum many elements at once, reducing the number of cycles required by the number of elements the vectorized processing unit can handle at once. Here's an excellent [blog post](https://kjellkod.wordpress.com/2012/02/25/why-you-should-never-ever-ever-use-linked-list-in-your-code-again/) on this

Read how to implement an LRU cache, and then actually write one that gets and sets in worst-case O(1) time. This is a weirdly common interview problem.

### Databases

Learn about SQL databases. Learn how to design a SQL database schema; it comes up in interviews often. Read about ACID, the CAP theorem, and BASE (you don’t need to memorize the terms, just understand the concepts at a high level.) Understand why joins can become unscalable. Learn the basics of [NoSQL databases](https://www.youtube.com/watch?v=qI_g07C_Q5I).

### Web Development

Learn [what happens](http://igoro.com/archive/what-really-happens-when-you-navigate-to-a-url/comment-page-3/) when you type a URL into your browser and press enter. Be comfortable talking about DNS lookups, the request-response cycle, HTTP verbs, TCP vs UDP, and how cookies work. Shows up all the time in interviews.

Learn the standard ways to speed up a slow website. This includes a lot of things like adding database indices to optimize common queries, better caching, loading front-end assets from a CDN, cleaning up zombie listeners, etc. Also an interview classic, pretty rabbit-holey.