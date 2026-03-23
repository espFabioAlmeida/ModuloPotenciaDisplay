///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasProtocoloModuloPotencia
//AUTOR:      Fabio Almeida
//CRIADO:     23/03/2026
//OBSERVACOES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
#define VALOR_MINIMO_LIGADO 200 //proximo a 5%
/*==============================================================================
RECEBE PACOTE MODULO POTENCIA
==============================================================================*/
void recebePacoteModuloPotencia() {
   
}
/*==============================================================================
ENVIA PACOTE MODULO POTENCIA
==============================================================================*/
void enviaPacoteModuloPotencia() {
    unsigned int32 enviaValor[5];
    enviaValor[0] = valorModuloPotencia / 10000;
    enviaValor[1] = valorModuloPotencia / 1000;
    enviaValor[2] = valorModuloPotencia / 100;
    enviaValor[3] = valorModuloPotencia / 10;
    enviaValor[4] = valorModuloPotencia % 10;

    for(unsigned int i = 0; i < 5; i ++) {
        if(enviaValor[i] > 9) {
            enviaValor[i] %= 10;
        }
    }

    if(valorModuloPotencia <= VALOR_MINIMO_LIGADO) {
        printf("$,090,0,1,00000,");
        return;
    }

    printf("$,090,1,1,");
    for(i = 0; i < 5; i ++) {
        printf("%u", enviaValor[i]);
    }
    printf(",\r\n");  
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
