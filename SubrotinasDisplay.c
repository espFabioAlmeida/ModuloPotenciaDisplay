///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasDisplays
//AUTOR:      Fabio Almeida
//CRIADO:     23/03/2026
//OBSERVACOES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
/*==============================================================================
ESCREVE DISPLAY 7 SEGMENTOS
==============================================================================*/
void escreve7segmentos(unsigned int valor) {
    switch(valor) {
        case ' ': off(DISPLAY_A); off(DISPLAY_B); off(DISPLAY_C); off(DISPLAY_D); off(DISPLAY_E); off(DISPLAY_F); off(DISPLAY_G); break;
        case 0: on(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); on(DISPLAY_D); on(DISPLAY_E); on(DISPLAY_F); off(DISPLAY_G); break;
        case 1: off(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); off(DISPLAY_D); off(DISPLAY_E); off(DISPLAY_F); off(DISPLAY_G); break;
        case 2: on(DISPLAY_A); on(DISPLAY_B); off(DISPLAY_C); on(DISPLAY_D); on(DISPLAY_E); off(DISPLAY_F); on(DISPLAY_G); break;
        case 3: on(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); on(DISPLAY_D); off(DISPLAY_E); off(DISPLAY_F); on(DISPLAY_G); break;
        case 4: off(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); off(DISPLAY_D); off(DISPLAY_E); on(DISPLAY_F); on(DISPLAY_G); break;
        case 5: on(DISPLAY_A); off(DISPLAY_B); on(DISPLAY_C); on(DISPLAY_D); off(DISPLAY_E); on(DISPLAY_F); on(DISPLAY_G); break;
        case 6: on(DISPLAY_A); off(DISPLAY_B); on(DISPLAY_C); on(DISPLAY_D); on(DISPLAY_E); on(DISPLAY_F); on(DISPLAY_G); break;
        case 7: on(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); off(DISPLAY_D); off(DISPLAY_E); off(DISPLAY_F); off(DISPLAY_G); break;
        case 8: on(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); on(DISPLAY_D); on(DISPLAY_E); on(DISPLAY_F); on(DISPLAY_G); break;
        case 9: on(DISPLAY_A); on(DISPLAY_B); on(DISPLAY_C); on(DISPLAY_D); off(DISPLAY_E); on(DISPLAY_F); on(DISPLAY_G); break;
        case '-': off(DISPLAY_A); off(DISPLAY_B); off(DISPLAY_C); off(DISPLAY_D); off(DISPLAY_E); off(DISPLAY_F); on(DISPLAY_G); break;
    }
}
/*==============================================================================
ESCREVE DISPLAY 7 SEGMENTOS
==============================================================================*/
void atualizacaoDisplay() {
    static unsigned int offset = 0;
    unsigned int16 cent = 0, deze = 0, unid = 0;

    cent = percentual / 100;
    deze = percentual / 10;
    unid = percentual % 10;

    if(cent > 9) {
        cent %= 10;
    }
    if(deze > 9) {
        deze %= 10;
    }

    off(DISPLAY_UNID);
    off(DISPLAY_DEZE);
    off(DISPLAY_CENT);

    off(DISPLAY_PD);

    switch(offset) {
        case 0:
            escreve7segmentos(cent);
            on(DISPLAY_CENT);
            break;

        case 1:
            escreve7segmentos(deze);
            on(DISPLAY_DEZE);
            break;

        case 2:
            escreve7segmentos(unid);
            on(DISPLAY_UNID);
            if(flagAcionaPontoDecimal) {
                on(DISPLAY_PD);
            }
            break;
    }

    offset ++;
    if(offset >= 3) {
        offset = 0;
    }
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
