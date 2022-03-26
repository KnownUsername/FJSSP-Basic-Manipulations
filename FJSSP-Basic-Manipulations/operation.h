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

#pragma region STRUCTS

/// <summary>
/// Defines 1 Operation
/// </summary>
typedef struct Operation {
	int opIdentifier; 
	ProcessList *alternProcesses; // List of possible processes to complete an operation
}Operation;

/// <summary>
/// Defines a list of Operations
/// </summary>
typedef struct OperationList {
	Operation operation;
	struct OperationList* nextOperation;
}OperationList;

#pragma endregion

#pragma region FUNCTIONS


#pragma region CRUD
// Inserts a Operation on a list of Operations
OperationList* InsertOperation(OperationList* operationList, Operation newOperation);

// Creates a Operation with given values
Operation CreateOperation(int opIdentifier, ProcessList* processList);

// Removes an operation from a list, given its identifier
OperationList* RemoveOperation(OperationList* operationList, int opIdentifier);

// Changes the id of an Operation, on a list
int ChangeOperationIdOnList(OperationList* operationList, int olderId, int newId);

#pragma endregion

#pragma region PRINTS
// Prints values of an Operation
void ShowOperation(Operation operation);

// Prints values of operations on a list
void ShowOperationList(OperationList* operationList);

#pragma endregion


// Searches an Operation based on the id
OperationList* SearchOperation(OperationList* operationList, int opIdentifier);

// Verify if Operation exists on a list
int OperationExists(OperationList* operationList, int opIdentifier);

// Calculates average time of Operations, to complete a Process 
float CalculateAverageOperationProcessTime(OperationList* operationList);

#pragma endregion

#endif
