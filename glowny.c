#include <stdio.h>

typedef enum { miesozerny,roslinozerny,wszystkozerny} Dieta;
typedef enum { spokojny,agresywny,impulsywny,nieprzewidywalny,przewidywalny} Temperament;
typedef enum { bezpieczny, pod_obserwacja, zagrozenie, ucieczka,awaryjna_kwarantanna} Status_bezpieczenstwa;

struct Dinozaur{
    char gatunek[100];
    Dieta dieta;
    float masa;
    int zagroda;
    Temperament temperament;
    Status_bezpieczenstwa status_bezpieczenstwa;
}; //zestaw cech obiektu 


int main(){
    int zmienna;
    char *gat = (char*)malloc(sizeof(char));
    int *diet = (int*)malloc(sizeof(int));
    float *m = (float*)malloc(sizeof(float));
    int *zag = (int*)malloc(sizeof(int));
    int *tem = (int*)malloc(sizeof(int));
    int *sb = (int*)malloc(sizeof(int));
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
                printf("Wybierz z 0-6!\n");
            case 1:
                printf("==REJESTRACJA==\n");
                while(1){
                printf("Podaj nazwe gatunku: \n");
                fgets("%s",&gat);
                int wybordiety;
                printf("Wybierz diete: \n");
                printf("1. miesozerny: \n");
                printf("2. roslinozerny: \n");
                printf("3. wszystkozerny: \n");
                scanf("%d",&wybordiety);
                switch(wybordiety){
                    default:
                        printf("Wybierz z 1-3!\n");
                    case 1:
                        printf("Wybrano miesozerny!\n");
                    case 2:
                        printf("Wybrano roslinozerny!\n");
                    case 3:
                        printf("Wybrano wszystkozerny!\n");                        
                }
                diet = wybordiety;
                printf("Wprowadz mase: \n");
                scanf("%f",&m);

                }
                break;
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