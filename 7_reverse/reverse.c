int reverse(const int x) {
	if (x == 0)
		return 0;
	
	int posArr[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
	int negArr[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};

	int sign = (x > 0) ? 1 : 0;
		
	int temp = x;
	int numDigits = 0;
	while (temp) {
		temp /= 10;
		numDigits++;
	}

	unsigned int multiplier = 1;

	while (--numDigits)
		multiplier *= 10;

	int retVal = 0;
	
	temp = x;
	int ii = 0;
	int compVal = (multiplier == 1000000000);
	while (temp) {
		if (compVal) {
			if (sign) {
				if ((temp % 10) > posArr[ii]) {
					return 0;
				}
			}
			else {
				if (abs((temp % 10)) < negArr[ii]) {
					compVal = 0;
				}
				if (abs((temp % 10)) > negArr[ii]) {
					return 0;
				}
			}
			ii++;
		}

		retVal += (temp % 10) * multiplier;
		multiplier /= 10;
		temp /= 10;
	}

	return retVal;
}