#include "structures.h"
#include "fonctions.h"

process* chooseshorterProcess(processList* l, int currentTime)
{
    process* shortestProcess = NULL;
    int shortestTime = 1000 ;

    for (int i = 0; i < l->processNbr; i++)
    {
        if (l->allProcess[i].status == READY )
        {
            if (l->allProcess[i].execTime < shortestTime)
            {
                shortestTime = l->allProcess[i].execTime;
                shortestProcess = &l->allProcess[i];
            }
        }
    }

    return shortestProcess;
}

void start_SPF_Processor(processList* l)
{
    int clock = 0;
    process* runningProcess = NULL;

    while (isAllProcessComplete(l) != 1)
    {
        updateAllProcessReady(l, clock);

        if (runningProcess != NULL && runningProcess->realExecTime == runningProcess->execTime)
        {
            runningProcess->status = ZOMBIE;
            runningProcess->endDate = clock;
            runningProcess = NULL;
        }

        if (runningProcess == NULL)
        {
            runningProcess = chooseshorterProcess(l, clock);
            if (runningProcess != NULL)
                l->contextChangeNbre++;
        }

        if (runningProcess != NULL)
        {
            clock++;
            runningProcess->realExecTime++;
            runningProcess->status = RUNNING;

            l->execString[strlen(l->execString)] = runningProcess->processName;
            l->execString[strlen(l->execString) + 1] = '\0';

            if (runningProcess->realExecTime == runningProcess->execTime)
            {
                runningProcess->status = ZOMBIE;
                runningProcess->endDate = clock;
                runningProcess = NULL;
            }
        }
        else
        {
            clock++;
        }
    }
}
