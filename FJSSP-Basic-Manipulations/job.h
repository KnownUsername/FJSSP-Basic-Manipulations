/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: job.h
	Intent:
		- Define needed structures for jobs
		- Identify functions to manipulate those structures
*/

#ifndef JOB
#define JOB

#include "operation.h"

#pragma region STRUCTURES

/// <summary>
/// Defines 1 job
/// </summary>
typedef struct Job {
	char* jobIdentifier; 
	OperationList* operations; // List of operations to complete a job
}Job;

/// <summary>
/// Defines a list of jobs
/// </summary>
typedef struct JobList {
	Job job;
	struct JobList* nextJob;
}JobList;

/// <summary>
/// Defines a Job with a Process established for each Operation,
/// instead of having all possibilities. 
/// 
/// It's also added the full duration of the Job.
/// </summary>
typedef struct JobProcess{
	Job job;
	int fullDuration;
}JobProcess;
#pragma endregion


#pragma region FUNCTIONS

// Inserts values of 1 Job from a file
Job LoadJob(char filename[], int* status);

// Calculates the minimum duration for a job and its respective path
JobProcess GetMinimumJobProcessLine(Job job);

// Calculates the maximum duration for a job and its respective path
JobProcess GetMaximumJobProcessLine(Job job);

// Saves job data into a csv file
int SaveJob(Job job, char filename[]);

// Prints values of a Job
void ShowJob(Job job);

// Prints values of a JobProcess
void ShowJobProcess(JobProcess jobProcess);

#pragma endregion

#endif