/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int normborderpx  = 0;        /* border pixel of windows */
static const unsigned int selborderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 20;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=11" };

/* alphas */
static const unsigned int opaque = 255; /* alpha */
static const unsigned int transparent = 1; /* alpha */
static const unsigned int semi_transparent = 150; /* alpha */

/* colors */
char col_bg[]      = "#fdf6e3";
char col_black[]   = "#32302f";
char col_red[]     = "#ff0000";
char col_green[]   = "#00ff00";
char col_yellow[]  = "#ffff00";
char col_blue[]    = "#0000ff";
char col_magenta[] = "#ff00ff";
char col_cyan[]    = "#00ffff";
char col_gray[]    = "#aaaaaa";
char col_white[]   = "#ffffff";
char col_fg[]      = "#2aa198";// "#268bd2"; //"#2aa198";

char *colors[][3]      = {
	/*               fg         bg              border   */
	[SchemeNorm] = { "#dddddd",    "#000000",     "#000000" },
	[SchemeSel]  = {  col_yellow,    "#000000",      col_yellow  },
	[SchemeSelTag] = { col_yellow,    "#000000",     "#000000" },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg                 border     */
	[SchemeNorm] = { opaque, 50,  transparent },
	[SchemeSel]  = { opaque, 50,  opaque },
	[SchemeSelTag] = { opaque, 50,  transparent },
};

/* tags */

static const char *tags[] = { "", "", "", "", "", "", "", "", "", "", "I" }; /* last two tags:  : favorite tag (always visible), I: hidden tag */
static const char *seltags[] = { "", "", "", "", "", "", "", "", "", "", "I" }; /* last two tags:  : favorite tag (always visible), I: hidden tag */

/* monitor tags */
static const char *montags[] = { "", "", "", ""}; /* keyboard: z, x, c, v */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title       tags mask     isfloating   monitor */
	{ "Gimp",           NULL,       NULL,       0,            1,           -1 }, /* Gimp */
	{ "Conky",          NULL,       NULL,       0,            1,           -1 }, /* Conky */
	{ "Pavucontrol",    NULL,       NULL,       0,            1,           -1 }, /* Pavucontrol */
	{ "Blueman",        NULL,       NULL,       0,            1,           -1 }, /* Blueman */
	{ "Arandr",         NULL,       NULL,       0,            1,           -1 }, /* Arandr */
	{ "Nm-connection-editor",       NULL,       NULL,       0,            1,           -1 }, /* Arandr */
	{ "Nm-applet",       NULL,       NULL,       0,            1,           -1 }, /* Arandr */
	{ NULL,             NULL,       "Figure",   0,            1,           -1 }, /* Matplotlib */
	{ NULL,             "float",    NULL,       0,            1,           -1 }, /* st -n float */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile }, /* tile */
 	{ "",      fibonacci }, /* fibonacci */
	{ "",      NULL }, /* floating */
	{ "",      deck }, /* deck */
	{ "",      monocle }, /* monocle */
	{ NULL,       NULL }, /* Sentinel */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define MONKEYS(KEY,TAG) \
	{ MODKEY,                  KEY,      absfocusmon,    {.ui = TAG} }, \
	{ MODKEY|ShiftMask,        KEY,      abstagmon,      {.ui = TAG} }, \
	{ MODKEY|ControlMask,      KEY,      swapmonitor,    {.ui = TAG} },

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ControlMask,           XK_space,  setmastermonitor, {0} },
	{ MODKEY,                       XK_Tab,    swapmonitor,    {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    switchtolastmon,    {0} },
	{ MODKEY|ControlMask,           XK_Tab,    setmastermonitor, {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },
	{ MODKEY,                       XK_t,      setlayout,      {0} }, /* toggle last two layouts */
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} }, /* toggle last two layouts */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,		                XK_semicolon, cyclelayout, {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, cyclelayout, {.i = +1 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_o,      winview,        {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = 511 } }, /*  111111111 */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = 511 } }, /*  111111111 */
	{ MODKEY|ShiftMask,             XK_d,      xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_backslash,              9)
	TAGKEYS(                        XK_grave,                  10)
	MONKEYS(                        XK_z,                      0)
	MONKEYS(                        XK_x,                      1)
	MONKEYS(                        XK_c,                      2)
	MONKEYS(                        XK_v,                      3)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1} },
	{ ClkLtSymbol,          0,              Button2,        setlayout,      {.v = &layouts[2]} },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1} },
	{ ClkWinTitle,          0,              Button1,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument    */
	{ 0,            logselmon,      {0}         },
	{ 0,            logmastermon,   {0}         },
	{ 1,            xrdb,           {.v = NULL} },
};
