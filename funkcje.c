#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "innecosie.h"

void wyszukaj_po_liczbie(struct Dinozaur *glowa,int liczba_dino,int szukana){
    if(glowa == NULL){
        printf("Baza pusta!\n");
        return;
    }
    while(getchar()!='\n');
    printf("Podaj szukana wartosc: ");
    int liczba;
    float liczba2;
    if(szukana==3){
        if(scanf("%f",&liczba2)!=1){
            printf("podano litere!\n");
            while(getchar()!='\n');
            return;
        }
    }
    else{
        if(scanf("%d",&liczba)!=1){
            printf("Podano litere!\n");
            while(getchar()!='\n');
            return;
        }
        if(szukana==2 && liczba<=0 || liczba>=5){printf("BLAD W WARTOSCI\n"); return;}
        if(szukana==5 && liczba<=0 || liczba>=6){printf("BLAD W WARTOSCI\n"); return;}
        if(szukana==6 && liczba<=0 || liczba>=6){printf("BLAD W WARTOSCI\n"); return;}
    }
    printf("=====WYNIKI WYSZUKIWANIA=====\n");
    struct Dinozaur *obecny = glowa;
    int znaleziono = 0;
    while(obecny!=NULL){
        int pasuje = 0;
        switch(szukana){
        case 2: 
            if(obecny->dieta == liczba){
                pasuje=1;
            }
            break;
        case 3:
            if(obecny->masa == liczba2){
                pasuje=1;
            }
            break ;
        case 4:
            if(obecny->zagroda == liczba){
                pasuje=1;
            }
            break;
        case 5:
            if(obecny->temperament == liczba){
                pasuje=1;
            }
            break;
        case 6:
            if(obecny->status_bezpieczenstwa==liczba){
                pasuje=1 ;
            }
            break ;
        }
        if(pasuje==1){
        printf("Gatunek: %s, dieta: %s, masa: %.1f, zagroda: %d, temperament: %s, status bezpieczenstwa: %s\n",obecny->gatunek,Diety[obecny->dieta],obecny->masa,obecny->zagroda,Temperamenty[obecny->temperament],Statusy[obecny->status_bezpieczenstwa]);
        znaleziono=1;
        }
        obecny = obecny->nast;
    }
    if(znaleziono==0){
        printf("Brak wynikow!\n");
    }
    int stop;
    printf("\nNacisnij 0, aby wyjsc\n");
    while(scanf("%d",&stop)!=1||stop!=0){
        printf("BLAD! Nacijnij 0, aby wyjsc!\n");
        while(getchar()!='\n');
    }
}
void wyszukaj_po_nazwie(struct Dinozaur *glowa,int liczba_dino){
    if(glowa == NULL){
        printf("Baza pusta!\n");
        return;
    }
    while(getchar()!='\n');
    char gat[50];
    int znaleziono = 0;
    struct Dinozaur *obecny = glowa;
    printf("=====Wybrano wyszukiwanie po gatunku=====\n");
    printf("Podaj nazwe gatunku: \n");
    fgets(gat,sizeof(gat),stdin);
    gat[strcspn(gat,"\n")]=0;
    
    printf("=====WYNIKI WYSZUKIWANIA=====\n\n");
    
    while(obecny!=NULL){
        int pasuje=0;
        if(strstr(obecny->gatunek,gat)!=NULL){
        pasuje=1;
        }
        if(pasuje==1){
        printf("Gatunek: %s, dieta: %s, masa: %.1f, zagroda: %d, temperament: %s, status bezpieczenstwa: %s\n",obecny->gatunek,Diety[obecny->dieta],obecny->masa,obecny->zagroda,Temperamenty[obecny->temperament],Statusy[obecny->status_bezpieczenstwa]);
        znaleziono=1;
        }
        obecny = obecny->nast;
    }
    if(znaleziono==0){
        printf("Brak wynikow!\n");
    }
    int stop;
    printf("\nNacisnij 0, aby wyjsc\n");
    while(scanf("%d",&stop)!=1||stop!=0){
        printf("BLAD! Nacisnij 0, aby wyjsc!\n");
        while(getchar()!='\n');
    }
}
struct Dinozaur* dodaj_dinozaura(struct Dinozaur *glowa){
    struct Dinozaur *nowy = (struct Dinozaur*)malloc(sizeof(struct Dinozaur));
    printf("==REJESTRACJA==\n");
    while(1){
        if(nowy==NULL){
            printf("BLAD ALOKACJI!");
            return glowa;
        }
        printf("podaj gatunek: \n");
        if (fgets(nowy->gatunek, sizeof(nowy->gatunek), stdin) != NULL ) {
        nowy->gatunek[strcspn(nowy->gatunek, "\n")] = 0; // to usuwa enter, bo fgets go dopisuje, strcspn to usowa dany znak
        int liczba_w_gatunku=0;
        for(int i=0;nowy->gatunek[i]!='\0';i++){
            if(nowy->gatunek[i]>='0' && nowy->gatunek[i]<='9'){
                liczba_w_gatunku=1;
                break;
            }
        }
        for(int i=0;nowy->gatunek[i]!='\0';i++){
            nowy->gatunek[i]=(char)tolower((unsigned)nowy->gatunek[i]);
        }
        if(liczba_w_gatunku==1){
            printf("BLAD! WYKRYTO LICZBE W NAZWIE!\n");
        }
        else{
            printf("dodano gatunek %s \n",nowy->gatunek);
            break;
        }
        }
    }
    while(1){
    printf("Wybierz diete: \n");
    printf("1. miesozerny: \n");
    printf("2. roslinozerny: \n");
    printf("3. wszystkozerny: \n");
        if(scanf("%d",&nowy->dieta)==1){
            if(nowy->dieta>=1 && nowy->dieta<=3){
            switch(nowy->dieta){
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
        if(scanf("%f",&nowy->masa)==1){
            if(nowy->masa>0.00){
            printf("Dodano mase: %.1f\n",nowy->masa);
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
        if(scanf("%d",&nowy->zagroda)==1){
            if(nowy->zagroda>0){
                printf("Dodano do zagrony nr: %d\n",nowy->zagroda);
                break;
            }
            else{
                printf("Zagronda nie moze byc na minusie!\n");
                while(getchar()!='\n');
            }
        }
        else{
            printf("BLAD, wykryto litere! Podaj jeszcze raz!\n");
            while(getchar()!='\n');
        }
    }
    while(1){
        printf("Wybierz temperament obiektu:\n");
        printf("1. spokojny\n");
        printf("2. agresywny\n");
        printf("3. impulsywny\n");
        printf("4. nieprzewidywalny\n");
        printf("5. przewidywalny\n");
        if(scanf("%d",&nowy->temperament)==1){
            if(nowy->temperament>=1 && nowy->temperament<=5){
            switch(nowy->temperament){
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
        if(scanf("%d",&nowy->status_bezpieczenstwa)==1){
            if(nowy->status_bezpieczenstwa>=1 && nowy->status_bezpieczenstwa<=5){
                switch(nowy->status_bezpieczenstwa){
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
nowy->nast = glowa;
return nowy;
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
                        printf("Wybrano wyszukiwanie po gatunku!\n");
                        wyszukaj_po_nazwie(di,liczba_dino);
                        break;
                    case 2:
                        printf("Wybrono wyszukiwanie po diecie!\n");
                        printf("Wybierz: 1 - Miesozerny, 2 - Roslinozerny, 3 - Wszystkozerny\n");
                        wyszukaj_po_liczbie(di,liczba_dino,szukaj_opcja);
                        break;
                    case 3:
                        printf("Wybrano wyszukiwanie po masie!\n");
                        wyszukaj_po_liczbie(di,liczba_dino,szukaj_opcja);
                        break;
                    case 4:
                        printf("Wybrano wyszukiwanie po zagrodzie!\n");
                        wyszukaj_po_liczbie(di,liczba_dino,szukaj_opcja);
                        break;
                    case 5:
                        printf("Wybrano wyszukiwanie po temperamencie!\n");
                        printf("Wybierz: 1 - Spokojny, 2 - Agresywny, 3 - Impulsywny, 4 - Nieprzewidywalny, 5 - Przewidywalny\n");
                        wyszukaj_po_liczbie(di,liczba_dino,szukaj_opcja);
                        break;
                    case 6:
                        printf("Wybrano wyszukiwanie po statusie bezpieczeństwa!\n");
                        printf("Wybierz: 1 - Bezpieczny, 2 - Pod obserwacja, 3 - Zagrozenie, 4 - Ucieczka, 5 - Awaryjna kwarantanna\n");
                        wyszukaj_po_liczbie(di,liczba_dino,szukaj_opcja);
                        break;
                    case 0:
                        printf("Opuszczono wyszukiwanie!\n");
                        break;
                }
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
struct Dinozaur* odczyt_z_pliku(const char* sciezka){
    FILE* plik = fopen(sciezka,"r");
    if(plik == NULL){
        printf("BLAD ODCZYTU Z PLIKU!");
        return NULL;
    }
    struct Dinozaur *glowa = NULL;
    struct Dinozaur *nowy = NULL;
    while(!feof(plik)){
        nowy = (struct Dinozaur*)malloc(sizeof(struct Dinozaur));
        if(nowy == NULL){
            break;
        }
        if(fscanf(plik,"%s %d %f %d %d %d\n",nowy->gatunek,&nowy->dieta,&nowy->masa,&nowy->zagroda,&nowy->temperament,&nowy->status_bezpieczenstwa)==6){
            nowy->nast=glowa;
            glowa = nowy;
        }
        else{
            free(nowy);
        }
    }
    fclose(plik);
    printf("Dane zostaly wczytane!\n");
    return glowa;
}
void zapis_do_pliku(struct Dinozaur *glowa,const char* sciezka){
    FILE* plik = fopen(sciezka,"w");
    if(plik == NULL){
        printf("BLAD PLIKU!");
        return;
    }
    struct Dinozaur *obecny = glowa;
    while(obecny != NULL){
        fprintf(plik,"%s %d %f %d %d %d\n",obecny->gatunek,obecny->dieta,obecny->masa,obecny->zagroda,obecny->temperament,obecny->status_bezpieczenstwa);
        obecny = obecny->nast;
    }
    fclose(plik);
    printf("Zapisano do pliku\n");
}
void odczyt_zapis(struct Dinozaur **glowa, const char* sciezka){
    printf("=====OBSLOGA PLIKOW=====\n");
    int zmienna;
    printf("1. Odczyt z pliku\n");
    printf("2. Zapis do pliku\n");
    printf("0. Wyjscie\n");
    if(scanf("%d",&zmienna)==1){
        if(zmienna>=0 && zmienna<=2){
            while(getchar()!='\n');
            switch(zmienna){
                case 1:
                    printf("Wybrano odczyt\n");
                    *glowa = odczyt_z_pliku(sciezka);
                    break;
                case 2:
                    printf("Wybrano zapis!\n");
                    zapis_do_pliku(*glowa,sciezka);
                    break;
                case 0:
                    printf("Opuszczono osbloge plikow!\n");
                    break;
            }
        }
        else{
            printf("Wybierz z zakresu 0-2!\n");
        }
    }
    else{
        printf("BLAD, sprobuj jeszcze raz!\n");
    }
}