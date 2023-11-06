/*
 * "ds_main.ino" - DecibelSentinel Runtime Code
 *
 * November 2023: Innovation Expo, Copyright (c)
 * Assistive Noise Monitoring Device - DecibelSentinel
 *
 * This file contains the running code that will be exec-
 * uted upon runtime in an arduino board. An active piezo
 * buzzer is used to alert the vicinity that noise is ge-
 * tting more prominent. The Big Sound Sensor analog data
 * is used for measuring.
 *
 * MAKE SURE TO PLUG PIEZO BUZZER SIGNAL INTO PIN 2. POST
 * WILL ACTIVATE PIN 2. (kay di na mo function og lahi na
 * pin.)
 *
 * Built from the ground-up. 
 *
 * I think, the sensor provides raw data rather than in dB.
 * (deciBels)
 * 
 * For inquiries and problems about the code, feel free to
 * contact
 * ---- Ronald Campos Jr. <camposronald826@gmail.com> ----
 */

#include  "ds_funcs.h"                      // Library header nga nag-contain og mga importante na mga functions nga gamiton later in our code.
#define   cuint8_t      const uint8_t       // define "cuint8_t" as an equivalent to typing "const uint8_t". (Compiler preprocessor directive ni siya.)

static uint8_t analogData;                  // Ato ni butanganan og data gikan sa analog pin. I've made it static para dili na mag unnecessary ang pag
                                            // allocate og deallocate para ani na variable throughout the program's lifetime. (Gamiton raba ni og loop func.)

union pinOutStruct{                        // List all these pins in a constant variable. Make sure nga naa rani siya sa isa ka memory location.
  cuint8_t activeBuzzer_signalPin = 2;
  cuint8_t bigSound_analogPin     = A0;
};

void setup(void){                                               // It is always a good-typing practice to be specific about your function arguments. Void = None. Thus, watay arguments ani na function.
  union pinOutStruct pOS_0;                                    // Naay pulos ato "struct" nga gi-define.
  
  pinMode(pOS_0.activeBuzzer_signalPin, OUTPUT);                // Ato-a pinModes kung pa-gawas ba ang data or pa-sulod sa Arduino.
  pinMode(pOS_0.bigSound_analogPin,      INPUT);

  postForBuzzer();

  Serial.begin(9600);                                           // Nominal polling rate or bits per second sa serial.
}

void loop(void){
  static union pinOutStruct pOS_1;

  analogData = analogRead(pOS_1.bigSound_analogPin);
  Serial.println(analogData);

  if(analogData >= 24){
      invokeBuzzer(3, 90, pOS_1.activeBuzzer_signalPin);          // "invokeBuzzer()" has three function arguments: delay, tone and pinout - should be in the range sa uint8_t na mga datatypes.
    }
}
