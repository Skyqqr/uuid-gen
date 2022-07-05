#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <uuid/uuid.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
char PRO_NAME[20] = "a";
struct flags {
bool PrintRaw;
bool PrintUUid;
bool Verbose;
bool PrintAll;
bool PrintSha;
bool PrintTimeUUid;
} flag;
void helptext() {
fprintf (stdout, "%s - Simple UUID Generator.\n", PRO_NAME);
fprintf(stdout, "r - Raw, v - Verbose, h - Help, u - uuid (format 4), a - print all, s - SHA, C - Sha code\n");
fprintf(stdout,"Ex: %s -rvsC IlikePumpkins\n",PRO_NAME);
};
/**
bool DebugMode;
bool PrintAll;
bool PrintTimeUUid = 0;
bool PrintSHA = 0;
**/
uuid_t uuid;
u_int8_t printRawuuid(uuid_t id) {
		for(int i=0; i < sizeof(uuid_t); i++) {
		fprintf(stdout,"%x ", id[i]);
		}
	fprintf(stdout,"\n");
};
u_int8_t printuuid(uuid_t id) {
	char uuidtext [sizeof(uuid_t)*2 + 5];
	uuid_unparse(uuid,uuidtext);
	fprintf(stdout,"%s\n",uuidtext);
};
int main (int argc, char **argv) {
flag.PrintRaw = 0;
flag.PrintUUid = 0;
flag.Verbose = 0;
flag.PrintAll = 0;
flag.PrintSha = 0;

  char *cvalue = NULL;
  int index;
  int c;
  opterr = 0;
  uuid_generate(uuid);
  while ((c = getopt (argc, argv, "rvhuasC:")) != -1) // r - Raw, v - Verbose, h - Help, u - uuid (defaulted 1), a - print all, s - SHA, C - Sha code
    switch (c)
      {
        case 'u':
        flag.PrintUUid = 1;
	printuuid(uuid);
	break;
      case 'r':
        flag.PrintRaw = 1;
        printRawuuid(uuid);
        break;
      case 'v':
	flag.Verbose = 1;
	break;
	case 'h':
        helptext();
        goto next;
        case 'a':
        flag.PrintAll = 1;
        break;
        case 's':
        flag.PrintSha = 1;
        break;
      case 'C':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'C')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.Try '%s -h' for more information.\n", optopt,PRO_NAME);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
	default:
	abort();
	}
next:
return 0;
/**
	printf("%d,%d,%d\n",DebugMode,PrintRaw,PrintSHA);
	printf("%d\n", sizeof(PrintUUid) );
	uuid_t uuid;
	uuid_generate(uuid);
//uuid raw
        if (PrintUUid==1) { printuuid(uuid); 
//uuid full
	char uuidtext [sizeof(uuid_t)*2 + 5];
	uuid_unparse(uuid,uuidtext);
	printf("\nUUID: %s\n",uuidtext);
//sha1 uuid
**/
}
