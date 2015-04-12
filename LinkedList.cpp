#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct isimler{                 //Liste için struct yapı oluşturuyoruz ve kendi içerisinde çağırıyoruz. *sonraki 
                                //listenin diğer elemanını oluşturmamız için.
    int no;
    char isim[20];
    struct isimler *sonraki;
};
typedef struct isimler isimler; 
isimler *olusturma();
goster(isimler *);
ekle(isimler **);
silme(isimler **);
int main()
{
    isimler *head;                 //Liste başını kaybetmememiz gerekli. Bu nedenle bir pointer'a atıyoruz.
                                  //Bundan sonraki göster sil ekle işlemlerimizi head ile yapacağız.
    head=olusturma();
    char sec;
	do{
		system("cls");
		printf("1 - Ekle\n2 - Sil\n3- Goster\n4- Son\n\nSec :");
		sec = getche();
		switch (sec){
			case '1':
			    ekle(&head);
                goster(head);
                break;
			case '2':
			    silme(&head);
                goster(head);
                break;
            case '3':
				printf("\nKayitlar: ");
				goster(head);
                break;
			case '4':
				exit(1);
			break;
		}
	} while (1);



    return 0;
}
isimler *olusturma()
{
    int a,i;
    printf("Kac eleman girilecek\n");
    scanf("%d",&a);
    isimler *p, *head;

    for(i=0; i<a;i++)
    {
        if(i==0)     //i = 0 listenin başını oluşturuyoruz yani head
    {
        head = (isimler *)malloc(sizeof(isimler));    //Dinamik bir bellek alanı ayırıyoruz
        p = head;                                    
    }
     else
     {
         p->sonraki = (isimler *)malloc(sizeof(isimler));
         p = p -> sonraki;                            //Listenin diğer elemanlarını eklemek için artık p yi kullanıyoruz.
                                                      //Ve struct ta yazdığımız sonraki ile diğer elemana geçiyoruz.
     }
     printf("\n%d. Eleman\n",i+1);
     printf("No: ");
     scanf("%d", &p->no);
     printf("Adi:");
     scanf("%s", p->isim);

    }
    p->sonraki=NULL;                                //Liste sonunu NULL yapıyoruz. Listemizin bittiği anlamına geliyor.
    return head;
}
goster(isimler *head)                               
{
    isimler *p;
    p=head;
    int say=1;
    printf("\n");
    while(p != NULL)
    {
        printf("%d. Eleman: %d %s\n",say, p->no, p->isim);
        p = p -> sonraki;
        say++;
    }
    getch();
}
ekle(isimler **head)                      //En başa eklenme ihtimaline karşı head' ın tutulacağı yerin adresini aldık.
{
    int al;
    isimler *p, *yeni,*q;
    p = *head;
    printf("\nHangi no dan sonra\n");
    scanf("%d", &al);
    printf("Eklenecek Verileri Giriniz\n");
    yeni =(isimler *)malloc(sizeof(isimler));
    scanf("%d %s", &yeni->no, yeni->isim);

    if(p->no == al)
    {

        yeni -> sonraki = p;
        *head = yeni;
    }
    else
    {
        while((p!=NULL) && (p->no != al))              
        {
           q = p;
           p = p -> sonraki;

        }
        if(p==NULL)
        {
             q->sonraki = yeni;
            yeni->sonraki = NULL;
        }
         else if(p->no==al)
            {
                q-> sonraki = yeni;
                yeni->sonraki=p;
            }

        }
}
silme(isimler **head)
{
    int al;
    printf("\nSilinecek verinin no'yu giriniz\n");
    scanf("%d",&al);
    isimler *p, *q;
    p=*head;

    if(p->no == al)
    {

        *head = p->sonraki;
        free(p);
    }
    else
    {
        while((p!=NULL) && (p->no != al))
        {
           q = p;
           p = p -> sonraki;

        }
        if(p==NULL)
            printf("\nSilinecek oge bulunamadi");
        else if(p->no == al)
            {
                q -> sonraki = p->sonraki;
                free(p);

            }
    }
}
