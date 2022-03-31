/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: operation.c
	Intent:
		- Implement functions to manipulate 1 or more Processes
*/

#include "operation.h"
#include <stdio.h>

/// <summary>
/// Creates a Operation with given values
/// </summary>
/// <param name="opIdentifier"></param>
/// <param name="time"></param>
/// <returns></returns>
Operation CreateOperation(int opIdentifier, ProcessList* processList) {
	Operation createdElement;

	// Values' attribution
	createdElement.opIdentifier = opIdentifier;
	createdElement.alternProcesses = DuplicateProcessList(processList);

	return createdElement;
}

/// <summary>
/// Creates a OperationList 'element' with an Operation
/// </summary>
/// <param name="Operation"></param>
/// <returns></returns>
OperationList CreateOperationListElement(Operation Operation) {
	OperationList createdOperationList;

	// Values' attribution
	createdOperationList.operation = Operation;
	createdOperationList.nextOperation = NULL;

	return createdOperationList;
}

/// <summary>
/// Searches an Operation based on the id
/// </summary>
/// <param name="operationList"></param>
/// <param name="opIdentifier"></param>
/// <returns> Operation pointer if found or NULL if not found </returns>
OperationList* SearchOperation(OperationList* operationList, int opIdentifier) {

	// Run through Operation list
	while (operationList) {

		// Compare opIdentifiers' values
		if (operationList->operation.opIdentifier == opIdentifier) return operationList; // Operation found

		// Navigate to next Operation
		operationList = operationList->nextOperation;

	}

	return NULL;
}

/// <summary>
/// Verify if Operation exists on a list
/// </summary>
/// <param name="OperationList"></param>
/// <param name="opIdentifier"></param>
/// <returns> 1 -> True | 0 -> False </returns>
int OperationExists(OperationList* operationList, int opIdentifier) {

	// Search for Operation -> If found, it exists
	if (SearchOperation(operationList, opIdentifier)) return 1;

	return 0; // False

}


/// <summary>
/// Inserts a Operation on a list of Operations
/// </summary>
/// <param name="OperationList"></param>
/// <param name="opIdentifier"></param>
/// <param name="time"></param>
/// <returns></returns>
OperationList* InsertOperation(OperationList* operationList, Operation newOperation) {

	// Empty List
	if (!operationList) {

		// Unique element is the pointer to new element
		operationList = (OperationList*)malloc(sizeof(OperationList));
		operationList->operation = newOperation;
		operationList->nextOperation = NULL;

	}

	// List with elements
	else {

		// Check if Operation is already on operation
		if (!OperationExists(operationList, newOperation.opIdentifier)) {

			OperationList* lastElement = operationList;

			// Search last element on list
			while (lastElement->nextOperation) {
				lastElement = lastElement->nextOperation;
			}

			// Struture to store new element on list
			OperationList aux = CreateOperationListElement(newOperation);

			// Connect last element to new one, by pointers
			lastElement->nextOperation = (OperationList*)malloc(sizeof(OperationList));
			lastElement->nextOperation->operation = newOperation;
			lastElement->nextOperation->nextOperation = NULL;

		}
	}

	// Pointer to 1st element
	return operationList;
}

#pragma region DISPLAY

/// <summary>
/// Prints values of an Operation
/// </summary>
void ShowOperation(Operation operation) {
	printf("\tOperation %d\n", operation.opIdentifier);
	ShowProcessList(operation.alternProcesses);
}

/// <summary>
/// Prints values of operations on a list
/// </summary>
/// <param name="operationList"></param>
void ShowOperationList(OperationList* operationList) {
	while (operationList) {
		ShowOperation(operationList->operation);
		operationList = operationList->nextOperation;
	}
}
#pragma endregion

/// <summary>
/// Removes an operation from a list, given its identifier
/// </summary>
/// <param name="operationList"></param>
/// <param name="opIdentifier"></param>
/// <returns></returns>
OperationList* RemoveOperation(OperationList* operationList, int opIdentifier) {
	
	// For element on 1st position
	if (operationList && (operationList->operation.opIdentifier == opIdentifier)) {

		// Store next element, to be the new first element
		OperationList* aux = operationList->nextOperation;

		// Remove Processes from Operation (free memory)
		DeleteProcessList(operationList->operation.alternProcesses);

		// Free allocated memory on Operation
		free(operationList);

		// Aux (stored on line 167) became the first element of the list
		return aux;
	}

	// Keep stored 1st element, since it's the same, to retrieve
	OperationList* firstOperation = operationList;

	// Search on all elements
	while (operationList->nextOperation) {

		// Correspondence between next element's machine id and desired
		if (operationList->nextOperation->operation.opIdentifier == opIdentifier) {
			
			// Reach to next element, after the desired Operation
			OperationList* aux = operationList->nextOperation->nextOperation;

			// Remove Processes from Operation (free memory)
			DeleteProcessList(operationList->nextOperation->operation.alternProcesses);

			// Free allocated memory on Operation
			free(operationList->nextOperation);

			// Connect elements that were before and after deleted Operation
			operationList->nextOperation = aux;
			break;
		}

		// Pass to next element
		operationList = operationList->nextOperation;
	}

	return firstOperation;
}

/// <summary>
/// Changes the id of an Operation, on a list
/// </summary>
/// <param name="operationList"></param>
/// <param name="olderId"></param>
/// <param name="newId"></param>
/// <returns></returns>
int ChangeOperationIdOnList(OperationList* operationList, int olderId, int newId) {

	// Get operation, based on id
	OperationList* operation = SearchOperation(operationList, olderId);

	// If Operation not found, there's no id to change
	// This may occur because of empty lists
	if (!operation) return 0;

	// Attribution of new value
	operation->operation.opIdentifier = newId;
	return 1;
}

/// <summary>
/// Calculates average time of Operations, to complete a Process 
/// </summary>
/// <param name="operationList"></param>
/// <return>
/// -1 if NULL list or average of list
/// </return>
float CalculateAverageOperationProcessTime(OperationList* operationList) {
	
	// Variables initialized as 0 to sum values into them
	int count = 0, operationCounter = 0, sum = 0;
	float average;

	// -1 for empty list
	if (!operationList) return -1;

	// Navigate through list
	while (operationList) {

		// Get sum of times of 1 Operation and the count of values
		sum += SumAndCountTimesOnProcessList(operationList->operation.alternProcesses, &operationCounter);

		// Update counter with counter passed on previous function
		count += operationCounter;

		// Go to next Operation
		operationList = operationList->nextOperation;
	}
	
	// Average calcul
	average = (float)sum / count;

	return average;
}