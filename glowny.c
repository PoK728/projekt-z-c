#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void dodaj_dinozaura(struct Dinozaur *d){
    printf("==REJESTRACJA==\n");
    while(1){
        if(d==NULL){
            printf("BLAD! NIE WPISANO GATUNKU!"); //jak tego nie bedzie to mi blad wywala :(, to spr czy wprowadzene dane nie sa puste
        }
        printf("podaj gatunek: \n");
        if (fgets(d->gatunek, sizeof(d->gatunek), stdin) != NULL ) {
        d->gatunek[strcspn(d->gatunek, "\n")] = 0; // to usuwa enter, bo fgets go dopisuje, strcspn to usowa dany znak
        int liczba_w_gatunku=0;
        for(int i=0;d->gatunek[i]!='\0';i++){
            if(d->gatunek[i]>='0' && d->gatunek[i]<='9'){
                liczba_w_gatunku=1;
                break;
            }
        }
        if(liczba_w_gatunku==1){
            printf("BLAD! WYKRYTO LICZBE W NAZWIE!\n");
        }
        else{
            printf("dodano gatunek %s \n",d->gatunek);
            break;
        }
        }
    }
    while(1){
    printf("Wybierz diete: \n");
    printf("1. miesozerny: \n");
    printf("2. roslinozerny: \n");
    printf("3. wszystkozerny: \n");
        if(scanf("%d",&d->dieta)==1){
            if(d->dieta>=1 && d->dieta<=3){
            switch(d->dieta){
                case 1:
                    printf("Wybrano miesozerny!\n");
                    break;
                case 2:
                    printf("Wybrano roslinozerny!\n");
                    break;
                case 3:
                    printf("Wybrano wszystkozerny!\n");  
                    break;                   
            }
            break;
        }
        else{
            printf("Wybierz z przedzialu 1-3!\n");
            while(getchar()!='\n');
        }
        }
        else{
            printf("BLAD! WCZYTAJ LICZBE!\n");
            while(getchar()!='\n');
        }
    }
    while(1){
        printf("Podaj mase: \n");
        if(scanf("%f",&d->masa)==1){
            if(d->masa>0.00){
            printf("Dodano mase: %.1f\n",d->masa);
            break;
            }
            else{
                printf("Masa nie moze byc na minusie!\n");
                while(getchar()!='\n');
            }
        }
        else{
            printf("BLAD, wykryto litere! Podaj mase jeszcze raz!\n");
            while(getchar()!='\n');
        }
    }
    while(1){
        printf("Podaj numer zagrody: \n");
        if(scanf("%d",&d->zagroda)==1){
            if(d->zagroda>0){
                printf("Dodano do zagrony nr: %d\n",d->zagroda);
                break;
            }
            else{
                printf("Zagronda nie moze byc na minusie!\n");
            }
        }
        else{
            printf("BLAD, wykryto litere! Podaj jeszcze raz!\n");
        }
    }
    while(1){
        printf("Wybierz temperament obiektu:\n");
        printf("1. spokojny\n");
        printf("2. agresywny\n");
        printf("3. impulsywny\n");
        printf("4. nieprzewidywalny\n");
        printf("5. przewidywalny\n");
        if(scanf("%d",&d->temperament)==1){
            if(d->temperament>=1 && d->temperament<=5){
            switch(d->temperament){
            case 1:
                printf("Wybrano spokojny!\n");
                break;
            case 2:
                printf("Wybrano agresywny!\n");
                break;
            case 3:
                printf("Wybrano impulsywny!\n");
                break;
            case 4:
                printf("Wybrano nieprzewidywalny!\n");
                break;
            case 5:
                printf("Wybrano przewidywalny!\n");
                break;
            };
            break;
        }
        else{
            printf("Podaj z zakresu 1-5!\n");
            while(getchar()!='\n');
        }
        }
        else{
            printf("BLAD, wykryto litere!\n");
            while(getchar()!='\n');
        }
    }
    while(1){
        printf("Wprowadz status bezpieczenstwa: \n");
        printf("1. bezpieczny\n");
        printf("2. pod obserwacja\n");
        printf("3. zagrozenie\n");
        printf("4. ucieczka\n");
        printf("5. awaryjna kwarantanna\n");
        if(scanf("%d",&d->status_bezpieczenstwa)==1){
            if(d->status_bezpieczenstwa>=1 && d->status_bezpieczenstwa<=5){
                switch(d->status_bezpieczenstwa){
                    case 1:
                        printf("Wybrano bezpieczny!\n");
                        break;
                    case 2:
                        printf("Wybrano pod obserwacja!\n");
                        break;
                    case 3:
                        printf("Wybrano zagrozenie!\n");  
                        break;
                    case 4:
                        printf("Wybrano ucieczka!\n");
                        break;
                    case 5:
                        printf("Wybrano awaryjna kwarantanna!\n");
                        break;
            }
            break;
        }
        else{
            printf("Podaj liczbe z zakresu 1-5!\n");
            while(getchar()!='\n');
        }
    }
    else{
        printf("BLAD, wykryto litere!\n");
        while(getchar()!='\n');
    }
}
}
int main(){
    struct Dinozaur *park = NULL;
    int liczba_dino = 0;
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
        while (getchar() != '\n');
        switch(zmienna){
            default:
                printf("Wybierz z 0-6!\n");
            case 1:
                liczba_dino++;
                struct Dinozaur *temp = realloc(park,liczba_dino*sizeof(struct Dinozaur));
                if(&temp != NULL){
                    park = temp;
                    dodaj_dinozaura(&park[liczba_dino-1]);
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
    free(park);
    return 0;
}