char c;
int dataStrings[12];

int dataStringIndex = 0;

bool cleanStart = false;

char Start = '<';
char End   = '>';
char Delimiter = ',';
//assume data will be in format <R1,G1,B1,R2,G2,B2,.....,>

int delayTime = 10;

//Declare Variables for RGB values
int RED1 = 0;
int GRN1 = 0;
int BLU1 = 0;

int RED2 = 0;
int GRN2 = 0;
int BLU2 = 0;

int RED3 = 0;
int GRN3 = 0;
int BLU3 = 0;

int RED4 = 0;
int GRN4 = 0;
int BLU4 = 0;

//assign names for PWM pins
#define Ri 2
#define Gi 3
#define Bi 4

#define Rii 5
#define Gii 6
#define Bii 7

#define Riii 8
#define Giii 9
#define Biii 10

#define Riv 11
#define Giv 12
#define Biv 13



void setup() {
  // put your setup code here, to run once:
pinMode(Ri, OUTPUT);
  pinMode(Gi, OUTPUT);
  pinMode(Bi, OUTPUT);
  
  pinMode(Rii, OUTPUT);
  pinMode(Gii, OUTPUT);
  pinMode(Bii, OUTPUT);

  pinMode(Riii, OUTPUT);
  pinMode(Giii, OUTPUT);
  pinMode(Biii, OUTPUT);
  
  pinMode(Riv, OUTPUT);
  pinMode(Giv, OUTPUT);
  pinMode(Biv, OUTPUT);
  
Serial.begin(115200);
Serial.println("booted");

}

void loop() {

 c = "";
 
  // clear byte buffer

if (Serial.available() > 0)  {
      
    c = Serial.read();  //gets one byte from serial buffer
    Serial.println(c);

  if (c == Start && dataStringIndex == 0) {
    
    Serial.println("beginStringRead");
    cleanStart = true; //flips boolean for full message
    
    dataStrings[dataStringIndex] = Serial.parseInt();
    Serial.println(dataStrings[dataStringIndex]);
   
    dataStringIndex++; //increment array
//    Serial.println("next array");
   
    Serial.println(dataStringIndex);
     }
     
  else if (c == End && dataStringIndex == 12){
    
//    Serial.println("message recieved");
//    print array
    for(int i = 0; i <= dataStringIndex; i++)
      {
//      Serial.println(dataStrings[i]);
      }
      
    writeAll();//write values to LED's
    delay(delayTime); //let them adjust
    dataStringIndex=0; // reset array index
    cleanStart = false; //flip boolean back for incomplete message
  }
  
  else if (c == Delimiter && cleanStart == true) {
    
    dataStrings[dataStringIndex] = Serial.parseInt();
    //Serial.println(dataStrings[dataStringIndex]);
    dataStringIndex++;
    
//    Serial.println("next array");
    }
  else if (c == 'r')
  {
      analogWrite(Ri, 0);
      analogWrite(Gi, 0);
      analogWrite(Bi, 0);

      analogWrite(Rii, 0);
      analogWrite(Gii, 0);
      analogWrite(Bii, 0);

      analogWrite(Riii, 0);
      analogWrite(Giii, 0);
      analogWrite(Biii, 0);

      analogWrite(Riv, 0);
      analogWrite(Giv, 0);
      analogWrite(Biv, 0);
//
//      Serial.println("on");

      
      delay(500);
      
      analogWrite(Ri, 255);
      analogWrite(Gi, 255);
      analogWrite(Bi, 255);

      analogWrite(Rii, 255);
      analogWrite(Gii, 255);
      analogWrite(Bii, 255);

      analogWrite(Riii, 255);
      analogWrite(Giii, 255);
      analogWrite(Biii, 255);

      analogWrite(Riv, 255);
      analogWrite(Giv, 255);
      analogWrite(Biv, 255);

//      
//      Serial.println("off");

      delay(500);
   }
   else {
     Serial.println("this won't work");
    dataStringIndex=0; // reset array index
    cleanStart = false; //flip boolean back for incomplete message
   }
}

}

void writeAll(void) {

      RED1=dataStrings[0];
      GRN1=dataStrings[1];
      BLU1=dataStrings[2];

      RED2=dataStrings[3];
      GRN2=dataStrings[4];
      BLU2=dataStrings[5];

      RED3=dataStrings[6];
      GRN3=dataStrings[7];
      BLU3=dataStrings[8];

      RED4=dataStrings[9];
      GRN4=dataStrings[10];
      BLU4=dataStrings[11];
      
      analogWrite(Ri, RED1);
      analogWrite(Gi, GRN1);
      analogWrite(Bi, BLU1);

      analogWrite(Rii, RED2);
      analogWrite(Gii, GRN2);
      analogWrite(Bii, BLU2);

      analogWrite(Riii, RED3);
      analogWrite(Giii, GRN3);
      analogWrite(Biii, BLU3);

      analogWrite(Riv, RED4);
      analogWrite(Giv, GRN4);
      analogWrite(Biv, BLU4);
      
//Serial.println(RED1);
//Serial.println(GRN1);
//Serial.println(BLU1);
//
//Serial.println(RED2);
//Serial.println(GRN2);
//Serial.println(BLU2);
//
//Serial.println(RED3);
//Serial.println(GRN3);
//Serial.println(BLU3);
//
//Serial.println(RED4);
//Serial.println(GRN4);
//Serial.println(BLU4);

}
