/* hello.c -- print a greeting message and exit.

   Copyright 1992, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2005,
   2006, 2007, 2008, 2010, 2011 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>
#include "system.h"
#include "progname.h"

static const struct option longopts[] =
{
  { "greeting", required_argument, NULL, 'g' },
  { "help", no_argument, NULL, 'h' },
  { "next-generation", no_argument, NULL, 'n' },
  { "traditional", no_argument, NULL, 't' },
  { "version", no_argument, NULL, 'v' },
  { NULL, 0, NULL, 0 }
};

/* Different types of greetings; only one per invocation.  */
typedef enum {
  greet_gnu, greet_new, greet_traditional, greet_user
} greeting_type;

/* Forward declarations.  */
static void print_help (void);
static void print_version (void);

int
main (int argc, char *argv[])
{
  int optc;
  int lose = 0;
  const char *greeting_msg = NULL;
  greeting_type g = greet_gnu;

  set_program_name (argv[0]);

  /* Set locale via LC_ALL.  */
  setlocale (LC_ALL, "");

#if ENABLE_NLS
  /* Set the text message domain.  */
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);
#endif

  /* Even exiting has subtleties.  On exit, if any writes failed, change
     the exit status.  The /dev/full device on GNU/Linux can be used for
     testing; for instance, hello >/dev/full should exit unsuccessfully.
     This is implemented in the Gnulib module "closeout".  */
  atexit (close_stdout);

  while ((optc = getopt_long (argc, argv, "g:hntv", longopts, NULL)) != -1)
    switch (optc)
      {
      /* --help and --version exit immediately, per GNU coding standards.  */
      case 'v':
        print_version ();
        exit (EXIT_SUCCESS);
        break;
      case 'g':
        greeting_msg = optarg;
        g = greet_user;
        break;
      case 'h':
        print_help ();
        exit (EXIT_SUCCESS);
        break;
      case 'n':
        g = greet_new;
        break;
      case 't':
        g = greet_traditional;
        break;
      default:
        lose = 1;
        break;
      }

  if (lose || optind < argc)
    {
      /* Print error message and exit.  */
      if (optind < argc)
        fprintf (stderr, _("%s: extra operand: %s\n"),
                 program_name, argv[optind]);
      fprintf (stderr, _("Try `%s --help' for more information.\n"),
               program_name);
      exit (EXIT_FAILURE);
    }

  /* Print greeting message and exit. */
  if (g == greet_traditional)
    printf (_("hello, world\n"));

  else if (g == greet_new)
    /* TRANSLATORS: Use box drawing characters or other fancy stuff
       if your encoding (e.g., UTF-8) allows it.  If done so add the
       following note, please:

       [Note: For best viewing results use a UTF-8 locale, please.]
    */
        printf (_("\
+---------------+\n\
| Hello, world! |\n\
+---------------+\n\
"));

  else if (g == greet_user)
    puts (greeting_msg);

  else if (g == greet_gnu)
    puts (_("Hello, world!"));

  else {
    /* No need for this impossible message to be translated.  */
    fprintf (stderr, "Impossible hello value %d\n", g);
    exit (EXIT_FAILURE);
  }

  exit (EXIT_SUCCESS);
}



/* Print help info.  This long message is split into
   several pieces to help translators be able to align different
   blocks and identify the various pieces.  */

static void
print_help (void)
{
  /* TRANSLATORS: --help output 1 (synopsis)
     no-wrap */
        printf (_("\
Usage: %s [OPTION]...\n"), program_name);

  /* TRANSLATORS: --help output 2 (brief description)
     no-wrap */
  fputs (_("\
Print a friendly, customizable greeting.\n"), stdout);

  puts ("");
  /* TRANSLATORS: --help output 3: options 1/2
     no-wrap */
  fputs (_("\
  -h, --help          display this help and exit\n\
  -v, --version       display version information and exit\n"), stdout);

  puts ("");
  /* TRANSLATORS: --help output 4: options 2/2
     no-wrap */
  fputs (_("\
  -t, --traditional       use traditional greeting format\n\
  -n, --next-generation   use next-generation greeting format\n\
  -g, --greeting=TEXT     use TEXT as the greeting message\n"), stdout);

  printf ("\n");
  /* TRANSLATORS: --help output 5+ (reports)
     TRANSLATORS: the placeholder indicates the bug-reporting address
     for this application.  Please add _another line_ with the
     address for translation bugs.
     no-wrap */
  printf (_("\
Report bugs to: %s\n"), PACKAGE_BUGREPORT);
#ifdef PACKAGE_PACKAGER_BUG_REPORTS
  printf (_("Report %s bugs to: %s\n"), PACKAGE_PACKAGER,
          PACKAGE_PACKAGER_BUG_REPORTS);
#endif
#ifdef PACKAGE_URL
  printf (_("%s home page: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
#else
  printf (_("%s home page: <http://www.gnu.org/software/%s/>\n"),
          PACKAGE_NAME, PACKAGE);
#endif
  fputs (_("General help using GNU software: <http://www.gnu.org/gethelp/>\n"),
         stdout);
}



/* Print version and copyright information.  */

static void
print_version (void)
{
  printf ("hello (GNU %s) %s\n", PACKAGE, VERSION);
  /* xgettext: no-wrap */
  puts ("");

  /* It is important to separate the year from the rest of the message,
     as done here, to avoid having to retranslate the message when a new
     year comes around.  */
  printf (_("\
Copyright (C) %s Free Software Foundation, Inc.\n\
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n"),
              "2011");
}
