/*****************************************************************************
*
*****************************************************************************/
#ifndef __MENU_H
#define __MENU_H
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <usr_sys.h>
#include <usr_usart.h>

#define CMD_ARGC_MAX			5			/* Max # of command parameters */
#define CMD_ARGC_VAR	   		(-1)		/* Variable # of parameters */
#define CMD_RC_FAILURE      -1     /* Failure Return Code (RC) */
#define CMD_RC_SUCCESS		   0     /* Success Return Code (RC) */
#define CMD_RC_SYNTAX_ERROR	1     /* Syntax Error (RC) */

typedef int (* CMD_FUNC)(void);		/* Generic command function def'n */

typedef struct _CMD_ENTRY {
	CMD_FUNC func;		/* Function associated with a command */
	int argc;					/* Number of parameters for a command */
	char *str;					/* Command line string */
	char *syntax;				/* Parameter list/names */
	char *hint;					/* Brief command description */
} CMD_ENTRY;

/* ---- Variable Externs -----------------------------------*/
/* ---- Function Prototypes --------------------------------*/
/* Menu routines */

extern void MenuMain( char *prompt, const CMD_ENTRY menu[] );
extern void MenuStart( char *prompt, const CMD_ENTRY menu[], int argc, char *argv[] );


/* Console I/O routines */
void conGets( char *buf, int size );
#define conGetc				usart_hitkey //getchar
#define conFlushOut()       fflush(stdout)
#define conPrintf			printf
#define conPrompt(str)		{conPuts(str); conFlushOut();}
#define conPutc(c)			putchar(c);
#define conPuts(s)			fputs(s, stdout)

#ifdef __cplusplus
}
#endif

#endif //__MENU_H
