// this is the first implementation in late 2017

#include <stdio.h>

void noobSort(int[], int);
int maximum(int[], int);
int minimum(int[], int);
int minLocation(int[], int);
int maxLocation(int[], int);
int maxDelete(int[], int);
int minDelete(int[], int);
void arrTraverse(int[], int);

int main() {
  freopen("inp.txt", "r", stdin);
  int size, i;
  // printf("Enter the size: ");
  scanf("%d", &size);
  int array[size];
  // printf("\nEnter %d elements:\n", size);
  for (i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  noobSort(array, size);
  printf("\nSorted array:\n");
  arrTraverse(array, size);
  printf("\n");
}

void noobSort(int array[], int size) {
  int n, loop, max, minLoc, min, maxLoc, i;
  n = size;
  if (n % 2 == 0) {
    loop = n / 2;
  } else if (n % 2 == 1) {
    loop = (n / 2) + 1;
  }
  int a[size];
  int m, P1 = 0, P2 = n - 1, k, c1 = 0, c2 = n - 1;
  for (k = 0; k < loop; k++) {
    max = maximum(array, n);
    min = minimum(array, n);
    for (m = c2; m >= loop; m--) {
      if (m == P2) {
        a[m] = max;
        P2--;
        c2--;
        break;
      }
    }
    for (m = c1; m < loop; m++) {
      if (m == P1) {
        a[m] = min;
        P1++;
        c1++;
        break;
      }
    }
    n = minDelete(array, n);
    n = maxDelete(array, n);
  }
  for (i = 0; i < size; i++) {
    array[i] = a[i];
  }
}

int minDelete(int array[], int n) {
  int i, min, minLoc;
  min = minimum(array, n);
  minLoc = minLocation(array, n);
  for (i = minLoc - 1; i < n - 1; i++) {
    array[i] = array[i + 1];
  }
  return (n - 1);
}

int maxDelete(int array[], int n) {
  int i, max, maxLoc;
  max = maximum(array, n);
  maxLoc = maxLocation(array, n);
  for (i = maxLoc - 1; i < n - 1; i++) {
    array[i] = array[i + 1];
  }
  return (n - 1);
}

int minimum(int array[], int n) {
  int j, min;
  min = array[0];
  for (j = 0; j < n; j++) {
    if (array[j] < min) {
      min = array[j];
    }
  }
  return min;
}
int minLocation(int array[], int n) {
  int j, min, minLoc;
  min = array[0];
  for (j = 0; j < n; j++) {
    if (array[j] < min) {
      min = array[j];
    }
    if (min == array[j]) {
      minLoc = j + 1;
    }
  }
  return minLoc;
}

int maximum(int array[], int n) {
  int j, max;
  max = array[0];
  for (j = 0; j < n; j++) {
    if (array[j] > max) {
      max = array[j];
    }
  }
  return max;
}

int maxLocation(int array[], int n) {
  int j, max, maxLoc;
  max = array[0];
  for (j = 0; j < n; j++) {
    if (array[j] > max) {
      max = array[j];
    }
    if (max == array[j]) {
      maxLoc = j + 1;
    }
  }
  return maxLoc;
}

void arrTraverse(int array[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}