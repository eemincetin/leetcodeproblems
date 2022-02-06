int lengthOfLongestSubstring(char* s) {
	int length = 0;
	int bigOne = 0;

	int map[128] = { 0 };
	int ii = 0;
	int jj = 0;
	
	for (; s[ii] != NULL; ii++) {
		if (map[s[ii]] == 1) {
			jj++;
			ii = jj;
			for (int kk = 0; kk < 128; kk++)
				map[kk] = 0;
			length = 0;
		}
		map[s[ii]] += 1;
		length++;
		if (length > bigOne) {
			bigOne = length;
		}
	}

	return bigOne;
}