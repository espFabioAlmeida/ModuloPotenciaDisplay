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
   
    if(uartBuffer[0] == '$' && uartBuffer[1] == '0' 
        && uartBuffer[2] == '9' && uartBuffer[3] == '0') {
            flagPacoteValidoRecebido = true;
        }

    limpaBufferUart();
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

    if(enviaValor[0] > 9) {
        enviaValor[0] %= 10;
    }
    if(enviaValor[1] > 9) {
        enviaValor[1] %= 10;
    }
    if(enviaValor[2] > 9) {
        enviaValor[2] %= 10;
    }
    if(enviaValor[3] > 9) {
        enviaValor[3] %= 10;
    }

    if(valorModuloPotencia <= VALOR_MINIMO_LIGADO) {
        printf("$,");
        printf("090");
        printf(",0,");
        printf("1,");
        printf("00");
        printf("00");
        printf("0");
        printf(",\r");  
        printf("\n"); 
        return;
    }

    printf("$,");
    printf("090");
    printf(",1,");
    printf("1,");
    printf("%Lu", enviaValor[0]);
    printf("%Lu", enviaValor[1]);
    printf("%Lu", enviaValor[2]);
    printf("%Lu", enviaValor[3]);
    printf("%Lu", enviaValor[4]);
    printf(",\r");  
    printf("\n");  
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
