#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    struct dogum_tarihi
    {
        int gun;
        int ay;
        int yil;
    };

    struct sahis_bilgileri
    {
        char isim[40];
        int boy;
        struct dogum_tarihi tarih;
    };

    struct sahis_bilgileri kisi[3] = {"Ebru", 165,{13, 2, 1993},
                                      "Emre", 178, {14, 4, 1998},
                                      "Bekir", 176, {4, 11, 1983}
                                      };

    for(i = 0; i<3; i++)
    {
        printf("Kayit no: %d\n", (i+1));
        printf("Ad: %s\n", kisi[i].isim);
        printf("Boy: %d\n", kisi[i].boy);
        printf("Dogum tarihi: %d/%d/%d\n\n",kisi[i].tarih.gun, kisi[i].tarih.ay, kisi[i].tarih.yil);
    }
    return 0;
}
