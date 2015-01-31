/*
 * Zachary Stark Kyle Nichols 1/30/2015
 * Assignment 3 testing linked list deque
 * VIM
 */

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int a, int b, char* message){
   printf("%s: ", message);
   if(a == b)
      printf("PASSED\n");
   else
      printf("FAILED\n");
}
int main(int argc, char* argv[]) {
   /* Test your linked list in here! */
   struct linkedList * lst = createLinkedList();   
   printf("testing isEmptyList...\n"); 
   assertTrue(isEmptyList(lst), 1, "Make sure list is empty");

   printf("testing addBackList...\n");
   for(int i = 0; i < 4; i++){
      addBackList(lst, i);
      assertTrue(backList(lst), i, "Make sure adding to the back");
   }

   printf("testing isEmptyList...\n");
   assertTrue(isEmptyList(lst), 0, "Make sure list isn't empty");

   printf("testing removeBackList...\n");
   for(int j = 0; j < 4; j++){
      assertTrue(backList(lst), 3 - j, "Make sure it removes from back");
      removeBackList(lst);
   }

   printf("testing addFrontList...\n");
   for(int k = 0; k < 5; k++){
      addFrontList(lst, k);
      assertTrue(frontList(lst), k, "Make sure adding to the Front");
   }

   printf("testing printList...\n");
   printList(lst);
   printf("\n");
   printf("should print out 43210\n");

   printf("testing removeFrontList...\n");
   for(int l = 0; l < 5; l++){
      assertTrue(frontList(lst), 4 - l, "Make sure it removes from front");
      removeFrontList(lst);
   }

   printf("testing addList and containsList...\n");
   for(int m = 0; m < 3; m++){
      addList(lst, m);
      assertTrue(frontList(lst), m, "Make sure adding to the Front");
      assertTrue(containsList(lst, m), 1, "Make sure contains works");
   }
   
   printf("testing the removeList...\n");
   for(int u = 0; u < 3; u++){
      assertTrue(frontList(lst), 2 - u, "make sure it removes");
      removeList(lst, 2 - u);
   }
   return 0;
}


