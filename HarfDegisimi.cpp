#include <stdio.h>

int main ()
{

    char buyuk[]="ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZXQW";
    char kucuk[]="abcçdefgğhıijklmnoöprsştuüvyzxqw";
    int i=0, k =0;
    char cumle[200];
    gets(cumle);

    for(i = 0; cumle[i] != '\0'; i++)
    {
        for(k = 0; k < 33; k++)
        {
            if(cumle[i] == buyuk[k])
            {
                cumle[i]=kucuk[k];
            }

            else if(cumle[i] == kucuk[k])
            {
                cumle[i]=buyuk[k];
            }
        }

    }

    printf("%s", cumle);

    return 0;
}


