int romanToInt(char* s) {
	const char* str = s;
	int i = 0;
	char oldChar = '\0';

	int retVal = 0;

	for (; str[i] != '\0'; i++) {
		switch (str[i]) {
			case 'M':
				retVal += 1000;
				if (oldChar == 'C') {
					retVal -= 2 * 100;
				}
				break;
			case 'D':
				retVal += 500;
				if (oldChar == 'C') {
					retVal -= 2 * 100;
				}
				break;
			case 'C':
				retVal += 100;
				if (oldChar == 'X') {
					retVal -= 2 * 10;
				}
				break;
			case 'L':
				retVal += 50;
				if (oldChar == 'X') {
					retVal -= 2 * 10;
				}
				break;
			case 'X':
				retVal += 10;
				if (oldChar == 'I') {
					retVal -= 2 * 1;
				}
				break;
			case 'V':
				retVal += 5;
				if (oldChar == 'I') {
					retVal -= 2 * 1;
				}
				break;
			case 'I':
				retVal += 1;
				break;
			
			default:
			
				break;
		}
		oldChar = str[i];
	}

	return retVal;
}