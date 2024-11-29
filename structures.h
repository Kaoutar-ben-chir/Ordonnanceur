#ifndef STRUCTURES_H
#define STRUCTURES_H

#define READY 0
#define RUNNING 1
#define BLOCKED 2
#define ZOMBIE 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char processName;
	int arrivaleDate;
	int execTime;
	int priority;

	int status;
	int realExecTime;
	int endDate;
} process;


typedef struct {
	process* allProcess;
	int processNbr;

	char execString[100];
	int contextChangeNbre;
} processList;

#endif
