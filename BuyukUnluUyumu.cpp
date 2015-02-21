#include <stdio.h>
#include <string.h>

int main ()
{
    char kelime[50];
    int i = 0, j = 0, kalinSay = 0, inceSay = 0;
    char kalin[8]="AIOUaıou";
    char ince[8]="EİÖÜeiöü";
    printf("Buyuk unlu uyumu kontrol icin bir kelime girin\n");
    gets(kelime);

    for(i = 0; i <= strlen(kelime); i++)
    {
        for(j = 0; j <9; j++)
        {
            if(kelime[i] == kalin[j])
            {
                kalinSay++;
            }
            else if(kelime[i] == ince[j])
            {
                inceSay++;
            }
        }
    }

    if(inceSay != 0 && kalinSay == 0)
    {
        printf("Buyuk unlu uyumu vardir");
    }
    else if(kalinSay != 0 && inceSay == 0)
    {
        printf("Buyuk unlu uyumu vardir");
    }
    else
    {
        printf("Buyuk unlu uyumu yoktur");
    }

    return 0;
}

