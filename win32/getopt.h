#ifndef __GETOPT_H__
#define __GETOPT_H__

extern int	opterr;		/* if error message should be printed */
extern int	optind;		/* index into parent argv vector */
extern int	optopt;		/* character checked for validity */
extern int	optreset;		/* reset getopt */
extern char    *optarg;		/* argument associated with option */

struct option		/* specification for a long form option...	*/
{
  const char *name;		/* option name, without leading hyphens */
  int         has_arg;		/* does it take an argument?		*/
  int        *flag;		/* where to save its status, or NULL	*/
  int         val;		/* its associated status value		*/
};

enum    		/* permitted values for its `has_arg' field...	*/
{
  no_argument = 0,      	/* option never takes an argument	*/
  required_argument,		/* option always requires an argument	*/
  optional_argument		/* option may take an argument		*/
};

int
getopt(int nargc, char * const *nargv, const char *options);

static int getopt_internal(int, char * const *, const char *,
			   const struct option *, int *, int);
static int parse_long_options(char * const *, const char *,
			      const struct option *, int *, int);
static int gcd(int, int);
static void permute_args(int, int, int, char * const *);

#endif