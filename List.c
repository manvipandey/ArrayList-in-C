# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct List List;
typedef struct List* ListPtr;
struct List {
    int size;
    int allocated;
    int *arr;
};
// Initialising the list (constructor kinda)
List* init() {
    
    List *l = (List *)malloc(sizeof(List));
    l->allocated = 10;
    l->arr = (int *)malloc(l->allocated*sizeof(int));
    l->size = 0;
    
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
    
    if(l->allocated < l->size + offset) {
        int new_size = (l->size) + offset;
        l->allocated = new_size;
        l->arr = (int *)realloc(l->arr, new_size*sizeof(int));
    }
    
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
    if( position < 0) {
        while(i-l->size != position) {
            l->arr[i+1] = l->arr[i]; 
            i-- ;
        }
    }
    else {
        while (i != position) {
        l->arr[i+1] = l->arr[i]; 
        i-- ;
        }
    }
    l->size += 1;
    l->arr[i+1] = l->arr[i];
    l->arr[i] = element;
}

// Removes the element at the specified position
int pop(List *l,int position){
    
    if(position < 0)
        position = l->size + position; 
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
    
    allocateSpaceForExtend(alist, blist->size);
    for(int i=0; i<blist->size; i++) {
        alist->arr[alist->size++] = blist->arr[i];
    }
    
}

// Returns a list with all the elements in the array passed as an argument
List* fromArray(int a[], int length) {
    
    List *l = init();
    allocateSpaceForExtend(l, length);
    for(int i=0; i<length; i++)
        l->arr[l->size++] = a[i];
    return l;
    
}

// Removes the first item with the specified value (returns -1 if element not found)
int removeElement(List *l, int element) {
    
    int pos = findIndex(l, element);
    if(pos == -1) 
        return -1;
    return pop(l, pos);

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
        return -1;
    if(index < 0)
        index = l->size + index;
    return l->arr[index];
    
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
    
    if(l->size == 0) {
        return "[]";
    }
    char *s = (char *)malloc((l->size*12+1)*sizeof(char));
    int index = 0;
    index += sprintf(&s[index],"[");
    for(int i=0; ; i++) {
        if(i<l->size-1)
            index += sprintf(&s[index], "%d, ", l->arr[i]);
        else {
            index += sprintf(&s[index], "%d]", l->arr[i]);
            break;
        }
    }
    return s;
    
}

// Displays or shows the current status of the list
void show(List *l) {
    
    printf("%s\n",toString(l));
    
}

// Sets the index provided with the given value in the list
void set(List *l, int index, int newValue) {
    if(index < 0)
        index = l->size + index;
    l->arr[index] = newValue;
    
}

// Returns the list where the old value is replaced by new value upto the given count; If the old value is not found it returns the original list
void replace(List *l, int oldValue, int newValue, int count) {
    
    for(int i=0;count>0 && i<l->size; i++) {
        if (l->arr[i] == oldValue) {
            l->arr[i] = newValue;
            count --;
        }
    }
    
}

// Returns a list with sequence of numbers starting from given lower limit and increaments by step, and stops before the upper limit
List* range(int lowerLimit, int upperLimit, int step) {
    
    if( (lowerLimit >= upperLimit && step > 0) || (lowerLimit <= upperLimit && step < 0) ) {
        List *l = (List *)malloc(sizeof(List));
        l->allocated = 0;
        l->arr = (int *)malloc(0*sizeof(int));
        l->size = 0;
        return l;
    }
    List *l = init();
    if(lowerLimit < upperLimit) {
        for(int i=lowerLimit; i<upperLimit; i+=step) {
            append(l, i);
        } 
    }
    else if (lowerLimit > upperLimit) {
        for(int i=lowerLimit; i>upperLimit; i+=step) {
            append(l, i);
        } 
    }
    return l;
    
}

// Returns a copy of the list with the sequence of numbers from the lower index, increamenting by step, and stops before upper index
List* slice(List *alist, int lowerIndex, int upperIndex, int step) {
    
    if(lowerIndex < 0)
        lowerIndex = alist->size + lowerIndex;
    if(upperIndex < 0)
        upperIndex = alist->size + upperIndex;
    if( (lowerIndex >= upperIndex && step > 0) || (lowerIndex <= upperIndex && step < 0) ) {
        List *l = (List *)malloc(sizeof(List));
        l->allocated = 0;
        l->arr = (int *)malloc(0*sizeof(int));
        l->size = 0;
        return l;
    }
    List *l = init();
        
    if(lowerIndex < upperIndex) {
        for(int i=lowerIndex; i<upperIndex; i+=step) {
            append(l, alist->arr[i]);
        } 
    }
    else if (lowerIndex > upperIndex) {
        for(int i=lowerIndex; i>upperIndex; i+=step) {
            append(l, alist->arr[i]);
        } 
    }
    return l;
    
}

// Removes all the elements of the list and returns an empty list
List* clear(List *alist) {
    
    free(alist->arr);
    alist->arr = (int *)malloc(0*sizeof(int));
    alist->size = 0;
    alist->allocated = 0;
    
    return alist;
    
}

/* This function takes last element as pivot, places the pivot element at it's correct
   position in sorted array, and places all the elements smaller than the pivot to left
   of pivot and all greater elements to right of pivot */
int partition(List *alist, int lowerIndex, int upperIndex) {
    
    int pivot = alist->arr[upperIndex];
    int i = (lowerIndex - 1), temp;
    for (int j=lowerIndex; j<upperIndex; j++) {
        if(alist->arr[j] < pivot) {
            i++;
            temp = alist->arr[i];
            alist->arr[i] = alist->arr[j];
            alist->arr[j] = temp;
        }
    }
    temp = alist->arr[i+1];
    alist->arr[i+1] = alist->arr[upperIndex];
    alist->arr[upperIndex] = temp;
    return (i+1);
    
}

//The main function that implements quick sort
void sort(List *alist, int lowerIndex, int upperIndex) {
    
    if (lowerIndex < upperIndex) {
        int partitionIndex = partition(alist, lowerIndex, upperIndex);
        sort(alist, lowerIndex, partitionIndex-1);
        sort(alist, partitionIndex+1, upperIndex);
    }
    
}

// Binary search
bool binarySearch(List *l, int element) {
     
    sort(l, 0, (l->size)-1);
    int startIndex = 0, endIndex = length(l)-1, mid;
    while(startIndex <= endIndex) {
        mid = (startIndex + endIndex)/2;
        if (l->arr[mid] > element)
            endIndex = mid-1;
        else if(l->arr[mid] < element)
            startIndex = mid + 1;
        else
            return true;
    }
    return false;

}

// Returns a list containing the values passed as variable length argument (argCount gives the number of values passed)
List* fromValues(int argCount, ...) {
    
    va_list varList;
    List* l = init();
    va_start(varList, argCount);
    for(int i=0; i < argCount; i++) {
        append(l, va_arg(varList,int));
    }
    va_end(varList);
    return l;
    
}

// Returns an array with all the elements present in the list passed as an argument 
int* toArray(List *l) {
    
    int *array = (int *)malloc(l->size*sizeof(int));
    for(int i=0; i<l->size; i++) 
        array[i] = l->arr[i];
    return array;
    
}

// Apppends the list with 'count' number of 'value' and returns the list
List* fill(List *l, int count, int value ) {
    
    if(l->size + count > l->allocated) 
        allocateSpaceForExtend(l, count);
    while(count > 0) {
        l->arr[l->size++] = value;
        count--;
    }
    return l;
    
}

// Trims the allocated space down to the size of the list
void trimToSize(List *l) {
    
    l->allocated = l->size;
    l->arr = realloc(l->arr, l->size*sizeof(int));
    
}


