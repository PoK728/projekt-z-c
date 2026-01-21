#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "innecosie.h"
void wyszukaj_po_nazwie(struct Dinozaur *d,int liczba_dino){
    while(getchar()!='\n');
    printf("%d",liczba_dino);
    char gat[100];
    int czy_liczba = 0;
    printf("==Wybrano wyszukiwanie po gatunku==\n");
    printf("Podaj nazwe gatunku lub jej fragment: \n");
    fgets(gat,sizeof(gat),stdin);
    gat[strcspn(gat,"\n")]=0;
    for(int i=0;gat[i]!='\0';i++){
    if(gat[i]>='0' && gat[i]<='9'){
        czy_liczba = 1;
        }
    }
    if(czy_liczba!=1){
    printf("==WYNIKI WYSZUKIWANIA==\n");
    for(int i=0;i<liczba_dino;i++){
    if(strstr(d[i].gatunek,gat)!=NULL){
    printf("Gatunek: %s, dieta: %s, masa: %.1f, zagroda: %d, temperament: %s, status bezpieczenstwa: %s\n",d[i].gatunek,Diety[d[i].dieta],d[i].masa,d[i].zagroda,Temperamenty[d[i].temperament],Statusy[d[i].status_bezpieczenstwa]);
    }
    else{
        printf("Brak wynikow!\n");
        break;
        }
       }    
    }
    else{
    printf("Wykryto liczbe!\n");
        while(getchar()!='\n');
    }
}
void wyszukaj_po_liczbie_dieta(struct Dinozaur *d,int liczba_dino){
    while(getchar()!='\n');
    int liczba;
    scanf("%d",&liczba);
    for(int i;i<liczba_dino;i++){
        if(d[i].dieta = liczba){
            printf("Gatunek: %s, dieta: %s, masa: %.1f, zagroda: %d, temperament: %s, status bezpieczenstwa: %s\n",d[i].gatunek,Diety[d[i].dieta],d[i].masa,d[i].zagroda,Temperamenty[d[i].temperament],Statusy[d[i].status_bezpieczenstwa]);
        }
    }
}
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
void wyszukaj_dino(struct Dinozaur *di, int liczba_dino){
    printf("==WYSZUKIWANIE==\n");
    while(1){
        int szukaj_opcja;
        printf("Wyszukaj po: \n");
        printf("1. Gatunek\n");
        printf("2. Dieta\n");
        printf("3. Masa\n");
        printf("4. Zagroda\n");
        printf("5. Temperament\n");
        printf("6. Status bezpieczenstwa\n");
        printf("0. Oposc wyszukiwanie\n");
        if(scanf("%d",&szukaj_opcja)==1){
            if(szukaj_opcja>=0 && szukaj_opcja<=6){
                switch(szukaj_opcja){
                    case 1:
                        wyszukaj_po_nazwie(struct Dinozaur *di,int liczba_dino);
                        break;
                    case 2:
                        wyszukaj_po_liczbie_dieta(struct Dinozaur *di,int liczba_dino);
                        break;
                    case 0:
                        printf("Opuszczono wyszukiwanie!\n");
                        break;
                }
                break;
            }
            else{
                printf("Podaj z zakresu 0-6!\n");
            }
        }
        else{
            printf("BLAD! WYKRYTO LITERE!\n");
        }
        break;
    }
}
