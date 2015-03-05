#include <stdio.h>
#include <stdlib.h>

 typedef struct bilgiler
    {
        char isim[10];
        char adres[20];
        int tel;
        int borc;
    } kisi;
void yazdir(kisi *z, int n);

int main()
{
    printf("Kac elemanli veri gireceksiniz\n");
    int n,i;
    scanf("%d",&n);
    kisi *a=(kisi*)malloc(n*sizeof(kisi));
    for(i=0; i<n; i++)
    {
        printf("isim: ");
        scanf("%s",(a+i)->isim);
        printf("Adres: ");
        scanf("%s",(a+i)->adres);
        printf("Telefon: ");
        scanf("%d", &(a+i)->tel);
        printf("Borc: ");
        scanf("%d", &(a+i)->borc);
    }
    printf("\n");
    yazdir(a,n);
    return 0;
}
void yazdir(kisi *z,int n)
{
    int i=0;
    for(i=0; i<n;i++)
    {
        printf("isim: %s\n", (z+i)->isim);
        printf("Adres: %s\n", (z+i)->adres);
        printf("Telefon: %d\n", (z+i)->tel);
        printf("Borc: %d\n", (z+i)->borc);
        printf("\n");
    }
}

