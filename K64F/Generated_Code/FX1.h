/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : FX1.h
**     CDE edition : Standard
**     Project     : Mini Project
**     Processor   : MK64FN1M0VLL12
**     Component   : FXOS8700CQ
**     Version     : Component 01.032, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-11-22, 16:17, # CodeGen: 1
**     Abstract    :
**         Implements a Driver for the MMA8451 accelerometer from Freescale.
**     Settings    :
**          Component Name                                 : FX1
**          Slave Address                                  : 1D
**          I2C Bus                                        : GI2C1
**          Constant Offsets                               : Enabled
**            X offset                                     : 0
**            Y offset                                     : 0
**            Z offset                                     : 0
**          Shell                                          : Disabled
**     Contents    :
**         Enable              - uint8_t FX1_Enable(void);
**         Disable             - uint8_t FX1_Disable(void);
**         isEnabled           - uint8_t FX1_isEnabled(bool *isEnabled);
**         SwReset             - uint8_t FX1_SwReset(void);
**         ReadReg8            - uint8_t FX1_ReadReg8(uint8_t addr, uint8_t *val);
**         WriteReg8           - uint8_t FX1_WriteReg8(uint8_t addr, uint8_t val);
**         GetX                - int16_t FX1_GetX(void);
**         GetY                - int16_t FX1_GetY(void);
**         GetZ                - int16_t FX1_GetZ(void);
**         GetRaw8XYZ          - uint8_t FX1_GetRaw8XYZ(void* *xyz);
**         CalibrateX1g        - void FX1_CalibrateX1g(void);
**         CalibrateY1g        - void FX1_CalibrateY1g(void);
**         CalibrateZ1g        - void FX1_CalibrateZ1g(void);
**         GetXmg              - int16_t FX1_GetXmg(void);
**         GetYmg              - int16_t FX1_GetYmg(void);
**         GetZmg              - int16_t FX1_GetZmg(void);
**         MeasureGetRawX      - uint16_t FX1_MeasureGetRawX(void);
**         MeasureGetRawY      - uint16_t FX1_MeasureGetRawY(void);
**         MeasureGetRawZ      - uint16_t FX1_MeasureGetRawZ(void);
**         GetXOffset          - int16_t FX1_GetXOffset(void);
**         GetYOffset          - int16_t FX1_GetYOffset(void);
**         GetZOffset          - int16_t FX1_GetZOffset(void);
**         GetX1gValue         - int16_t FX1_GetX1gValue(void);
**         GetY1gValue         - int16_t FX1_GetY1gValue(void);
**         GetZ1gValue         - int16_t FX1_GetZ1gValue(void);
**         SetFastMode         - uint8_t FX1_SetFastMode(bool on);
**         WhoAmI              - uint8_t FX1_WhoAmI(uint8_t *value);
**         GetTemperature      - uint8_t FX1_GetTemperature(int8_t *temperature);
**         GetMagX             - uint8_t FX1_GetMagX(int16_t *value);
**         GetMagY             - uint8_t FX1_GetMagY(int16_t *value);
**         GetMagZ             - uint8_t FX1_GetMagZ(int16_t *value);
**         MagneticSensorReset - uint8_t FX1_MagneticSensorReset(void);
**         Init                - uint8_t FX1_Init(void);
**         Deinit              - uint8_t FX1_Deinit(void);
**
**Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**All Rights Reserved.
**
**Redistribution and use in source and binary forms, with or without modification,
**are permitted provided that the following conditions are met:
**
**o Redistributions of source code must retain the above copyright notice, this list
**  of conditions and the following disclaimer.
**
**o Redistributions in binary form must reproduce the above copyright notice, this
**  list of conditions and the following disclaimer in the documentation and/or
**  other materials provided with the distribution.
**
**o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**  contributors may be used to endorse or promote products derived from this
**  software without specific prior written permission.
**
**THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**http: www.freescale.com
**mail: support@freescale.com
** ###################################################################*/
/*!
** @file FX1.h
** @version 01.00
** @brief
**         Implements a Driver for the MMA8451 accelerometer from Freescale.
*/         
/*!
**  @addtogroup FX1_module FX1 module documentation
**  @{
*/         

#ifndef __FX1_H
#define __FX1_H

/* MODULE FX1. */
#include "MCUC1.h" /* SDK and API used */
#include "FX1config.h" /* configuration */

/* Include inherited components */
#include "GI2C1.h"
#include "WAIT1.h"
#include "MCUC1.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FX1_PARSE_COMMAND_ENABLED  FX1_CONFIG_PARSE_COMMAND_ENABLED  /* set to 1 if method ParseCommand() is present, 0 otherwise */

/* 3-axis accelerometer control register addresses */
#define FX1_CTRL_REG_1 0x2A
/* 3-axis accelerometer control register bit masks */
#define FX1_ACTIVE_BIT_MASK 0x01
#define FX1_F_READ_BIT_MASK 0x02

#define FX1_CTRL_REG_2 0x2B
#define FX1_CTRL_REG_2_MASK_RST (1<<4) /* software reset */

/* External 3-axis accelerometer data register addresses */
#define FX1_OUT_X_MSB 0x01
#define FX1_OUT_X_LSB 0x02
#define FX1_OUT_Y_MSB 0x03
#define FX1_OUT_Y_LSB 0x04
#define FX1_OUT_Z_MSB 0x05
#define FX1_OUT_Z_LSB 0x06

#define FX1_WHO_AM_I  0x0D    /* Who am I register, should return 0xC4 for preproduction devices and 0xC7 for production devices */
#define FX1_WHO_AM_I_VAL 0xC7 /* production device value */

#define FX1_XYZ_DATA_CFG 0x0E  /* XYZ Data Configuration Register */

/* magnetometer control register */
#define FX1_M_CTRL_REG_1 0x5B
#define FX1_M_CTRL_REG_2 0x5C
#define FX1_M_CTRL_REG_3 0x5D

/* Magnetometer data register addresses */
#define FX1_M_OUT_X_MSB 0x33
#define FX1_M_OUT_X_LSB 0x34
#define FX1_M_OUT_Y_MSB 0x35
#define FX1_M_OUT_Y_LSB 0x36
#define FX1_M_OUT_Z_MSB 0x37
#define FX1_M_OUT_Z_LSB 0x38

/* die temperature (needs to add an offset as not factory trimmed) */
#define FX1_DIE_TEMP  0x51 /* die temperature register, signed 8bit in C */
#define FX1_DIE_TEMP_OFFSET   FX1_CONFIG_TEMP_OFFSET /* offset to temperature reading as value on device is not calibrated */

#define FX1_I2C_ADDR          FX1_CONFIG_I2C_DEVICE_ADDRESS /* I2C slave device address as set in the properties */



uint8_t FX1_GetRaw8XYZ(uint8_t *xyz);
/*
** ===================================================================
**     Method      :  FX1_GetRaw8XYZ (component FXOS8700CQ)
**     Description :
**         Returns in an array the x, y and z accelerometer as 8bit
**         values.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * xyz             - Pointer to an array of three unsigned 8bit
**                           values which are used to return the
**                           accelerometer values.
**     Returns     :
**         ---             - Error code, ERR_OK for no error.
** ===================================================================
*/

uint8_t FX1_Deinit(void);
/*
** ===================================================================
**     Method      :  FX1_Deinit (component FXOS8700CQ)
**     Description :
**         Counterpart to Init() method.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, ERR_OK if everything is ok.
** ===================================================================
*/

uint8_t FX1_Init(void);
/*
** ===================================================================
**     Method      :  FX1_Init (component FXOS8700CQ)
**     Description :
**         Initializes the device driver
**     Parameters  : None
**     Returns     :
**         ---             - Error code, ERR_OK if everything is ok.
** ===================================================================
*/

void FX1_CalibrateX1g(void);
/*
** ===================================================================
**     Method      :  FX1_CalibrateX1g (component FXOS8700CQ)
**     Description :
**         Performs a calibration of the sensor. It is assumed that the
**         Y and Z sensors have 0 g, and the X sensor has 1 g.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FX1_CalibrateY1g(void);
/*
** ===================================================================
**     Method      :  FX1_CalibrateY1g (component FXOS8700CQ)
**     Description :
**         Performs a calibration of the sensor. It is assumed that the
**         X and Z sensors have 0 g, and the Y sensor has 1 g.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FX1_CalibrateZ1g(void);
/*
** ===================================================================
**     Method      :  FX1_CalibrateZ1g (component FXOS8700CQ)
**     Description :
**         Performs a calibration of the sensor. It is assumed that the
**         X and Y sensors have 0 g, and the Z sensor has 1 g.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

int16_t FX1_GetXmg(void);
/*
** ===================================================================
**     Method      :  FX1_GetXmg (component FXOS8700CQ)
**     Description :
**         Returns the X value in mg
**     Parameters  : None
**     Returns     :
**         ---             - The g value in 1/1000g units
** ===================================================================
*/

int16_t FX1_GetYmg(void);
/*
** ===================================================================
**     Method      :  FX1_GetYmg (component FXOS8700CQ)
**     Description :
**         Returns the Y value in mg
**     Parameters  : None
**     Returns     :
**         ---             - The g value in 1/1000g units
** ===================================================================
*/

int16_t FX1_GetZmg(void);
/*
** ===================================================================
**     Method      :  FX1_GetZmg (component FXOS8700CQ)
**     Description :
**         Returns the Z value in mg
**     Parameters  : None
**     Returns     :
**         ---             - The g value in 1/1000g units
** ===================================================================
*/

uint16_t FX1_MeasureGetRawX(void);
/*
** ===================================================================
**     Method      :  FX1_MeasureGetRawX (component FXOS8700CQ)
**     Description :
**         Performs a measurement on X channel and returns the raw
**         value.
**     Parameters  : None
**     Returns     :
**         ---             - X sensor value
** ===================================================================
*/

uint16_t FX1_MeasureGetRawY(void);
/*
** ===================================================================
**     Method      :  FX1_MeasureGetRawY (component FXOS8700CQ)
**     Description :
**         Performs a measurement on Y channel and returns the raw
**         value.
**     Parameters  : None
**     Returns     :
**         ---             - Y sensor value
** ===================================================================
*/

uint16_t FX1_MeasureGetRawZ(void);
/*
** ===================================================================
**     Method      :  FX1_MeasureGetRawZ (component FXOS8700CQ)
**     Description :
**         Performs a measurement on Z channel and returns the raw
**         value.
**     Parameters  : None
**     Returns     :
**         ---             - Z sensor value
** ===================================================================
*/

int16_t FX1_GetXOffset(void);
/*
** ===================================================================
**     Method      :  FX1_GetXOffset (component FXOS8700CQ)
**     Description :
**         Returns the offset applied to the X value.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

int16_t FX1_GetYOffset(void);
/*
** ===================================================================
**     Method      :  FX1_GetYOffset (component FXOS8700CQ)
**     Description :
**         Returns the offset applied to the Y value.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

int16_t FX1_GetZOffset(void);
/*
** ===================================================================
**     Method      :  FX1_GetZOffset (component FXOS8700CQ)
**     Description :
**         Returns the offset applied to the Z value.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

int16_t FX1_GetX1gValue(void);
/*
** ===================================================================
**     Method      :  FX1_GetX1gValue (component FXOS8700CQ)
**     Description :
**         Returns the value for 1g for channel  X.
**     Parameters  : None
**     Returns     :
**         ---             - 1g value for X
** ===================================================================
*/

int16_t FX1_GetY1gValue(void);
/*
** ===================================================================
**     Method      :  FX1_GetY1gValue (component FXOS8700CQ)
**     Description :
**         Returns the value for 1g for channel  Y.
**     Parameters  : None
**     Returns     :
**         ---             - 1g value for Y
** ===================================================================
*/

int16_t FX1_GetZ1gValue(void);
/*
** ===================================================================
**     Method      :  FX1_GetZ1gValue (component FXOS8700CQ)
**     Description :
**         Returns the value for 1g for channel  Z.
**     Parameters  : None
**     Returns     :
**         ---             - 1g value for Z
** ===================================================================
*/

int16_t FX1_GetX(void);
/*
** ===================================================================
**     Method      :  FX1_GetX (component FXOS8700CQ)
**     Description :
**         Retrieves the value for the X axis. The value is adjusted
**         with the zero calibration value (0 for 0 g, negative for
**         negative acceleration and positive for positive acceleration).
**     Parameters  : None
**     Returns     :
**         ---             - Measured X value
** ===================================================================
*/

int16_t FX1_GetY(void);
/*
** ===================================================================
**     Method      :  FX1_GetY (component FXOS8700CQ)
**     Description :
**         Retrieves the value for the Y axis. The value is adjusted
**         with the zero calibration value (0 for 0 g, negative for
**         negative acceleration and positive for positive acceleration).
**     Parameters  : None
**     Returns     :
**         ---             - Measured Y value
** ===================================================================
*/

int16_t FX1_GetZ(void);
/*
** ===================================================================
**     Method      :  FX1_GetZ (component FXOS8700CQ)
**     Description :
**         Retrieves the value for the Z axis. The value is adjusted
**         with the zero calibration value (0 for 0 g, negative for
**         negative acceleration and positive for positive acceleration).
**     Parameters  : None
**     Returns     :
**         ---             - Measured Z value
** ===================================================================
*/

uint8_t FX1_SetFastMode(bool on);
/*
** ===================================================================
**     Method      :  FX1_SetFastMode (component FXOS8700CQ)
**     Description :
**         Turns the F_READ (Fast Read Mode) on or off
**     Parameters  :
**         NAME            - DESCRIPTION
**         on              - if to turn the F_READ mode on or off
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_Enable(void);
/*
** ===================================================================
**     Method      :  FX1_Enable (component FXOS8700CQ)
**     Description :
**         Enables the device with setting the ACTIVE bit in the CTRL
**         register 1
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_Disable(void);
/*
** ===================================================================
**     Method      :  FX1_Disable (component FXOS8700CQ)
**     Description :
**         Disables the device with clearing the ACTIVE bit in the CTRL
**         register 1
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_isEnabled(bool *isEnabled);
/*
** ===================================================================
**     Method      :  FX1_isEnabled (component FXOS8700CQ)
**     Description :
**         Returns the status of the the ACTIVE bit in the CTRL
**         register 1
**     Parameters  :
**         NAME            - DESCRIPTION
**       * isEnabled       - Pointer to where to store the
**                           result, TRUE if ACTIVE bit is set, FALSE
**                           otherwise
**     Returns     :
**         ---             - error code
** ===================================================================
*/

uint8_t FX1_WhoAmI(uint8_t *value);
/*
** ===================================================================
**     Method      :  FX1_WhoAmI (component FXOS8700CQ)
**     Description :
**         Returns the value of the WHO_AM_I (0x0D) register
**     Parameters  :
**         NAME            - DESCRIPTION
**       * value           - Pointer to value to store
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_GetTemperature(int8_t *temperature);
/*
** ===================================================================
**     Method      :  FX1_GetTemperature (component FXOS8700CQ)
**     Description :
**         Returns the temperature of the die as signed 8bit values in
**         degree Celsius
**     Parameters  :
**         NAME            - DESCRIPTION
**       * temperature     - Pointer to variable where
**                           to store the temperature
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_GetMagX(int16_t *value);
/*
** ===================================================================
**     Method      :  FX1_GetMagX (component FXOS8700CQ)
**     Description :
**         Returns the X magnetometer value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * value           - Pointer to where to store the value.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_GetMagY(int16_t *value);
/*
** ===================================================================
**     Method      :  FX1_GetMagY (component FXOS8700CQ)
**     Description :
**         Returns the Y magnetometer value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * value           - Pointer to where to store the value.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_GetMagZ(int16_t *value);
/*
** ===================================================================
**     Method      :  FX1_GetMagZ (component FXOS8700CQ)
**     Description :
**         Returns the Z magnetometer value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * value           - Pointer to where to store the value.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_MagneticSensorReset(void);
/*
** ===================================================================
**     Method      :  FX1_MagneticSensorReset (component FXOS8700CQ)
**     Description :
**         Initiates a magnetic sensor reset cycle that will restore
**         correct operation after exposure to an excessive magnetic
**         field which exceeds the Full Scale Range but is less than
**         the Maximum Applied Magnetic Field.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_ReadReg8(uint8_t addr, uint8_t *val);
/*
** ===================================================================
**     Method      :  FX1_ReadReg8 (component FXOS8700CQ)
**     Description :
**         Reads an 8bit device register
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - device memory map address
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_WriteReg8(uint8_t addr, uint8_t val);
/*
** ===================================================================
**     Method      :  FX1_WriteReg8 (component FXOS8700CQ)
**     Description :
**         Write an 8bit device register
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - device memory map address
**         val             - value to write
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FX1_SwReset(void);
/*
** ===================================================================
**     Method      :  FX1_SwReset (component FXOS8700CQ)
**     Description :
**         Perform a software reset using the rst bit in the CTRL
**         register 2
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END FX1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __FX1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
