///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    InterrupcaoTimer1 
//AUTOR:      Fabio Almeida
//CRIADO:     17/04/2019
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
TAREFAS 1MS
==============================================================================*/
void tarefas1ms() {
   flagAtualizaDisplay = true;
}
/*==============================================================================
TAREFAS 10MS
==============================================================================*/
void tarefas10ms() {

}
/*==============================================================================
TAREFAS 100MS
==============================================================================*/
void tarefas100ms() {
   flagLeituraAnalogica = true;

   if(flagPacoteValidoRecebido && !flagAcionaPontoDecimal) {
      flagAcionaPontoDecimal = true;
   }
   else {
      if(flagAcionaPontoDecimal) {
         flagAcionaPontoDecimal = false;
         flagPacoteValidoRecebido = false;
      }
   }
}
/*==============================================================================
TAREFAS 1S
==============================================================================*/
void tarefas1s() {
   flagEnviaPacoteUart = true;
}
/*==============================================================================
INTERRUPÇÃO TIMER1
==============================================================================*/
#INT_TIMER1                                     
void timer1_() {
   static unsigned int conta1ms = 0, conta10ms = 0, conta100ms = 0;
   set_timer1(64558 + get_timer1()); 

   tarefas1ms();
   conta1ms ++;

   if(conta1ms >= 10) {
      conta1ms = 0;
      tarefas10ms();
      conta10ms ++;

      if(conta10ms >= 10) {
         conta10ms = 0;
         tarefas100ms();
         conta100ms ++;

         if(conta100ms >= 10) {
            conta100ms = 0;
            tarefas1s();
         }
      }
   }

}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/ 
