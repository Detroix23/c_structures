/**
 * # Structures : CLI arguments.
 * src/structures/lists.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "../../include/structures/cli.h"

void cli_match_tokens(
    size_t argc,
    char *argv[argc],
    size_t token_count,
    struct CliArgument tokens[token_count]
) {
    for (size_t i = 1; i < argc; i++) {
        bool used = false;
        for (size_t j = 0; j < token_count; j++) {
            if (strcmp(argv[i], tokens[j].string) == 0) {
                tokens[j].function();
                used = true;
                break;
            }
        }
        if (!used) printf(
            "(!) %s:%s() Unknown argument `%s`.\n",
            __FILE__, __func__, argv[i]
        );
    }

    return;
}