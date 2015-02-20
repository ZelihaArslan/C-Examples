#include <stdio.h>

int main ()
{
    int i = 0, k = 0, harfSay = 0;
    char cumle[200];
    char harf[65]="ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZQWXabcçdefgğhıijklmnoöprsştuüvyzqwx";

    printf("Bir cumle giriniz.\n");
    gets(cumle);

    for( i = 0; cumle[i]!='\0' ; i++)
    {
        for(k =0; k <64; k++)
        {
            if (cumle[i] == harf[k])
            harfSay++;
        }

    }

    printf("Girilen harf Sayisi: %d", (harfSay));

    return 0;
}

