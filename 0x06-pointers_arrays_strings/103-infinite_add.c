#include <stdio.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r);
int main()
{
char n1[] = "123456789";
char n2[] = "987654321";
int size_r = 20;
char result[size_r];
char *sum = infinite_add(n1, n2, result, size_r);
if (sum)
printf("Sum: %s\n", sum);
else
printf("Result cannot be stored in the buffer.\n");
return 0;
}
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int i = 0, j = 0, carry = 0, digits = 0;
int val1 = 0, val2 = 0, temp_sum = 0;
while (*(n1 + i) != '\0')
i++;
while (*(n2 + j) != '\0')
j++;
i--;
j--;
if (j >= size_r || i >= size_r)
return 0;
while (j >= 0 || i >= 0 || carry == 1)
{
if (i < 0)
val1 = 0;
else
val1 = *(n1 + i) - '0';
if (j < 0)
val2 = 0;
else
val2 = *(n2 + j) - '0';
temp_sum = val1 + val2 + carry;
if (temp_sum >= 10)
carry = 1;
else
carry = 0;
if (digits >= (size_r - 1))
return 0;
*(r + digits) = (temp_sum % 10) + '0';
digits++;
j--;
i--;
}
if (digits == size_r)
return 0;
*(r + digits) = '\0';
rev_string(r); // Reverse the string to get the correct result
return r;
}
