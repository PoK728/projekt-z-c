#include <stdio.h>

struct Dinozaur{
    char gatunek[100];
    char dieta[20];
    float masa;
    int zagroda;
    char temperament[20];
    char status_bezpieczenstwa[20];
}; //zestaw cech obiektu 


int main(){
    int zmienna;
    while(1){
        printf("==Witaj w systemie zarzadzania parkiem dinozaurow==\n ");
        printf("Wybierz opcje: \n");
        printf("1. Rejestracja\n");
        printf("2. Wyszukaj\n");
        printf("3. Modyfikuj\n");
        printf("4. Sortuj\n");
        printf("5. Usun\n");
        printf("6. Zapisz/Odczytaj z pliku\n");
        printf("0. Wyjdz\n");
        scanf("%d",&zmienna);
        switch(zmienna){
            default:
                printf("Wybierz z 0-6!");
            case 1:

            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 0:
                printf("Do widzenia!\n");
                break;
        }
    }
    return 0;
}