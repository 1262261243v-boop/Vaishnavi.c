#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[256], destPath[256];
    int ch;

    printf("Enter source file name: ");
    if (scanf("%255s", sourcePath) != 1) {
        printf("Invalid source file name.\n");
        return 1;
    }

    printf("Enter destination file name: ");
    if (scanf("%255s", destPath) != 1) {
        printf("Invalid destination file name.\n");
        return 1;
    }

    // Open source file in read mode ("r")
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file in write mode ("w") — creates if absent, overwrites if present
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    // Read character by character until EOF and write to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully from '%s' to '%s'.\n", sourcePath, destPath);

    // Close both file streams
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
