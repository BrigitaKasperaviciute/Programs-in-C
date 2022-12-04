/*Autore: Brigita Kasperavičiūtė
Programos paskirtis: pagal vartotojo įvestą sveiką skaičių (X) apskaičiuoti ir išvesti
visus sekos {Xn} narius iki pirmojo vieneto.*/
#include <stdio.h>
int main()
{
    double X_0; // vartotojo ivestas bet koks skaicius
    int X;      // vartotojo ivestas tinkamas sveikasis skaicius
    int kiek_nariu_spausdinti, kiek_nariu_dar_spausdinti, atspausdinti_nariai = 0, ar_baigtas_spausdinimas = 0;
    printf("Iveskite sveika skaiciu, kuris bus pirmasis sekos narys.\n");
    do
    {
        if ((scanf("%lf", &X_0) == 1) && (getchar() == '\n') && (X_0 == (int)X_0))
        {
            printf("Ivestas tinkamas skaicius\n");
            break;
        }
        else
        {
            printf("Netinkama ivestis! Iveskite sveika skaiciu\n");
            while (getchar() != '\n')
                ;
        }
    } while (X_0 != (int)X_0);
    X = (int)X_0;
    if (X > 0)
    {
        printf("Seka:\n%d\n", X);
        while (X != 1)
        {
            if (X % 2 == 0)
                X = X / 2;
            else
                X = 3 * X + 1;
            printf("%d\n", X);
        }
    }
    else
    {
        printf("Seka yra begaline. Parasykite, kiek nariu norite atspausdinti\n");
        scanf("%d", &kiek_nariu_spausdinti);
        printf("Seka:\n%d\n", X);
        while (ar_baigtas_spausdinimas == 0)
        {
            while (atspausdinti_nariai != kiek_nariu_spausdinti)
            {
                if (X % 2 == 0)
                    X = X / 2;
                else
                    X = 3 * X + 1;
                printf("%d\n", X);
                atspausdinti_nariai++;
            }
            printf("Ar norite isvesti daugiau sekos nariu?\nJei taip iveskite, kiek nariu dar norite atspausdinti.\nJei ne, rasykite 0.\n");
            scanf("%d", &kiek_nariu_dar_spausdinti);
            if (kiek_nariu_dar_spausdinti > 0)
            {
                kiek_nariu_spausdinti += kiek_nariu_dar_spausdinti;
            }
            else
            {
                ar_baigtas_spausdinimas++;
                printf("Norima seka isvesta. Programa baige darba.\n");
            }
        }
    }
    return 0;
}
