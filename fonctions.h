#include "structures.h"

void initList(processList* l);
void updateAllProcessReady(processList* l, int clock);
int isAllProcessComplete(processList* l);
float TRM(processList* l);
float TAM(processList* l);
void Afficher(processList* l);
