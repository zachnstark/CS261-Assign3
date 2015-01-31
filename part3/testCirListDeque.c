/*
 * Kyle Nichols, Zach Stark	January 25, 2015
 * Assignment 3
 * VIM/Notepad++
 */

#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message)
{
	printf("%s ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

int main(int argc, char* argv[])
{
	printf("Creating list...\n");
	struct cirListDeque *list = createCirListDeque();
	
	// Adding to the front of the list
	printf("\nTesting addFrontCirListDeque()...\n");
	addFrontCirListDeque(list, 5.0);
	assertTrue(EQ(frontCirListDeque(list), 5.0), "Front is 5.0 = ");
	addFrontCirListDeque(list, 27.8);
	assertTrue(EQ(frontCirListDeque(list), 27.8), "Front is 27.8 = ");
	addFrontCirListDeque(list, 10.0);
	assertTrue(EQ(frontCirListDeque(list), 10.0), "Front is 10.0 = ");
	
	// Adding to the back of the list
	printf("\nTesting addBackCirListDeque()...\n");
	addBackCirListDeque(list, 42.0);
	assertTrue(EQ(backCirListDeque(list), 42.0), "Back is 42.0 = ");
	addBackCirListDeque(list, 0.0);
	assertTrue(EQ(backCirListDeque(list), 0.0), "Back is 0.0 = ");
	addBackCirListDeque(list, -48.1);
	assertTrue(EQ(backCirListDeque(list), -48.1), "Back is -48.1 = ");
	
	// Testing both adds
	printf("\nTesting both adds...\n");
	printf("Deque = {10.0, 27.8, 5.0, 42.0, 0.0, -48.1\n");
	printCirListDeque(list);
	
	// Testing the reverse process
	printf("\nTesting reverseCirListDeque()...\n");
	printf("Reverse of the deque = { -48.1, 0.0, 42.0, 5.0, 27.8, 10.0}\n");
	reverseCirListDeque(list);
	printCirListDeque(list);
	
	// Testing removing from the front
	printf("\nTesting removeFrontCirListDeque()...\n");
	removeFrontCirListDeque(list);
	assertTrue(!EQ(frontCirListDeque(list), -48.1), "Front is not -48.1 = ");
	
	// Testing removing from the back
	printf("\nTesting removeBackCirListDeque()...\n");
	removeBackCirListDeque(list);
	assertTrue(!EQ(backCirListDeque(list), 10.0), "Back is not 10.0 = ");

	// Testing freeing and the empty check
	printf("\nTesting freeCirListDeque()...\n");
	assertTrue(EQ(isEmptyCirListDeque(list), 0), "List is not empty = ");
	printf("Freeing deque...\n");
	freeCirListDeque(list);
	printf("%d\n", isEmptyCirListDeque(list));
	assertTrue(EQ(isEmptyCirListDeque(list), 1), "List is empty = ");
	
	// Removing from empty list
	printf("\nAttempting to remove from empty list (front and back)... Error message should occur twice...\n");
	removeFrontCirListDeque(list);
	removeBackCirListDeque(list);
	
	return 0;
}


