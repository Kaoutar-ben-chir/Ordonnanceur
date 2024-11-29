#include "structures.h"
#include "fonctions.h"

process* chooseProcess(processList* l, int lastProcessIndex)
{

    for(int i = (lastProcessIndex + 1) % l->processNbr; i != lastProcessIndex; i = (i + 1) % l->processNbr)
    {
        if (l->allProcess[i].status == READY)
        {
            return &(l->allProcess[i]);
            break;
        }
    }
    return NULL;
}

void start_Tourniquet_Processor(processList* l)
{
    int clock = 0;
    int compteur = 0;
    int Q = 5;
    int indice = -1;

    strcat(l->execString, "Tc");

    while (!isAllProcessComplete(l))
    {
        updateAllProcessReady(l, clock);
        process* runningProcess = chooseProcess(l, indice);

        if (runningProcess != NULL)
        {
            clock++;
            runningProcess->realExecTime++;
            runningProcess->status = RUNNING;
            strncat(l->execString, &(runningProcess->processName), 1);

            if (runningProcess->realExecTime == runningProcess->execTime)
            {
                runningProcess->status = ZOMBIE;
                runningProcess->endDate = clock;
            }

            compteur++;

            if (compteur == Q || runningProcess->realExecTime == runningProcess->execTime)
            {
                l->contextChangeNbre++;
                strcat(l->execString, "Tc");
                compteur = 0;

                indice = (indice + 1) % l->processNbr;
            }
        }
        else
        {
            clock++;
        }
    }
}
