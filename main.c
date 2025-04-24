#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <jansson.h>
#include "simulation.h"

/**
 * The main entry point of the program.
 *
 * The program processes the input file and writes the result to an output file in JSON format.
 * 
 * @param argc Number of command line arguments.
 * @param argv An array of command line arguments. 
 *             Expected arguments:
 *             - argv[1]: input file name (with data).
 *             - argv[2]: name of output file (for JSON writing).
 * 
 * @return Returns EXIT_SUCCESS if the program completed successfully, or EXIT_FAILURE in case of an error.
 */
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char inputFilePath[256];
    snprintf(inputFilePath, sizeof(inputFilePath), "data/%s", argv[1]);

    char outputFilePath[256];
    snprintf(outputFilePath, sizeof(outputFilePath), "output/%s", argv[2]);

    mkdir("output", 0777);

    char command[512];
    snprintf(command, sizeof(command), "python3 scripts/parser.py %s", inputFilePath);

    FILE *fp = popen(command, "r");
    if(fp == NULL)
    {
        perror("Unable to run the command");
        return EXIT_FAILURE;
    }

    Simulation* simulation = simulation_create();

    char line[1024];
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        line[strcspn(line, "\n")] = 0;

        simulation_run(simulation, line);
    }

    pclose(fp);

    char *final_json = simulation_run(simulation, NULL);

    FILE *outputFile = fopen(outputFilePath, "w");
    if(outputFile)
    {
        fprintf(outputFile, "%s\n", final_json);
        fclose(outputFile);
        printf("JSON was written to the file: %s\n", outputFilePath);
    }
    else
    {
        perror("Unable to open output file");
    }

    free(final_json);

    simulation_destroy(simulation);
    return EXIT_SUCCESS;
}