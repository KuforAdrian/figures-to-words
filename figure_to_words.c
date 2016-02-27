/*program thats prints  in
 *  words(english) any number enter in figure 
 * only numbers ranging from 0 - 1000000000000
 * written by nde yanick che*/
#include <stdio.h>
#include <ctype.h>
void unit(unsigned long long );
void tens(unsigned long long );
void hundred(unsigned long long);
void hthousand(unsigned long long);
void hmillion (unsigned long long);
void billion(unsigned long long);
void hbillion(unsigned long long);
unsigned long int k;
//program execution begins
int main(){
    unsigned long long number,temp_number;
    int i,j=0,k,p;
    printf("enter your number in figures\n");
    scanf("%lld",&number);
    
    if(number==0){
        printf("zero\n");
        return 0;
    }
    else if(number==1000000000000){
        printf("one trillion\n");
        return 0;
    }
    temp_number=number;
    //determining the numbers of digit "the variable number" has
    while(temp_number!=0){
        temp_number=temp_number/10;
        j++;
    }
    p=j;

    switch(p){
        case 1:
            unit(number);
            break;
        case 2:
            k=number/10;
            switch(k){
                case 1:
                    if(number==10){printf(" ten\n");}if(number==11){printf(" eleven\n");}
                    if(number==12){printf(" twelve\n");}if(number==13){printf(" thirteen\n");}
                    if(number==14){printf(" fourteen\n");}if(number==15){printf(" fifteen\n");}
                    if(number==16){printf(" sixteen\n");}if(number==17){printf(" seventeen\n");}
                    if(number==18){printf(" eighteen\n");}if(number==19){printf(" nineteen\n");}
                    break;
                case 2:
                    printf(" twenty ");
                    number=number%10;
                    unit(number);
                    break;
                case 3:
                    printf(" thirty  ");
                    number=number%10;
                    unit(number);
                    break;
                case 4:
                    printf(" forty ");
                    number=number%10;
                    unit(number);
                    break;
                case 5:
                    printf(" fifty ");
                    number=number%10;
                    unit(number);
                    break;
                case 6:
                    printf(" sixty ");
                    number=number%10;
                    unit(number);
                    break;
                case 7:
                    printf(" seventy ");
                    number=number%10;
                    unit(number);
                    break;
                case 8:
                    printf(" eighty ");
                    number=number%10;
                    unit(number);
                    break;
                case 9:
                    printf(" ninety ");
                    number=number%10;
                    unit(number);
                    break;
                    }
            break;
        case 3:
            k=number/100;
            unit(k);
            if((number%100)==0){printf(" hundred ");}
            else{
            printf(" hundred and ");}
            number=number%100;
            if(number<10){
            unit(number);}
            else{tens(number);}
            break;
        case 4:
            k=number/1000;
            unit(k);
            printf(" thousand ");
            number=number%1000;
            hundred(number);
            break;
        case 5:
            k=number/1000;
            tens(k);
            printf(" thousand ");
            number=number%1000;
            hundred(number);
            break;

        case 6:
            k=number/1000;
            hundred(k);
            printf(" thousand ");
            number=number%1000;
            hundred(number);
            break;
        case 7:
            k=number/1000000;
            unit(k);
            printf(" million ");
            number=number%1000000;
            hthousand(number);
            break;
        case 8:
            k=number/1000000;
            tens(k);
            printf(" million ");
            number=number%1000000;
            hthousand(number);
            break;
        case 9:
            k=number/1000000;
            hundred(k);
            printf(" million ");
            number=number%1000000;
            hthousand(number);
            break;
        case 10:
            k=number/1000000000;
            unit(k);
            printf(" billion ");
            number=number%1000000000;
            hmillion(number);
            break;
        case 11:
            k=number/1000000000;
            tens(k);
            printf(" billion ");
            number=number%1000000000;
            hmillion(number);
            break;
        case 12:
            k=number/1000000000;
            hundred(k);
            printf(" billion ");
            number=number%1000000000;
            hmillion(number);
            break;
        default:
            printf("\nERROR!!!!!sorry this program supports number from zero to one trillion\n\n");
            return 0;

        }
printf("\n\n\n");
    return 0;
}
//function definition to print from one to nine
void unit(unsigned long long number){
       switch(number){
case 0:
    printf("");
    break;
case 1:
    printf(" one ");
    break;
case 2:
    printf(" two ");
    break;
case 3:
    printf(" three ");
    break;
case 4:
    printf(" four ");
    break;
case 5:
    printf(" five ");
    break;
case 6:
    printf(" six ");
    break;
case 7:
    printf(" seven ");
    break;
case 8:
    printf(" eight ");
    break;
case 9:
    printf(" nine ");
    break;
    }
}
void tens(unsigned long long number){
    int k;
        k=number/10;
            switch(k){
                case 1:
                    if(number==10){printf(" ten\n");}if(number==11){printf(" eleven\n");}
                    if(number==12){printf(" twelve\n");}if(number==13){printf(" thirteen\n");}
                    if(number==14){printf(" fourteen\n");}if(number==15){printf(" fifteen\n");}
                    if(number==16){printf(" sixteen\n");}if(number==17){printf(" seventeen\n");}
                    if(number==18){printf(" eighteen\n");}if(number==19){printf(" nineteen\n");}
                    break;
                case 2:
                    printf(" twenty ");
                    number=number%10;
                    unit(number);
                    break;
                case 3:
                    printf(" thirty  ");
                    number=number%10;
                    unit(number);
                    break;
                case 4:
                    printf(" forty ");
                    number=number%10;
                    unit(number);
                    break;
                case 5:
                    printf(" fifty ");
                    number=number%10;
                    unit(number);
                    break;
                case 6:
                    printf(" sixty ");
                    number=number%10;
                    unit(number);
                    break;
                case 7:
                    printf(" seventy ");
                    number=number%10;
                    unit(number);
                    break;
                case 8:
                    printf(" eighty ");
                    number=number%10;
                    unit(number);
                    break;
                case 9:
                    printf(" ninety ");
                    number=number%10;
                    unit(number);
                    break;
        }
}
void hundred(unsigned long long number){
k=number/100;
            unit(k);
            printf(" hundred and ");
            number=number%100;
            if(number<10){
            unit(number);}
            else{tens(number);}
}
void hthousand(unsigned long long number){
k=number/1000;
            hundred(k);
            printf(" thousand ");
            number=number%1000;
            hundred(number);
}
void hmillion(unsigned long long number){
k=number/1000000;
            hundred(k);
            printf(" million ");
            number=number%1000000;
            hthousand(number);
}
