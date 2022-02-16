int ndigit(int x) {
    int cnt = 0;
    while (x) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

char* convertStr(int x, int ndigit) {
    char* str = (char*)malloc((ndigit + 1) * sizeof(char));
    if (NULL == str)
        return NULL;

    int ii = 0;
    if (x < 0) {
        return NULL;
    }
    else if (x == 0) {
        return "0";
    }
    else {
        for (; ii < ndigit; ii++) {
            char ch = (x % 10) + '0';
            *(str + ii) = ch;
            x /= 10;
        }
    }
    *(str + ii) = '\0';

    return str;
}

bool isPalindrome(int x) {
    char* str = convertStr(x, ndigit(x));

    if (NULL == str)
        return 0;

    int ii = 0;
    for (; ii < (strlen(str) / 2); ii++) {
        if (str[ii] != str[strlen(str) - 1 - ii]) {
            break;
        }
    }

    return (ii == strlen(str) / 2) ? 1 : 0;
}