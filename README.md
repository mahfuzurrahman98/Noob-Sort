# Noob-Sort
Noob sort is an array sorting algorithm with a complexity of O(n^2). I had designed this algorithm in my early data structure learning days.


An process(algorithm) of Array sorting, steps are given below:<br>

0. A user takes an array(actual) of definite size.<br>
1. Finding: Finds the minimum & maximum element of that array.<br>
2. Assigning: Assigns them in an another array(its size will be same as the actual array) as first and last element respectively.<br>
3. Deleting: Deletes both of the minimum & maximum element from the actual array. Now the array size will decrease down to size=(size-2). The actual array will be replaced by the decrease sized array.<br>

#Now these three steps will continue cyclically on the replaced array for n times.<br>
#n = ceiling value of(size/2).<br>
