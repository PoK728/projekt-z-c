#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef INNECOSIE_H
#define INNECOSIE_H
//enumy
typedef enum { brak,miesozerny,roslinozerny,wszystkozerny} Dieta;
typedef enum { brakuje,spokojny,agresywny,impulsywny,nieprzewidywalny,przewidywalny} Temperament;
typedef enum { braki,bezpieczny, pod_obserwacja, zagrozenie, ucieczka,awaryjna_kwarantanna} Status_bezpieczenstwa;
//slowniki
const char* Diety[] = {"Brak","Miesozerny","Roslinozerny","Wszystkozerny"};
const char* Temperamenty[] = {"Brak","Spokojny","Agresywny","Impulsywny","Nieprzewidywalny","Przewidywalny"};
const char* Statusy[] = {"Brak","Bezpieczny","Pod obserwacja","Zagrozenie","Ucieczka","Awaryjna kwarantanna"};


struct Dinozaur{
    char gatunek[100];
    Dieta dieta;
    float masa;
    int zagroda;
    Temperament temperament;
    Status_bezpieczenstwa status_bezpieczenstwa;
    struct Dinozaur *nast;
}; //zestaw cech obiektu 
#endif