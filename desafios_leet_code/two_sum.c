// https://leetcode.com/problems/two-sum/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * O site leet_code já importa a lib stdlib.h.
 */

// Criando solução sem usar hashtable
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  *returnSize = 2;
  int last_values[numsSize];
  int* indexes = malloc(*returnSize * sizeof(int));
  for (int i = 0; i < numsSize; i++)
  {
    if (i == 0){
      last_values[i] = nums[i];
      continue;
    }
    int current_number = nums[i];

    for (int j = 0; j < i; j++){
      if ((current_number + last_values[j]) == target){
        indexes[0] = j;
        indexes[1] = i;
        return indexes;
      }
    }
    last_values[i] = current_number;
  }
  return NULL;
}
