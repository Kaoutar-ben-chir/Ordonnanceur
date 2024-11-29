#include "structures.h"
#include "fonctions.h"

process* chooseRunningProcess(processList* l)
{
	process* selectedProcess = NULL;

	for(int i=0; i<l->processNbr; i++)
	{
		if(l->allProcess[i].status == READY)
		{
			selectedProcess = l->allProcess + i;
			break;
		}
	}

	if(selectedProcess == NULL)
		return NULL;


	for(int i=0; i<l->processNbr; i++)
	{
		if(l->allProcess[i].status == READY &&
		   l->allProcess[i].arrivaleDate < selectedProcess->arrivaleDate)
		{
			selectedProcess = l->allProcess + i;
		}
	}

	return selectedProcess;
}

void start_FCFS_Processor (processList* l)
{
	int clock = 0;
	process* runningProcess = NULL;

	while (isAllProcessComplete(l) != 1)
	{
		updateAllProcessReady(l, clock);

		if(runningProcess != chooseRunningProcess(l))
		{
			runningProcess = chooseRunningProcess(l);

			if(runningProcess != NULL)
				l->contextChangeNbre++;
		}

		if(runningProcess != NULL)
		{
			clock++;
			runningProcess->realExecTime ++;
			runningProcess->status = RUNNING;

			l->execString[strlen(l->execString)+1] = '\0';
			l->execString[strlen(l->execString)] = runningProcess->processName;

			if(runningProcess->realExecTime == runningProcess->execTime)
			{
				runningProcess->status = ZOMBIE;
				runningProcess->endDate = clock;
			}
		}
		else
		{
			clock++;
		}
	}

}
