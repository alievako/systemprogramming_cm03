/**
 * C program to check whether a file exists or not.
 */
#include <stdio.h>
#include <unistd.h>
// #include <io.h>
#include <sys/stat.h>

int isFileExists(const char *path);
int isFileExistsAccess(const char *path);
int isFileExistsStats(const char *path);
int filePermissions(const char *path);

int main()
{   char path[100];
    printf("Enter source file path: ");
    scanf("%s", path);
    // Check if file exists or not
    if (isFileExistsAccess(path))
        printf("File exists at path '%s'\n", path);
    else
        printf("File does not exists at path '%s'\n", path);
    filePermissions(path);
    return 0;
}

/**
 * Function to check whether a file exists or not.
 * It returns 1 if file exists at given path otherwise
 * returns 0.
 */
int isFileExists(const char *path)
{   // Try to open file
    FILE *fptr = fopen(path, "r");
    // If file does not exists
    if (fptr == NULL)
        return 0;
    // File exists hence close file and return true.
    fclose(fptr);
    return 1;
}

/**
 * Function to check whether a file exists or not using
 * access() function. It returns 1 if file exists at
 * given path otherwise returns 0.
 */
int isFileExistsAccess(const char *path)
{   // Check for file existence
    if (access(path, F_OK) == -1) //doesn't exist
        return 0;
    return 1;
}

/**
 * Function to check whether a file exists or not using
 * stat() function. It returns 1 if file exists at
 * given path otherwise returns 0.
 */
int isFileExistsStats(const char *path)
{   struct stat stats;
    stat(path, &stats);
    // Check for file existence
    if (stats.st_mode & F_OK)
        return 1;
    return 0;
}

int filePermissions(const char *path){
    struct stat fileStat;
    stat(path, &fileStat);
    printf("--------------------------\n");
    printf("Permissions of the file: \n");
    printf( ( __S_IREAD) ? "r" : "-");
    printf( (__S_IWRITE) ? "w" : "-");
    printf( (__S_IEXEC) ? "x" : "-");
    printf("-");
    printf( (S_IRUSR) ? "r" : "-");
    printf( (S_IWUSR) ? "w" : "-");
    printf( (S_IXUSR) ? "x" : "-");
    printf("-");
    printf( (S_IRGRP) ? "r" : "-");
    printf( (S_IWGRP) ? "w" : "-");
    printf( (S_IXGRP) ? "x" : "-");
    printf("-");
    printf( (S_IROTH) ? "r" : "-");
    printf( (S_IWOTH) ? "w" : "-");
    printf( (S_IXOTH) ? "x" : "-");
    printf("\n\n");
    printf("File mode is %07o\n", fileStat.st_mode); //explain output numbers

}
