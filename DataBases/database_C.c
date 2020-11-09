//gcc database_C.c $(mysql_config --libs) -o database_C $(mysql_config --cflags) 

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

MYSQL *conexion;
MYSQL_RES *respuesta;
MYSQL_ROW row; //consulta

char *server = "localhost";
char *user = "root";
char *password = "Password";
char *database = "BaseDatso";

char consulta[100];
char users[50];

void main(){
    conexion = mysql_init(NULL);
    if(!mysql_real_connect(conexion,server,user,password,database,0,NULL,0)){
        printf("%s\n",mysql_error(conexion));
        exit(1);
    }

    //Comandos
    if(mysql_query(conexion,"show tables;")){
        printf("%s\n",mysql_error(conexion));
        exit(1);
    }
    respuesta = mysql_use_result(conexion);

    printf("Las tablas de datos son \n");
    while ((row = mysql_fetch_row(respuesta)) != NULL){
        printf("%s\n",row[0]);
    }

    printf("Ingrese el usuario:"); scanf("%s",users); while (getchar() != '\n');
    sprintf(consulta,"select *  from Users where username = '%s';",users);


    if(mysql_query(conexion,consulta)){
        printf("%s\n",mysql_error(conexion));
        exit(1);
    }

    respuesta = mysql_use_result(conexion);

    printf("Los datos son:");
    while ((row = mysql_fetch_row(respuesta)) != NULL){
        int l =0 ;
        while (row[l+1]!=NULL){
            printf("%s\n",row[l]);
            l++;
        }
    }
    
    //Cerramos conexion
    mysql_free_result(respuesta);
    mysql_close(conexion);
}
