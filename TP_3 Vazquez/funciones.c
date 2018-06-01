#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int cargaArchivo(eMovie* pelis)
{
  int retorno = -1;
    FILE* pMovie;

    Inicializar(pelis);

    pMovie=fopen("movies.dat","rb");
    if(pMovie==NULL)
    {
        pMovie=fopen("movies.dat","wb");
        if(pMovie==NULL)
        {
            printf("No se pudo abrir el archivo");
            system("pause");
            return retorno;
        }
    }
    fread(pelis,sizeof(eMovie),TA,pMovie);
    retorno = 0;
    printf("El archivo ha sido cargado\n");
    printf("\n");
    system("pause");
    system("cls");
    fclose(pMovie);
    return retorno;
}

Inicializar(eMovie* pelis)
{
    int i;
    for(i=0; i < TA; i++)
    {
        pelis[i].estado = 0;
        pelis[i].id = 0;
    }
}
validaIngresoDatos(eMovie* pelis)
{
    int id;
    char n_id[10];
    int duracion;
    char n_duracion[10];
    int puntaje;
    char n_puntaje[10];
    int validaId = 0;
    int validaTitulo = 0;
    int validaGen = 0;
    int validaDura = 0;
    int validaDesc = 0;
    int validaPunt = 0;
    int validaLink = 0;

    char v_genero[50];
    char v_titulo[100];
    char v_descripcion[1024];
    char v_linkImagen[500];

    char v_generoAux[50];
    char v_tituloAux[100];
    char v_descripcionAux[1024];
    char v_linkImagenAux[500];

    eMovie pelisAux;

    while(validaTitulo == 0)
    {
        printf("Ingrese el titulo de la pelicula\n");
        fflush(stdin);
        gets(v_tituloAux);
        if(strlen(v_tituloAux) <= 100)
        {
            strcpy(v_titulo,v_tituloAux);
            validaTitulo = 1;
        }
        else
        {
            printf("La longitud del titulo debe ser menor o igual 100 \n");
            strcpy(v_titulo,"");
            validaTitulo = 0;
        }
    }

    while(validaGen == 0)
    {
        printf("Ingrese el genero de la pelicula\n");
        fflush(stdin);
        gets(v_generoAux);

        if(strlen(v_generoAux) <= 50)
        {
            strcpy(v_genero,v_generoAux);
            validaGen = 1;
        }
        else
        {
            printf("La longitud del genero debe ser menor o igual 50 \n");
            strcpy(v_genero,"");
            validaGen = 0;
        }
    }

    while(validaDura == 0)
    {
        printf("Ingrese los minutos que dura la pelicula\n");
        scanf("%s",n_duracion);
        if(atoi(n_duracion) != 0)
        {
            duracion = atof(n_duracion);
            validaDura = 1;
        }
        else
        {
            strcpy(n_duracion,"");
            printf("No se ha ingresado una duracion valida, vuelva a cargar sus datos \n");
            validaDura = 0;
        }
    }


    while(validaDesc == 0)
    {
        printf("Ingrese una descripcion de la pelicula\n");
        fflush(stdin);
        gets(v_descripcionAux);
        if(strlen(v_descripcionAux) <= 1024)
        {
            strcpy(v_descripcion,v_descripcionAux);
            validaDesc = 1;
        }else
        {
            printf("La longitud de la descripcion es muy extensa\n");
            strcpy(v_descripcion,"");
            validaDesc = 0;
        }
    }

    while(validaPunt == 0)
    {
        printf("Que puntaje le daria a la pelicula?(entre 1 y 10)\n");
        scanf("%s",n_puntaje);
        if(atoi(n_puntaje) != 0 && atoi(n_puntaje)<=10)
        {
            puntaje = atof(n_puntaje);
            validaPunt = 1;
        }
        else
        {
            strcpy(n_puntaje,"");
            printf("No se ha ingresado un puntaje en rango, vuelva a cargar sus datos \n");
            validaPunt = 0;
        }
    }


    id = GenerarId(pelis);


    while(validaLink == 0)
    {
        printf("Ingrese el link de una imagen de la pelicula\n");
        printf("\n");
        printf("***IMPORTANTE: Para no tipear el link de su buscador, puede copiar el mismo, hacer click derecho sobre la consola y seleccionar la opcion pegar. El Ctrl+V no funciona\n\n");
        fflush(stdin);
        gets(v_linkImagenAux);
        if(strlen(v_linkImagenAux) <= 500)
        {
            strcpy(v_linkImagen,v_linkImagenAux);
            validaLink = 1;
        }else
        {
            printf("Link muy extenso, ingrese uno no mayor a los 500 char\n");
            strcpy(v_linkImagen,"");
            validaLink = 0;
        }
    }

    int pos;
     int retorno = 1;

     if(pelis!=NULL)
     {
        pos= obtenerEspacioLibre(pelis);
        if(pos==-1)
        {
            printf("\nNo queda espacio\n");
            system("pause");
            return -1;
        }
        else
        {
            pelisAux.id=id;
            strcpy(pelisAux.titulo,v_titulo);
            strcpy(pelisAux.genero,v_genero);
            pelisAux.duracion=duracion;
            strcpy(pelisAux.descripcion,v_descripcion);
            pelisAux.puntaje=puntaje;
            strcpy(pelisAux.linkImagen,v_linkImagen);
            pelisAux.estado=1;

            pelis[pos] = pelisAux;

            retorno=0;
            printf("\nCarga realizada");
        }
     }
    return retorno;

}


 int obtenerEspacioLibre(eMovie* pelix)
 {
    int i;
    int posi = 0;
    if(pelix!=NULL)
    {
        for(i=0; i < TA; i++)
        {
            if(pelix[i].estado == posi)
            {
                return i;
            }
        }
    }
    return -1;
 }

 void guardarBinario(eMovie* pelis)
{
    FILE* pMovie;
    pMovie=fopen("movies.dat","wb");
    if(pMovie==NULL)
    {
        printf("Error al abrir\n");
        exit(1);
    }
    fwrite(pelis,sizeof(eMovie),TA,pMovie);
    printf("\nArchivo guardado!\n");
    fclose(pMovie);
}


void generarHtml(eMovie* pelis)
{
    int i;
    FILE* pFile;
    pFile=fopen("index.html","w");
    if(pFile==NULL)
    {
        printf("\nError al abrir el archivo\n");
        exit(1);
    }

    fprintf(pFile,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css' integrity='sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u' crossorigin='anonymous'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "<h1>PELICULAS</small></h1>"
            "</div>"
            "<div class='row'>\n");

    for(i=0;i<TA;i++)
    {
        if(pelis[i].estado!=0)
        {
            fprintf(pFile,"<article class='col-md-4 article-intro'> <a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>",pelis[i].linkImagen);
            fprintf(pFile,"</a><h3><a href='#'> %s</a></h3><ul>",pelis[i].titulo);
            fprintf(pFile,"<li>Id Pelicula: %d</li><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d minutos</li></ul>",pelis[i].id,pelis[i].genero,pelis[i].puntaje,pelis[i].duracion);
            fprintf(pFile,"<p> %s</p></article>",pelis[i].descripcion);
        }
    }

    fprintf(pFile,"</div></div></body></html>");

    fclose(pFile);
    printf("\nArchivo creado con exito!");
}


void mostrarTodo(eMovie* pelis)
{
   int i;
   printf("TITULO\t\tGENERO\tDURACION\tDESCRIPCION\t\t\tPUNTAJE\tLINK\tESTADO\t\n\n");
   for(i = 0; i < TA; i++)
   {
        if(pelis[i].estado == 1)
        {
            printf("\n");
            printf("%s\t%s\t%d\t%s\t%d\t%s\t%d\n\n",pelis[i].titulo,pelis[i].genero,pelis[i].duracion,pelis[i].descripcion,pelis[i].puntaje,pelis[i].linkImagen,pelis[i].estado);
        }
   }
}

void bajaLogica(eMovie* pelis)
{
    int i;
    int auxElim;
    int respuesta;

    if(pelis !=NULL)
    {
        printf("ID\tTITULO\n\n");
        for(i=0;i<TA;i++)
        {
            if(pelis[i].estado==1)
            {
                printf("\n");
                printf("%d\t%s\t\n\n",pelis[i].id,pelis[i].titulo);
            }
        }
        printf("Ingrese el ID de la pelicula a eliminar\n");
        scanf("%d",&auxElim);
        for(i=0;i<TA;i++)
        {
            if(pelis[i].id == auxElim)
            {
               pelis[i].estado = 0;
               printf("La pelicula con el ID %d, ha sido eliminada\n",auxElim);
            }

        }
        if(pelis[i].id != auxElim)
        {
             printf("No existe pelicula con ese ID");
        }
    }

}

int modificar(eMovie*pelis)
{
    int retorno = -1;
    int auxModif;
    int i;
    int opcion;
    int opcionAux;
    char seguir = 's';
    int idN;
    char idV [50];
    int pos;
    int correcto =0;

    char tituloAux[40];
    char generoAux[30];
    int duracionAux;
    char descripcionAux[400];
    int puntajeAux;
    char linkImagenAux[200];

    char a_generoAux[1024];
    char a_tituloAux[1024];
    char a_descripcionAux[1024];
    char a_linkImagenAux[1024];
    char a_duracionAux[1024];
    char a_puntajeAux[1024];

    int validaId = 0;
    int validaTitulo = 0;
    int validaGen = 0;
    int validaDura = 0;
    int validaDesc = 0;
    int validaPunt = 0;
    int validaLink = 0;
    int validaPuntRe = 0;

    char opcionVAux[1024];
    char todoOk = 'n';

    if(pelis !=NULL)
    {
        printf("ID\tTITULO\n\n");
        for(i=0;i<TA;i++)
        {
            if(pelis[i].estado==1)
            {
                printf("\n");
                printf("%d\t%s\t\n\n",pelis[i].id,pelis[i].titulo);
            }
        }
        while(todoOk == 'n')
        {
            printf("Ingrese el ID de la pelicula a modificar\n");
            scanf("%s",&idV);
            if(atoi(idV) != 0)
            {
                idN = atof(idV);
                todoOk='s';
            }
            else
            {
                printf("La id no es correcto, reingrese\n");
            }
        }


        for(i=0;i<TA;i++)
        {
            if(pelis[i].id == idN)
            {
                pos = i;
                correcto = 1;
            }
        }

        if(correcto == 0)
        {
            printf("No existe pelicula con el id ingresado\n");
            retorno = -1;
        }
        else
        {
             while (seguir == 's')
             {
                while(todoOk == 'n')
                {
                    printf("1--Modificar Titulo\n");
                    printf("2--Modificar Genero\n");
                    printf("3--Modificar Duracion\n");
                    printf("4--Modificar Descripcion\n");
                    printf("5--Modificar Puntaje\n");
                    printf("6--Modificar Link de Imagen\n");
                    printf("7--SALIR\n");
                    printf("\n");

                   scanf("%s",&opcionVAux);

                   if(atoi(opcionVAux) != 0)
                   {
                        opcionAux = atof(opcionVAux);
                        if(opcionAux < 1 || opcionAux > 7)
                        {
                            printf("Opcion no valida\n");
                            printf("Vuelva a ingresar\n");
                        }
                        else
                        {
                           opcion = opcionAux;
                           todoOk = 's';
                        }
                   }
                   else
                   {
                        printf("Opcion no valida\n");
                        printf("Vuelva a ingresar\n\n");
                   }
                }

                todoOk = 'n';


                    switch (opcion)
                    {
                        case 1 :
                                while(validaTitulo==0)
                                {
                                    printf("INGRESE EL NUEVO TITULO\n");
                                    fflush(stdin);
                                    gets(a_tituloAux);
                                    if(strlen(a_tituloAux) <= 40)
                                    {
                                        strcpy(tituloAux,a_tituloAux);
                                        validaTitulo = 1;
                                    }
                                    else
                                    {
                                        printf("La longitud del titulo debe ser menor o igual 100 caracteres \n");
                                        strcpy(a_tituloAux,"");
                                        validaTitulo = 0;
                                    }
                                }

                                validaTitulo = 0;

                                if(strcmp(pelis[pos].titulo,tituloAux)==0)
                                {
                                    printf("\nEl titulo ingresado ya existe\n");
                                    break;
                                }
                                else
                                {
                                    strcpy(pelis[pos].titulo,tituloAux);
                                    printf("\nPelicula modificada\n\n");
                                    break;
                                }
                                system("cls");
                                retorno = 1;
                                break;

                       case 2:
                                while(validaGen==0)
                                {
                                    printf("INGRESE EL NUEVO GENERO\n");
                                    fflush(stdin);
                                    gets(a_generoAux);
                                    if(strlen(a_generoAux) <= 30)
                                    {
                                        strcpy(generoAux,a_generoAux);
                                        validaGen = 1;
                                    }
                                    else
                                    {
                                        printf("La longitud del genero debe ser menor o igual 30 caracteres \n");
                                        strcpy(a_generoAux,"");
                                        validaGen = 0;
                                    }

                                }

                                validaGen = 0;

                                if(strcmp(pelis[pos].genero,generoAux)==0)
                                {
                                    printf("\nEl genero ingresado es identico al que ya estaba cargado\n");
                                    break;
                                }
                                else
                                {
                                    strcpy(pelis[pos].genero,generoAux);
                                    printf("\Genero modificado\n\n");
                                    break;
                                }
                                system("cls");
                                retorno = 1;
                                break;

                        case 3:
                                while(validaDura ==0)
                                {
                                    printf("INGRESE LA NUEVA DURACION\n");
                                    fflush(stdin);
                                    gets(a_duracionAux);
                                    if(atoi(a_duracionAux) != 0)
                                    {
                                        duracionAux = atof(a_duracionAux);
                                        validaDura = 1;
                                    }
                                    else
                                    {
                                        printf("Duracion no compatible\n");
                                        validaDura = 0;
                                    }
                                }

                                validaDura = 0;

                                if(duracionAux == pelis[pos].duracion)
                                {
                                    printf("Las duracion ingresada es identica a la que ya estaba cargada");
                                    break;
                                }
                                else
                                {
                                    pelis[pos].duracion = duracionAux;
                                    printf("Cambio realizado\n");
                                    break;
                                }
                                system("cls");
                                retorno = 1;
                                break;

                        case 4:
                                while(validaDesc ==0)
                                {
                                    printf("INGRESE LA NUEVA DESCRIPCION\n");
                                    fflush(stdin);
                                    gets(a_descripcionAux);
                                    if(strlen(a_descripcionAux) <= 400)
                                    {
                                        strcpy(descripcionAux,a_descripcionAux);
                                        validaDesc = 1;
                                    }
                                    else
                                    {
                                        printf("La longitud de la descripcion debe ser menor o igual 400 caracteres \n");
                                        strcpy(a_descripcionAux,"");
                                        validaDesc = 0;
                                    }
                                }

                                validaDesc = 0;

                                if(strcmp(pelis[pos].descripcion,descripcionAux)==0)
                                {
                                    printf("\nLa descripcion ingresada es identica al que ya estaba cargada\n");
                                    break;
                                }
                                else
                                {
                                    strcpy(pelis[pos].descripcion,descripcionAux);
                                    printf("\Descripcion modificada\n\n");
                                    break;
                                }
                                system("cls");
                                retorno = 1;
                                break;


                        case 5:
                                while(validaPunt ==0)
                                {
                                    printf("INGRESE LA NUEVA PUNTUACION\n");
                                    fflush(stdin);
                                    gets(a_puntajeAux);
                                    if(atoi(a_puntajeAux) != 0)
                                    {
                                        puntajeAux = atof(a_puntajeAux);

                                        if(puntajeAux >= 1 || puntajeAux <= 10)
                                        {
                                            validaPunt = 1;
                                        }
                                        else
                                        {
                                            printf("No esta en rango entre 1 -10\n");
                                            validaPunt = 0;
                                        }

                                        validaPunt = 1;
                                    }
                                    else
                                    {
                                        printf("puntaje no compatible\n");
                                        validaPunt = 0;
                                    }
                                }

                                validaPunt = 0;

                                if(puntajeAux == pelis[pos].puntaje)
                                {
                                    printf("El puntaje es identico al cargado previamente\n");
                                    break;
                                }
                                else
                                {
                                    pelis[pos].puntaje = puntajeAux;
                                    printf("Cambio realizado\n");
                                    break;
                                }
                                system("cls");
                                retorno = 1;
                                break;
                        case 6:
                                while(validaLink ==0)
                                {
                                    printf("INGRESE EL NUEVO LINK DE IMAGEN\n");
                                    printf("\n");
                                    printf("***IMPORTANTE: Para no tipear el link de su buscador, puede copiar el mismo, hacer click derecho sobre la consola y seleccionar la opcion pegar. El Ctrl+V no funciona\n\n");
                                    fflush(stdin);
                                    gets(a_linkImagenAux);
                                    if(strlen(a_linkImagenAux) <= 200)
                                    {
                                        strcpy(linkImagenAux,a_linkImagenAux);
                                        validaLink = 1;
                                    }
                                    else
                                    {
                                        printf("La longitud de la descripcion debe ser menor o igual 400 caracteres \n");
                                        strcpy(a_linkImagenAux,"");
                                        validaLink = 0;
                                    }
                                }

                                validaLink = 0;

                                if(strcmp(pelis[pos].linkImagen,linkImagenAux)==0)
                                {
                                    printf("\nEl link ingresado es identico al que ya estaba cargado\n");
                                    break;
                                }
                                else
                                {
                                    strcpy(pelis[pos].linkImagen,linkImagenAux);
                                    printf("\Link modificado\n\n");
                                    break;
                                }
                                system("cls");
                                retorno = 1;
                                break;

                        case 7:
                           seguir = 'n';
                            system("cls");
                            retorno = -1;
                            break;
                    }
                }
        }

        return retorno;
    }
}

int GenerarId(eMovie pelis[])
{
    int i;
    int max = 0;
    int id = -1;

    for(i = 0; i< TA;i++)
    {
        if(pelis[i].id > max)
        {
            max = pelis[i].id;
        }
    }
    id = max + 1;
    return id;
}




