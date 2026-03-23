# Modulo Potência Display
Projeto Automasensor Módulo Potência Display
# Escopo
Leitura do potenciômetro e apresentação do valor no display de 7 segmentos. Entre 0 a 100%. <br>
Envia pela porta serial para o módulo de potência via RS485 Modbus <br>
# Protocolo RS485
Comunica somente com o módulo de endereço 90 <br>
Solicitação do mestre: $,090,1,1,12345,\r\n <br>
O endereço sempre é 3 dígitos <br>
Primeiro dado é o status da saída 0=desligado e 1=ligado (não há mais seleção de rotação) <br>
Segundo dado é o modo de operação. 1=razão cíclica e 2=setpoint rpm <br>
Terceiro dado é setpoint, sempre 5 dígitos. O valor máximo da PWM é 4095. <br>
<br>
Resposta do módulo de potência: $,090,01234,\r\n <br>
O único dado é a RPM lida, sempre 5 dígitos. <br>
