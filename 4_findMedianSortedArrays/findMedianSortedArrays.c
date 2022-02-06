double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	const int isEven = (((nums1Size + nums2Size) % 2) ? 0 : 1);
	const int totalLength = nums1Size + nums2Size;
	const int targetIndex = totalLength / 2;
	int index = 0;
	int index1 = 0;
	int index2 = 0;

	int* arr = (int*)malloc(totalLength * sizeof(int));
	if (NULL == arr)
		return 0.0;

	while (index < totalLength) {
		if (index1 < nums1Size && index2 < nums2Size) {
			*(arr + index) = (*(nums1 + index1) < *(nums2 + index2)) ? *(nums1 + index1++) : *(nums2 + index2++);
		}
		else if (index1 == nums1Size) {
			*(arr + index) = *(nums2 + index2);
			index2++;
		}
		else if (index2 == nums2Size) {
			*(arr + index) = *(nums1 + index1);
			index1++;
		}
		index++;
	}

	if (isEven) {
		return (double)((*(arr + targetIndex) + *(arr + targetIndex - 1)) / 2.0);
	}
	else {
		return (double)(*(arr + targetIndex));
	}
}