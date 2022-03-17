/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: Main.c
	Intent: Run code's functionalities

*/

#include "process.h"
#include "operation.h"
#include "job.h"
#include <stdio.h>

int main() {
	Process newProcess;
	newProcess.machine = 1;
	newProcess.time = 3;

	Process secondProcess;
	secondProcess.machine = 2;
	secondProcess.time = 3;

	ProcessList* processList = NULL;
	processList = InsertProcess(processList, newProcess);


	//if (InsertProcess(processList, newProcess)) {
	if (InsertProcess(processList, secondProcess)) {

		newProcess.machine = 6;
		newProcess.time = 1;
		InsertProcess(processList, newProcess);

		printf("Success");

		printf("1st Machine\n");
		printf("Process: %d\n", processList->process.machine);
		printf("Time: %d", processList->process.time);

		printf("\n\n2nd Machine\n");
		printf("Process: %d\n", processList->nextProcess->process.machine);
		printf("Time: %d", processList->nextProcess->process.time);

		printf("\n\n3rd Machine\n");
		printf("Process: %d\n", processList->nextProcess->nextProcess->process.machine);
		printf("Time: %d", processList->nextProcess->nextProcess->process.time);

	}
	else printf("Unsucessfull");

	Operation operation;
	operation = CreateOperation(1, *processList);

	Operation operation2 = CreateOperation(2, *processList);


	OperationList* operations = NULL;
	operations = InsertOperation(operations, operation);
	InsertOperation(operations, operation2);

	return 0;
}