#include <syslog.h>
#include <stdio.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* argv[]) {
	
	openlog(NULL, LOG_CONS, LOG_USER);

	if(argc !=3) {
		printf("Usage : %s <directory\\file> <string>\n",argv[0]);
		syslog(LOG_ERR,"Invalid number of arguments: %d",argc);
		return 1;
	}

	syslog(LOG_INFO,"Writing %s to %s",argv[2],argv[1]);

	FILE *file;
        file = fopen(argv[1],"w");
	if(file) {
		fprintf(file,"%s\n",argv[2]);
		fclose(file);
	} else {
		printf("Error creating file %s: %s\n",argv[2],strerror(errno));
		syslog(LOG_ERR,"Error creating file %s: %s",argv[2],strerror(errno));
		return 1;
	}

	closelog();

	return 0;
}
