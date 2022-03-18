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
	int opIdentifier; 
	ProcessList alternProcesses; // List of possible processes to complete an operation
}Operation;

/// <summary>
/// Defines a list of Operations
/// </summary>
typedef struct OperationList {
	Operation operation;
	struct OperationList* nextOperation;
}OperationList;

// Inserts a Operation on a list of Operations
OperationList* InsertOperation(OperationList* operationList, Operation newOperation);

// Creates a Operation with given values
Operation CreateOperation(int opIdentifier, ProcessList processList);

// Prints values of an Operation
void ShowOperation(Operation operation);

// Prints values of operations on a list
void ShowOperationList(OperationList* operationList);

#endif
