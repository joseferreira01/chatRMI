#include "acoes.h"
/*Limpa a tela*/
void cls(void)
{
    #ifdef linux
    //código especifico para linux
    //system ("clear");//poderia ser este mas escolhi este outro pois é mais a cara do C
    printf("\e[H\e[2J");
    #elif defined WIN32
    //código específico para windows
    system ("cls");
    #else
    //outro sistema
    #endif

}
/*Pausa o sistema*/
void pause(void)
{
    #ifdef linux
    //código especifico para linux
    char _a;
    printf("Pressione qualquer tecla para continuar... ");
    setbuf(stdin,NULL);
    scanf("%[^\n]c",&_a);
    #elif defined WIN32
    //código específico para windows
    system ("pause");
    #else
   	//outro sistema
    #endif

}
