#include <stdio.h>
#include <stdlib.h>

void noobSort(int *a, int n) {

  int *b = (int *)malloc(n * sizeof(int));
  int *mp = (int *)malloc(n * sizeof(int));

  int i, j = 0, f_id = -1, r_id = n;
  int cur_min, cur_max, min_loc, max_loc;
  int g_min = a[0], g_max = a[0];

  // get the min and max elements of the initial array,
  // we will use these value for further comparison
  for (i = 0; i < n; i++) {
    if (a[i] < g_min) {
      g_min = a[i];
    }
    if (a[i] > g_max) {
      g_max = a[i];
    }
  }

  // run n / 2 iterations
  while (j < n / 2) {
    cur_min = g_max;
    cur_max = g_min;

    // find min and max elements with their location
    for (i = 0; i < n; i++) {
      // skip already marked indexes
      if (mp[i]) {
        continue;
      }
      if (a[i] < cur_min) {
        cur_min = a[i];
        min_loc = i;
      }
      if (a[i] > cur_max) {
        cur_max = a[i];
        max_loc = i;
      }
    }

    // insert those min and max elements on appropriate position
    // mark those indexes containing min and max elements
    b[++f_id] = cur_min;
    mp[min_loc] = 1;

    b[--r_id] = cur_max;
    mp[max_loc] = 1;

    j++;
  }

  for (i = 0; i < n; i++) {
    // in case, the array size is odd insert the unmarked position's element at one ahead of the front pointer
    if (mp[i] == 0) {
      b[f_id + 1] = a[i];
      mp[i] = 1;
    }
    // copy the full array
    a[i] = b[i];
  }

  free(b);
  free(mp);
}

int main() {

  int arr[] = {9, 2, -11, 35, 1, 0, 44, 21, -4};
  int n = sizeof(arr) / sizeof(int), i;

  noobSort(arr, n);
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}