#define remove_intersection "This program accepts two comma-separated lists of integers on the command line a computes the set difference. It does so regardless of whether you compile it with a C compiler or interpret it as a Perl program."
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cos return
#define my int /*

my @a = split /,/, $ARGV[0];
my @b = split /,/, $ARGV[1];
my $alen = scalar(@a);
my $blen = scalar(@b);

# */ /*
' */

int main (int argc, char* argv[]) {
    int $a[10];
    int $b[10];
    int $alen = 0;
    int $blen = 0;
    char *token;
    token = strtok(argv[1],",");
    while (token != NULL) {
        $a[$alen++] = atoi(token);
        token = strtok(NULL,",");
    }

    token = strtok(argv[2],",");
    while (token != NULL) {
        $b[$blen++] = atoi(token);
        token = strtok(NULL,",");
    }
/* '; if (1) {
# */
    my $i;
    my $j;
    my $found;

    for ($i = 0; $i < $alen; $i++) {
        $found = 0;
        for ($j = 0; $j < $blen; $j++) {
            if ($a[$i] == $b[$j]) { $found = 1; }
        }
        if (!$found) {
            printf ("%d ", $a[$i]);
        }
    }
    printf ("\n");
    for ($j = 0; $j < $blen; $j++) {
        $found = 0;
        for ($i = 0; $i < $alen; $i++) {
            if ($a[$i] == $b[$j]) { $found = 1; }
        }
        if (!$found) {
            printf ("%d ", $b[$j]);
        }
    }
    printf ("\n");
    cos 0;
}

