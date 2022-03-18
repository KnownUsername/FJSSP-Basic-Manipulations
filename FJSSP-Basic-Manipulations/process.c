#include "process.h"
#include <stdlib.h>

/// <summary>
/// Creates a Process with given values
/// </summary>
/// <param name="machine"></param>
/// <param name="time"></param>
/// <returns></returns>
Process CreateProcess(int machine, int time) {
	Process createdElement;

	// Values' attribution
	createdElement.machine = machine;
	createdElement.time = time;

	return createdElement;
}

/// <summary>
/// Creates a ProcessList 'element' with a Process
/// </summary>
/// <param name="process"></param>
/// <returns></returns>
ProcessList CreateProcessListElement(Process process) {
	ProcessList createdProcessList;

	// Values' attribution
	createdProcessList.process = process;
	createdProcessList.nextProcess = NULL;

	return createdProcessList;
}

/// <summary>
/// Verify if process exists on a list
/// </summary>
/// <param name="processList"></param>
/// <param name="machine"></param>
/// <returns> 1 -> True | 0 -> False </returns>
int ProcessExists(ProcessList* processList, int machine) {

	// Run through process list
	while (processList) {

		// Compare machines' values
		if (processList->process.machine == machine) return 1; // True

		// Navigate to next process
		processList = processList->nextProcess;

	}

	return 0; // False

}

/// <summary>
/// Inserts a Process on a list of processes
/// </summary>
/// <param name="processList"></param>
/// <param name="machine"></param>
/// <param name="time"></param>
/// <returns></returns>
ProcessList* InsertProcess(ProcessList* processList, Process newProcess) {
	
	// Empty List
	if (!processList) {

		// Struture to store new element on list
		//ProcessList aux = CreateProcessListElement(newProcess);
		
		// Unique element is the pointer to new element
		processList = (ProcessList*)malloc(sizeof(ProcessList));
		processList->process = newProcess;
		processList->nextProcess = NULL;

	}

	// List with elements
	else {

		// Check if process is already on operation
		if (!ProcessExists(processList, newProcess.machine)) {
			
			ProcessList* lastElement = processList;

			// Search last element on list
			while (lastElement->nextProcess) {
				lastElement = lastElement->nextProcess;
			}

			// Struture to store new element on list
			ProcessList aux = CreateProcessListElement(newProcess);
			
			// Connect last element to new one, by pointers
			//lastElement->nextProcess = &aux;
			
			lastElement->nextProcess = (ProcessList*)malloc(sizeof(ProcessList));
			lastElement->nextProcess->process = newProcess;
			lastElement->nextProcess->nextProcess = NULL;

		}
	}

	// Pointer to 1st element
	return processList;
}

/// <summary>
/// Prints values of a Process
/// </summary>
void ShowProcess(Process process) {
	printf("Machine: %d\n", process.machine);
	printf("Time: %d\n\n", process.time);
}

/// <summary>
/// Shows values of processes on a list
/// </summary>
/// <param name="processList"></param>
void ShowProcessList(ProcessList* processList) {
	while (processList) {
		ShowProcess(processList->process);
		processList = processList->nextProcess;
	}
}