#include <stdio.h>
#include <stdlib.h>

FILE *dosya, *yedek;
    typedef struct
    {
        char ad[10];
        int no, Not;
    }ogrenci;

    ogrenci kisi;
    int no, durum;

KayitGiris();
Listeleme();
KayitSilme();
KayitArama();
KayitDegistir();
degistir(char *, int);
int main()
{
    FILE *dosya, *yedek;
    typedef struct
    {
        char ad[10];
        int no, Not;
    }ogrenci;

    ogrenci kisi;
    int durum = 0;
    char isim[10];
    int nott;

    do
    {
        system("cls");
        printf("Menu\n1- Kayit Giris\n2- Kayit Listeleme\n3- Kayit Silme\n4- Kayit Arama\n5- Kayit Degistirme\n6- Cikis\n7- Isme gore degistir");
        switch(getch())
        {
            case '1':
                KayitGiris();
                break;
            case '2':
                Listeleme();
                break;
            case '3':
                KayitSilme();
                break;
            case '4':
                KayitArama();
                break;
            case '5':
                KayitDegistir();
                break;
            case '6':
                printf("Cikis yapiliyor...");
                return 0;
                break;
            case '7':
                printf("\nIsim girin\n");
                scanf("%s",&isim);
                printf("Not girin");
                scanf("%d",&nott);

                getch();
                degistir(isim,nott);
                break;
            default:
                printf("Hatali bir secim yaptiniz");
                getch();
        }
    }while(1);
    return 0;
}
KayitGiris()
{
    dosya = fopen("bilgiler.txt","w");
    int i =0;
    if(dosya == NULL)
    {
        puts("Dosya Acilmadi\n");
        exit(1);
    }
    puts("Bilgileri Giriniz\n");
    do
    {
        i++;
        fflush(stdin);
        printf("%d . Ogrencinin Adi: ",i);
        gets(kisi.ad);
        printf("%d . Ogrencinin Numarasi: ",i);
        scanf("%d",&kisi.no);
        printf("%d . Ogrencinin Notu: ",i);
        scanf("%d",&kisi.Not);
        printf("\n");
        fprintf(dosya,"%d %s %d\n", kisi.no, kisi.ad, kisi.Not);
        puts("Yeni kayit icin bir tusa basiniz\nCikmak icin ""ESC"" tusunu kullanabilirsiniz");
    }while(getch() != 27);
    fclose(dosya);
    puts("Bilgiler kaydedildi\a");
    getch();
}
Listeleme()
{
    dosya = fopen("bilgiler.txt", "r");
    if(dosya == NULL)
    {
        puts("Dosya acilamadi\n");
        exit(1);
    }
    while(!feof(dosya))
    {
        fflush(stdout);
        fscanf(dosya,"%d %s %d\n", &kisi.no, kisi.ad, &kisi.Not);
        if(kisi.ad != NULL)
        {
            printf("\n");
            printf("%d %s %d", kisi.no, kisi.ad, kisi.Not);
        }
    }
    fclose(dosya);
    getch();
}
KayitSilme()
{

    printf("Silinecek ogrenci no: \n");
    scanf("%d",&no);
    dosya = fopen("bilgiler.txt","r");
    yedek = fopen("yedek.txt","a");
    if(!dosya)
        printf("Dosya acilamadi\n");
    while(!feof(dosya))
    {
        fscanf(dosya,"%d %s %d\n",&kisi.no, kisi.ad, &kisi.Not);
        if(no != kisi.no)
        {
            fprintf(yedek, "%d %s %d\n", kisi.no, kisi.ad, kisi.Not);
        }
        else
            durum = 1;
        }
        fclose(dosya);
        fclose(yedek);
        if(durum == 1)
        {
            puts("Kayit Silindi");
            remove("bilgiler.txt");
            rename("yedek.txt","bilgiler.txt");
            puts("\nIslem tamamlandi");
        }
        else
        {
            puts("Kayit Bulunamadi");
            remove("yedek.txt");
        }
        fflush(stdin);
        getch();
}
KayitArama()
{
    fflush(stdin);
    printf("\nOgrenci No: ");
    scanf("%d",&no);
    dosya = fopen("bilgiler.txt","r");
    if(!dosya)
    printf("Dosya acilamadi\n");
    durum = 1;
    while(!feof(dosya))
    {
        fscanf(dosya,"%d %s %d \n", &kisi.no, kisi.ad, &kisi.Not);
        if(no == kisi.no)
        {
            printf("%d %s %d", kisi.no, kisi.ad, kisi.Not);
            durum = 0;
        }
    }
    fclose(dosya);
    if(durum == 1)
        puts("Kayit Bulunamadi");
    getch();
}
KayitDegistir()
{
    printf("Degisiklik yapma istediginiz ogrenci no: ");
    scanf("%d", &no);
    dosya = fopen("bilgiler.txt","r");
    yedek = fopen("yedek.txt","w");
    if(!dosya) printf("Dosya acilamadi");
    durum = 0;
    while(!feof(dosya))
    {
        fscanf(dosya,"%d %s %d\n", &kisi.no, kisi.ad, &kisi.Not);
        if(no != kisi.no)
        {
            fprintf(yedek,"%d %s %d\n", kisi.no, kisi.ad, kisi.Not);
        }
        else if(no == kisi.no)
        {
            fflush(stdin);
            printf("Ogrencinin Adi: ");
            gets(kisi.ad);
            printf("Ogrencinin Numarasi: ");
            scanf("%d",&kisi.no);
            printf("Ogrencinin Notu: ");
            scanf("%d",&kisi.Not);
            printf("\n");
            fprintf(yedek,"%d %s %d\n",kisi.no, kisi.ad, kisi.Not);
            durum = 1;
        }
    }
    fclose(dosya);
    fclose(yedek);
    if(durum == 1)
    {
        printf("Degisiklik Yapildi");
        remove("bilgiler.txt");
        rename("yedek.txt","bilgiler.txt");
        puts("\nIslem tamamlandi");
    }
    else
    {
        puts("Kayit Bulunamadi");
        remove("yedek.txt");
    }
    fflush(stdin);
    getch();
}
degistir(char *isim,int nott)
{
    int karsilastirma;
    dosya = fopen("bilgiler.txt","r");
    yedek = fopen("yedek.txt","w");
    if(!dosya) printf("Dosya acilamadi");
    while(!feof(dosya))
    {
        fscanf(dosya,"%d %s %d\n", &kisi.no, kisi.ad, &kisi.Not);
        karsilastirma = strcmp(kisi.ad, isim);
        printf("%d",karsilastirma);
        if(karsilastirma !=0)
        {
            fprintf(yedek,"%d %s %d\n", kisi.no, kisi.ad, kisi.Not);
        }
        else if(karsilastirma == 0)
        {

            fprintf(yedek,"%d %s %d\n", kisi.no, kisi.ad, nott);
            durum = 1;
        }
    }
        fclose(dosya);
        fclose(yedek);
        if(durum == 1)
        {
            printf("Degisiklikler yapildi\n");
            remove("bilgiler.txt");
        rename("yedek.txt","bilgiler.txt");
            printf("Islem tamam\n");
        }
        else
        {
            printf("Isim bulunamadi\n");
            remove("yedek.txt");
        }
        fflush(stdin);
        getch();
}
