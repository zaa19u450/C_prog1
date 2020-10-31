#include <stdio.h>
#include <string.h>
#include "my_strspn.h"

int main(void)
{
    char str_1[] = "123456";
    char poisk_1[] = "312";

    char str_2[] = "abcdef";
    char poisk_2[] = "kl";

    char str_3[] = "abcde";
    char poisk_3[] = "c";

    char str_4[] = "aaaaaaa";
    char poisk_4[] = "ab";

    setbuf(stdout, NULL);

    printf("TEST ONE: first three symbols are in poisk\n");
    printf("Lenght of sygment (using standart library): %d\n", (int) strspn(str_1, poisk_1));
    printf("Lenght of sygment (using my function): %d\n\n", my_strspn(str_1, poisk_1));

    printf("TEST TWO: there are no symbols that are in poisk\n");
    printf("Lenght of sygment (using standart library): %d\n", (int) strspn(str_2, poisk_2));
    printf("Lenght of sygment (using my function): %d\n\n", my_strspn(str_2, poisk_2));

    printf("TEST THREE: only a symbol in the middle is in poisk\n");
    printf("Lenght of sygment (using standart library): %d\n", (int) strspn(str_3, poisk_3));
    printf("Lenght of sygment (using my function): %d\n\n", my_strspn(str_3, poisk_3));

    printf("TEST FOUR: all symbols are in poisk\n");
    printf("Lenght of sygment (using standart library): %d\n", (int) strspn(str_4, poisk_4));
    printf("Lenght of sygment (using my function): %d\n\n", my_strspn(str_4, poisk_4));

    return 0;
}