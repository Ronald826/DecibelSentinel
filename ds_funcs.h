/*
 * "ds_funcs.h" - DecibelSentinel Header File
 *
 * November 2023: Innovation Expo, Copyright (c)
 * Assistive Noise Monitoring Device - DecibelSentinel
 *
 * This file serves as the header for the main runtime
 * code. This file should not be modified as function
 * arguments serves as the basis of sensor behavior
 * modification.
 *
 * Built from the ground-up. 
 *
 * 
 * For inquiries and problems about the code, feel free to
 * contact
 * ---- Ronald Campos Jr. <camposronald826@gmail.com> ----
 */

void postForBuzzer(void){                                       // Power-On Self-Test for our Active Piezo Buzzer.
  for(uint8_t i = 0; i < 50; i++){
      digitalWrite(2, HIGH);
      delay(1);
      digitalWrite(2, LOW);
      delay(1);
  }
  Serial.println("Make sure the Active Piezo Buzzer is ringing...");
}

void invokeBuzzer(uint8_t del, uint8_t tone, uint8_t pinout){   // Have to specify "uint8_t" or i-fallback rasab sa "int".
  for(uint8_t i = 0; i < tone; i++){                            // "Unsaon diay pag change sa tone?" A: I-edit ng "i < 80".
      digitalWrite(pinout, HIGH);
      delay(del);
      digitalWrite(pinout, LOW);
      delay(del);
  }
}