int ledPin1 = 9; // Red LED for FlameDetector sensor 
int ledPin2 = 8; // Blue LED for PIR sensor
unsigned int pCount = 0; 

void setup()
{

  
  Serial.begin(9600); // Communication rate
  pinMode(ledPin1, OUTPUT); // Assign ledPin1 to output
  pinMode(ledPin2, OUTPUT); // Assign ledPin2 to output

}



void loop()
{
  int Flame_Detector_sensor1, Flame_Detector_sensor2; // Assign two integers. 
  int PIR_sensor; // Assign integer.
  

  // Connect the sensors to analog pins.  
  PIR_sensor = digitalRead(7); // From analog to digital (0 and 1)
  //	Flame_Detector_sensor1 = analogRead(A1); // Reads analog.
  Flame_Detector_sensor2 = analogRead(A0); // Reads analog. 

  // Only two instance of a static field exists

  static long start1 = 0;  // It will be shared by all instances.
  static long start2 = 0;  // .....
  static int timer = 2000; //	 .....
  static int bigtimer = 2000; // ....

  // && millis() > timer + start1

  if(PIR_sensor == 1 && millis() > timer + start1){

    start1 = millis(); // start1 counter 
    digitalWrite(ledPin1, HIGH); // Active blue LED.
     

  } 
  else if(PIR_sensor == 0){ 
    digitalWrite(ledPin1, LOW); // Unactive blue LED.
  } 

  // && millis() > timer + start2
  if(Flame_Detector_sensor2 >= 450 && millis() > timer + start2){

    start2 = millis(); // start2 counter
    digitalWrite(ledPin2, HIGH); // Active red LED.

  } 
  else if(Flame_Detector_sensor2 <= 450) { 

    digitalWrite(ledPin2, LOW); // Unactive blue LED.
  }
  // If the start1 timer -is less than start2 timer, and start1 counter is active.  
  // && PIR_sensor == 1

  if(start1 < start2 && start1 > 0){

    pCount++;
   
    Serial.print(" [ ");
	Serial.print(pCount);    
   //Serial.print("Velkommen");
   //Serial.print("\t");
   //Serial.print(start1);
   //Serial.print("\t");
   //Serial.print("<");
   //Serial.print("\t");
   //Serial.print(start2);
   //Serial.print("\t");
   //Serial.print(PIR_sensor);
   //Serial.print("\t");
   //Serial.print(Flame_Detector_sensor2);
    Serial.print(" ] ");
    Serial.println();

    start1 = 0; 
    start2 = 0; 

  }

  //  && PIR_sensor == 1
  if(start1 > start2 && start2 > 0){
    
    pCount--;
 
    Serial.print(" [ ");
    Serial.print(pCount);
  //  Serial.print("Hadebra"); 
  //  Serial.print("\t");
  //  Serial.print(start1);
  //  Serial.print("\t");
  //  Serial.print(">");
  //  Serial.print("\t");
  //  Serial.print(start2);
  //  Serial.print("\t");
  //  Serial.print(PIR_sensor);
  //  Serial.print("\t");
  //  Serial.print(Flame_Detector_sensor2);
    Serial.print(" ] ");
    Serial.println();	


    start1 = 0; 
    start2 = 0; 

  }

  // If a single sensor is triggered, without 
  // triggering both after 5 seconds (5000 ms), set that sensor timer to zero.   

  if(millis() > start1 + bigtimer && start2 == 0 && start1 > 0){
    start1 = 0; 
  } 

  if(millis() > start2 + bigtimer && start1 == 0 && start2 > 0){
    start2 = 0; 
  }

  delay(100);

}







