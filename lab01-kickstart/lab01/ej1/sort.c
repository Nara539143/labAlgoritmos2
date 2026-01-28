#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
proc insert (in/out a:array[1..n] of T, in i: nat)
	var j:nat
	j:=i
	do j>1 ∧ a[j]<a[j-1] → 
		swap(a,j-1,j)
		j:=j-1
	od
end proc
*/

static void insert(int a[], unsigned int i, unsigned int length) {
    unsigned int j=i;
    while((j>0) && (a[j]<a[j-1])){
        swap(a,j-1,j);
        --j;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
}
