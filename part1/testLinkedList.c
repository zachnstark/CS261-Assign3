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
   struct DLink temp = malloc(sizeof(struct DLink));
   temp = lst->firstLink;
   printf("testing isEmptyList...");
   assertTrue(isEmptyList(lst), 1, "Make sure list is empty");

   printf("testing addBackList...");
   for(int i = 0; i < 4; i++){
      addBackList(lst, i);
      assertTrue(temp->value, i, "Make sure list got values");
      temp = temp->next;
   }

   printf("testing isEmptyList...")
   assertTrue(isEmptyList(lst), 0, "Make sure list isn't empty");

   temp = lst->lastLink;

   printf("testing removeBackList...");
   for(int i = 0; i < 4; i++){
      assertTrue(temp->value, 3 - i, "Make sure it removes from back");
      temp = temp->prev;
      removeBackList(lst);
   }

   printf("testing addFrontList...");
   for(int i = 0; i < 5; i++){
      addFrontList(lst, i);

   return 0;
}


