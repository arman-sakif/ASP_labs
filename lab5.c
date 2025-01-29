#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

// #define BUFF_SIZE 100

void testError(int x){
    if (x == -1){
    fprintf(stderr, "There was an unexpected error!\n");
    exit(1);
}
    
}

int main(){
char *buff1 = malloc(30); //keep a string variable to keep the buff 1 value
long int nbyte;
int offset_mark; //where the current offset is or where I want it to be


mode_t old_mask = umask(0);//save the old mask
umask(0000);

int fd = open("lab5.txt", O_CREAT | O_RDWR, 0755);
testError(fd);

//write the initial string
char *str1 = "Welcome to COMP 8567, University of Windsor";
// puts(str1);
nbyte = write(fd, str1, strlen(str1));
testError(nbyte);


// read university of windsor into buff1
offset_mark = strlen("Welcome to COMP 8567, ");
lseek(fd, offset_mark, SEEK_SET); // Position to start of "University of Windsor"
nbyte = read(fd, buff1, strlen("University of Windsor"));
// puts(buff1);
testError(nbyte);


// Write "School of Computer Science,"
str1 = "School of Computer Science, "; //reusing old variable for efficiency
lseek(fd, offset_mark, SEEK_SET); // Position after "Welcome to COMP 8567"
nbyte = write(fd, str1, strlen(str1));
testError(nbyte);

// Write "University of Windsor" (buff1) immediately after school of computer science
lseek(fd, 0, SEEK_END); // Position after "School of Computer Science,"
nbyte = write(fd, buff1, strlen(buff1));
testError(nbyte);
free(buff1); //last use of buff1


// Insert "-" between "COMP" and "8567"
offset_mark = strlen(" 8567, School of Computer Science, University of Windsor");
lseek(fd, -offset_mark, SEEK_CUR); // Position before "8567"
nbyte = write(fd, "-", 1);
testError(nbyte);


// Write "Winter 2025" 12 positions after the end
lseek(fd, 12, SEEK_END); // Move to the EOF
nbyte = write(fd, "Winter 2025", 11); // Write "Winter 2025"


close(fd);
umask(old_mask); // Restore original umask
// buff1 already freed.

return 0;
}
