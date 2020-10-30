# Custom Memory Manager

*CS 3353 - Spring 2020 - Project 01*

My project cpontains 4 artificial test as well as test for the sentimental analysis from lasat semester.
The command line should contain three different statements:
first is the type of fitting:
 - '-f' for first fit
 - '-b' for best fit
 - '-m' for my fit which it will add the object right where the next pointer is. when it will get to the end of the chunk of the memory it will go back and will use the first fit algorithm.
 
Second is the kind of test:
 - 't1' test array of int pointers which will make random length of int arrays and delete every other array
 - 't2' which will make an ptr array for an object which contain many differnent variables
 - 't3' will make ptr array of longs as well as doubles. it will delete once in a while.
 - 't4' it will run t1 then run t2
 - 'sa' for running the santimental analysis with a small data set.
 
Third is the data size:
 - 'small' for smaller data size. About 40,000 different arrays for t1
 - 'med' for medium data sizes. About 70,000 arrays for t1
 - 'large' for about 100K arrays in t1
 
 
My Allocator contains a Bookkeeping 2D array, freeList 2D array, and a freeAddresses map.
- the bookkeeping contains 100,000 in the first dimention and 671 in the second. it is order by the address.  
