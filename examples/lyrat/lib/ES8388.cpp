#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "ES8388.h"
#include "driver/i2c.h"

// Initialize codec
uint8_t ES8388::init(void)
{
  initI2C();
  
  // GENERAL CONFIG
  writeReg(ES8388_CONTROL1,18); // 0001 0010: chip control settings
  writeReg(ES8388_CONTROL2,80); // 0101 0000: chip control settings
  writeReg(ES8388_CHIPPOWER,0); // 0000 0000: chip power management
  writeReg(ES8388_ADCPOWER,0); // 0000 0000: Activating ADC
  writeReg(ES8388_DACPOWER,60); // 0011 1100: Activating DAC
  writeReg(ES8388_MASTERMODE,0); // 0000 0000: slave serial port mode 
  
  // ADC CONFIG
  writeReg(ES8388_ADCCONTROL1,136); // 1000 1000: mic preamps gains
  writeReg(ES8388_ADCCONTROL4,12); // 0000 1100: settings i2s config (16 bits)
  writeReg(ES8388_ADCCONTROL5,2); // 0000 0010: ADC MCLK at 256 fo ADC
  writeReg(ES8388_ADCCONTROL8,0); // 0000 0000: Digital volume control attenuates the signal in 0.5 dB incremental at 0dB for ADC L
  writeReg(ES8388_ADCCONTROL9,0); // 0000 0000: Digital volume control attenuates the signal in 0.5 dB incremental at 0dB for ADC R
  writeReg(ES8388_ADCCONTROL10,12); // 0000 1100: PGA gain
  
  // DAC CONFIG
  writeReg(ES8388_DACCONTROL1,24); // 0001 1000: i2s config (16 bits)
  writeReg(ES8388_DACCONTROL2,2); // 0000 0010: DACFsRatio (Master mode DAC MCLK to sampling frequency ratio) is set to 256 
  writeReg(ES8388_DACCONTROL4,0); // 0000 0000: gain of output (L) is 0dB
  writeReg(ES8388_DACCONTROL5,0); // 0000 0000: gain of output (R) is 0dB  
  writeReg(ES8388_DACCONTROL17,144); // 1001 0000: left DAC to left mixer enabled + LIN signal to left mixer gain is 0dB
  writeReg(ES8388_DACCONTROL20,144); // 1001 0000: same config as above but for right mixer
  writeReg(ES8388_DACCONTROL21,128); // 1000 0000: DACLRC and ADCLRC are same
  writeReg(ES8388_DACCONTROL24,30); // 0001 1110: DAC volume is 0dB (L)
  writeReg(ES8388_DACCONTROL25,30); // 0001 1110: DAC volume is 0dB (R)
  
  return 0;
}

// Initialize i2c for the ESP32
void ES8388::initI2C(void)
{
  i2c_port_t i2c_master_port = (i2c_port_t) I2C_MASTER_NUM;
  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = (gpio_num_t) I2C_MASTER_SDA_IO;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.scl_io_num = (gpio_num_t) I2C_MASTER_SCL_IO;
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
  i2c_param_config(i2c_master_port, &conf);
  i2c_driver_install(i2c_master_port, conf.mode,
                     I2C_MASTER_RX_BUF_DISABLE,
                     I2C_MASTER_TX_BUF_DISABLE, 0);
}

// Register write
// reg: Register Address
// val: Register value
uint8_t ES8388::writeReg(uint8_t reg,uint8_t val)
{    
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);
  i2c_master_write_byte(cmd, ES8388_ADDR, 1);
  i2c_master_write(cmd, &reg, sizeof(reg), ACK_CHECK_EN);
  i2c_master_write(cmd, &val, sizeof(val), ACK_CHECK_EN);
  i2c_master_stop(cmd);
  i2c_master_cmd_begin((i2c_port_t) I2C_NUM_1, cmd, 1000 / portTICK_RATE_MS);
  i2c_cmd_link_delete(cmd);
    
  return 0;
}

// Returns the value in reg
// reg: Register Address
uint8_t ES8388::readReg(uint8_t reg)
{
  uint8_t p_data;
  i2c_cmd_handle_t cmd;
  cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);
  i2c_master_write_byte(cmd, ES8388_ADDR, ACK_CHECK_EN);
  i2c_master_write(cmd, &reg, sizeof(reg), ACK_CHECK_EN);
  i2c_master_stop(cmd);
  i2c_master_cmd_begin((i2c_port_t) I2C_NUM_1, cmd, 1000 / portTICK_RATE_MS);
  i2c_cmd_link_delete(cmd);
  
  cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);
  i2c_master_write_byte(cmd, ES8388_ADDR | 0x01, ACK_CHECK_EN);
  
  int datalen = 1;
  uint8_t *r_data;
  r_data = &p_data;
  for (int i = 0; i < datalen - 1; i++) {
    i2c_master_read_byte(cmd, &r_data[i], (i2c_ack_type_t) 0);
  }
  i2c_master_read_byte(cmd, &r_data[datalen - 1], (i2c_ack_type_t) 1);
  i2c_master_stop(cmd);
  i2c_master_cmd_begin((i2c_port_t) I2C_NUM_1, cmd, 1000 / portTICK_RATE_MS);
  i2c_cmd_link_delete(cmd);
  
  return p_data;
}
