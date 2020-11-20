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
- recursive backtracking

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

## Steve Yegge's [Get That Job at Google](http://steve-yegge.blogspot.com/2008/03/get-that-job-at-google.html)

**Algorithm Complexity:** you need to know Big-O. It's a must. If you struggle with basic big-O complexity analysis, then you are almost guaranteed not to get hired. It's, like, one chapter in the beginning of one theory of computation book, so just go read it. You can do it.

**Sorting:** know how to sort. Don't do bubble-sort. You should know the details of at least one n*log(n) sorting algorithm, preferably two (say, quicksort and merge sort). Merge sort can be highly useful in situations where quicksort is impractical, so take a look at it.

For God's sake, don't try sorting a linked list during the interview.

**Hashtables:** hashtables are arguably the single most important data structure known to mankind. You absolutely have to know how they work. Again, it's like one chapter in one data structures book, so just go read about them. You should be able to implement one using only arrays in your favorite language, in about the space of one interview.

**Trees:** you should know about trees. I'm tellin' ya: this is basic stuff, and it's embarrassing to bring it up, but some of you out there don't know basic tree construction, traversal and manipulation algorithms. You should be familiar with binary trees, n-ary trees, and trie-trees at the very very least. Trees are probably the best source of practice problems for your long-term warmup exercises.

You should be familiar with at least one flavor of balanced binary tree, whether it's a red/black tree, a splay tree or an AVL tree. You should actually know how it's implemented.

You should know about tree traversal algorithms: BFS and DFS, and know the difference between inorder, postorder and preorder.

You might not use trees much day-to-day, but if so, it's because you're avoiding tree problems. You won't need to do that anymore once you know how they work. Study up!

### Graphs

Graphs are, like, really really important. More than you think. Even if you already think they're important, it's probably more than you think.

There are three basic ways to represent a graph in memory (objects and pointers, matrix, and adjacency list), and you should familiarize yourself with each representation and its pros and cons.

You should know the basic graph traversal algorithms: breadth-first search and depth-first search. You should know their computational complexity, their tradeoffs, and how to implement them in real code.

You should try to study up on fancier algorithms, such as Dijkstra and A*, if you get a chance. They're really great for just about anything, from game programming to distributed computing to you name it. You should know them.

Whenever someone gives you a problem, think graphs. They are the most fundamental and flexible way of representing any kind of a relationship, so it's about a 50-50 shot that any interesting design problem has a graph involved in it. Make absolutely sure you can't think of a way to solve it using graphs before moving on to other solution types. This tip is important!

### Other data structures

You should study up on as many other data structures and algorithms as you can fit in that big noggin of yours. You should especially know about the most famous classes of NP-complete problems, such as traveling salesman and the knapsack problem, and be able to recognize them when an interviewer asks you them in disguise.

You should find out what NP-complete means.

Basically, hit that data structures book hard, and try to retain as much of it as you can, and you can't go wrong.

### Math

Some interviewers ask basic discrete math questions. This is more prevalent at Google than at other places I've been, and I consider it a Good Thing, even though I'm not particularly good at discrete math. We're surrounded by counting problems, probability problems, and other Discrete Math 101 situations, and those innumerate among us blithely hack around them without knowing what we're doing.

Don't get mad if the interviewer asks math questions. Do your best. Your best will be a heck of a lot better if you spend some time before the interview refreshing your memory on (or teaching yourself) the essentials of combinatorics and probability. You should be familiar with n-choose-k problems and their ilk – the more the better.

I know, I know, you're short on time. But this tip can really help make the difference between a "we're not sure" and a "let's hire her". And it's actually not all that bad – discrete math doesn't use much of the high-school math you studied and forgot. It starts back with elementary-school math and builds up from there, so you can probably pick up what you need for interviews in a couple of days of intense study.

Sadly, I don't have a good recommendation for a Discrete Math book, so if you do, please mention it in the comments. Thanks.

### Operating Systems

This is just a plug, from me, for you to know about processes, threads and concurrency issues. A lot of interviewers ask about that stuff, and it's pretty fundamental, so you should know it. Know about locks and mutexes and semaphores and monitors and how they work. Know about deadlock and livelock and how to avoid them. Know what resources a processes needs, and a thread needs, and how context switching works, and how it's initiated by the operating system and underlying hardware. Know a little about scheduling. The world is rapidly moving towards multi-core, and you'll be a dinosaur in a real hurry if you don't understand the fundamentals of "modern" (which is to say, "kinda broken") concurrency constructs.

The best, most practical book I've ever personally read on the subject is Doug Lea's Concurrent Programming in Java. It got me the most bang per page. There are obviously lots of other books on concurrency. I'd avoid the academic ones and focus on the practical stuff, since it's most likely to get asked in interviews.

### Coding

You should know at least one programming language really well, and it should preferably be C++ or Java. C# is OK too, since it's pretty similar to Java. You will be expected to write some code in at least some of your interviews. You will be expected to know a fair amount of detail about your favorite programming language.