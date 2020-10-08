#include "lab8.h"

int main(void){
	Student *test=initList();
	int searchTest=0;

	test=addToHead(test,3);
	test=addToHead(test,2);
	test=addToHead(test,1);

	test=addToTail(test,4);
	test=addToTail(test,5);

	printList(test);

	searchTest=searchAge(test, 4);
	printf("%d\n", searchTest);
	
	test=freeList(test);
}
