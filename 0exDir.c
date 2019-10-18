/*
 * C Program to List Files in Directory
 */
#include <dirent.h>
#include <stdio.h>
// #include <sys/stat.h>

int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");//specified in POSIX.1-2001.
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("File inode: %ld \t File name: %s \t File type: %d \t File size: %d\n", dir->d_ino, dir->d_name, dir->d_type, dir->d_reclen);
        }
        closedir(d);
    }
    return(0);
}
//ask students to write code which prints file type names, not numbers