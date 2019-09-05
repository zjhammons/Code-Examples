// This is my code
// Zach Hammons
// CS366\fP

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <utime.h>
#include <sys/stat.h>

//Purpose: copies file
//Input: filepointer
//Output: no output on success
void duplicateFile(FILE *name)
{
    char newCopyName[100];
    char c;
    FILE *copyFile;
    long length;
    
    //enter name for copied file
    printf("Enter destination name: ");
    scanf(" %s", newCopyName);
    
    //open new file and copies each character from old to new file
    copyFile = fopen(newCopyName, "w");
    fseek(name, 0L, SEEK_END);
    length = ftell(name);
    fseek(name, 0L, SEEK_SET);
    while (length--)
    {
        c = fgetc(name);
        fputc(c, copyFile);
    }
    fclose(name);
    fclose(copyFile);
}

//Purpose: rename file
//Input: name of file
//Output: no ouput on success
void renameFile(char* name)
{
    int x = 0;
    char newName[100];
    
    printf("Enter new file name: ");
    scanf(" %s", newName);
    
    // rename function
    x = rename(name, newName);
    if (x != 0)
    {
        perror("DID NOT RENAME!!!");
    }
}

//Purpose: Unlink/Delete file
//Input: name of the file
//Output: nothing on success
void unlinkFile(char * name)
{
    int success;
    success = unlink(name);
    // returns 0 if succesfuly deleted
    if (success != 0)
    {
        perror("DID NOT UNLINK!!!!");
    }
}

//Purpose: truncate file
//Input: name of file
//Output: no output on success
void truncateFile(char* name)
{
    //truncate function
    int success;
    success = truncate(name, 0);
    if (success != 0)
    {
        perror("DID NOT TRUNCATE!!!");
    }
}

//Purpose: appends one file to another and saves as a new file
//Input: file1 pointer, file2 to appened, new name for appended file
//Output: no output on success, new file will be created with name user gives
void appendFile(FILE *file1)
{
    FILE *file2, *appendedFile;
    char c,otherFile[100], newFile[100];
    
    printf("Enter other file to appened: ");
    scanf(" %s", otherFile);
    printf("Enter name of new file: ");
    scanf(" %s", newFile);
    
    // open file2
    file2 = fopen(otherFile, "r");
    if (file2 == NULL)
    {
        perror("ERROR!");
    }
    
    //open new file for writting
    appendedFile =fopen(newFile, "w");
    if (appendedFile == NULL)
    {
        perror("ERROR");
    }
    //put all file1 in first
    while((c = fgetc(file1)) != EOF)
    {
        fputc(c, appendedFile);
    }
    // then loop through second file after
    while ((c = fgetc(file2)) != EOF)
    {
        fputc(c, appendedFile);
    }
    fclose(file1);
    fclose(file2);
    fclose(appendedFile);
    
}

//Purpose: get last 100 bytes from file
//Input: file pointer
//Output: last 100 bytes
void last100(FILE *name)
{
    const int x = 100; 
    long length;
    char c;
    
    //get last 100 bytes
    fseek(name, 0, SEEK_END);
    length = ftell(name);
    fseek(name, (length - x), SEEK_SET);
    
    //print the 100 bytes
    do
    {
        c = fgetc(name);
        putchar(c);
    }
    while (c != EOF);
    
    fclose(name);
}

//Purpose: list current file contents to /dev/tty
//Input: file pointer
//Output:file contents in /dev/tty
void catFile(FILE *name)
{
    char c;
    FILE *devFile;
    long length;
    //open /dev/tty and write file contents to it
    devFile = fopen("/dev/tty", "w");
    fseek(name, 0L, SEEK_END);
    length = ftell(name);
    fseek(name, 0L, SEEK_SET);
    if (length ==0 )
    {
     printf("FILE EMPTY!\n");
     fclose(name);
     fclose(devFile);
     return;
    }
    while (length--)
    {
        c = fgetc(name);
        fputc(c, devFile);
    }
    fclose(name);
    fclose(devFile);
    
}

//Purpose: change permisisons of file
//Input: file name
//Output: no output on success
void changeMode(char *name)
{
    unsigned int mode;
	
    printf("Enter new file mode in octal 0000-0777: ");
    scanf(" %o", &mode);
    //printf("mode decimal: %d\n", mode);
    //printf("mode octal: %o\n", mode);

    if (chmod(name, mode) != 0)
     {
        perror("ERROR! FILE PERMISSIONS NOT CHANGED!\n");
     }	
}

int main(int argc, char * argv[])
{
    int i;
    FILE *fp;
    
    // loop to proccess all files entered
    for ( i = 1; i < argc; i++ )
    {
        if ( (fp = fopen(argv[i], "r")) == NULL )
        {
            perror("COULD NOT OPEN FILE!!!");
            return 0;
        }
        else
        {
            char command;
            char *fileName = argv[i]; // gets name of file
            printf("File " "%s: " , fileName);
            
            printf("Command:");
            scanf(" %c", &command);
            
            //switch stament based on user input
            switch (command)
            {
                case 'c':
                    catFile(fp);
                    break;
                    
                case 'd':
                    duplicateFile(fp);
                    break;
                    
                case 'r':
                    renameFile(fileName);
                    break;
                    
                case 'u':
                    unlinkFile(fileName);
                    break;
                    
                case 't':
                    truncateFile(fileName);
                    break;
                    
                case 'a':
                    appendFile(fp);
                    break;
                    
                case 'l':
                    last100(fp);
                    break;
                    
                case 'm':
                    changeMode(fileName);
                    break;
                                
                case 'n':
                    break;
                    
                case 'q':
                    return 0; // quit
                    
                // if wrong command entered notify and exit...
                default:
                    printf("Please enter the correct command...\n");
                    fclose(fp);
                    break;
            }
        }
    }
}
