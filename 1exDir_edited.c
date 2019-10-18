/*
 * C Program to List Files in Directory
 */
#include <dirent.h>
#include <stdio.h>
#include <string.h>
// #include <sys/socket.h>

int main(void)
{
    DIR *d;
    struct dirent *dir;
    char msg[256];
    d = opendir("/dev");//specified in POSIX.1-2001.
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            switch(dir->d_type) {
                case(DT_BLK): strcpy(msg, "block device"); break;
                case(DT_CHR): strcpy(msg, "character device"); break;
                case(DT_DIR): strcpy(msg, "directory"); break;
                case(DT_FIFO): strcpy(msg, "pipe"); break;
                case(DT_LNK): strcpy(msg, "symbolic link"); break;
                case(DT_REG): strcpy(msg, "regular file"); break;
                case(DT_SOCK): strcpy(msg, "socket"); break;
                case(DT_UNKNOWN): strcpy(msg, "File type could not be determined"); break;
                default: strcpy(msg," ");
            }
            // printf("File inode: %ld \t File name: %s \t "
            //     "File type: %d \t File size: %d (%s)\n", 
            //     dir->d_ino, dir->d_name, dir->d_type, dir->d_reclen,
            //     msg);
            printf("File name: %s \t type: %s\n", dir->d_name,msg);
        }
        closedir(d);
    }
    return(0);
}
