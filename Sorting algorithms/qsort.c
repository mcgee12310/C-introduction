#include <stdio.h>
#include <stdlib.h>

void input(double array[], int n){
    for(int i=0; i<n; i++){
        scanf("%lf", &array[i]);
    }
}

void swap(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

int partition(double array[], int low, int high) {
    double pivot = array[low]; 
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

void quickSort(double array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi);
    quickSort(array, pi + 1, high);
  }
}

void printArray(double array[], int size) {
  for (int i = size-1; i >= 0; i--) {
    printf("%.2lf\n", array[i]);
  }
  printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    double a[n];n
    
    input(a, n);
    quickSort(a, 0, n-1);
    printArray(a, n);
}
