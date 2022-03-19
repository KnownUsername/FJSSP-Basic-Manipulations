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
	createdElement.alternProcesses = processList;

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
/// Verify if Operation exists on a list
/// </summary>
/// <param name="OperationList"></param>
/// <param name="opIdentifier"></param>
/// <returns> 1 -> True | 0 -> False </returns>
int OperationExists(OperationList* OperationList, int opIdentifier) {

	// Run through Operation list
	while (OperationList) {

		// Compare opIdentifiers' values
		if (OperationList->operation.opIdentifier == opIdentifier) return 1; // True

		// Navigate to next Operation
		OperationList = OperationList->nextOperation;

	}

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

/// <summary>
/// Prints values of an Operation
/// </summary>
void ShowOperation(Operation operation) {
	printf("Operation %d\n", operation.opIdentifier);
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

/// <summary>
/// Removes an operation from a list, given its identifier
/// </summary>
/// <param name="operationList"></param>
/// <param name="opIdentifier"></param>
/// <returns></returns>
OperationList* RemoveOperation(OperationList* operationList, int opIdentifier) {
	
	// For element on 1st position
	if (operationList && (operationList->operation.opIdentifier == opIdentifier)) {
		OperationList* aux = operationList->nextOperation;
		DeleteProcessList(operationList->operation.alternProcesses);
		free(operationList);
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