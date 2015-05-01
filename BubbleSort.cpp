//Klavyeden 10 sayı giriliyor. Bubble sort ile sondan başa doğru uygulayarak//
//Büyükten küçüğe sıralanıyor ve her adımda sayılar listeleniyor.//

#include <stdio.h>
#include <stdlib.h>

int k=1;
void goster(int []);
void sirala(int sayilar[]);
int main()
{
    int i;
    int sayilar[10];
    printf("10 adet sayi giriniz\n");
    for(i=0; i<10; i++)
    {
        printf("%d. sayi: ",i+1);
        scanf("%d", &sayilar[i]);
    }
    sirala(sayilar);
    return 0;
}
void sirala(int sayilar[])
{
    int gecici;
    int i, j;
    for(i=0; i<10-1; i++)
    {
        for(j=0; j<10-1-i; j++)
        {
            if(sayilar[j] > sayilar[j+1])
            {
                gecici = sayilar[j];
                sayilar[j]=sayilar[j+1];
                sayilar[j+1] = gecici;
            }
        }
         goster(sayilar);
         getch();
    }
}
void goster(int sayilar[])
{
    int i;
    printf("\n%d. Adim\n",k);
    k++;
    for(i=0; i<10; i++)
    {
        printf("%2d. sayi: %2d\n", i+1, sayilar[i]);
    }
}
