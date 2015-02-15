/* Cümle içerisindeki harf sayısını bulma */
#include <stdio.h>

int main ()
{
    int i = 0, k = 0, harfSay = 0;
    char cumle[200];
    char harf[]="ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZqwxabcçdefgğhıijklmnoöprsştuüvyzqwx";

    printf("Bir cumle giriniz.\n");
    gets(cumle);

    for( i = 0; cumle[i]!='\0' ; i++)
    {
        for(k =0; k < 64; k++)
        {
            if (cumle[i] == harf[k]) /* Girilen cümledeki bir harf, harf dizisindeki elemanlardan
                                      biriyle eşleşiyorsa harfSay değişkenini bir arttır */
            harfSay++;
        }

    }

    printf("Girilen Harf Sayisi: %d", (harfSay));

    return 0;
}

