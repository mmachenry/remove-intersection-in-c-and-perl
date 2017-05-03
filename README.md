# remove-intersection-in-c-and-perl
A program to compute set difference of two sets of integers written simultaneously in C and Perl.

This program accepts two sets of integers as comma separated lists. It will
compute the set difference for both. The first set without the elements from
the second set is printed on the first line of the output. The second minus the
first is printed on the next line.

#To run this as a C program

    $ gcc -o remove-intersection remove-intersection.pl.c
    $ ./remove-intersection 1,2,3 3,4,5
    1 2 
    4 5 

#To run this as a Perl program

    perl remove-intersection.pl.c 1,2,3 3,4,5
    1 2 
    4 5 
