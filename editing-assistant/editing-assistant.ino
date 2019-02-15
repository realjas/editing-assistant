//#include <Keyboard.h>
//#include <ArduinoJson.h>

int stepForward = 6;
int sfBol = false;

int stepBackward = 5;
int sbBol = false;

int sliceEnd = 4;
int sleBol = false;

int sliceBeginning = 3;
int slbBol = false;

int output = false;

void setup() {
  Serial.begin(9600);
  while(!Serial) {
    //
  }

  //Keyboard.begin();
  
  pinMode(stepForward,INPUT);
  pinMode(stepBackward,INPUT);
  pinMode(sliceEnd,INPUT);
  pinMode(sliceBeginning,INPUT);
}

void loop() {
  output = false;
  if((digitalRead(stepForward) == HIGH) && (sfBol == false)){
    sfBol = true;
    //Serial.println("Step Forward");
    output = true;
  }
  if((digitalRead(stepForward) == LOW) && (sfBol == true)){
    sfBol = false;    
  }

  if((digitalRead(stepBackward) == HIGH) && (sbBol == false)){
    sbBol = true;
    //Serial.println("Step Backward");
    output = true;
  }
  if((digitalRead(stepBackward) == LOW) && (sbBol == true)){
    sbBol = false;    
  }

  if((digitalRead(sliceEnd) == HIGH) && (sleBol == false)){
    sleBol = true;
    //Serial.println("Slice End");
    output = true;
  }
  if((digitalRead(sliceEnd) == LOW) && (sleBol == true)){
    sleBol = false;    
  }

  if((digitalRead(sliceBeginning) == HIGH) && (slbBol == false)){
    slbBol = true;
    //Serial.println("Slice Beginning");
    output = true;
  }
  if((digitalRead(sliceBeginning) == LOW) && (slbBol == true)){
    slbBol = false;    
  }

  //Print results as JSON
  if (output == true){
      Serial.print("{\"sfBol\":");
      Serial.print(sfBol);
      Serial.print(",\"sbBol\":");
      Serial.print(sbBol);
      Serial.print(",\"sleBol\":");
      Serial.print(sleBol);
      Serial.print(",\"slBol\":");
      Serial.print(slbBol);
      Serial.print("}");
      Serial.println();
  }
}
