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
    struct Dinozaur nowy;
    // char *gat = (char*)malloc(sizeof(char));
    // int *diet = (int*)malloc(sizeof(int));
    // float *m = (float*)malloc(sizeof(float));
    // int *zag = (int*)malloc(sizeof(int));
    // int *tem = (int*)malloc(sizeof(int));
    // int *sb = (int*)malloc(sizeof(int));
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
                fgets("%s",&nowy.gatunek,100);
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
                        wybordiety=nowy.dieta;
                    case 2:
                        printf("Wybrano roslinozerny!\n");
                        wybordiety=nowy.dieta;
                    case 3:
                        printf("Wybrano wszystkozerny!\n");  
                        wybordiety=nowy.dieta;                      
                };
                printf("Wprowadz mase: \n");
                scanf("%2.f",&nowy.masa);
                printf("Wprowadz numer zagrody: \n");
                scanf("%d",&nowy.zagroda);
                int wybor_temp;
                printf("Wybierz temperament obiektu:\n");
                printf("1. spokojny\n");
                printf("2. agresywny\n");
                printf("3. impulsywny\n");
                printf("4. nieprzewidywalny\n");
                printf("5. przewidywalny\n");
                scanf("%d",&wybor_temp);
                switch(wybor_temp){
                    default:
                        printf("Wybierz z 1-5!");
                    case 1:
                        printf("Wybrano spokojny!");
                        nowy.temperament = wybor_temp;
                    case 2:
                        printf("Wybrano agresywny!");
                        nowy.temperament = wybor_temp;
                    case 3:
                        printf("Wybrano impulsywny!");
                        nowy.temperament = wybor_temp;
                }







                printf("Wprowadz status bezpieczenstwa: \n");
                printf("1. bezpieczny\n");
                printf("2. pod obserwacja\n");
                printf("3. zagrozenie\n");
                printf("4. ucieczka\n");
                printf("5. awaryjna kwarantanna\n");
                int wybor_status;
                switch(wybor_status){
                    default:
                        printf("Wybierz z 1-5!\n");
                    case 1:
                        printf("Wybrano bezpieczny!\n");
                        wybor_status=nowy.status_bezpieczenstwa;
                    case 2:
                        printf("Wybrano pod obserwacja!\n");
                        wybor_status=nowy.status_bezpieczenstwa;
                    case 3:
                        printf("Wybrano zagrozenie!\n");  
                        wybor_status=nowy.status_bezpieczenstwa;
                    case 4:
                        printf("Wybrano ucieczka!");
                        wybor_status=nowy.status_bezpieczenstwa;
                    case 5:
                        printf("Wybrano awaryjna kwarantanna!");
                        wybor_status=nowy.status_bezpieczenstwa;                      
                };


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