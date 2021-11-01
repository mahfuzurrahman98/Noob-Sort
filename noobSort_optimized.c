#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void noobSort(int *a, int n) {

  int *b = (int*)malloc(n * sizeof(int));
  int *mp = (int*)malloc(n * sizeof(int));

  int i, j = 0, f_id = 0, r_id = n - 1;
  int cur_min, cur_max, min_loc, max_loc;
  int g_min = a[0], g_max = a[0];

  for (i = 0; i < n; i++) {
    if (a[i] < g_min) {
      g_min = a[i];
    }
    if (a[i] > g_max) {
      g_max = a[i];
    }
  }

  while (j < n / 2) {
    cur_min = g_max;
    cur_max = g_min;

    for (i = 0; i < n; i++) {
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

    b[f_id] = cur_min;
    f_id++;
    mp[min_loc] = 1;

    b[r_id] = cur_max;
    r_id--;
    mp[max_loc] = 1;

    j++;
  }
  for (i = 0; i < n; i++) {
    if (mp[i] == 0) {
      b[f_id] = a[i];
      mp[i] = 1;
    }
  }
  for (i = 0; i < n; i++) {
    a[i] = b[i];
  }
  free(b);
}

int main() {

  int arr[] = {9, 2, 11, 35, 1, 0, 44};
  int n = sizeof(arr) / sizeof(int), i;

  noobSort(arr, n);
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}