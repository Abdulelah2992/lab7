#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int CW(FILE *ptr) {
	ptr = fopen("/home/it/lab7/lab7/task2/task2test.txt", "r");
    if (ptr == NULL) {
    printf("Memory allocation failed.\n");
           exit(0);}
    int word = 0, flag = 0;
    char t;
    while ((t = fgetc(ptr)) != EOF) {
        if (isspace(t)) {
            if (flag) {
                word++;
                flag = 0;  }
        } else {
            flag = 1;}}
    if (flag) word++;
    fclose(ptr);
    return word;}

int CL(FILE *ptr) {
    ptr = fopen("/home/it/lab7/lab7/task2/task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);}
    int line = 0;
    char temp;
    while ((temp = fgetc(ptr)) != EOF) {
        if (temp == '\n') line++;}
    fclose(ptr);
    return line;}

int CC(FILE *ptr) {
    ptr = fopen("/home/it/lab7/lab7/task2/task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);}
    int character = 0;
    char temp;
    while ((temp = fgetc(ptr)) != EOF) {
        character++;}
    fclose(ptr);
    return character;}

int main() {
    FILE *ptr = fopen("/home/it/lab7/lab7/task2/task2test.txt", "r");
    if (!ptr) {
        printf("Error: file did not open!\n");
        exit(1);}
    printf("Lines: %d\n", CL(ptr));
    printf("Characters: %d\n", CC(ptr));
    printf("Words: %d\n", CW(ptr));
    fclose(ptr);
    return 0;}

