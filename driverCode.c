#include "List.h"

void initDemo() {
	printf("\n\t\t =============== START DEMO - init() =============== \n\n\n");
	
	printf("Initialising List a with initialise() \n\n");
	List *a = init();
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 5, 9 \n\n");
	append(a, 5);
	append(a, 9);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - init() =============== \n\n\n");
}

/*void initialiseWithCapacityDemo() {
	printf("\n\t\t =============== START DEMO - initialiseWithCapacity() =============== \n\n\n");
	
	printf("Initialising List a with initialiseWithCapacity(0) \n\n");
	List *a = initialiseWithCapacity(0);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 5, 4, 15, 9, 19 \n\n");
	append(a, 5);
	append(a, 4);
	append(a, 15);
	append(a, 9);
	append(a, 19);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - initialiseWithCapacity() =============== \n\n\n");
}

void initialiseWithArrayDemo() {
	printf("\n\t\t =============== START DEMO - initialiseWithArray() =============== \n\n\n");
	
	printf("Initialising int arr[] with numbers from 1 to 18 \n\n");
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
	
	printf("Initialising List a with arr[] using initialiseWithArray(arr, 18) \n\n");
	List *a = initialiseWithArray(arr, 18);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - initialiseWithArray() =============== \n\n\n");
}*/

void fromValuesDemo() {
	printf("\n\t\t =============== START DEMO - fromValues() =============== \n\n\n");
	
	printf("Initialising List a with values(5, 1, 2, 5, 9, 17) \n\n");
	List *a = values(5, 1, 2, 5, 9, 17);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - fromValues() =============== \n\n\n");
}

void rangeDemo() {
	printf("\n\t\t =============== START DEMO - range() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising List b with range(10, -1, -2) \n\n");
	List *b = range(10, -1, -2);
	
	printf("\t b = %s \n", toString(b));
	printf("\t Number of elements = %d \n", length(b));
	printf("\t Capacity of a = %d \n\n", cap(b));
	
	printf("toString( range(5, 51, 5) ) = %s \n", toString( range(5, 51, 5) ));
	
	printf("\n\n\t\t =============== END DEMO - range() =============== \n\n\n");
}

void sliceDemo() {
	printf("\n\t\t =============== START DEMO - slice() =============== \n\n\n");
	
	printf("Initialising List a with range(10, 21, 1) \n\n");
	List *a = range(10, 21, 1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	
	printf("toString( slice(a, 2, 6, 1) ) = %s \n\n", toString( slice(a, 2, 6, 1) ));
	printf("toString( slice(a, 10, -1, -2) ) = %s \n\n", toString( slice(a, 10, -1, -2) ));
	
	printf("\n\n\t\t =============== END DEMO - slice() =============== \n\n\n");
}

void copyDemo() {
	printf("\n\t\t =============== START DEMO - copy() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 10, 2) \n\n");
	List *a = range(0, 10, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising List b with copy(a) \n\n");
	List *b = copy(a);
	
	printf("\t b = %s \n", toString(b));
	printf("\t Number of elements = %d \n", length(b));
	printf("\t Capacity of b = %d \n", cap(b));
	
	printf("\n\n\t\t =============== END DEMO - copy() =============== \n\n\n");
}

void clearDemo() {
	printf("\n\t\t =============== START DEMO - clear() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 1) \n\n");
	List *a = range(0, 11, 1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Removing all elements from List a using clear(a) \n\n");
	clear(a);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 5 \n\n");
	append(a, 5);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - clear() =============== \n\n\n");
}

/*void ensureCapacityDemo() {
	printf("\n\t\t =============== START DEMO - ensureCapacity() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Ensuring a minimum capacity of 2 using ensureCapacity(a, 2) \n\n");
	ensureCapacity(a, 2);
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Ensuring a minimum capacity of 6 using ensureCapacity(a, 6) \n\n");
	ensureCapacity(a, 6);
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Ensuring a minimum capacity of 7 using ensureCapacity(a, 7) \n\n");
	ensureCapacity(a, 7);
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Ensuring a minimum capacity of 20 using ensureCapacity(a, 20) \n\n");
	ensureCapacity(a, 20);
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - ensureCapacity() =============== \n\n\n");
}*/

void trimToSizeDemo() {
	printf("\n\t\t =============== START DEMO - trimToSize() =============== \n\n\n");
	
	printf("Initialising List a with initialise() \n\n");
	List *a = initialise();
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising int arr[] with numbers from 1 to 6 \n\n");
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	printf("Extending List a with arr[] using extendWithArray(a, arr, 6) \n\n");
	extendWithArray(a, arr, 6);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Trimming Unused Space in List a using trimToSize(a) \n\n");
	trimToSize(a);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - trimToSize() =============== \n\n\n");
}

void fillDemo() {
	printf("\n\t\t =============== START DEMO - fill() =============== \n\n\n");
	
	printf("Initialising List a with initialise() \n\n");
	List *a = initialise();
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Filling List a with 10 occurences of 5 using fill(a, 5, 10) \n\n");
	fill(a, 5, 10);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Filling List a with 7 occurences of 19 using fill(a, 19, 7) \n\n");
	fill(a, 19, 7);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - fill() =============== \n\n\n");
}

void appendDemo() {
	printf("\n\t\t =============== START DEMO - append() =============== \n\n\n");
	
	printf("Initialising List a with initialiseWithCapacity(0) \n\n");
	List *a = initialiseWithCapacity(0);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 5, 4, 15, 9, 19 using append(a, n) \n\n");
	append(a, 5);
	append(a, 4);
	append(a, 15);
	append(a, 9);
	append(a, 19);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - append() =============== \n\n\n");
}

/*void extendWithArrayDemo() {
	printf("\n\t\t =============== START DEMO - extendWithArray() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising int arr[] with numbers from 1 to 6 \n\n");
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	printf("Extending List a with arr[] using extendWithArray(a, arr, 6) \n\n");
	extendWithArray(a, arr, 6);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - extendWithArray() =============== \n\n\n");
}*/

void extendDemo() {
	printf("\n\t\t =============== START DEMO - extend() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising List b with range(1, 11, 2) \n\n");
	List *b = range(1, 11, 2);
	
	printf("\t b = %s \n", toString(b));
	printf("\t Number of elements = %d \n", length(b));
	printf("\t Capacity of b = %d \n\n", capacity(b));
	
	printf("Extending List a with List b using extend(a, b) \n\n");
	extend(a, b);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Extending List a using extend(a, range(90, 96, 2)) \n\n");
	extend(a, range(90, 96, 2));
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - extend() =============== \n\n\n");
}

void insertDemo() {
	printf("\n\t\t =============== START DEMO - insert() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 10, 1) \n\n");
	List *a = range(0, 10, 1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Inserting 99 at 0th index using insert(a, 0, 99) \n\n");
	insert(a, 0, 99);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Inserting 88 at the end using insert(a, length(a), 88) \n\n");
	insert(a, length(a), 88);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Inserting 55 at 5th index using insert(a, 5, 55) \n\n");
	insert(a, 5, 55);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Inserting 22 at the last index using insert(a, -1, 22) \n\n");
	insert(a, -1, 22);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - insert() =============== \n\n\n");
}

void findIndexDemo() {
	printf("\n\t\t =============== START DEMO - findIndex() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Searching for the first occurrence of numbers from 0 to 10 using indexOf(a, i) \n\n");
	for(int i = 0; i < 11; i++) {
		int index = findIndex(a, i);
		if(index < 0)
			printf("\t %d not found in a \n", i);
		else
			printf("\t %d found at index %d \n", i, index);
	}
	
	printf("\n\n\t\t =============== END DEMO - findIndex() =============== \n\n\n");
}

/*void lastIndexOfDemo() {
	printf("\n\t\t =============== START DEMO - lastIndexOf() =============== \n\n\n");
	
	printf("Initialising int arr[] with {0, 1, 2, 2, 3, 4, 5, 6, 2, 7, 8, 9} \n\n");
	int arr[] = {0, 1, 2, 2, 3, 4, 5, 6, 2, 7, 8, 9};
	
	printf("Initialising List a with arr[] using initialiseWithArray(arr, 12) \n\n");
	List *a = initialiseWithArray(arr, 12);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Searching for the last occurrence of 2, 10 using lastIndexOf(a, i) \n\n");
	printf("\t Last index of 2 = %d \n", lastIndexOf(a, 2));
	printf("\t Last index of 10 = %d \n", lastIndexOf(a, 10));
	
	printf("\n\n\t\t =============== END DEMO - lastIndexOf() =============== \n\n\n");
}
*/
void binarySearchDemo() {
	printf("\n\t\t =============== START DEMO - binarySearch() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Searching for the index of numbers from 0 to 10 using binarySearch(a, i) \n\n");
	for(int i = 0; i < 11; i++) {
		int index = binarySearch(a, i);
		if(index < 0)
			printf("\t %d not found in a \n", i);
		else
			printf("\t %d found at index %d \n", i, index);
	}
	
	printf("\n\n\t\t =============== END DEMO - binarySearch() =============== \n\n\n");
}

void searchDemo() {
	printf("\n\t\t =============== START DEMO - search() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Checking for the presence of numbers from 0 to 10 using contains(a, i) \n\n");
	for(int i = 0; i < 11; i++) {
		if(search(a, i))
			printf("\t a contains %d \n", i);
		else
			printf("\t a doesn't contain %d \n", i);
	}
	
	printf("\n\n\t\t =============== END DEMO - search() =============== \n\n\n");
}

/*void isEmptyDemo() {
	printf("\n\t\t =============== START DEMO - isEmpty() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 1) \n\n");
	List *a = range(0, 11, 1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Checking if a is empty using isEmpty(a) \n\n");
	if(isEmpty(a))
		printf("\t a is empty \n\n");
	else
		printf("\t a is not empty \n\n");
	
	printf("Removing all elements from List a using clear(a) \n\n");
	clear(a);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Checking if a is empty using isEmpty(a) \n\n");
	if(isEmpty(a))
		printf("\t a is empty \n");
	else
		printf("\t a is not empty \n");
	
	printf("\n\n\t\t =============== END DEMO - isEmpty() =============== \n\n\n");
}*/

void isEqualDemo() {
	printf("\n\t\t =============== START DEMO - isEqual() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 10, 2) \n\n");
	List *a = range(0, 10, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising List b with copy(a) \n\n");
	List *b = copy(a);
	
	printf("\t b = %s \n", toString(b));
	printf("\t Number of elements = %d \n", length(b));
	printf("\t Capacity of b = %d \n\n", cap(b));
	
	printf("Checking if List a is equal to List b using isEqual(a, b) \n\n");
	if(isEqual(a, b))
		printf("\t a is equal to b \n\n");
	else
		printf("\t a is not equal to b \n\n");
	
	printf("Appending 0 to List b using append(b, 0) \n\n");
	append(b, 0);
	
	printf("\t b = %s \n", toString(b));
	printf("\t Number of elements = %d \n", length(b));
	printf("\t Capacity of b = %d \n\n", cap(b));
	
	printf("Checking if List a is equal to List b using isEqual(a, b) \n\n");
	if(isEqual(a, b))
		printf("\t a is equal to b \n\n");
	else
		printf("\t a is not equal to b \n\n");
	
	printf("Appending 0 to List a using append(a, 0) \n\n");
	append(a, 0);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Checking if List a is equal to List b using isEqual(a, b) \n\n");
	if(isEqual(a, b))
		printf("\t a is equal to b \n");
	else
		printf("\t a is not equal to b \n");
	
	printf("\n\n\t\t =============== END DEMO - isEqual() =============== \n\n\n");
}

void popDemo() {
	printf("\n\t\t =============== START DEMO - pop() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 1) \n\n");
	List *a = range(0, 11, 1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Removing first element of a using pop(a, 0) \n\n");
	pop(a, 0);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Removing last element of a using pop(a, -1) \n\n");
	pop(a, -1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Trying to remove value at index 10 from a using pop(a, 10) \n\n");
	if(pop(a, 10))
		printf("\t a = %s \n\n", toString(a));
	else
		printf("\t index %d not found in a \n\n", 10);
	
	printf("Trying to remove value at index 2 from a using pop(a, 2) \n\n");
	if(pop(a, 2))
		printf("\t a = %s \n\n", toString(a));
	else
		printf("\t index %d not found in a \n\n", 10);
	
	printf("Removing value at 2nd last index using pop(a, -2) \n\n");
	pop(a, -2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - pop() =============== \n\n\n");
}

void removeElementDemo() {
	printf("\n\t\t =============== START DEMO - removeElement() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Trying to delete numbers from 0 to 10 using delete(a, i) \n\n");
	for(int i = 0; i < 11; i++) {
		if(removeElement(a, i))
			printf("\t %d deleted from a \n", i);
		else
			printf("\t a doesn't contain %d \n", i);
	}
	printf("\n");
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - removeElement() =============== \n\n\n");
}

void getDemo() {
	printf("\n\t\t =============== START DEMO - get() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Trying to print the values at indexes 0 to 10 using get(a, i) \n\n");
	for(int i = 0; i < 11; i++) {
		printf("\t Value at index %d = %d \n", i, get(a, i));
	}
	
	printf("\n\n\t\t =============== END DEMO - get() =============== \n\n\n");
}

void setDemo() {
	printf("\n\t\t =============== START DEMO - set() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Trying to double the value of all elements using set(a, i, get(a, i) * 2) \n\n");
	for(int i = 0; i < 11; i++) {
		if(set(a, i, get(a, i) * 2))
			printf("\t Doubling value at index %d successful \n", i);
		else
			printf("\t Index %d not found \n", i);
	}
	printf("\n");
	
	printf("a after doubling \n\n");
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - set() =============== \n\n\n");
}

void reverseDemo() {
	printf("\n\t\t =============== START DEMO - reverse() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 1) \n\n");
	List *a = range(0, 11, 1);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Reversing the order of elements using reverse(a) \n\n");
	reverse(a);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - reverse() =============== \n\n\n");
}

void replaceDemo() {
	printf("\n\t\t =============== START DEMO - replace() =============== \n\n\n");
	
	printf("Initialising int arr[] with {0, 1, 2, 3, 4, 5, 6, 1, 2, 2, 3, 4, 2, 6, 2} \n\n");
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 1, 2, 2, 3, 4, 2, 6, 2};
	
	printf("Initialising List a with arr[] using fromArray(arr, 15) \n\n");
	List *a = fromArray(arr, 15);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Replacing all occurrences of 2 with 99 using replace(a, 2, 99, count(a, 2)) \n\n");
	replace(a, 2, 99, count(a, 2));
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - replace() =============== \n\n\n");
}

void sortDemo() {
	printf("\n\t\t =============== START DEMO - sort() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Extending List a using extend(a, range(1, 11, 2)) \n\n");
	extend(a, range(1, 11, 2));
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Sorting the elements of a in increasing order using sort(a) \n\n");
	sort(a);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - sort() =============== \n\n\n");
}

/*void sortReverseDemo() {
	printf("\n\t\t =============== START DEMO - sortReverse() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Extending List a using extend(a, range(1, 11, 2)) \n\n");
	extend(a, range(1, 11, 2));
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Sorting the elements of a in increasing order using sortReverse(a) \n\n");
	sortReverse(a);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - sortReverse() =============== \n\n\n");
}
*/
void countDemo() {
	printf("\n\t\t =============== START DEMO - count() =============== \n\n\n");
	
	printf("Initialising int arr[] with {1, 2, 2, 3, 3, 3, 5, 5, 5, 5} \n\n");
	int arr[] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
	
	printf("Initialising List a with arr[] using fromArray(arr, 10) \n\n");
	List *a = fromArray(arr, 10);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Counting the frequency of numbers from 0 to 5 using count(a, i) \n\n");
	for(int i = 0; i <= 5; i++)
		printf("\t %d is present %d times \n", i, count(a, i));
	
	printf("\n\n\t\t =============== END DEMO - count() =============== \n\n\n");
}

void sumDemo() {
	printf("\n\t\t =============== START DEMO - sum() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Calculating sum of all elements of a using sum(a) \n\n");
	printf("\t Sum(a) = %d \n", sum(a));
		
	printf("\n\n\t\t =============== END DEMO - sum() =============== \n\n\n");
}

void lengthDemo() {
	printf("\n\t\t =============== START DEMO - length() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 5, 9 \n\n");
	append(a, 5);
	append(a, 9);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Finding new length of a using length(a) \n\n");
	printf("\t length(a) = %d \n", length(a));
	
	printf("\n\n\t\t =============== END DEMO - length() =============== \n\n\n");
}

void capacityDemo() {
	printf("\n\t\t =============== START DEMO - capacity() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 5 \n\n");
	append(a, 5);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n\n", length(a));
	
	printf("Finding new capacity of a using capacity(a) \n\n");
	printf("\t capacity(a) = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - capacity() =============== \n\n\n");
}

void toArrayDemo() {
	printf("\n\t\t =============== START DEMO - toArray() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("\t a = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Initialising int arr[] with elements of List a using toArray(a) \n\n");
	int *arr = toArray(a);
	int arrlength = length(a);
	
	printf("\t arr[] = ");
	for(int i = 0; i < arrlength; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	printf("\n\n\t\t =============== END DEMO - toArray() =============== \n\n\n");
}

void toStringDemo() {
	printf("\n\t\t =============== START DEMO - toString() =============== \n\n\n");
	
	printf("Initialising List a with range(1000000000, 1000000009, 1) \n\n");
	List *a = range(1000000000, 1000000009, 1);
	
	printf("\t toString(a) = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n\n", capacity(a));
	
	printf("Appending 1111111111 \n\n");
	append(a, 1111111111);
	
	printf("\t toString(a) = %s \n", toString(a));
	printf("\t Number of elements = %d \n", length(a));
	printf("\t Capacity of a = %d \n", capacity(a));
	
	printf("\n\n\t\t =============== END DEMO - toString() =============== \n\n\n");
}

void showDemo() {
	printf("\n\t\t =============== START DEMO - show() =============== \n\n\n");
	
	printf("Initialising List a with range(0, 11, 2) \n\n");
	List *a = range(0, 11, 2);
	
	printf("Displaying the elements of a using show(a) \n\n");
	printf("\t ");
	show(a);
	printf("\n");
	
	printf("Appending 5 \n\n");
	append(a, 5);
	
	printf("Displaying the elements of a using show(a) \n\n");
	printf("\t ");
	show(a);
	
	printf("\n\n\t\t =============== END DEMO - show() =============== \n\n\n");
}

int main(void) {
	
	initialiseDemo();
	
	initialiseWithCapacityDemo();
	
	initialiseWithArrayDemo();
	
	valuesDemo();
	
	rangeDemo();
	
	sliceDemo();
	
	copyDemo();
	
	clearDemo();
	
	ensureCapacityDemo();
	
	trimToSizeDemo();
	
	fillDemo();
	
	appendDemo();
	
	extendWithArrayDemo();
	
	extendDemo();
	
	insertDemo();
	
	indexOfDemo();
	
	lastIndexOfDemo();
	
	binarySearchDemo();
	
	containsDemo();
	
	isEmptyDemo();
	
	isEqualDemo();
	
	popDemo();
	
	deleteDemo();
	
	getDemo();
	
	setDemo();
	
	reverseDemo();
	
	replaceDemo();
	
	sortDemo();
	
	sortReverseDemo();
	
	countDemo();
	
	sumDemo();
	
	lengthDemo();
	
	capDemo();
	
	toArrayDemo();
	
	toStringDemo();
	
	displayDemo();
	
	return 0;
}