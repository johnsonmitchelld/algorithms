# Interview Prep Curriculum

Compiled from Haseeb Qureshi's [Tech Interview Study Guide](https://haseebq.com/how-to-break-into-tech-job-hunting-and-interviews/) and Steve Yegge's [Get That Job at Google](http://steve-yegge.blogspot.com/2008/03/get-that-job-at-google.html).

## Data Structures

Work through the Princeton algorithms course. You should follow along and implement as much as you can. Along the way, also implement all these major data structures. (Many of these are not explicitly covered in the course—implement them on your own). Know all of the time complexities for their basic operations. It helps to visually intuit them. Look at images. Draw them out on paper/whiteboard.

- Linked List
- [Dynamic array](https://en.wikipedia.org/wiki/Dynamic_array), implemented with a [ring buffer](https://en.wikipedia.org/wiki/Circular_buffer) (use a statically sized array underneath the hood). Be able to implement one in an interview using only arrays in your favorite language.
- Hash set
- [Hash map](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining_with_linked_lists) (with chaining)
- Binary heap (without decrease-key; know that [Fibonacci heaps](https://en.wikipedia.org/wiki/Fibonacci_heap) exist and know their guarantees)
- Binary search tree (doesn’t need to be self-balancing; know that [self-balancing trees](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree#Implementations) exist and know their guarantees)
- Be familiar with at least one flavor of balanced binary tree, whether it's a red/black tree, a splay tree or an AVL tree. You should actually know how it's implemented.
- Prefix tree (a.k.a. trie)
- Suffix tree (don’t worry about compression, just build a dumb version; know that [Ukkonen’s algorithm](https://en.wikipedia.org/wiki/Ukkonen%27s_algorithm) exists and learn its guarantees)
- An object-oriented [adjacency list](https://en.wikipedia.org/wiki/Adjacency_list) for graphs

## Algorithms

Implement this subset of the most common algorithms. Know the time complexities and space complexities of all of these algorithms ([cheat-sheet](http://bigocheatsheet.com/)). Know the difference between [amortized, average](https://stackoverflow.com/a/7335098), and worst-case time guarantees.

- Binary search (implement it both iteratively and recursively)
- Randomized quicksort (pay extra attention to the partition subroutine, as it’s useful in a lot of places)
- Merge sort can be highly useful in situations where quicksort is impractical, so take a look at it.
- Breadth-first search in a graph
- Depth-first search in a graph (augment it to detect cycles)
- Know basic tree construction, traversal and manipulation algorithms. You should be familiar with binary trees, n-ary trees, and trie-trees at the very very least. Trees are probably the best source of practice problems for your long-term warmup exercises.
- know about tree traversal algorithms: BFS and DFS, and know the difference between inorder, postorder and preorder.
- Topological sort (using [Tarjan’s algorithm](https://en.wikipedia.org/wiki/Topological_sorting#Depth-first_search))
- Dijkstra’s algorithm ([without decrease-key](https://stackoverflow.com/questions/9255620/why-does-dijkstras-algorithm-use-decrease-key))
- Longest common subsequence (using dynamic programming with matrices)
- Knapsack problem (also dynamic programming)
- Do at least one or two problems where you BFS or DFS through a matrix.

Once you finish these you should have a decent grounding in algorithms and data structures. Read through the entirety of Algorithm Design Manual to solidify your understanding. Implement anything that you find sufficiently interesting.

A few points of interest: 
- learn about heap sort, but don’t bother coding it. Know that it’s O(1) space but practically very slow due to cache inefficiency.
- Learn about quickselect and median-of-medians. Code them if you want.
- recursive backtracking
- Don't try sorting a linked list during the interview

## Graphs

Graphs are, like, really really important. There are three basic ways to represent a graph in memory (objects and pointers, matrix, and adjacency list), and you should familiarize yourself with each representation and its pros and cons. Know the basic graph traversal algorithms: breadth-first search and depth-first search. You should know their computational complexity, their tradeoffs, and how to implement them in real code. Try to study up on fancier algorithms, such as Dijkstra and A*, if you get a chance.

Whenever someone gives you a problem, think graphs. They are the most fundamental and flexible way of representing any kind of a relationship, so it's about a 50-50 shot that any interesting design problem has a graph involved in it. Make absolutely sure you can't think of a way to solve it using graphs before moving on to other solution types. This tip is important!

## Other data structures

Study up on as many other data structures and algorithms as you can. Find out what NP-complete means. You should especially know about the most famous classes of NP-complete problems, such as traveling salesman and the knapsack problem, and be able to recognize them when an interviewer asks you them in disguise.

## Math

Spend some time before the interview refreshing your memory on (or teaching yourself) the essentials of combinatorics and probability. You should be familiar with n-choose-k problems and their ilk – the more the better.

## Coding

You should know at least one programming language really well, and it should preferably be C++ or Java. C# is OK too, since it's pretty similar to Java. You will be expected to write some code in at least some of your interviews. You will be expected to know a fair amount of detail about your favorite programming language.

## Computer Architecture

Learn the basics of bit manipulation. Be able to explain what AND, OR, and XOR do. Know what a signed integer is. Know that there are 8 bits in a byte. Know what assembly is (from a high level), and get a sense of the basic operations that hardware exposes. This [awesome video](https://www.youtube.com/watch?v=RZUDEaLa5Nw) about the inner workings of the original Game Boy covers just about all you need to know.

Read about caches and cache efficiency. Know what a cache miss is. Know that reading from registers is lightning-fast, reading from the various caches is pretty fast, reading from memory is slow, and that reading from the hard disk is abysmally slow.

From [Hacker News](https://news.ycombinator.com/item?id=22708094): Learn how much slower it is to sum integers in a linked list than an array, and why. [SIMD processor operations](https://safari.ethz.ch/digitaltechnik/spring2019/lib/exe/fetch.php?media=digitaldesign-2019-lecture20-simd-afterlecture.pdf) allow you to perform the same operation on many values in an array simultaneously. Summing a linked list would require the processor to perform one add operation per element, then one operation to traverse the pointer. A naive implementation of the array sum would require only one add operation per element with no pointer traversal, but a SIMD-capable processor could sum many elements at once, reducing the number of cycles required by the number of elements the vectorized processing unit can handle at once. Here's an excellent [blog post](https://kjellkod.wordpress.com/2012/02/25/why-you-should-never-ever-ever-use-linked-list-in-your-code-again/) on this.

CS students should know cache behaviour, SIMD-friendliness, branch prediction, multi-threaded programming, real-time constraints, hardware acceleration, etc.

Read how to implement an LRU cache, and then actually write one that gets and sets in worst-case O(1) time. This is a weirdly common interview problem.

## Operating Systems

Know about processes, threads and concurrency issues. Know about locks and mutexes and semaphores and monitors and how they work. Know about deadlock and livelock and how to avoid them. Know what resources a processes needs, and a thread needs, and how context switching works, and how it's initiated by the operating system and underlying hardware. Know a little about scheduling.

## Databases

Learn about SQL databases. Learn how to design a SQL database schema; it comes up in interviews often. Read about ACID, the CAP theorem, and BASE (you don’t need to memorize the terms, just understand the concepts at a high level.) Understand why joins can become unscalable. Learn the basics of [NoSQL databases](https://www.youtube.com/watch?v=qI_g07C_Q5I).

## Web Development

Learn [what happens](http://igoro.com/archive/what-really-happens-when-you-navigate-to-a-url/comment-page-3/) when you type a URL into your browser and press enter. Be comfortable talking about DNS lookups, the request-response cycle, HTTP verbs, TCP vs UDP, and how cookies work. Shows up all the time in interviews.

Learn the standard ways to speed up a slow website. This includes a lot of things like adding database indices to optimize common queries, better caching, loading front-end assets from a CDN, cleaning up zombie listeners, etc.