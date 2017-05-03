remove-intersection in C and Perl
----
A program to compute set difference of two sets of integers written simultaneously in C and Perl.

This program accepts two sets of integers as comma separated lists. It will
compute the set difference in both directions. The first set without the
elements from the second set is printed on the first line of the output. The
second minus the first is printed on the next line.

To run this as a C program
----

    $ gcc -o remove-intersection remove-intersection.pl.c
    $ ./remove-intersection 1,2,3 3,4,5
    1 2 
    4 5 

To run this as a Perl program
----

    $ perl remove-intersection.pl.c 1,2,3 3,4,5
    1 2 
    4 5 

How it works
----

Through some commenting tricks, some of the code is interpreted only as Perl
and some only as C. The bulk of the actual computation is done in a block of
code that is being interpreted as both. Here is a breakdown of how each of the
lines works.

Line 1 is a comment in Perl due to the # symbol as well as an unused useless
define of a string in C. I use this for the header comment for both languages.

Lines 2-4 are includes needed in C and they are automatically ignored in Perl
since they begin with a # symbol.

Line 5: I need to have the main function in C end with a return statement but
a return statement in Perl is going to be invalid when not in the scope of a
function. I solve this by defining cos to be return in C. That when when I say
cos 0 it returns 0 from the main function in C. But this rewrite doesn't happen
in Perl since it's a #define and thus at the end of the Perl program I simply
compute the cosine of zero in a null context and it's thrown away. (see line 59)

Line 6: I define my to be int in C, which line the previous line is just
ignored by Perl. This allows me to define integers in both Perl and C with the
shared syntax of "my $i;" which turns into "int $i;" in C. (see lines 35-37)
This line also begins a C block comment at the end of it, which ignores the
Perl-only block to come. The C comment is ignored in Perl, obviously because
this hole line is ignored by Perl.

Lines 8-11: These lines are interpreted only by Perl and are used to setup the
command line input. I read in both the array of integers for both inputs as
well as computes the lens of both for later use.

Line 12: In order to ignore the C-only block of code to come, I use a single
quote to turn it all into a Perl string which will evaluate in a null context
and have no effect.

Line 14: I end the Perl-only block of code by closing the C block comment which
was opened on line 6. The line begins with a # so that Perl doesn't interpret
the closing block comment symbol as anything.

Lines 16-32: This is a C-only block of code and turns into a string in Perl.
It does the reading of command line inputs in a way that C needs them to be
read. It is the C counter part to the above Perl-only block for reading inputs.
It begins a main function, uses the strtok function to split the
comma-separated values up, and atoi to convert the strings to integers. Pretty
standard stuff. Some things to note, I use $ sigils for variables that are
going to be used later in the Perl/C code that computes set difference. They
are required in Perl and though not very common in C, they are a totally legal
character for a variable name.

Line 33: Here we need to transition for a C-only block of code into code that
works in both Perl and C for the rest of the program. First, we must comment
out these lines in C so they don't do anything. We end the single-quoted Perl
string we started on line 12 and add a semi colon to finish the useless
statement. Then we create a needless Perl if statement that executes always.
The purpose of this is to create a curly brace context to match the closing
brace that occurs on line 60. This is needed to match the open curly brace on
16, which starts the C main function, which is not interpreted by Perl.

Line 34: Finally on line 34 we close out this little C comment in a way that
Perl will ignore by preceding it with a # symbol.

Lines 35-60: This block of code is the heart of the computation and should
be more or less readable to you if you know either C or Perl. Notice printf
is a function in both Perl and C and has the same syntax in both, luckily
enough. For loops and if block similarly have a common subset of valid syntax.
Notice on line 59, we make use of the cosine return and on 60 we close out
the curly brace that is started in two different places.
