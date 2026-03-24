///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityAnalog 
//AUTOR:      Fabio Almeida
//CRIADO:     11/06/2020
//OBSERVAÇÕES:   
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
CONSTANTES DO ARQUIVO                                       
==============================================================================*/
#define MAX_ADC 1023
#define MAX_MODULO_POTENCIA 4095
/*==============================================================================
LEITURA POTENCIOMETRO
==============================================================================*/ 
void leituraPotenciometro() {
    unsigned int32 valorAnalog = MAX_ADC - read_adc();
    valorModuloPotencia = valorAnalog;
    valorModuloPotencia *= MAX_MODULO_POTENCIA;
    valorModuloPotencia /= MAX_ADC;

    valorAnalog *= 100;
    valorAnalog /= MAX_ADC;
    percentual = valorAnalog;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/ 
