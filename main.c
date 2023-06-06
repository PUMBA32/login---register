#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define REGISTR                 1
#define LOGIN                   2

void Registration()
{
    FILE *file = fopen("data.txt", "a");
    char name[100];
    long long pass;

    printf("User-Name (no more than 100 characters): ");
    scanf("%s", &name);

    printf("Password (only numbers): ");
    scanf("%lld", &pass);

    printf("\n=======================\n");
    printf("Name: %s", name);
    printf("\nPassword: %lld", pass);
    printf("\n====You Registred!=====\n\n");

    fprintf(file, "%s %lld \n", name, pass); 
    fclose(file);
}

void Login()
{
    FILE *file = fopen("data.txt", "r");
    char name[100], buffer[256], sep[10]=" ", *istr;
    long long pass;
    bool isLogined = false;

    printf("Enter your user-name: ");
    scanf("%s", &name);

    printf("Enter your password: ");
    scanf("%lld", &pass);


    while((fgets(buffer, 256, file)) != NULL)
    {
        char str_name[100], str_pass[100]; // полученные данные из файла
        long long res_pass; //сюда запишем преобразованный пароль из файла

        //Получаем ник
        istr = strtok(buffer, sep);
        strcpy (str_name, istr);
        
        //Получаем пароль
        istr = strtok (NULL, sep);
        strcpy (str_pass, istr);  
        
        //Преобразуем полученый пароль в число
        res_pass = atoll(str_pass);

        //Сравниваем полученные данные с введеными
        if(strcmp(str_name, name) == 0) {
            if(pass == res_pass) {
                printf("\nYOU LOGINED!");
                isLogined = true;
                break;
            }            
        }
    }

    if(!isLogined) {
        printf("\nLOGINED FAILED!");
    }

    fclose(file);
}

int main(void)
{   
    int mes;
    printf("Registration - [1]; Login - [2]\n->");
    scanf("%d", &mes);

    switch (mes)
    {
        case REGISTR:
            Registration();
            break;
        case LOGIN:
            Login();
            break;
        default:
            printf("!Error!");
            return 0;
            break;
    }
    return 0;
}