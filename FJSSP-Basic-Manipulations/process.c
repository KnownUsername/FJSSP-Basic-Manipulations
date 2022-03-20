/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: process.h
	Intent:
		- Implement functions to manipulate 1 or more Processes
*/

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
/// Searches a Process based on the id
/// </summary>
/// <param name="processList"></param>
/// <param name="machine"></param>
/// <returns> Process pointer if found or NULL if not found </returns>
ProcessList* SearchProcess(ProcessList* processList, int machine) {

	// Run through Operation list
	while (processList) {

		// Compare opIdentifiers' values
		if (processList->process.machine == machine) return processList; // Operation found

		// Navigate to next Operation
		processList = processList->nextProcess;

	}

	return NULL;
}

/// <summary>
/// Verify if process exists on a list
/// </summary>
/// <param name="processList"></param>
/// <param name="machine"></param>
/// <returns> 1 -> True | 0 -> False </returns>
int ProcessExists(ProcessList* processList, int machine) {

	// Search for Process -> If found, it exists
	if (SearchProcess(processList, machine)) return 1;

	return 0; // False

}

/// <summary>
/// Inserts a Process on a list of processes
/// </summary>
/// <param name="processList"></param>
/// <param name="newProcess"></param>
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
/// <param name="process"></param>
void ShowProcess(Process process) {

	// Display of each value of Process structure
	printf("Machine: %d\n", process.machine);
	printf("Time: %d\n\n", process.time);
}

/// <summary>
/// Shows values of processes on a list
/// </summary>
/// <param name="processList"></param>
void ShowProcessList(ProcessList* processList) {
	while (processList) {

		// Prints value of current Process
		ShowProcess(processList->process);

		// Pass to next element
		processList = processList->nextProcess;
	}
}

/// <summary>
/// Removes a process from a list, given its using machine
/// </summary>
/// <param name="processList"></param>
/// <param name="machineID"></param>
/// <returns></returns>
ProcessList* RemoveProcess(ProcessList* processList, int machineID) {

	// For element on 1st position
	if (processList && (processList->process.machine == machineID) ) {
		ProcessList* aux = processList->nextProcess;
		free(processList);
		return aux;
	}

	// Keep stored 1st element, since it's the same, to retrieve
	ProcessList* firstProcess = processList;

	// Search on all elements
	while (processList->nextProcess) {

		// Correspondence between next element's machine id and desired
		if (processList->nextProcess->process.machine == machineID) {

			// Reach to next element, after the desired Process
			ProcessList* aux = processList->nextProcess->nextProcess;

			// Free allocated memory on Process
			free(processList->nextProcess);

			// Connect elements that were before and after deleted Process
			processList->nextProcess = aux;
			break;
		}

		// Pass to next element
		processList = processList->nextProcess;
	}

	return firstProcess;
}

/// <summary>
/// Deletes a list (= removes all elements on the list, leaving it empty)
/// Recursive implementation
/// </summary>
/// <param name="processList"></param>
void DeleteProcessList(ProcessList* processList) {

	// Only free memory from existent elements
	if (processList) {

		// 'Iterate' till last element 
		DeleteProcessList(processList->nextProcess);

		// Free memory allocated from current Process
		free(processList);
	}
}