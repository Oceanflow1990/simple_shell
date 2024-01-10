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
#include <fcntl.h>
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
	list_t *history;
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
int hsh(info_t *info, char **v);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);

/* parser.c */
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);

/* loophsh.c */
int loophsh(char **);

/* errors.c */
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string.c */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *heystack, const char *nidle);
char *_strcat(char *d, char *s);

/* string1.c */
char *_strncpy(char *d, char *s);
char *_strdup(const char *str);
void _puts(char *s);
int _putchar(char c);

/* exits.c */
char *_strncpy(char *dest, char *src, int n;
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);

/* tokenizer.c */
char **strtnow(char *s, char *d);
char **strtnow2(char *str, char d);

/* memory */
int bfree(void **ptr);

/* atoi.c */
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/* errors1.c */
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int n, int s, int flag);
void remove_comments(char *buf);

/* builtin.c */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/* getline */
ssize_t get_input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *t);
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandle(__attribute__((unused))int sig_num);

/* builtin1.c */
int _myhistory(info_t *info);
int unset_alias(info_t *info);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);

/* getinfo.c */
void clear_info(info_t *info);
void set_info(info_t *info, char **v);
void free_info(info_t *, int a);

/* environ.c */
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);

/* getenv.c */
char **get_environ(info_t *info);
int _unsetenv(info_t *, char *v);
int _setenv(info_t *info, char *v, char x);

/* history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history(info_t *info, char *buf, int lincount);
int renumber_history(info_t *info);

/* lists.c */
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/* lists1.c */
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t prints_lists(const list_t *h);
list_t *node_starts_width(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);

/* vars.c */
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char *new);

#endif
