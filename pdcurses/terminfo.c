/*
***************************************************************************
* This file comprises part of PDCurses. PDCurses is Public Domain software.
* You may use this code for whatever purposes you desire. This software
* is provided AS IS with NO WARRANTY whatsoever.
* Should this software be used in another application, an acknowledgement
* that PDCurses code is used would be appreciated, but is not mandatory.
*
* Any changes which you make to this software which may improve or enhance
* it, should be forwarded to the current maintainer for the benefit of 
* other users.
*
* The only restriction placed on this code is that no distribution of
* modified PDCurses code be made under the PDCurses name, by anyone
* other than the current maintainer.
* 
* See the file maintain.er for details of the current maintainer.
***************************************************************************
*/
#define	CURSES_LIBRARY 1
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include <term.h>

/* undefine any macros for functions defined in this module */
#undef	mvcur
#undef  vidattr
#undef  vidputs

/* undefine any macros for functions called by this module if in debug mode */
#ifdef PDCDEBUG
#endif

#ifdef PDCDEBUG
char *rcsid_terminfo  = "$Id: terminfo.c,v 1.9 2006/01/27 16:18:00 wmcbrine Exp $";
#endif

/*man-start*********************************************************************

  Name:                                                      terminfo

  Synopsis:
	int mvcur(int oldrow, int oldcol, int newrow, int newcol);
	int del_curterm(TERMINAL *);
	int putp(const char *);
	int restartterm(char *, int, int *);
	TERMINAL *set_curterm(TERMINAL *);
	int setupterm(char *, int, int *);
	int tgetent(char *, const char *);
	int tgetflag(char *);
	int tgetnum(char *);
	char *tgetstr(char *, char **);
	char *tgoto(char *, int, int);
	int tigetflag(char *);
	int tigetnum(char *);
	char *tigetstr(char *);
	char *tparm(char *,long, long, long, long, long, long, long, 
		long, long);
	int tputs(const char *, int, int (*)(int));
	int vidattr(chtype attr);
	int vidputs(chtype attr, int (*putfunc)(int));

  X/Open Description:
	The mvcur() function controls low-level cursor motion with 
	optimization.

	NOTE: The remainer of the terminfo functions have not been
	implemented.

  X/Open Return Value:
	All functions return OK on success and ERR on error.

  X/Open Errors:
	No errors are defined for this function.

  Portability                             X/Open    BSD    SYS V
                                          Dec '88
      mvcur                                 Y        Y       Y

**man-end**********************************************************************/

TERMINAL *cur_term = NULL;

/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	mvcur(int oldrow, int oldcol, int newrow, int newcol)
#else
int	PDC_CDECL	mvcur(oldrow, oldcol, newrow, newcol)
int oldrow;
int oldcol;
int newrow;
int newcol;
#endif
/***********************************************************************/
{
	PDC_LOG(("mvcur() - called: oldrow %d oldcol %d newrow %d newcol %d\n",
		oldrow, oldcol, newrow, newcol));

	if ((newrow >= LINES) || (newcol >= COLS) ||
	    (newrow < 0) || (newcol < 0))
		return ERR;

	PDC_gotoxy(newrow, newcol);
	SP->cursrow = newrow;
	SP->curscol = newcol;

	return OK;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL del_curterm(TERMINAL *oterm)
#else
int     PDC_CDECL del_curterm(oterm)
TERMINAL *oterm;
#endif
/***********************************************************************/
{
	PDC_LOG(("del_curterm() - called\n"));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL putp(const char *str)
#else
int     PDC_CDECL putp(str)
char *str;
#endif
/***********************************************************************/
{
	PDC_LOG(("putp() - called: str %s\n", str));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL restartterm(char *term, int filedes, int *errret)
#else
int     PDC_CDECL restartterm(term, filedes, errret)
char *term;
int filedes;
int *errret;
#endif
/***********************************************************************/
{
	PDC_LOG(("restartterm() - called\n"));

	if (errret)
		*errret = -1;

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
TERMINAL* PDC_CDECL set_curterm(TERMINAL *nterm)
#else
TERMINAL* PDC_CDECL set_curterm(nterm)
TERMINAL *nterm;
#endif
/***********************************************************************/
{
	PDC_LOG(("set_curterm() - called\n"));

	return (TERMINAL *)NULL;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL setterm(char *term)
#else
int     PDC_CDECL setterm(term)
char *term;
#endif
/***********************************************************************/
{
	PDC_LOG(("setterm() - called\n"));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL setupterm(char *term, int filedes, int *errret)
#else
int     PDC_CDECL setupterm(term, filedes, errret)
char *term;
int filedes;
int *errret;
#endif
/***********************************************************************/
{
	PDC_LOG(("setupterm() - called\n"));

	if (errret)
		*errret = -1;
	else
		fprintf(stderr, "There is no terminfo database\n");

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL tgetent(char *bp, const char *name)
#else
int     PDC_CDECL tgetent(bp, name)
char *bp;
char *name;
#endif
/***********************************************************************/
{
	PDC_LOG(("tgetent() - called: name %s\n", name));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL tgetflag(char *id)
#else
int     PDC_CDECL tgetflag(id)
char *id;
#endif
/***********************************************************************/
{
	PDC_LOG(("tgetflag() - called: id %s\n", id));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL tgetnum(char *id)
#else
int     PDC_CDECL tgetnum(id)
char *id;
#endif
/***********************************************************************/
{
	PDC_LOG(("tgetnum() - called: id %s\n", id));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
char*   PDC_CDECL tgetstr(char *id, char **area)
#else
char*   PDC_CDECL tgetstr(id, area)
char *id;
char **area;
#endif
/***********************************************************************/
{
	PDC_LOG(("tgetstr() - called: id %s\n", id));

	return (char *)NULL;
}

/***********************************************************************/
#ifdef HAVE_PROTO
char*   PDC_CDECL tgoto(char *cap, int col, int row)
#else
char*   PDC_CDECL tgoto(cap, col, row)
char *cap;
int col;
int row;
#endif
/***********************************************************************/
{
	PDC_LOG(("tgoto() - called\n"));

	return (char *)NULL;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL tigetflag(char *capname)
#else
int     PDC_CDECL tigetflag(capname)
char *capname;
#endif
/***********************************************************************/
{
	PDC_LOG(("tigetflag() - called: capname %s\n", capname));

	return -1;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL tigetnum(char *capname)
#else
int     PDC_CDECL tigetnum(capname)
char *capname;
#endif
/***********************************************************************/
{
	PDC_LOG(("tigetnum() - called: capname %s\n", capname));

	return -2;
}

/***********************************************************************/
#ifdef HAVE_PROTO
char*   PDC_CDECL tigetstr(char *capname)
#else
char*   PDC_CDECL tigetstr(capname)
char *capname;
#endif
/***********************************************************************/
{
	PDC_LOG(("tigetstr() - called: capname %s\n", capname));

	return (char *)(-1);
}

/***********************************************************************/
#ifdef HAVE_PROTO
char*   PDC_CDECL tparm(char *cap, long p1, long p2, long p3, long p4, 
			long p5, long p6, long p7, long p8, long p9)
#else
char*   PDC_CDECL tparm(cap, p1, p2, p3, p4, p5, p6, p7, p8, p9)
char *cap;
long p1;
long p2;
long p3;
long p4; 
long p5;
long p6;
long p7;
long p8;
long p9;
#endif
/***********************************************************************/
{
	PDC_LOG(("tparm() - called: cap %s\n", cap));

	return (char *)NULL;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int     PDC_CDECL tputs(const char *str, int affcnt, int (*putfunc)(int))
#else
int     PDC_CDECL tputs(str, affcnt, putfunc)
char *str;
int affcnt;
int (*putfunc)(int);
#endif
/***********************************************************************/
{
	PDC_LOG(("tputs() - called\n"));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	vidattr(chtype attr)
#else
int	PDC_CDECL	vidattr(attr)
chtype attr;
#endif
/***********************************************************************/
{
	PDC_LOG(("vidattr() - called: attr %d\n", attr));

	return ERR;
}

/***********************************************************************/
#ifdef HAVE_PROTO
int	PDC_CDECL	vidputs(chtype attr, int (*putfunc)(int))
#else
int	PDC_CDECL	vidputs(attr, putfunc)
chtype attr;
int (*putfunc)();
#endif
/***********************************************************************/
{
	PDC_LOG(("vidputs() - called: attr %d\n", attr));

	return ERR;
}
