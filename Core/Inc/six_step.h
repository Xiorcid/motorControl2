#pragma once

void MC_DisablePWM(void);
void MC_EnablePWM(void);

void MC_InitPWM(void);
void MC_LoadStep(uint8_t step);
void MC_SetDuty(uint16_t DutyCycle);