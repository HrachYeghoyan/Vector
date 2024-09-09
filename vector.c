#include <stdio.h>
#include "vector.h"

int main()
{
	vector ob;
	ctor(&ob);
    
	for (int i = 0; i < 5; ++i) {
    	push_back(&ob, i + 1);
	}
    
	pop_back(&ob);
    
	printf("The size of array is %zu.\n", size(&ob));
	printf("The capacity of array is %zu.\n", capacity(&ob));
    
	for (int i = 5; i < 10; ++i) {
    	push_back(&ob, i);
	}
    
	insert(&ob, 4, 5);
    
	print(&ob);
    
	dtor(&ob);

	return 0;
}

