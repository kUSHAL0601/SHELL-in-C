#include <stdio.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int i,j,k;
char a;
char pr_dir[1024];
char pwd[1024];
char modified[1024];
char arg[100][1024];
struct passwd *pw;
struct passwd *uidnm;
struct group *gidnm;
uid_t uid;
struct utsname unm;
DIR *mydir;
DIR *mydir1;
struct dirent *entry;
struct dirent *entry1;
struct stat sb1;
struct stat sb;
int tempvar;
int ampcount;
int hid;
int lng;
int ap;
char exec_path[2000];
char exec[2000];
char new_dir[2000];
char procid[20];
char line[1000];
