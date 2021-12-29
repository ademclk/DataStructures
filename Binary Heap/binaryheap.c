#include <stdio.h>
#include <stdlib.h>

void insertToMax_heap(int *array, int x, int index) {
    if(index == SIZE)
        printf("Heap dolu !\n");
    else {
        array[index] = x;
        while(index != 1 && array[index / 2] < array[index]) {
            swap(&array[index / 2], &array[index]); // yer değiştiriliyor
            index /= 2;
        }
    }
}

int deleteMax(int *array, int index) {
    int max, i = 1;
    if(index == 1) {
        printf("Heap bos\n");
        return 0;
    } else {
    max = array[i];
    array[i] = array[index-1];
    array[index-1] = 0; 
    while(array[i] < array[2*i] || array[i] < array[(2*i) + 1]) {
        if(array[2*i] > array[(2*i) + 1]) { 
        swap(&array[2*i], &array[i]);
        i = 2*i;
    }
    else { 
        swap(&array[(2*i) + 1], &array[i]); 
        i = (2*i) + 1;
    }
}
    return max;
    }   
}