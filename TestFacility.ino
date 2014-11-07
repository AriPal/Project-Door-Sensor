int ledPin1 = 6; // Red LED for FlameDetector sensor 
int ledPin2 = 7; // Blue LED for PIR sensor
int PIR_sensor; // Assign integer.
int pCountInn = 0;
unsigned int pCountInn = 0; 
int Flame_Detector_sensor1, Flame_Detector_sensor2; // Assign two integers.  

void setup()
{
	Serial.begin(9600); // Communication rate
	pinMode(ledPin1, OUTPUT); // Assign ledPin1 to output
	pinMode(ledPin2, OUTPUT); // Assign ledPin2 to output
	

}
void loop()
{
	
	// Connect the sensors to analog pins.  
// 	PIR_sensor = digitalRead(A0); // From analog to digital (0 and 1)
	Flame_Detector_sensor1 = analogRead(A0); // Reads analog.
	Flame_Detector_sensor2 = analogRead(A1); // Reads analog. 

// Only two instance of a static field exists

static long start1 = 0;  // It will be shared by all instances.
static long start2 = 0;  // .....
static int timer = 1000; //	 .....
static int bigtimer = 5000; // ....


	
	if(Flame_Detector_sensor1 <= 500 && millis() - start1 > timer){
	    	
	    start1 = millis(); // start1 counter
	    digitalWrite(ledPin1, HIGH); // Active blue LED. 

	} else if(Flame_Detector_sensor1 >= 500){ 

		digitalWrite(ledPin1, LOW); // Unactive blue LED.

	} 

// If PIR is equal to 1 and it has gone 1, start clock counter, and set activate blue led. 
		  if(Flame_Detector_sensor2 <= 500 && millis() - start2 > timer){
		    start2 = millis(); // start2 counter
		    digitalWrite(ledPin2, HIGH); // Active red LED.
		   
		} else if(Flame_Detector_sensor2 >= 500) { 

			digitalWrite(ledPin2, LOW); // Unactive blue LED.
		}


// If the start1 timer is less than start2 timer, and start1 counter is active.  
			if(start1 < start2 && start1 > 0){
				
				// start table
				Serial.print("| ");
			    Serial.print("Velkommen");
				Serial.print("\t");
				Serial.print(start1);
				Serial.print("\t");
				Serial.print(start2);
				Serial.print("\t");
				Serial.print(Flame_Detector_sensor1);
				Serial.print("\t");
				Serial.print(Flame_Detector_sensor2);
				Serial.print(" |");
				Serial.println();
				// end table
				pcount++;

				start1 = 0; 
				start2 = 0; 
			}


			if(start1 > start2 && start2 > 0){
					
					// Start table
					Serial.print("| ");
			   		Serial.print("Hadebra"); 
					Serial.print("\t");
					Serial.print(start1);
					Serial.print("\t");
					Serial.print(start2);
					Serial.print("\t");
					Serial.print(Flame_Detector_sensor1);
					Serial.print("\t");
					Serial.print(Flame_Detector_sensor2);
					Serial.print(" |");
					Serial.println();	
					// end table

				pcount--;

				start1 = 0; 
				start2 = 0; 
	            
			}

// If a single sensor is triggered, without 
// triggering both after 5 seconds (5000 ms), set that sensor timer to zero.   
			if(start1 > bigtimer){
			    start1 = 0; 
			} else if(start2 > bigtimer){
				start2 = 0; 
			}

	delay(100); // Wait 100/1000 = 0.1 sec.   


}

