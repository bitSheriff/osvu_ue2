#pragma once

/**
 * @file  common.h
 * @author  Benjamin Mandl (12220853)
 * @date 2023-11-07
 * @brief Stuff that every module needs
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

/* **** SHARED MEMORY **** */
#include <fcntl.h> /* For O_* constants */
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */

/** @brief Name of the shared memory file */
#define SHAREDMEM_FILE "sharedMem"

/*!
 * @struct shared_mem_flags_t
 * @brief   Bundle for all runtime and configuration flags
 *
 * @details
 *
 **/
typedef struct
{
    bool genActive; /*!< Flag that the generatros should be active */
} shared_mem_flags_t;

typedef struct
{
} shared_mem_circbuf_t;

typedef struct
{
    shared_mem_flags_t flags; /*!< All flags needed for the shared memory */

    shared_mem_circbuf_t circbuf; /*!< Bundle for the circular buffer */

} shared_mem_t;

/*!
 * @struct edge_t
 * @brief  Structre to store edges
 **/
typedef struct
{
    uint16_t v1; /*!< vertex 1 */
    uint16_t v2; /*!< vertex 2 */

} edge_t;

/* **** FUNCTIONS **** */
void emit_error(char* msg, error_t retCode);
