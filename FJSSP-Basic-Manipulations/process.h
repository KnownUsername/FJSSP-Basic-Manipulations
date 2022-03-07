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

// Defines 1 process
typedef struct Process{
	int machine; // assuming machine id can only assume integer values
	int time; // For now, assuming same as above
}Process;


/* Defines a list of Processes */
typedef struct ProcessList {
	Process process;
	struct ProcessList* nextProcess;
};
#endif