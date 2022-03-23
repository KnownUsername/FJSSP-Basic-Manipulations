#include "job.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

/// <summary>
/// Inserts values of 1 Job from a file
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
Job ImportJob(char filename[]) {

    Job job;
    job.operations = NULL;
    job.jobIdentifier = strcpy(job.jobIdentifier, "Ola");

    Operation* operationElement;
    Process process;

    Operation operation;

	FILE* fp;
    char processPlan[100], string2[100], string3[100], string4[100];
    int operationId;

    // Read file
	fp = fopen(filename, "r");

    // Verify if file exists
    //assert(fp);

    // Skip 1st line (columns' names)
    if (!feof(fp)) fscanf(fp, "%[^\,],%[^\,],%[^\,]\,%[^\n]\n", processPlan, string2, string3, string4);

    // Walk through file
    while (!feof(fp)) {

        fscanf(fp, "%[^\,]\,%d\,%d\,%d\n", processPlan, &operationId, &process.machine, &process.time); // Get fields from each line

        // Job ID
        job.jobIdentifier = strcpy(job.jobIdentifier, processPlan);

        // On operations that are already present on a job, simply add the new Process to it
        if (OperationExists(job.operations, operationId)) {

            // Find pointer to Operation inputted
            operationElement = SearchOperation(job.operations, operationId);

            // Insert new process on Operation
            operationElement->alternProcesses = InsertProcess(operationElement->alternProcesses, process);
        }

        // Add new Operation
        else {
            // Create new operation with associated Process on same file line
            operation = CreateOperation(operationId, InsertProcess(NULL, process));

            // Add new operation to the job
            job.operations = InsertOperation(job.operations, operation);
        }

    }

    // Delete file's buffer
    fclose(fp);

    return job;
}