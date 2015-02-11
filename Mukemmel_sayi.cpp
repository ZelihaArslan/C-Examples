#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi = 0, i = 0, toplam =0;
    printf("Bir sayi giriniz.\n");
    scanf("%d", &sayi);

    for(i = 1; i < sayi; i++)
    {
        if(sayi % i == 0)
            toplam += i;
    }
    if(toplam == sayi)
    {
        printf("\n%d Mukemmel sayidir", toplam);
    }
    else
    {
        printf("\n%d Mukemmel sayi degildir", sayi);
    }

    return 0;
}
