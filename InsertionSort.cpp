//10 adet küçükten büyüğe sıralanmış listeye rastgele//
//5 eleman daha ekler ve elemanlar sıralama bozulmadan uygun konuma yerleştirilir.//
#include <stdio.h>
#include <stdlib.h>

int i,j;
void sirala(int sayilar[15]);
int main()
{
    int veri[] = {2, 9, 12, 19, 28, 45, 58, 63, 85, 96};
    int dizi[5];
    int sayilar[15];
    printf("Varolan sayilarimiz\n");
    for(i=0; i<10; i++)
    {
        printf("%2d. Eleman: %3d", i+1, veri[i]);
        printf("\n");
    }
    printf("\n5 adet sayi giriniz\n");

    for(i=0; i<5; i++)
    {
        printf("%d. sayi: ", i+1);
        scanf("%d", &dizi[i]);
    }
    printf("\n");
    for(i=0; i<15; i++)          //İki diziyi birleştiriyoruz//
    {
        if(i<10)
        {
            sayilar[i] = veri[i];
        }
        else
        {

            sayilar[i] = dizi[j];
            j++;
        }

    }
    sirala(sayilar);
    printf("Insertion Sort ile siralanmis hali\n");
    for(i=0; i<15; i++)
    {
        printf("%2d. sayi: %3d\n",i+1, sayilar[i]);
    }
    return 0;
}
void sirala(int sayilar[15])
{
    int gecici;
    for(i=10; i<15; i++)
    {
        gecici = sayilar[i];
        j = i;
        while((j >0) && (sayilar[j-1] > gecici))
        {
            sayilar[j] = sayilar[j-1];
            j--;
        }
        sayilar[j] = gecici;
    }
}
