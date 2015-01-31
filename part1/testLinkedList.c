/*
 * Kyle Nichols, Zach Stark	January 25, 2015
 * Assignment 3
 * VIM/Notepad++
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
   
   // Create the list
   struct linkedList * lst = createLinkedList();

   // Testing the the isEmpty check
   printf("testing isEmptyList...\n"); 
   assertTrue(isEmptyList(lst), 1, "Make sure list is empty");

   // Testing adding to the back
   printf("testing addBackList...\n");
   for(int i = 0; i < 4; i++){
      addBackList(lst, i);
      assertTrue(backList(lst), i, "Make sure adding to the back");
   }

   // Testing the empty check when not empty
   printf("testing isEmptyList...\n");
   assertTrue(isEmptyList(lst), 0, "Make sure list isn't empty");

   // Testing removing from the back
   printf("testing removeBackList...\n");
   for(int j = 0; j < 4; j++){
      assertTrue(backList(lst), 3 - j, "Make sure it removes from back");
      removeBackList(lst);
   }

   // Testing adding to the front
   printf("testing addFrontList...\n");
   for(int k = 0; k < 5; k++){
      addFrontList(lst, k);
      assertTrue(frontList(lst), k, "Make sure adding to the Front");
   }

   /*printf("testing frontList...");
   assertTrue(lst->firstLink->value, frontList(lst), "frontList returns correct value");

   printf("testing backList...");
   assertTrue(lst->lastLink->value, backList(lst), "Backlist returns correct value");*/

   // Testing removing from the front
   printf("testing removeFrontList...\n");
   for(int l = 0; l < 5; l++){
      assertTrue(frontList(lst), 4 - l, "Make sure it removes from front");
      removeFrontList(lst);
   }
   return 0;
}


