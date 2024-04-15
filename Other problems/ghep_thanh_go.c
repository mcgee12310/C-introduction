#include <stdio.h>
#include <stdlib.h>

int sum=0;

void input(int array[], int n){
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[low]; 
    int i = low - 1, j = high + 1; 
  
    while (1) { 
        // Find leftmost element greater than 
        // or equal to pivot 
        do { 
            i++; 
        } while (array[i] < pivot); 
  
        // Find rightmost element smaller than 
        // or equal to pivot 
        do { 
            j--; 
        } while (array[j] > pivot); 
  
        // If two pointers met. 
        if (i >= j) 
            return j; 
  
        swap(&array[i], &array[j]); 
    } 
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i <size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    
    input(a, n);
    quickSort(a, 0, n-1);
    printArray(a, n);

    for(int i=1; i<n; i++){
      int tmp = a[i] + a[i-1];
      sum += tmp;
      for(int j=i; j<n; j++){
          if(tmp < a[j+1]){
            a[j] = tmp;
            break;
          }
          a[j] = a[j+1];
      }
    }
    printArray(a, n);
    printf("%d", sum);
}
