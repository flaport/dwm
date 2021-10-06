/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int stextdelim = 32;      /* ascii code of delimiter character used in status bar */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 16;       /* gap pixel between windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = {
    "monospace:pixelsize=14:antialias=true:autohint=true",
	"JoyPixels:pixelsize=14:antialias=true:autohint=true",
};
static const char dmenufont[]       = "monospace:size=10";
static char black[]					= "#222222";
static char gray[]					= "#777777";
static char white[]					= "#ffffff";
static char selcolor[]           	= "#005577";
static char *colors[][3] = {
       /*               fg          bg          border   */
    [SchemeNorm] = 		{ white, 	black,  	black },
    [SchemeSel]  = 		{ white,  	selcolor,  	selcolor  },
	[SchemeInactive] = 	{ white, 	gray, 		NULL },
};
static const unsigned int alphas[][3]      = {
	/*               fg    bg  border  */
	[SchemeNorm] = { 255,  50,   0   },
	[SchemeSel]  = { 255,  180, 255  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "H"}; /* last tag is hidden */
static const char *montags[] = { "Z", "X", "C", "V"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */

	/* class        instance       title      tags mask  iscentered isfloating  isterminal  noswallow  monitor */
	{ "Alacritty",      NULL,       NULL,         0,          1,         0,          1,          0,      -1 }, /* Alacritty */
	{ "Anki",           NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Anki */
	{ "Arandr",         NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Arandr */
	{ "autorun.exe",    NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Wine */
	{ "Barrier",        NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Barrier */
	{ "Blueman",        NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Blueman */
	{ "CfgDFInput",     NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* PCSXR */
	{ "Conky",          NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Conky */
	{ "Eid-viewer",     NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* eid viewer */
	{ "Fceux",          NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Fceux NES emulator */
	{ "fdtd-solutions-app", NULL,   NULL,         0,          1,         1,          0,          0,      -1 }, /* Lumerical FDTD */
	{ "mode-solutions-app", NULL,   NULL,         0,          1,         1,          0,          0,      -1 }, /* Lumerical MODE */
	{ "Helpdesk DICT",  NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* DICT */
	{ "MEGAsync",       NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* MEGA sync client */
	{ "mpv",            NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* MPV Media Player */
	{ "firefox",        NULL,       NULL,         0,          1,         0,          0,          1,      -1 }, /* Firefox */
	{ "Nextcloud",      NULL,       NULL,         0,          0,         1,          0,          0,      -1 }, /* Nextcloud client */
	{ "Nm-applet",      NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* NetworkManager Applets */
	{ "Nm-connection-editor", NULL, NULL,         0,          1,         1,          0,          0,      -1 }, /* NetworkManager Connections */
	{ "Pavucontrol",    NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Pavucontrol */
	{ "PCSXR",          NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* PCSXR */
	{ "SimpleScreenRecorder", NULL, NULL,         0,          1,         1,          0,          0,      -1 }, /* SimpleScreenRecorder */
	{ "st-256color",    NULL,       NULL,         0,          1,         0,          1,          0,      -1 }, /* st */
	{ "Steam",          NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Steam */
	{ "St",             NULL,       NULL,         0,          1,         0,          1,          0,      -1 }, /* st */
	{ "Wfica",          NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* ICA Client */
	{ "winecfg.exe",    NULL,       NULL,         0,          1,         1,          0,          0,      -1 }, /* Wine */

	{ "Alacritty",   NULL,       "float",         0,          1,         1,          1,          0,      -1 }, /* Alacritty -t float */
	{ "st-256color", "float",       NULL,         0,          1,         1,          1,          0,      -1 }, /* st -n float */
	{ "St",          "float",       NULL,         0,          1,         1,          1,          0,      -1 }, /* st -n float */
	{ NULL, "fdtd-solutions-app",   NULL,         0,          1,         1,          0,          0,      -1 }, /* Lumerical FDTD */
	{ NULL, "mode-solutions-app",   NULL,         0,          1,         1,          0,          0,      -1 }, /* Lumerical MODE */

	{ NULL, NULL, "Confirm Exit",                 0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "Customize PyCharm",            0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "Event Tester",                 0,          1,         1,          0,          1,      -1 }, /* xev */
	{ NULL, NULL, "Figure",                       0,          1,         1,          0,          1,      -1 }, /* Matplotlib */
	{ NULL, NULL, "Lumerical",                    0,          1,         0,          0,          0,      -1 }, /* Lumerical */
	{ NULL, NULL, "Import PyCharm Settings",      0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "License Activation",           0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "Marker Database Browser",      0,          1,         1,          0,          0,      -1 }, /* KLayout */
	{ NULL, NULL, "Message from webpage",         0,          1,         1,          0,          0,      -1 }, /* SAP notifications */
	{ NULL, NULL, "Microsoft Teams Notification", 0,          0,         1,          0,          0,      -1 }, /* Microsoft Teams Notifications */
	{ NULL, NULL, "Network Operations Manager",   0,          1,         1,          0,          0,      -1 }, /* VirtualBox */
	{ NULL, NULL, "PlayOnLinux",                  0,          1,         1,          0,          0,      -1 }, /* PlayOnLinux */
	{ NULL, NULL, "PyCharm User Agreement",       0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "Tip of the Day",               0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "Welcome to PyCharm",           0,          1,         1,          0,          0,      -1 }, /* PyCharm */
	{ NULL, NULL, "zoom",                         0,          1,         1,          0,          0,      -1 }, /* Wine */

	{ "Skype", NULL, "Skype Preview",             0,          0,         0,          0,          0,      -1 }, /* Main Skype Window [defined before popups!]*/
	{ "Skype", NULL, NULL,                        0,          0,         1,          0,          0,      -1 }, /* Skype Popups [defined after main window!]*/
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol   arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle }, /* maximized layout (bar still visible) */
	{ NULL,     NULL },  /* sentinel to allow for cycling through layouts */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define MONKEYS(KEY,TAG) \
	{ MODKEY,                  KEY,      focusmon,    {.i = TAG+1} }, \
	{ MODKEY|ShiftMask,        KEY,      tagmon,      {.i = TAG+1} }, \
	{ MODKEY|ControlMask,      KEY,      swapmon,     {.i = TAG+1} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ControlMask,           XK_Tab,    swapmon,        {.i = 0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {1} }, /* restart dwm */
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} }, /* quit dwm */
	{ MODKEY,                       XK_t,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_f,      fullscreen,     {0} },
	{ MODKEY|ControlMask,           XK_m,      setmastermon,   {.i = 0} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_o,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,		                XK_semicolon, cyclelayout, {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, cyclelayout, {.i = +1 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask,           XK_comma,  setmastermon,   {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_period, setmastermon,   {.i = +1 } },
	{ MODKEY,                       XK_o,      winview,        {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_grave,                  9)
	MONKEYS(                        XK_z,                      1)
	MONKEYS(                        XK_x,                      2)
	MONKEYS(                        XK_c,                      3)
	MONKEYS(                        XK_v,                      4)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1} },
	{ ClkLtSymbol,          0,              Button2,        setlayout,      {.v = &layouts[0]} },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
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
	/* signum       function        argument  */
	{ 1,            quit,      		{.i = 0} },
	{ 2,            quit,      		{.i = 1} },
	{ 3,            xrdb,      		{.v = NULL} },
};
