/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: operation.h
	Intent:
		- Define needed structures for operations
		- Identify functions to manipulate those structures
*/

#ifndef OPERATION
#define OPERATION

#include "process.h"

/// <summary>
/// Defines 1 Operation
/// </summary>
typedef struct Operation {
	int opIdentifier; // assuming identifier can only assume integer values
	ProcessList alternProcesses; // List of possible processes to complete an operation
}Operation;

/// <summary>
/// Defines a list of Operations
/// </summary>
typedef struct OperationList {
	Operation op;
	struct OperationList* nextOperation;
}OperationList;
#endif
