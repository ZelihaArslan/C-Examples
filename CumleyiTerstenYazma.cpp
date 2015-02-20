#include <stdio.h>

int main ()
{
    char cumle[200];
    gets(cumle);
    int i;

    for(i = strlen(cumle); i >= 0; i--)
    {
        printf("%c", cumle[i]);
    }
    return 0;
}

