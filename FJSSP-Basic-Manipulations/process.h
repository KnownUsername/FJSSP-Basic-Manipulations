/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: process.h
	Intent: 
		- Define needed structures for processes 
		- Identify functions to manipulate those structures
*/

#ifndef PROCESS
#define PROCESS

/// <summary>
/// Defines 1 process
/// </summary>
typedef struct Process{
	int machine; 
	int time; 
}Process;


/// <summary>
/// Defines a list of Processes
/// </summary>
typedef struct ProcessList {
	Process process;
	struct ProcessList* nextProcess;
}ProcessList;


/*		Methods		*/

#pragma region CRUD
// Creates a Process with given values
Process CreateProcess(int machine, int time);

// Inserts a process on a process list
ProcessList* InsertProcess(ProcessList* processList, Process newProcess);

// Removes a process from a list, given its using machine
ProcessList* RemoveProcess(ProcessList* processList, int machineID);

// Deletes a list (= removes all elements on the list, leaving it empty)
void DeleteProcessList(ProcessList* processList);

// Changes the machine of a Process, on a list
int ChangeProcessMachineOnList(ProcessList* processList, int oldMachine, int newMachine);

// Changes the time of a Process of a machine, on a list
int ChangeProcessTimeOnList(ProcessList* processList, int machine, int newTime);

// Deletes all Processes of a list, and inserts Processes from the other
ProcessList* ReplaceAllProcesses(ProcessList* oldProcessList, ProcessList* newProcessList);

#pragma endregion

// Duplicates a Process list
ProcessList* DuplicateProcessList(ProcessList* originalProcessList);


#pragma region PRINTS

// Prints values of a Process
void ShowProcess(Process process);

// Shows values of processes on a list
void ShowProcessList(ProcessList* processList);

#pragma endregion

// Retrieves Process with less duration
Process GetMinimumDurationProcess(ProcessList* processList);

// Retrieves Process with higher duration
Process GetMaximumDurationProcess(ProcessList* processList);

// Calculates average time of a list to complete a Process
float CalculateAverageProcessListTime(ProcessList* processList);

// Verify if process exists on a list
int ProcessExists(ProcessList* processList, int machine);

// Searches a Process based on the id
ProcessList* SearchProcess(ProcessList* processList, int machine);

// Searches all Processes on a list with same time value
ProcessList* SearchProcessesByTime(ProcessList* processList, int time);

// Sums times' values and counts the occurences
int SumAndCountTimesOnProcessList(ProcessList* processList, int* counter);

#endif