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

static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", base03, "-nf", base00, "-sb", base03 , "-sf", blue, NULL };
