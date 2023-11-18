/**
 * @file generator.c
 * @author  Benjamin Mandl (12220853)
 * @date 2023-11-07
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "debug.h"
#include "errors.h"

static void readEdges(edge_t* pEdges[], char** argv, ssize_t argc)
{
    // step through all the given parameters and parse the endges
    for (ssize_t i = 1U; i < argc; i++)
    {
        // the verticies are sepertaed with a dash, and the edges with a space
        if (sscanf(argv[i], "%hu-%hu", &((*pEdges)[i - 1].v1), &((*pEdges)[i - 1].v2)) < 0)
        {
            emit_error("Something went wrong with reading edges\n", 0U);
        }
    }
}

int main(int argc, char* argv[])
{
    debug("This is the generator\n", NULL);

    ssize_t edgeCnt = argc - 1U;                     /*!< number of given edges */
    edge_t* edges = calloc(sizeof(edge_t), edgeCnt); /*!< memory to store all edges */

    debug("Number of Edges: %ld\n", edgeCnt);

    // read the edges from the parameters
    readEdges(&edges, argv, argc);

    return EXIT_SUCCESS;
}
