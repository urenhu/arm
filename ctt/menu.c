/*****************************************************************************
* @menu
*****************************************************************************/
#define STDIN_TERMINAL 0 

/* ---- Include Files ---------------------------------------- */
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "usr_sys.h"
#include "usr_usart.h"  // getc putc 


/* ---- Public Variables ------------------------------------- */
/* ---- Private Constants and Types -------------------------- */
/* Command prompt string */
#define PROMPT_FORMAT      "[%s]> "

/* Column to begin displaying hint */
#define COL_HINT           40

/* Definitions for some built-in commands */
#define CMD_HELP1          "?"
#define CMD_HELP2          "help"
#define CMD_HELP_HINT      "List menu commands"
#define CMD_HELP_SYNTAX    ""

#define CMD_QUIT           "quit"
#define CMD_QUIT_HINT      "Exit this menu"
#define CMD_QUIT_SYNTAX    ""

#define CMD_TRACE          "trace"
#define CMD_TRACE_HINT     "Menu command trace"
#define CMD_TRACE_SYNTAX   "<on|off>"

#define CMD_ECHO           "echo"
#define CMD_ECHO_HINT      "Display a line of text"
#define CMD_ECHO_SYNTAX    ""

#define CMD_COMMENT        "#"

/* Return codes to indicate if to exit a sub-menu or not */

#define MENU_CONTINUE      0
#define MENU_QUIT          1

/* Definitions to indicate if a menu is at the top level or not */

#define LVL_MAIN_MENU      0
#define LVL_SUB_MENU       1

/* Command line parsing definitions */

#define TOKEN_DELIMITERS   " ,\t\r\n"
#define TOKEN_MAX_CNT      10

typedef int (* FUNC_VARGS)(int argc, char *argv[]);
typedef int (* FUNC_5ARGS)(char *p1, char *p2, char *p3, char *p4, char *p5);

/* ---- Private Variables ------------------------------------ */

static int cmdTrace = 0;      /* Trace command execution flag */

/* ---- Private Function Prototypes -------------------------- */

#define CmdMatch(c1, c2)         (strcmp(c1, c2) == 0)

static int    CmdExec( char *prompt, int level, const CMD_ENTRY menu[], int argc, char *argv[] );
static const  CMD_ENTRY *CmdFind( const CMD_ENTRY menu[], char *str );
static void   CmdLoop( char *prompt, int level, const CMD_ENTRY menu[] );
static int    CmdParse( char *cmdLine, char *argv[] );

#define DisplayCmdUnknown(p, s)  conPrintf("%s unknown command: '%s'\r\n", p, s)
#define DisplaySyntax(p, c)      conPrintf("%s syntax: '%s %s'\r\n", p, (c)->str, (c)->syntax)
#define DisplayFuncError(p, c)   conPrintf("%s command '%s' function missing\r\n", p, (c)->str)

static void DisplayCmd( char *cmd, char *syntax, char *hint );
static void DisplayMenu( char *prompt, int level, const CMD_ENTRY menu[] );

/* TO DO:  remove hack */
#if STDIN_TERMINAL
#define EchoChar(c)
#define EchoStr(s)
#else
#define EchoChar(c)            {conPutc(c); conFlushOut();}
#define EchoStr(s)             {conPuts(s); conFlushOut();}
#endif


/* ---- Public Functions ------------------------------------- */

/***************************************************************************
*  NOTES:
*      Buffer is null terminated when complete, and the terminating
*      character '\n' is discarded.
****************************************************************************/
void conGets( char *buf, int lim )
{
   char ch;
   int  i;
	
	 if (lim > 126)
		 lim = 126;
	 
	 for(i = 0; i < lim - 1 ; i++ ){
		  buf[i] = 0; 
	 }
	   
   for(i = 0; i < lim - 1 && (ch = (char)conGetc()&0xff) != EOF && ch != '\n' && ch != '\r'; ++i) {
       buf[i] = ch;
		   EchoChar( ch ) 
	 }
   if(ch == '\n' || ch == '\r'){
       buf[i] = '\r';
       ++i;     
       buf[i] = '\n';
       ++i;     
   }
   buf[i] = 0;
   // return i;
}
	

/***************************************************************************
*  NOTES:
****************************************************************************/
void MenuMain( char *prompt, const CMD_ENTRY menu[] )
{
  for (;;) 
		CmdLoop( prompt, LVL_MAIN_MENU, menu );
	 
}

/***************************************************************************
*  NOTES:
*
****************************************************************************/
void MenuStart( char *prompt, const CMD_ENTRY menu[], int argc, char *argv[] )
{
   if( argc > 0 ) {
      CmdExec( prompt, LVL_SUB_MENU, menu, argc, argv );
   }   else   {
      CmdLoop( prompt, LVL_SUB_MENU, menu );
   }
}


/* ---- Private Functions ------------------------------------ */

/***************************************************************************
*
****************************************************************************/
int CmdExec( char *prompt, int level, const CMD_ENTRY menu[], int argc, char *argv[] )
{
   const CMD_ENTRY *cmdP;
   int rc;

   if( !(argc && argv[0] && *argv[0]) )  {
      return( MENU_CONTINUE );
   }
   argc--;
   if( CmdMatch(argv[0], CMD_HELP1) || CmdMatch(argv[0], CMD_HELP2) )   {
		  DisplayMenu( prompt, level, menu );
   }   else if( CmdMatch(argv[0], CMD_QUIT) )  {
       return( MENU_QUIT );
   }  else if( (cmdP = CmdFind(menu, argv[0]))== NULL )  {
      DisplayCmdUnknown( prompt, argv[0] );
   }   else if( cmdP->argc == CMD_ARGC_VAR ) {
      /* Variable argument command, e.g. sub-menu */
      (* (FUNC_VARGS)cmdP->func)( argc, &argv[1] );
   }   else if( cmdP->argc != argc )  {
      DisplaySyntax( prompt, cmdP );
   }   else if( !cmdP->func )  {
      /* Sanity check for an invalid function associated with a command */
      DisplayFuncError( prompt, cmdP );
   }  else   {
      /* Normal command with fixed number of parameters. */
      rc = (* (FUNC_5ARGS)cmdP->func)(argv[1], argv[2], argv[3], argv[4], argv[5]);
      if( rc == CMD_RC_SYNTAX_ERROR )     {
         DisplaySyntax( prompt, cmdP );
      }     else if( cmdTrace && rc )     {
         conPrintf("%s Error executing '%s' (%d)\r\n", prompt, cmdP->str, rc );
      }
   }
   return( MENU_CONTINUE );
}

/***************************************************************************

****************************************************************************/
const CMD_ENTRY *CmdFind( const CMD_ENTRY menu[], char *str )
{
   for ( ; menu->str; menu++ )   {
      if ( CmdMatch(menu->str, str) )      {
         break;
      }
   }

   if ( menu->str )   {
      return( menu );
   }   else   {
      return( NULL );
   }
}

/***************************************************************************
****************************************************************************/
void CmdLoop( char *prompt, int level, const CMD_ENTRY menu[] )
{
   int argc;
   static char *argv[TOKEN_MAX_CNT];
   static char cmdLine[128];
   static char p[128];

   sprintf( p, "\r\n" PROMPT_FORMAT, prompt );

   while ( 1 )   {
      conPrompt( p );
      conGets( cmdLine, sizeof(cmdLine) );
      if ((argc = CmdParse( cmdLine, argv )) > 0)      {
         if ((CmdExec( prompt, level, menu, argc, argv )) == MENU_QUIT)  {
           return;
         }
      }
   }
}

/***************************************************************************
*
****************************************************************************/
int CmdParse( char *cmdLine, char *argv[] )
{
   int argc;
   char *argp;

   argc = 0;
   argp = strtok( cmdLine, TOKEN_DELIMITERS );
   while ( (argp != NULL) && (argc < TOKEN_MAX_CNT) )   {
      argv[ argc++ ] = argp;
      argp = strtok( NULL, TOKEN_DELIMITERS );
   }
   return( argc );
}

/***************************************************************************
*  NOTES:
*
****************************************************************************/
void DisplayCmd( char *cmd, char *syntax, char *hint )
{
   int len;

   if ( *syntax == '\0' )   {
      len = conPrintf( "%s ", cmd );
   }   else   {
      len = conPrintf( "%s %s ", cmd, syntax );
   }
   for ( ; len < COL_HINT; len++ )   {
      conPutc( '.' );
   }
   conFlushOut();
   conPrintf( " %s\r\n", hint );
}

/***************************************************************************
*  NOTES:
*
****************************************************************************/
void DisplayMenu( char *prompt, int level, const CMD_ENTRY menu[] )
{
   int len;

   conPutc( '\r' );
   conPutc( '\n' );
   len = conPrintf( "%s Console Commands\r\n", prompt ) - 1;
   while ( len-- )   {
      conPutc( '-' );
   }
   conPutc( '\r' );
   conPutc( '\n' );
   DisplayCmd( CMD_HELP1, CMD_HELP_SYNTAX, CMD_HELP_HINT );
   DisplayCmd( CMD_HELP2, CMD_HELP_SYNTAX, CMD_HELP_HINT );
   DisplayCmd( CMD_QUIT, CMD_QUIT_SYNTAX, CMD_QUIT_HINT );

   for ( ; menu->str; menu++ ){
      DisplayCmd(menu->str, menu->syntax, menu->hint);
   }
   conPutc( '\r' );
   conPutc( '\n' );
}
