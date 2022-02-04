int* twoSum(const int* nums, const int numsSize, const int target, int* returnSize){
    *returnSize = 2;
    int *arr = (int *)malloc((*(returnSize))*sizeof(int));
    if(NULL == arr)
        return NULL;
    
    for(int ii = 0; ii < numsSize; ii++){
        for(int jj = ii + 1; jj < numsSize; jj++){
                if(target == *(nums + ii) + *(nums + jj)){
                    *arr = ii;
                    *(arr + 1) = jj;
                    break;
                }
        }
    }
    
    return arr;
}
