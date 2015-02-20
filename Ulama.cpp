#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, k = 0;
    char cumle[200];
    int kontrol = 0;
    printf("Ulama icin bir cumle giriniz\n");
    char sessiz[42]="BCÇDFGĞHJKLMNPRSŞTVYZbcçdfgğhjklmnprsştvyz";
    gets(cumle);

    for(i = 0; cumle[i] != '\0'; i++ )
    {
         if(cumle[i] == ' ' && cumle[i+1] != ' ')
            {
            for(k =0; k < 43; k++)
                {
                    if(cumle[i-1] == sessiz[k] && cumle[i+1] != sessiz[k])
                        kontrol++;
                }
            }
    }
    if(kontrol > 0)
        printf("Ulama vardir.");
    else
        printf("Ulama yoktur.");

    return 0;
}

