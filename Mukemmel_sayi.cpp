/*Mükemmel sayı: Sayılar teorisinde, kendisi hariç pozitif tam bölenlerinin toplamı kendisine eşit olan sayı. 
Diğer bir ifadeyle, bir mükemmel sayı, bütün pozitif tam bölenlerinin toplamının yarısına eşittir. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi = 0, i = 0, toplam =0;
    printf("Bir sayi giriniz.\n");
    scanf("%d", &sayi);

    for(i = 1; i < sayi; i++)
    {
        if(sayi % i == 0) /*Pozitif tam bölenlerini bulmak için sayımızı sürekli böldük. */
            toplam += i; /*Sayımız i değişkenine tam bölünüyorsa i değişkenini toplama attık.*/
    }
    if(toplam == sayi)/* Döngü bitiminde toplamın içerisinde tutulan değer girilen değere eşif ise
                        o mükemmel sayıdır dedik.*/
    {
        printf("\n%d Mukemmel sayidir", toplam);
    }
    else
    {
        printf("\n%d Mukemmel sayi degildir", sayi);
    }

    return 0;
}
