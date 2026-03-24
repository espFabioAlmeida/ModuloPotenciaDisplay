///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityCOM
//AUTOR:      Fabio Almeida
//CRIADO:     23/07/2021
//OBSERVACOES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
LIMPA STRING
==============================================================================*/
void limpaBufferUart() {
   for(unsigned int i = 0; i < TAMANHO_UART_BUFFER; i ++) {
      uartBuffer[i] = 0x00; 
   }
   contUartBuffer = 0;
}
/*==============================================================================
INTERRUPCAO RDA
==============================================================================*/
#INT_RDA
void rda() { 
  /* if(kbhit()) {
      char dado = getch();
      uartBuffer[contUartBuffer] = dado;
      
      contUartBuffer ++;
      if(contUartBuffer >= TAMANHO_UART_BUFFER) {
         limpaBufferUart();
      }
      
      if(dado == 0x0A) {
         flagPacoteUart = true;
      }
   }*/
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
