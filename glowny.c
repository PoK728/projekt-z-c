#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.c"
#include "innecosie.h"

int main(){
    struct Dinozaur *park = NULL;
    int liczba_dino = 0;
    int zmienna;
    printf("==Witaj w systemie zarzadzania parkiem dinozaurow==\n ");
    while(1){
        printf("Wybierz opcje: \n");
        printf("1. Rejestracja\n");
        printf("2. Wyszukaj\n");
        printf("3. Modyfikuj\n");
        printf("4. Sortuj\n");
        printf("5. Usun\n");
        printf("6. Zapisz/Odczytaj z pliku\n");
        printf("0. Wyjdz\n");
        if(scanf("%d",&zmienna)==1){
            if(zmienna>=0 && zmienna<=6){
            switch(zmienna){
            case 1:
                while(getchar()!='\n');
                park = dodaj_dinozaura(park);
                break;
            case 2:
                while(getchar()!='\n');
                wyszukaj_dino(park,liczba_dino);
                break;
            case 3:
            
            case 4:

            case 5:

            case 6:

            case 0:
                printf("Do widzenia!\n");
                return 0;
            
        }
        }
        else{
            printf("Podaj liczbe z zakresu 0-6!\n");
            while (getchar() != '\n');
        }
        }
        else{
            printf("BLAD! PODANO LITERE!\n");
            while (getchar() != '\n');
        }
    }
    free(park);
    return 0;
}