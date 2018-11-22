/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Siji:size=12", "SauceCodePro Nerd Font:size=12" };
static const char dmenufont[]       = "SauceCodePro Nerd Font:size=12";

static const char base03[]          = "#002b36";
static const char base02[]          = "#073642";
static const char base01[]          = "#586e75";
static const char base00[]          = "#657b83";
static const char base0[]           = "#839496";
static const char base1[]           = "#93a1a1";
static const char base2[]           = "#eee8d5";
static const char base3[]           = "#fdf6e3";
static const char yellow[]          = "#b58900";
static const char orange[]          = "#cb4b16";
static const char red[]             = "#dc322f";
static const char magenta[]         = "#d33682";
static const char violet[]          = "#6c71c4";
static const char blue[]            = "#268bd2";
static const char cyan[]            = "#2aa198";
static const char green[]           = "#859900";
static const int gappx = 14;
static const char *colors[][12]      = {
	                /* fg         bg          border   */
	[SchemeNormDark]    = { base1,    base03,     base02},
	[SchemeSelDark]     = { blue,     base03,     blue  },
	[SchemeGoodDark]    = { green,    base03,     green },
	[SchemeOkDark]      = { yellow,   base03,     yellow},
	[SchemeWarnDark]    = { orange,   base03,     orange},
	[SchemeUrgentDark]  = { red,      base03,     red   },
	[SchemeNormLight]   = { base01,   base3,      base2 },
	[SchemeSelLight]    = { blue,     base3,      blue  },
	[SchemeGoodLight]   = { green,    base3,      green },
	[SchemeOkLight]     = { yellow,   base3,      yellow},
	[SchemeWarnLight]   = { orange,   base3,      orange},
	[SchemeUrgentLight] = { red,      base3,      red   },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 * WM_CLASS(STRING) = instance, class
	 * WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	//{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", base03, "-nf", base00, "-sb", base03 , "-sf", blue, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *firefoxcmd[] = { "firefox", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_i     , spawn,          {.v = firefoxcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      switchcol,      {0} },
	{ MODKEY,                       XK_l,      switchcol,      {0} },
	{ MODKEY,                       XK_n,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_period, setmfact,       {.f = +0.05} },
	/*{ MODKEY,                       XK_n,      moveresize,     {.v = (int []){ -25, 0, 0, 0 }}},
	{ MODKEY,                       XK_m,      moveresize,     {.v = (int []){ 0, 25, 0, 0 }}},
	{ MODKEY,                       XK_comma,  moveresize,     {.v = (int []){ 0, 25, 0, 0 }}},
	{ MODKEY,                       XK_period, moveresize,     {.v = (int []){ 25, 0, 0, 0 }}},
	{ MODKEY|ShiftMask,             XK_h,      moveresize,     {.v = (int []){ 0, 0, -25, 0 }}},
	{ MODKEY|ShiftMask,             XK_j,      moveresize,     {.v = (int []){ 0, 0, 0, -25 }}},
	{ MODKEY|ShiftMask,             XK_k,      moveresize,     {.v = (int []){ 0, 0, 0, 25 }}},
	{ MODKEY|ShiftMask,             XK_l,      moveresize,     {.v = (int []){ 0, 0, 25, 0 }}},
	*/
	{ MODKEY|ShiftMask,             XK_h,      zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_l,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    viewnext,       {0} },
	{ MODKEY,                       XK_t,      togglecolors,   {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
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
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_e,      quit,           {1} },
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

