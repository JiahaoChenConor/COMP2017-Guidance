/*
https://utcc.utoronto.ca/~cks/space/blog/unix/ReaddirOrder : the order of file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUF_SIZE (1024)
/* grep each file in the directory using the
    * "/usr/bin/grep" binary
    *
    * Each file should grep with a different process.
    * The return code of this program should be:
    * 0 if found
    * >0 if not found
    * -1 if directory non-existent, missing command line arguments
*/
int main (int argc, char **argv)
{
    DIR *src_dir;
    // Ensure correct argument count.
    if (argc != 3)
    {
        printf ("Usage: grep_dir <dir> <pattern>\n");
        return -1;
    }

    // Ensure we can open directory.
    src_dir = opendir (argv[1]);
    if (src_dir == NULL)
    {
        printf ("Failed to open directory '%s'\n", argv[1]);
        return 2;
    }

    struct dirent *src_dirent;
    // Process each entry

    while (1)
    {
        src_dirent = readdir(src_dir);
        if (src_dirent == NULL)
            break;

        // we only need a normal file, we do not need directory/pipe file... man 3 readdir
        if (src_dirent -> d_type == DT_REG){
            printf ("[%s]\n", src_dirent->d_name);
            char buf[BUF_SIZE];
            snprintf(buf, BUF_SIZE, "%s/%s", argv[1], src_dirent->d_name);
            // printf("%s\n", buf);

            pid_t pid = fork();

            if (pid < 0) {
                perror("unable to fork");
                return 1;
            }
            if (pid == 0) {
                // grep string_to_match file_path
                execl("/usr/bin/grep", "grep", argv[2], buf);
                return 0;
            } else {
                wait(NULL);
            }
            
        }
        
    }

    closedir (src_dir);
    return 0;
}
