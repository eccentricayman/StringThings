#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************/
/* I LOVE POINTING AT THINGS WITH POINTERS ITS SO MUCH FUN */
/***********************************************************/

int mystrlen(char string[]) {
    int ctr = 0;
    char *cp = string;
    while (*cp) {
        ctr++;
        cp++;
    }
    return ctr;
}

void mystrcpy(char destination[], char source[]) {
    char *destp = destination;
    char *srcp = source;
    while (*srcp) {
        *destp = *srcp;
        srcp++;
        destp++;
    }
    while (*destp) {
        *destp = '\0';
        destp++;
    }
}

void mystrcat(char destination[], char source[]) {
    char *dp = destination;
    char *sp = source;
    int ctr = 0;
    while (ctr < mystrlen(destination)) {
        dp++;
        ctr++;
    }
    while (*sp) {
        *dp = *sp;
        dp++;
        sp++;
    }
    
}

int mystrcmp(char s1[], char s2[]) {
    return (mystrlen(s1) - mystrlen(s2));
}

//char * mystrchr() {
//    char *sadpointer = ":'(";
//    return sadpointer;
//}

int main() {
    //feelin dr. seuss-y today
    char s1[] = "I will pick up the hook and you\'ll see something new, ";
    char s2[] = "for now we shall call them String 1 and String 2.";
    char s3[strlen(s1) + strlen(s2)];
    char s4[strlen(s1) + strlen(s2)];

    printf("s1: %s \n", s1);
    printf("s2: %s \n\n", s2);

    //testing lengths
    printf("Testing lengths... \n");
    printf("strlen s1: %lu \n", strlen(s1));
    printf("mystrlen s1: %d \n\n", mystrlen(s1));

    //testing copies
    printf("Testing copy... \n");
    strcpy(s3, s1);
    printf("strcpy s2 -> s3: %s \n", s3);
    s3[0] = '\0';
    mystrcpy(s3, s1);
    printf("mystrcpy s2 -> s3: %s \n\n", s3);

    //testing concatenate
    strcat(s3, s2);
    printf("strcat s2 + s3 -> s3: %s \n", s3);

    strcpy(s4, s1);
    mystrcat(s4, s2);
    printf("mystrcat s2 + s4 -> s4: %s \n\n", s4);

    //testing compare
    printf("strcmp s3 & s4: %d \n", strcmp(s3, s4));
    printf("mystrcmp s3 & s4: %d \n\n", mystrcmp(s3, s4));

    //testing locate character
    //on the next episode of dbz...
}
