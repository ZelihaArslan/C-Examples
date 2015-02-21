#include <stdio.h>

int main ()
{
    char cumle[200];
    gets(cumle);
    int i;

    for(i = strlen(cumle)-1; i >= 0; i--)
    {
        printf("%c", cumle[i]);
    }
    return 0;
}

