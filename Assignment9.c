#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    int ch;

    
    printf("Enter source file path: ");
    scanf("%99s", sourcePath);

    printf("Enter destination file path: ");
    scanf("%99s", destPath);

    
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile); // Close source file before exiting
        return 1;
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

   
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

      
    
