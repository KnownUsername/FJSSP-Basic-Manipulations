/*
	Student: Jo�o Rodrigues
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

// Creates a Process with given values
Process CreateProcess(int machine, int time);

// Inserts a process on a process list
ProcessList* InsertProcess(ProcessList* processList, Process newProcess);

// Prints values of a Process
void ShowProcess(Process process);

// Shows values of processes on a list
void ShowProcessList(ProcessList* processList);
#endif