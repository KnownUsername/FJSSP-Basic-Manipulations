/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: process.c
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

		// Navigate to next Process
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

#pragma region DISPLAY
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
	puts("");
}

#pragma endregion

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

/// <summary>
/// Changes the machine of a Process, on a list
/// </summary>
/// <param name="processList"></param>
/// <param name="oldMachine"></param>
/// <param name="newMachine"></param>
/// <returns></returns>
int ChangeProcessMachineOnList(ProcessList* processList, int oldMachine, int newMachine) {

	// Get respective process, based on id
	ProcessList* foundProcess = SearchProcess(processList, oldMachine);
	
	// If Process not found, there's no machine to change
	// This may occur because of empty lists
	if (!foundProcess) return 0;

	// Attribution of new value
	foundProcess->process.machine = newMachine;

	return 1;
}

/// <summary>
/// Changes the time of a Process of a machine, on a list
/// </summary>
/// <param name="processList"></param>
/// <param name="machine"></param>
/// <param name="newTime"></param>
/// <returns></returns>
int ChangeProcessTimeOnList(ProcessList* processList, int machine, int newTime) {

	// Get respective process, based on id
	ProcessList* foundProcess = SearchProcess(processList, machine);

	// If Process not found, there's no machine to change
	// This may occur because of empty lists
	if (!foundProcess) return 0;

	// Attribution of new value
	foundProcess->process.time = newTime;

	return 1;
}

/// <summary>
/// Duplicates a Process list
/// </summary>
/// <param name="originalProcessList"></param>
/// <returns></returns>
ProcessList* DuplicateProcessList(ProcessList* originalProcessList) {

	ProcessList* cloneList = NULL;

	// Run through Process list
	while (originalProcessList) {

		// Copy correspondent Process to new list
		cloneList = InsertProcess(cloneList, originalProcessList->process);

		// Pass to next element
		originalProcessList = originalProcessList->nextProcess;
	}

	return cloneList;
}

/// <summary>
/// Deletes all Processes of a list, and inserts Processes from the other
/// </summary>
/// <param name="oldProcessList"></param>
/// <param name="newProcessList"></param>
/// <returns></returns>
ProcessList* ReplaceAllProcesses(ProcessList* oldProcessList, ProcessList* newProcessList) {

	// Free memory from list being replaced
	DeleteProcessList(oldProcessList);

	// Pass values from 1 list to another, creating a new one
	oldProcessList = DuplicateProcessList(newProcessList);

	return oldProcessList;
}

/// <summary>
/// Retrieves Process with less duration
/// </summary>
/// <param name="processList"></param>
/// <returns></returns>
Process GetMinimumDurationProcess(ProcessList* processList) {

	Process minimumProcess;

	// Minimum is initialized with 1st element from the list
	if (processList) minimumProcess = processList->process;
	else {

		// Attribute -1 to all fields - a value that makes no sense on them
		minimumProcess.machine = -1;
		minimumProcess.time = 0;
		return minimumProcess;
	}

	// Point to 2nd element, as 1st is already the starting point - no reason to compare with itself
	processList = processList->nextProcess;

	// Navigate through the list
	while (processList) {

		// Compare time values
		if (processList->process.time < minimumProcess.time)
			
			// Change minimum to current Process, which has less time consumption
			minimumProcess = processList->process;

		// Go to next Process
		processList = processList->nextProcess;
	}

	return minimumProcess;
}

/// <summary>
/// Retrieves Process with higher duration
/// </summary>
/// <param name="processList"></param>
/// <returns></returns>
Process GetMaximumDurationProcess(ProcessList* processList) {
	Process maximumProcess;
	
	// Maximum is initialized with 1st element from the list
	if (processList) maximumProcess = processList->process;
	else {

		// Attribute -1 to all fields - a value that makes no sense on them
		maximumProcess.machine = -1;
		maximumProcess.time = 0;
		return maximumProcess;
	}

	// Point to 2nd element, as 1st is already the starting point - no reason to compare with itself
	processList = processList->nextProcess;

	// Navigate through the list
	while (processList) {

		// Compare time values
		if (processList->process.time > maximumProcess.time)

			// Change maximum to current Process, which has higher time consumption
			maximumProcess = processList->process;

		// Go to next Process
		processList = processList->nextProcess;
	}

	return maximumProcess;
}


/// <summary>
/// Searches a Process based on time
/// </summary>
/// <param name="processList"></param>
/// <param name="machine"></param>
/// <returns> Process pointer if found or NULL if not found </returns>
ProcessList* SearchProcessByTime(ProcessList* processList, int time) {

	// Run through Operation list
	while (processList) {

		// Compare opIdentifiers' values
		if (processList->process.time == time) return processList; // Operation found

		// Navigate to next Process
		processList = processList->nextProcess;

	}

	return NULL;
}


/// <summary>
/// Searches all Processes on a list with same time value
/// </summary>
/// <param name="processList"></param>
/// <returns></returns>
ProcessList* SearchProcessesByTime(ProcessList* processList, int time) {

	// New list to store filtered Processes
	ProcessList* filteredList = NULL;

	// Go to first Process with given time
	processList = processList = SearchProcessByTime(processList, time);

	// Validate each Search
	while (processList) {

		filteredList = InsertProcess(filteredList, processList->process);

		// Find next Process with same time
		processList = SearchProcessByTime(processList->nextProcess, time);
	}

	return filteredList;
}

/// <summary>
/// Calculates average time of a list to complete a Process 
/// </summary>
/// <param name="processList"></param>
/// <returns> Average time on success or -1 when list is empty </returns>
float CalculateAverageProcessListTime(ProcessList* processList) {

	// Variables initialized as 0 to sum values into them
	int sum = 0, count = 0; 
	float averageTime;

	if (!processList) return -1;

	// Navigate throgh list
	while (processList) {

		// Add process's time value
		sum += processList->process.time;

		// Add 1 to the counter
		count += 1;

		// Go to next element
		processList = processList->nextProcess;
	}

	// Cast of float on 1 value, to obtain a float result
	averageTime = (float)sum / count;

	return averageTime;
}

/// <summary>
/// Sums times' values and counts the occurences
/// Count of values is returned via pointer
/// </summary>
/// <param name="processList"></param>
/// <param name="counter"></param>
/// <returns> Value of sum, on existent list </returns>
int SumAndCountTimesOnProcessList(ProcessList* processList, int* counter) {
	
	// Initialization as 0 to sum values
	int sum = 0;
	*counter = 0;

	// Walk through list
	while (processList) {
		
		// Add time from current Process
		sum += processList->process.time;

		// Update counter
		*counter += 1;
		
		// Go to next value
		processList = processList->nextProcess;
	}

	return sum;
}