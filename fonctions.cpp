#include "fonctions.h"

void initList(processList* l)
{
	l->processNbr = 5;
	l->contextChangeNbre = 0;

	l->allProcess = (process*)malloc(l->processNbr * sizeof(process));

	l->allProcess[0].processName = 'A'; l->allProcess[0].execTime = 3; l->allProcess[0].arrivaleDate=0;
	l->allProcess[1].processName = 'B'; l->allProcess[1].execTime = 6; l->allProcess[1].arrivaleDate=1;
	l->allProcess[2].processName = 'C'; l->allProcess[2].execTime = 4; l->allProcess[2].arrivaleDate=4;
	l->allProcess[3].processName = 'D'; l->allProcess[3].execTime = 2; l->allProcess[3].arrivaleDate=6;
	l->allProcess[4].processName = 'E'; l->allProcess[4].execTime = 1; l->allProcess[4].arrivaleDate=7;

	for(int i=0; i<l->processNbr; i++)
	{
		l->allProcess[i].status = -1;
		l->allProcess[i].realExecTime = 0;
		l->allProcess[i].endDate = 0;
	}
	strcpy(l->execString, "");
}
void updateAllProcessReady(processList* l, int clock)
{
	for(int i=0; i<l->processNbr; i++)
	{
		if(l->allProcess[i].arrivaleDate <= clock &&
			l->allProcess[i].realExecTime < l->allProcess[i].execTime)
		{
			l->allProcess[i].status = READY;
		}
	}
}

int isAllProcessComplete(processList* l)
{
	for(int i=0; i<l->processNbr; i++)
	{
		if(l->allProcess[i].status != ZOMBIE)
		{
			return 0;
		}
	}

	return 1;
}

float TRM(processList* l)
{
	int s = 0;

	for(int i=0; i<l->processNbr; i++)
	{
		s += (l->allProcess[i].endDate - l->allProcess[i].arrivaleDate);
	}

	return (float)s/l->processNbr;
}

float TAM(processList* l)
{
	int s = 0;

	for(int i=0; i<l->processNbr; i++)
	{
		s += (l->allProcess[i].endDate - l->allProcess[i].arrivaleDate - l->allProcess[i].execTime);
	}

	return (float)s/l->processNbr;
}

void Afficher(processList* l)
 {
 	printf("Exec String = %s, Nbre de changement de context = %d \n", l->execString, l->contextChangeNbre);
 	printf("TRM = %.2f, TAM = %.2f \n", TRM(l), TAM(l));

 	printf("\n##### Porcess #######\n\n");

 	for(int i=0; i<l->processNbr; i++)
	{
		printf("Process %c, D.arrivee = %d, D.exec = %d, status = %d, R.exec = %d, D.end = %d \n",
		l->allProcess[i].processName, l->allProcess[i].arrivaleDate, l->allProcess[i].execTime,
		l->allProcess[i].status, l->allProcess[i].realExecTime, l->allProcess[i].endDate );
	}

 }
 // Les processus pour le Tourniquet
/*void initList(processList* l)
{
	l->processNbr = 3;
	l->contextChangeNbre = 0;

	l->allProcess = (process*)malloc(l->processNbr * sizeof(process));

	l->allProcess[0].processName = 'A'; l->allProcess[0].execTime = 8; l->allProcess[0].arrivaleDate=0;
	l->allProcess[1].processName = 'B'; l->allProcess[1].execTime = 8; l->allProcess[1].arrivaleDate=3;
	l->allProcess[2].processName = 'C'; l->allProcess[2].execTime = 4; l->allProcess[2].arrivaleDate=4;

	for(int i=0; i<l->processNbr; i++)
	{
		l->allProcess[i].status = -1;
		l->allProcess[i].realExecTime = 0;
		l->allProcess[i].endDate = 0;
	}
	strcpy(l->execString, "");

}*/
