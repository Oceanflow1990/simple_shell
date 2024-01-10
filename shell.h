#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcnl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVER_UNSIGNED		2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number filed
 * @str: a string
 * @next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo argument to pass
 *@arg: string generated from getline
 *@argv: array of string generated
 *@path: a strgin path from te current command
 *@argc: string argument count
 *@line_count: the errorcount
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: program file name
 *@env: linkedlist local copy
 *@environ: custom modified copy
 *@history: thehistory node
 *@alias: the alias node
 *@env_changed: ....................
 *@status: ..........................
 *@cmd_buf: .....................................
 *@cmd_buf_type: ..........................
 *@readfd: ........................................
 *@histcount: the history line number count
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	lisr_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define FINO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0, }

/**
 * struct builtin - contain a built int string and reakted function
 * @type: the built in command flag
 * @func: the function
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;



/* shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* parser.c */
int is_cmd(info *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char);

/* loophsh.c */
int loophsh(char **);

/* errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, intfd);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
int _starts_with(const char *, const char *);
char *_strcat(char*, char *);

/* string1.c */
char *_strncpy(char *, char *);
char *_strncat(char *, char *);
char *_strchr(char *, char);

/* exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* tokenizer.c */
char **strtnow(char *, char *);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory */
int bfree(void **);

/* atoi.c */
int interactive(info_t /);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errors1.c */
int_erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int_myhelp(info_t *);

/* getline */
ssize_t get_input(info_t *);
int _getline(info_t, char **, size_t);
void sigintHandler(int);

/* builtin1.c */
int _myhistory(infot_t *);
int _myalias(info_t *);

/* getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* getenv.c */
char **getenviron(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* history.c */
char *gethistory_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history(info_t *info, char *buf, int lincount);
int renumber_history(info_t *info);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists1.c */
size_tlist_len(const list_t);
char **list_to_strings(lists_t *);
size_t prints_lists(const list_t *);
list_t *node_starts_width(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* vars.c */
int is_chain(info_t *, size_t *);
void check_chain(info_t *, char *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(infot_t);
int replace_string(char **, char *);

#endif
