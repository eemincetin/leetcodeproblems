char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

#define bigone(A, B) (((A) > (B)) ? (A) : (B))

char* addStrings(char* num1, char* num2) {
    char* val1 = num1;
    char* val2 = num2;

    unsigned int sum = 0, carry = 0;

    size_t size1 = strlen(val1);
    size_t size2 = strlen(val2);
    size_t size = bigone(size1, size2);
    char* retStr = (char *)malloc((size + 2) * sizeof(char));

    unsigned char digit1 = 0, digit2 = 0;
    size_t index = 0, index1 = 0, index2 = 0;

    while((index1 < size1 || index2 < size2 || carry == 1)) {
        if(index1 < size1) {
            digit1 = ((*(val1 + size1 - 1 - index1++)) - 48);
        }
        else {
            digit1 = 0;
        }

        if(index2 < size2) {
            digit2 = ((*(val2 + size2 - 1 - index2++)) - 48);
        }
        else {
            digit2 = 0;
        }

        sum = digit1 + digit2 + carry;
        *(retStr + index++) = (sum % 10) + 48;

        if(sum > 9) {
            carry = 1;
        }
        else {
            carry = 0;
        }
        digit1 = 0;
        digit2 = 0;
    }
    
    *(retStr + index) = '\0';

    return strrev(retStr);
}
