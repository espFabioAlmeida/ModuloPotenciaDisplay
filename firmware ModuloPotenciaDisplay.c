////////////////////////////////////////////////////////////////////////////////                                          
//PROJETO:   ModuloPotenciaDisplay                                                                                              
//CLIENTE:   AUTOMASENSOR                                                                                                               
//CONTATO:   RICARDO KADOTA                                                                                               
//TELEFONE:                                                                                                                 
////////////////////////////////////////////////////////////////////////////////
//AUTOR:    FABIO EDUARDO DE ALMEIDA
//TELEFONE: 47 98411-2998                                                                  
//E-MAIL:   teg.fabio.almeida@gmail.com               
////////////////////////////////////////////////////////////////////////////////
//COMPILADOR: CCS 5.028   
////////////////////////////////////////////////////////////////////////////////                
#include <16F1936.h>          
#define VERSAO_FIRMWARE 1 
#device ADC=10
/*==============================================================================
CONFIGURACOES                          
==============================================================================*/
#fuses INTRC_IO, NOWDT, PUT, PROTECT, BROWNOUT, NOLVP, NOCPD 
#use delay(clock = 16000000)  
#use rs232(baud=9600, parity=N, xmit=PIN_C6, rcv=PIN_C7, enable=PIN_B5, bits=8, ERRORS)
#priority RDA, TIMER1          
/*==============================================================================
CONSTANTES                         
==============================================================================*/
#define on           output_high         
#define off          output_low  

#define TAMANHO_UART_BUFFER   32
/*==============================================================================
DEFINICOES DOS PINOS                                      
==============================================================================*/
#define DISPLAY_A   PIN_C1
#define DISPLAY_B   PIN_C3
#define DISPLAY_C   PIN_A2
#define DISPLAY_D   PIN_A5
#define DISPLAY_E   PIN_C0
#define DISPLAY_F   PIN_C2
#define DISPLAY_G   PIN_A1
#define DISPLAY_PD  PIN_A3

#define DISPLAY_UNID    PIN_C4
#define DISPLAY_DEZE    PIN_C5
#define DISPLAY_CENT    PIN_B0
/*==============================================================================
VARIAVEIS
==============================================================================*/ 
int1 
   flagLeituraAnalogica = false,

   flagEnviaPacoteUart = false,
   flagPacoteUart = false,
   flagPacoteValidoRecebido = false,

   flagAcionaPontoDecimal = false;

unsigned int
   percentual = 0,

   contUartBuffer = 0;

unsigned int32
   valorModuloPotencia = 0;

char
   uartBuffer[TAMANHO_UART_BUFFER];
/*==============================================================================
VARIAVEIS ARRAY
==============================================================================*/
/*==============================================================================
ARQUIVOS ANEXOS
==============================================================================*/
#include <UtilityAnalog.c>
#include <UtilityCOM.c>
#include <SubrotinasProtocoloModuloPotencia.c>
#include <SubrotinasDisplay.c>
#include <InterrupcaoTimer1.c>
/*==============================================================================
MAIN                                           
==============================================================================*/
void main() {                              
   setup_oscillator(OSC_16MHZ);  
   setup_adc(adc_clock_internal);
   setup_adc_ports(sAN0);
   set_adc_channel(0);
                            
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_4);       
   setup_timer_2(T2_DISABLED, 0, 1); 
   
   delay_ms(500);  
                                                                                                    
   enable_interrupts(GLOBAL); 
   enable_interrupts(INT_TIMER1);
   enable_interrupts(INT_RDA);

   while(true) {
      
      if(flagLeituraAnalogica) {
         flagLeituraAnalogica = false;
         leituraPotenciometro();
      }

      if(flagPacoteUart) {
         flagPacoteUart = false;
         recebePacoteModuloPotencia();
      }

      if(flagEnviaPacoteUart) {
         flagEnviaPacoteUart = false;
         enviaPacoteModuloPotencia();
      } 
   }                                                   
}                          
/*==============================================================================
FIM DO FIRMWARE
==============================================================================*/
