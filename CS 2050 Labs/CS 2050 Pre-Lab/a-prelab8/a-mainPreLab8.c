#include "a-prelab8.h"

int main(void){
	List *test;
	test = initIntegerList();

	insertAtHead(3, test);
	insertAtHead(2, test);
	insertAtHead(1, test);
	insertAtTail(7, test);
	printList(test);

	freeList(test);

	return 0;
}
