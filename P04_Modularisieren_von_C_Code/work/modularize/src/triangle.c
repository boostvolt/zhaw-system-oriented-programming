/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */

#include <stdio.h>
#include "read.h"
#include "rectang.h"

#define MAX_NUMBER 1000

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) on failure.
 */
int main(void) {
	// begin students to add code for task 4.1

    int word;
    int a;
    int b;
    int c;

    for (;;) {
        printf("\nDreiecksbestimmung (CTRL-C: Abbruch)\n\n");

        do {
            printf("Seite a: ");
            word = getInt(MAX_NUMBER);
        }
        while ((word < 0) && (word != READ_ERROR));
        if (word >= 0)
            a = word;
        else
            break;

        do {
           printf("Seite b: ");
           word = getInt(MAX_NUMBER);
        }
        while ((word < 0) && (word != READ_ERROR));
        if (word >= 0)
            b = word;
        else
            break;

        do {
            printf("Seite c: ");
            word = getInt(MAX_NUMBER);
        }
        while ((word < 0) && (word != READ_ERROR));
        if (word >= 0)
            c = word;
        else
            break;

        if (Rectangular(a, b, c) == true)
            printf("-> Dreieck %d-%d-%d ist rechtwinklig\n", a, b, c);
        else
            printf("-> Dreieck %d-%d-%d ist nicht rechtwinklig\n", a, b, c);
        printf("\n\n");
    }
    printf("\n\nbye bye\n\n");

	// end students to add code

    return 0;
}
