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

char * mystrcpy(char destination[], char source[]) {
    char *destp = destination;
    char *srcp = source;
    while (*srcp) {
        *destp = *srcp;
        srcp++;
        destp++;
    }
    *destp = '\0';
    return destination;
}

char * mystrncpy(char destination[], char source[]) {
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
    return destination;
}

char * mystrcat(char destination[], char source[]) {
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
    return destination;
}

char * mystrncat(char destination[], char source[], int max) {
    char *dp = destination;
    char *sp = source;
    int ctr = 0;
    while  (ctr < mystrlen((destination))) {
        dp++;
        ctr++;
    }
    while (*sp && max) {
        *dp = *sp;
        dp++;
        sp++;
        max--;
    }
    return destination;
}

int mystrcmp(char s1[], char s2[]) {
    char *p1 = s1;
    char *p2 = s2;
    while (*p1 == *p2 && *p1 && *p2) {
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

char * mystrchr(char string[], char c) {
    char *sp = string;
    while (*sp) {
        if (*sp == c) {
            return sp;
        }
        sp++;
    }
    return NULL;
}

char * mystrstr(char big[], char little[]) {
    char *bp = big;
    char *lp = little;
    char *sp = NULL;
    while (*bp) {
        if (!(*lp)) {
            return sp;
        }
        if (*bp == *lp && sp == NULL) {
            sp = bp;
            bp++;
            lp++;
        }
        else if (*bp == *lp && sp != NULL) {
            bp++;
            lp++;
        }
        else if (*bp != *lp && sp == NULL) {
            bp++;
         }
        else if (*bp != *lp && sp != NULL) {
            sp = NULL;
            lp = little;
        }
    }
    return sp;
}

int main() {
    //feelin dr. seuss-y today
    char s1[] = "I will pick up the hook and you\'ll see something new, ";
    char s2[200] = "for now we shall call them String 1 and String 2.";
    char s3[mystrlen(s1) + mystrlen(s2) + 1];
    char s4[mystrlen(s1) + mystrlen(s2) + 1];

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
    printf("Testing concatenate... \n");
    strcat(s3, s2);
    printf("strcat s2 + s3 -> s3: %s \n", s3);

    strcpy(s4, s1);
    mystrcat(s4, s2);
    printf("mystrcat s2 + s4 -> s4: %s \n\n", s4);

    //testing compare
    printf("Testing compare... \n");
    printf("strcmp s3 & s4: %d \n", strcmp(s3, s4));
    printf("mystrcmp s3 & s4: %d \n\n", mystrcmp(s3, s4));

    //testing locate character
    printf("Testing locate character... \n");
    printf("strchr w in s1: %c \n", *strchr(s1, 'w'));
    printf("mystrchr w in s1: %c \n\n", *mystrchr(s1, 'w'));

    //testing substring
    printf("Testing substring... \n");
    printf("strstr 'will' in s1: %c \n", *strstr(s1, "will"));
    printf("mystrstr 'will' in s1: %c \n", *mystrstr(s1, "will"));
}
