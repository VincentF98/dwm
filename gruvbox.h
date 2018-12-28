static const char bg_dark[]         = "#32302f";
static const char bg_light[]        = "#f2e5bc";
static const char fg_dark[]         = "#ebdbb2";
static const char fg_light[]        = "#3c3836";
static const char border_dark[]     = "#3c3838";
static const char border_light[]    = "#ebdbb2";

static const char yellow[]          = "#d79921";
static const char orange[]          = "#d65d0e";
static const char red[]             = "#cc241d";
static const char magenta[]         = "#d3869b";
static const char violet[]          = "#b16286";
static const char blue[]            = "#458588";
static const char cyan[]            = "#689d6a";
static const char green[]           = "#98971a";
static const int gappx = 14;
static const char *colors[][12]      = {
	                     /* fg         bg          border   */
	[SchemeNormDark]    = { fg_dark,   bg_dark,     border_dark},
	[SchemeSelDark]     = { blue,      bg_dark,     blue  },
	[SchemeGoodDark]    = { green,     bg_dark,     green },
	[SchemeOkDark]      = { yellow,    bg_dark,     yellow},
	[SchemeWarnDark]    = { orange,    bg_dark,     orange},
	[SchemeUrgentDark]  = { red,       bg_dark,     red   },
	[SchemeNormLight]   = { fg_light,  bg_light,    border_light },
	[SchemeSelLight]    = { blue,      bg_light,    blue  },
	[SchemeGoodLight]   = { green,     bg_light,    green },
	[SchemeOkLight]     = { yellow,    bg_light,    yellow},
	[SchemeWarnLight]   = { orange,    bg_light,    orange},
	[SchemeUrgentLight] = { red,       bg_light,    red   },
};

static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg_dark, "-nf", fg_dark, "-sb", bg_dark , "-sf", blue, NULL };
