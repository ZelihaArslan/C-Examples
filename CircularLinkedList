#include <stdio.h>
#include <stdlib.h>

struct puan
{
    unsigned dkod;
    char ders[20];
    unsigned vize, finall;
    struct puan *bag;
};
typedef struct puan puan;

puan *liste_olustur();
goster(puan *);
ekle(puan **);
sil(puan **);
int main()
{
    puan *p, *head;
    head = liste_olustur();
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
                sil(&head);
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
	getch();
    return 0;
}
puan *liste_olustur()
{
    int sayi,i;
    puan *p, *head;
    printf("Kac eleman girilecek\n");
    scanf("%d", &sayi);

    for(i=0; i<sayi; i++)
    {
        if(i==0)
        {
            head = (puan *)malloc(sizeof(puan));
            p = head;
        }
        else
        {
            p -> bag = (puan *)malloc(sizeof(puan));
            p = p->bag;

        }
        printf("\nDers Kodu: ");
        scanf("%d", &p->dkod);
        printf("Ders Adi: ");
        scanf("%s", p->ders);
        printf("Vize: ");
        scanf("%d", &p->vize);
        printf("Final: ");
        scanf("%d", &p->finall);

    }
    	p->bag = head;
	return (head);
}
goster(puan *head)
{
    puan *p;
    p = head;
    while(1)
	{
		printf("\nDers Kodu: %d Adi: %s Vize: %d Final: %d", p->dkod, p->ders, p->vize,p->finall);
		if(p->bag==head)
			break;
		else
			p = p->bag;
	}
getch();
}
ekle(puan **head)
{
    puan *p, *yeni,*q;
    p = *head;
    int sayi;
    printf("\nVerilei Giriniz\n");
    yeni= (puan *)malloc(sizeof(puan));
    printf("Ders kodu, Ders adi, Vize ve Final notu");
    scanf("%d %s %d %d", &yeni->dkod, yeni->ders, &yeni->vize, &yeni->finall);
    printf("\nHangi ders kodundan once eklenecek\n");
    scanf("%d",&sayi);
    if(p->dkod == sayi)
    {
        q = p;
        p = p-> bag;
        while(p->bag != q)
            p = p->bag;
        if(p->bag == q)
        {
            yeni -> bag = q;
            p -> bag = yeni;

            *head=yeni;
        }
    }
    else
    {
        while (p->dkod != sayi){
			q = p;
			p = p->bag;
			if(p == *head)
				break;
		}
        if(p == *head)
        {
            q->bag=yeni;
            yeni->bag = *head;
        }
        else if(p->dkod == sayi)
            {
                q->bag=yeni;
                yeni->bag=p;
            }
    }

}
sil(puan **head)
{
    puan *p, *q;
    p = *head;
    int sayi;
    printf("\nHangi ogrenci silinecek. Ders kodunu giriniz\n");
    scanf("%d", &sayi);

    if(p -> dkod == sayi)
    {
        q = p;

        p=p -> bag;
            while(p -> bag != q)
            {
                p = p -> bag;
            }
            if(p->bag ==q)
                {
                    p -> bag = q -> bag;
                    *head = q -> bag;
                    free(q);
                }
    }
    else
    {

        while(p -> dkod != sayi)
        {
            q = p;
            p = p->bag;
            if(p == *head)
				break;
        }
        if(p->dkod == sayi)
        {
            q -> bag = p -> bag;
            free(p);
        }
        else if(p == *head)
            printf("\nAranilan eleman bulunamadi\n");
    }
}
