/**
 * # Structures : CLI arguments.
 * include/structures/lists.h
 */

/**
 * # `CliArgument` to structure parsing.
 * 
 * Fields : 
 * - `string` : `char *`;
 * - `function` : `void * (void)`;
 */
struct CliArgument {
    char *string;
    void (*function)(void);
};

/**
 * Match `tokens` to `argv` and execute the requested functions. 
 */
void cli_match_tokens(
    size_t argc,
    char *argv[argc],
    size_t token_count,
    struct CliArgument tokens[token_count]
);
