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

	//Job job_test = ImportJob("../one_job.csv");
	//ShowOperationList(job_test.operations);


	Process newProcess = CreateProcess(1, 3);

	Process secondProcess = CreateProcess(2, 3);

	ProcessList* processList = NULL;
	processList = InsertProcess(processList, newProcess);


	if (InsertProcess(processList, secondProcess)) {

		newProcess.machine = 6;
		newProcess.time = 1;
		InsertProcess(processList, newProcess);

	}
	else printf("Unsucessfull");



	processList = RemoveProcess(processList, 6);

	Operation operation;
	operation = CreateOperation(1, processList);

	/*			Operation 2			*/	
	ProcessList* processList2 = NULL;
	processList2 = InsertProcess(processList2, CreateProcess(1, 5));
	InsertProcess(processList2, CreateProcess(3, 7));
	InsertProcess(processList2, CreateProcess(4, 2));

	ShowProcessList(processList2);
	Process higherTimeProcess = GetMaximumDurationProcess(processList2);
	ShowProcess(higherTimeProcess);


	Operation operation2 = CreateOperation(2, processList2);

	/*			Operation 3			*/
	ProcessList* processList3 = NULL;
	processList3 = InsertProcess(processList3, CreateProcess(2, 2));
	InsertProcess(processList3, CreateProcess(4, 3));
	InsertProcess(processList3, CreateProcess(5, 7));
	InsertProcess(processList3, CreateProcess(6, 8));

	Operation operation3 = CreateOperation(3, processList3);

	/*		List of Operations		*/
	OperationList* operations = NULL;
	operations = InsertOperation(operations, operation);
	InsertOperation(operations, operation2);
	InsertOperation(operations, operation3);

	ChangeOperationIdOnList(operations, 2, 5);
	ChangeProcessMachineOnList(SearchOperation(operations, 5)->operation.alternProcesses, 3, 6);
	ChangeProcessTimeOnList(SearchOperation(operations, 1)->operation.alternProcesses, 1, 13);

	operations->operation.alternProcesses = ReplaceAllProcesses(operations->operation.alternProcesses, processList3);
	processList3->process.machine = 13;

	// Removal of an operation
	//operations = RemoveOperation(operations, 3);

	//ShowOperationList(operations);
	
	Job job;

	job.jobIdentifier = 2;
	job.operations = operations;

	JobProcess jp;
	jp = GetMinimumJobProcessLine(job);

	printf(" \t\t >> Operations\n\n");
	ShowOperationList(operations);

	printf("\n\n \t\t >> Efficient Processes « \n\n");
	printf("Duration: %d\n\n", jp.fullDuration);
	ShowOperationList(jp.job.operations);
	//ImportJob("one_job.csv");

	return 0;
}