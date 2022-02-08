int isPalindrome(const char* s, const int len) {
	int ii;
	for (ii = 0; ii < len / 2; ii++)
		if (s[ii] != s[len - 1 - ii])
			break;

	return (ii == len / 2) ? 1 : 0;
}

char* longestPalindrome(char* s) {
	int length = 0;
	for (; s[length] != '\0'; length++);

	int longest = 0;

	int tmp1 = 0;
	int tmp2 = 0;

	for (int ii = 0; ii < length; ii++) {
		for (int jj = (length - ii); jj > 0; jj--) {
			if (isPalindrome((s + ii), jj)) {
				if (jj > longest) {
					tmp1 = ii;
					tmp2 = jj;
					longest = tmp2;
				}
                if (jj > ii)
				    break;
			}
		}
	}

	char* str = (char*)malloc((tmp2 + 1) * sizeof(char));
	strncpy(str, (s + tmp1), (size_t)tmp2);
	*(str + tmp2) = '\0';

 	return str;
}