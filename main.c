//
// Created by Dario on 14/03/16.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 120

//THIS SHOULD WORK NO MATTER WHAT

bool check(int, int, int);
int ask_for_number();
int rithmics(int);

int main()                                  //Non è il modo più intelligente di fare questa cosa ma penso funzioni
{
    int ans;
    int numb = ask_for_number();
    int tmp = rithmics(numb);
    printf("\nWhat's your guess?\n");
    scanf("%d", &ans);
    check(ans, tmp, numb);
}

int ask_for_number()
{
    char s[MAX];
                                            //potrei fare un controllo con isdigit(numb) per vedere se la prima cifra è un numero
    printf("\nInsert your number:\n");      //l'utente medio per creare problemi non andrà oltre
    fgets(s, sizeof(s), stdin);
    long int numb;
    numb = atoi(s);
    if (numb <= 0)
    {
        printf("\nYou've entered an invalid number\n");
        return ask_for_number();
    }
    else {
        return numb;
    }
}


int rithmics(int numb)
{
    int fact, tmp;
    fact = 2;
    tmp = 0;
    while (fact <= numb)
    {
        tmp += numb / fact;
        fact = fact * 2;
    }
    return tmp;
}

bool check(int ans, int tmp, int numb)
{
    if(tmp == ans)
    {
        printf("\nYour deduction was right, %d! have %d consecutive zeros\n", numb, tmp);
        return true;
    }
    else
    {
        printf("Nope, right answer was %d ", tmp);
        return false;
    }
}
