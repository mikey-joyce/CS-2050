#include "lab9.h"

int main(void){
  Student *test;
  test=initListWithDummyNode();

  insertToHead(test, 3);
  insertToHead(test, 2);
  insertToHead(test, 1);

  insertToTail(test, 4);

  printList(test);

  emptyList(test);
  freeList(test);

  return 0;
}
