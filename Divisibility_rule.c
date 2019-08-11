#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *plik0;
    FILE *plik2;
    FILE *plik3;
    FILE *plik5;
    plik0 = fopen("0.txt","w+");
    plik2 = fopen("2.txt","w+");
    plik3 = fopen("3.txt","w+");
    plik5 = fopen("5.txt","w+");

    if(plik0==NULL)
    {
        printf("Couldn't create file");
        return 5;
    }
    else if (plik2==NULL)
    {
        printf("Couldn't create file");
        fclose(plik0);
        return 5;
    }
    else if (plik3==NULL)
    {
        printf("Couldn't create file");
        fclose(plik0);
        fclose(plik2);
        return 5;
    }
        else if (plik5==NULL)
    {
        printf("Couldn't create file");
        fclose(plik0);
        fclose(plik2);
        fclose(plik3);
        return 5;
    }
    printf("Podaj liczby\n");
    for (int i=0; ; i++)
    {
        int liczba;
        scanf("%d", &liczba);
        if (liczba == 0)
        {
            break;
        }
        else if (liczba%2==0)
        {
            fprintf(plik2, "%d\n", liczba);
            if (liczba%3==0)
            {
                fprintf(plik3, "%d\n", liczba);
                if (liczba%5==0) fprintf(plik5, "%d\n", liczba);
            }
            else if (liczba%5==0)
            fprintf(plik5, "%d\n", liczba);
        }
        else if (liczba%3==0)
        {
            fprintf(plik3, "%d\n", liczba);
            if (liczba%5==0) fprintf(plik5, "%d\n", liczba);
        }
        else if (liczba%5==0)
            fprintf(plik5, "%d\n", liczba);
        else fprintf(plik0, "%d\n", liczba);
    }
    fclose(plik0);
    fclose(plik2);
    fclose(plik3);
    fclose(plik5);
    printf("Files saved");
    return 0;
}
