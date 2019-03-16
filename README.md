# Iterators 

Iterators are a generalisation of pointers: they are objects that point to other objects. As the name suggests, iterators are often used to iterate over a range of objects: if an iterator points to one element in a range, then it is possible to increment it so that it points to the next element.

We implemented an Iterator for vector class. To accomplish that we need to do the following:

- Write begin and end functions which returns an iterators pointing at begining and end of vector resp.

- Similarly we implemented rbegin and rend which returns an iterators pointing at end and beginning of vector resp.
- We defined a iterator class inside vector class.
- We overloaded '!=', '++', * operator which is used on iterator.

This much is sufficient to write a simple iterator.
