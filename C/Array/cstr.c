#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int strlength(char *);
int strlength1(char *);
void toggleCase(char *);
void reverse(char[]);
void reverse1(char[]);
void countVowCons(char *);
int isPalindrome(char *);
int stringComp(char *, char *);
void findDuplicates(char []);
void findDuplicates1(char *);
void findDuplicate2(char *);
int isAnagram(char *);

int main(){
    char *arg = "Hello";
    char str[] = "WeLcOmE";
    printf("The length of the string is %d \n", strlength1(arg));
    toggleCase(str);
    reverse1(str);
    char *str1 = "findings";
    findDuplicate2(str1);
    return 0;
}

int strlength(char *str){
    int i;
    for (i=1; str[i] != '\0'; i++){}
    return i;
}

int strlength1(char *str){
    int count = 0;
    while (*str++ !='\0'){
        count++;
    }

    return count;

}

void toggleCase(char str[]){
   for (int i = 0; str[i] != 0; i++ ){
        if (str[i] > 65 && str[i] < 91)
            str[i] += 32;
        else if (str[i] > 97 && str[i] <= 122)
            str[i] -= 32;
   }

    printf("Modified string is: %s\n", str);
}

void reverse(char str[]){
    char result[10];
    int i, j;
    j = strlength(str) - 1;
    for (i = 0; str[i] != 0; i++, j--)
        result[i] = str[j];
    result[i] = '\0';
    printf("Reversed string is: %s\n", result);

}

void reverse1(char str[]){
    int i, j;
    i = 0;
    j = strlength(str) - 1;
    while (i < j){
        char t = str[i];
        str[i++] = str[j];
        str[j--] = t;    
    }
    printf("Reversed string is: %s\n", str);

}

void findDuplicates(char str[]){

    for (int i = 0; str[i+1] != 0; i++){
        int count = 1;
        if (str[i] != -1){
            for (int j = i+1; str[j] != 0; j++){
                if (str[i] == str[j]){
                     count++;
                    str[j] = -1;
                }
            }
            if (count > 1)
            printf("The duplicate character is %c, count is %d\n", str[i], count);
        }
    }
}

void findDuplicates1(char *str){
    int H[26] = {0};
    while (*str++){
        H[(*str-97)]++;
    }
    for (int i = 0; i < 26; i++){
        if (H[i] > 1 ){
            printf ("Find duplicates : %c, count is: %d\n", i+97, H[i] );
        }
    }
}

void findDuplicate2(char *str){
    int bitVector;
    int x = 1;
    while (*str++){
        x = x<<(*str-97);
        if (bitVector&x){
            printf("Find duplicate %c\n", *str);
        }
        bitVector = bitVector|x;
        x = 1;
       
    }
    
}