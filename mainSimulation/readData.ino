void readData(void)
{
  // leitura de tensao, corrente e temperatura
  tensao_V = analogRead(analogPin_Tensao);
  current_mA = analogRead(analogPin_Corrente);
  temperatura_C = analogRead(analogPin_Temperatra);

  // escrita nos holding registers
   modbus_update_holding(0, tensao_V);
   modbus_update_holding(1, current_mA);
   modbus_update_holding(2, temperatura_C);
}
