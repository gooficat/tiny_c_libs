A series of single-header-single-source C libraries containing various utilities such as data structures, designed for easy use.

hash: a hashmap library using FNV-1a hashing with safety checks for collisions. Uses void* generics for value

vector: a dynamic array library that uses a back-header to hold size and capacity, and macro tricks for element size.
This neatly hides the implementation and allows the user to treat the vector like a normal heap array when indexing.

pstr: pascal strings for c

arena: a bump arena allocator that is capable of storing itself within its own buffer, allowing it to be easily passed as a free-standing pointer
