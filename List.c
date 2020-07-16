# include <stdio.h>
# include <stdlib.h>

typedef struct List List;
typedef struct List* ListPtr;
struct List
{
   int size;
   int allocated;
   int *arr;
};
// Initialising the list (constructor kinda)
List* init() {
    List *l = (List *)malloc(sizeof(List));
    l->arr = (int *)malloc(10*sizeof(int));
    l->size = 0;
    l->allocated = 10;
    
    return l;
}
// Allocating more space if required space for list surpasses the allocated space
void allocateSpaceForAppend(List *l) {
    
    int new_size = (l->size) + (l->size >> 1);
    l->allocated = new_size;
    l->arr = (int *)realloc(l->arr, new_size*sizeof(int));
    
}

// Allocating large spaces when more than one element is appended to the list (To avoid repeated checking for availability of space while extending a list)
void allocateSpaceForExtend(List *l, int offset) {
    
    int new_size = (l->size) + offset;
    l->allocated = new_size;
    l->arr = (int *)realloc(l->arr, new_size*sizeof(int));
    
}

// Append the given element at the end of the list
void append(List *l, int element) {
    
    if (l->allocated <= l->size) {
       allocateSpaceForAppend(l);
    }    
    l->arr[l->size++] = element;
    
}

// Returns the length of the List passed as an argument
int length(List *l) {
    return l->size;
}

// Creates a deep copy of the provided list
List* copy(List *l) {
    
    List *copied_list = init();
    for( int i=0; i<length(l); i++) 
        append(copied_list, l->arr[i]);
    return copied_list;
    
}

// Returns the number of elements with the specified value
int count(List *l, int element) {
    int count = 0;
    for(int i=0; i<l->size; i++)
        if(l->arr[i] == element)
            count ++;
    return count;    
}

// Returns the index of the first element with the specified value ( returns -1 if element not found in the list)
int findIndex(List *l, int element) {
    for(int i=0; i<l->size; i++)
        if(l->arr[i] == element)
            return i;
    return -1;
}

// Adds an element at the specified position 
void insert(List *l, int element, int position){
    if (l->allocated <= l->size)
        allocateSpaceForAppend(l);
    int i = (l->size - 1);
    while (i != position) {
        l->arr[i+1] = l->arr[i]; 
        i-- ;
    }
    l->size += 1;
    l->arr[i+1] = l->arr[i];
    l->arr[i] = element;
}

// Removes the element at the specified position
int pop(List *l,int position){
    
    int returnElement = l->arr[position];
    int i = position+1;
    while (i < l->size) {
        l->arr[i-1] = l->arr[i]; 
        i++ ;
    }
    l->size -= 1;
    return returnElement;
}

// Add the elements of a list, to the end of the current list
void extend(List *alist, List *blist) {
    if(alist->size + blist->size > alist->allocated)
        allocateSpaceForExtend(alist, blist->size);
    for(int i=0; i<blist->size; i++) {
        alist->arr[alist->size++] = blist->arr[i];
    }
}


//gcc List.c -Wall -Wextra
// Main function
int main() {
    
    List *first = init();
    
    for(int i=1; i<=20; i++)
        append(first, i);
        

    List *first_copy = copy(first);
        
    for(int i=21; i<=25; i++)
        append(first_copy, i);
       
    for(int i=0; i<first->size;i++) 
        printf(" %d", first->arr[i]);
    printf("\n");  
    
    for(int i=0; i<first_copy->size;i++) 
        printf(" %d", first_copy->arr[i]);  
    printf("\n");        
    
    printf(" %d\n", length(first));    
    printf(" %d\n", length(first_copy));
    
    printf(" %d\n", count(first, 20)+count(first_copy, 20));
    
    printf(" %d\n %d\n %d\n", findIndex(first, 9), findIndex(first_copy, 25), findIndex(first, 25));
    
    insert(first, 0, 0);   
    insert(first, 100, 10);    
    insert(first, 200, 20);  
    
    for(int i=0; i<first->size;i++) 
        printf(" %d", first->arr[i]);
    printf("\n");  
    
    printf(" %d\n",pop(first,0));
    printf(" %d\n",pop(first,10));
    printf(" %d\n",pop(first,20));
    
    extend(first, first_copy);
    for(int i=0; i<first->size;i++) 
        printf(" %d", first->arr[i]);
    printf("\n");
    
        
    return 0;
}    

