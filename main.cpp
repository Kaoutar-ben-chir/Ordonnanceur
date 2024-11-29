#include "structures.h"
#include "fonctions.h"
#include"FCFS.h"
#include "SPF.h"
#include "Tourniquet.h"



int main(int argc, char** argv) {

	processList l;

	initList(&l);

	start_FCFS_Processor(&l);
    printf("                   Ordennanceur FCFS:             \n\n");
	Afficher(&l);

	start_SPF_Processor(&l);
	printf("                     Ordennanceur SPF:\n \n");
	Afficher(&l);

	start_Tourniquet_Processor(&l);
	printf("                     Ordennanceur Tourniquet             \n\n");
	Afficher(&l);

	return 0;
}
