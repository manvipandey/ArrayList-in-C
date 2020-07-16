# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

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
void insert(List *l, int element, int position) {
    
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

// Add the elements of the list passed as second argument to the end of the list passed as first argument
void extend(List *alist, List *blist) {
    
    if(alist->size + blist->size > alist->allocated)
        allocateSpaceForExtend(alist, blist->size);
    for(int i=0; i<blist->size; i++) {
        alist->arr[alist->size++] = blist->arr[i];
    }
    
}

// Removes the first item with the specified value (returns -1 if element not found)
int removeElement(List *l, int element) {
    
    int pos = findIndex(l, element);
    if(pos == -1) 
        return -1;
    pop(l, pos);

}

// Reverses the order of the list
void reverse(List *l) {
    
    int limit = (l->size / 2) - 1;
    for(int i=0; i<=limit; i++) {
        int temp = l->arr[i];
        l->arr[i] = l->arr[l->size - (1 + i)];
        l->arr[l->size - (1 + i)] = temp;
    }
    
}

// Returns the sum of all the elements present in the list
int sum(List *l ) {
    
    int sumOfElements = 0;
    for(int i=0; i<l->size; i++)
        sumOfElements += l->arr[i];
        
    return sumOfElements;
    
}

// Returns the value at the given index in the list (returns NULL if list index out of limit)
int get(List *l, int index) {
    
    if(index > l->size-1)
        return NULL;
    return l->arr[index];
    
}

// Displays or shows the current status of the list
void show(List *l) {
    
    int i = 0;
    printf("[");
    for(; i<l->size-1; i++) {
        printf(" %d,", l->arr[i]);
    }
    printf(" %d ]\n", l->arr[i]);
    
}

// Returns true if element is found in the list; otherwise returns false (Linear search)
bool search(List *l, int element) {
    
    for(int i=0; i<l->size; i++) {
        if(l->arr[i] == element)
            return true;
    }
    return false;
    
} 

// Returns true if the given two lists are equal
bool isEqual(List *alist, List *blist) {
    
    if(alist->size == blist->size) {
        for(int i=0; i<alist->size; i++) {
            if(alist->arr[i] != blist->arr[i])
                return false;
        }
        return true;
    }
    return false;
    
} 

// Returns a string of all the elements present in the current list
char* toString(List *l) {
    
    char *s = (char *)malloc((l->size*2+15)*10*sizeof(char)); 
    int index = 0, i = 0;
    index += sprintf(&s[index],"[");
    for(; i<l->size-1; i++) {
        index += sprintf(&s[index], " %d,", l->arr[i]);
    }
    index += sprintf(&s[index], " %d ]", l->arr[i]);
    return s;
    
}

// Sets the index provided with the given value in the list
void set(List *l, int index, int newValue) {
    
    l->arr[index] = newValue;
    
}

// Returns the list where the old value is replaced by new value upto the given count; If the old value is not found it returns the original list
List* replace(List *l, int oldValue, int newValue, int count) {
    
    for(int i=0;count>0 && i<l->size; i++) {
        if (l->arr[i] == oldValue) {
            l->arr[i] = newValue;
            count --;
        }
    }
    return l;
    
}

// Returns a list with sequence of numbers starting from given lower limit and increaments by step, and stops before the upper limit
List* range(int lowerLimit, int upperLimit, int step) {
    
    List *l = init();
    for(int i=lowerLimit; i<upperLimit; i+=step) {
        append(l, i);
    } 
    return l;
    
}

// Returns a copy of the list with the sequence of numbers from the lower index, increamenting by step, and stops before upper index
List* slice(List *alist, int lowerIndex, int upperIndex, int step) {
    
    List *l = init();
    for(int i=lowerIndex; i<upperIndex; i+=step) {
        append(l, alist->arr[i]);
    }
    return l;
    
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
       
    show(first);  
    
    show(first_copy);       
    
    printf(" %d\n", length(first));    
    printf(" %d\n", length(first_copy));
    
    printf(" %d\n", count(first, 20)+count(first_copy, 20));
    
    printf(" %d\n %d\n %d\n", findIndex(first, 9), findIndex(first_copy, 25), findIndex(first, 25));
    
    insert(first, 0, 0);   
    insert(first, 100, 10);    
    insert(first, 200, 20);  
    
    show(first);  
    
    printf(" %d\n",pop(first,0));
    printf(" %d\n",pop(first,10));
    printf(" %d\n",pop(first,20));
    
    extend(first, first_copy);
    
    removeElement(first, 200);
    if(removeElement(first_copy, 200) == -1)
        printf(" Element not found in the list!\n");
    
    show(first);
    
    reverse(first);
    show(first);
    
    printf(" %d\n", sum(first)); 
    printf(" %d\n", get(first, 100)); 
    
    show(first);    
    
    if(search(first, 100))
        printf(" Element found !\n");
    else
        printf(" Element not found !\n");
        
    if(isEqual(first, first_copy))
        printf(" Equal\n");
    else 
        printf(" Not equal !\n");
        
    printf(" %s\n",toString(first));
    
    if(get(first, 100) == NULL)
        printf(" Index not found !\n");
    printf(" %d\n",get(first, 15));
    
    set(first, 15, 1);
    
    show(first);
    
    show(replace(first, 1, 0, 2));
    
    extend(first_copy, range(0, 10, 2));
    
    show(first_copy);
    
    show(slice(first_copy, 25, length(first_copy), 1));
        
    return 0;
}    

