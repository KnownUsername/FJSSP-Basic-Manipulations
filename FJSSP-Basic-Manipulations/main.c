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
	Process newProcess = CreateProcess(1, 3);

	Process secondProcess = CreateProcess(2, 3);

	ProcessList* processList = NULL;
	processList = InsertProcess(processList, newProcess);


	if (InsertProcess(processList, secondProcess)) {

		newProcess.machine = 6;
		newProcess.time = 1;
		InsertProcess(processList, newProcess);

		//ShowProcessList(processList);

	}
	else printf("Unsucessfull");

	processList = RemoveProcess(processList, 1);

	ShowProcessList(processList);

	Operation operation;
	operation = CreateOperation(1, *processList);

	Operation operation2 = CreateOperation(2, *processList);


	OperationList* operations = NULL;
	operations = InsertOperation(operations, operation);
	InsertOperation(operations, operation2);

	//ShowOperation(operation);
	ShowOperationList(operations);
	
	return 0;
}