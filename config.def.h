/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=11" };
static const char dmenufont[]       = "monospace:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_red[]         = "#ff0000";
static const char col_green[]       = "#00ff00";
static const char col_blue[]        = "#0000ff";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_green  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[\\]",     dwindle },
 	{ "[@]",      spiral },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */

    /* spawn terminal */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

    /* toggle menu bar */
	{ MODKEY,                       XK_b,      togglebar,      {0} },

    /* focus next window */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },

    /* focus previous window */
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

    /* increase number of windows in master area */
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },

    /* decrease number of windows in master area */
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },

    /* decrease master area size */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },

    /* increase master area size */
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

    /* promote window */
	{ MODKEY|ShiftMask,             XK_j,      zoom,           {0} },

    /* toggles between the previously selected tags */
	{ MODKEY,                       XK_Tab,    view,           {0} },

    /* kill current window */
	{ MODKEY,                       XK_q,      killclient,     {0} },

    /* set tiling layout */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    
    /* set floating layout */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },

    /* set fibonacci dwindle layout */
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },

    /* set monocle layout */
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[2]} },

    /* set default layout */
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
    
    /* set default layout */
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[0]} },

    /* set default dwindle layout */
	{ MODKEY|ShiftMask,             XK_g,      setlayout,      {.v = &layouts[0]} },

    /* set default layout */
	{ MODKEY|ShiftMask,             XK_n,      setlayout,      {.v = &layouts[0]} },

    /* toggle between current and previous layout */
	{ MODKEY,                       XK_space,  setlayout,      {0} },

    /* toggle floating layout */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

    /* quit wdm */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

    /* view all windows with any tag */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },

    /* apply all tags to focused window */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

    /* decrease gaps between windows */
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },

    /* increase gaps between windows */
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },

    /* reset gaps between windows */
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },

    /* focus on monitor left */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },

    /* focus on monitor right */
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },

    /* move active window to monitor left */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },

    /* move active window to monitor right */
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

