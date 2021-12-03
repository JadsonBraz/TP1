/**
   Setup inicial dos holding registers
*/

void setupInitialValuesOfModbusRegisters (void)
{
  // setup holding registers
  modbus_update_holding(0, 0);    // tensao
  modbus_update_holding(1, 0);    // corrente
  modbus_update_holding(2, 0);    // temperatura
  modbus_update_holding(3, 120);    // PWM
  modbus_update_holding(4, (uint16_t)  DEFAULT_DELAY);    // T_ON
  modbus_update_holding(5, (uint16_t)  DEFAULT_DELAY);    // T_OFF
  modbus_update_holding(6, (uint16_t)  DEFAULT_KP);       // Kp
  modbus_update_holding(7, (uint16_t)  DEFAULT_KI);       // Ki
  modbus_update_holding(8, (uint16_t)  DEFAULT_KD);       // Kd
  modbus_update_holding(9, (uint16_t)  DEFAULT_SETPOINT); // Setpoint
  modbus_update_holding(10, (uint16_t) CONTINUO);         // Configuracao global
}
