/*//www.elbrujitocanaio.es 
//Todo el código esta bajo licencia de la Creative Commons.
#define Trig 2                                      //Definimos como constante Pin sensor
#define Echo 4                                   //Definimos como constante Pin sensor
#define PinLed 3                               //Define el pin del Led
#define PinSonoro 5                        //Define el  pin buzzer 
#define Freq 68                               //Valores de 31Hz a 65535 Hz
#define AlarmaLed 20                     //Define la alarma a 20 centimetros
#define AlarmaSonora 10              //Define sonido a 10 centimetros
void setup() {
Serial.begin(9600);                           //Define salida serie
pinMode(Trig,OUTPUT);                 //Pin como salida
pinMode(Echo,INPUT);                   //Pin como entrada
pinMode(PinLed,OUTPUT);          //Pin alarma luminosa.
pinMode(PinSonoro,OUTPUT);   //Pin altavoz

}

void loop() {

////////////////////////////////////////////////////////////////////////           ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////Mandar la senal
digitalWrite(Trig,LOW);                        //Pone bajo el pin
delayMicroseconds(2);                         //Pausa de tiempo
digitalWrite(Trig,HIGH);                     //Pone alto el pin
delayMicroseconds(10);                       //Pausa de tiempo
digitalWrite(Trig,LOW);                       //Pone bajo el pin
///////////////////////////////////////////Resibe la senal
int duracion = pulseIn(Echo,HIGH);//Guarda la senal
int distancia = (duracion/58);            //Convertimos en centimetros
if (distancia <= 2) distancia =2;         //Evita error
if (distancia >= 400) distancia =400;//Evita error

/////////////////////////////////////////////////////////////////////////                                                                       /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////Alarma
if (distancia <= AlarmaLed){
digitalWrite(PinLed,HIGH);
}else{
digitalWrite(PinLed,LOW);
}
if (distancia <= AlarmaSonora){
tone(PinSonoro,Freq);                       //Alarma
Serial.print("Distancia ");                //Salida por puerto serie
Serial.println(distancia);                  //Dato a mostrar
delay(100);
}else{
noTone(PinSonoro);                          //Apaga alarma
////////////////////////////////////////////////Salida puerto serie

Serial.print("Distancia ");                //Salida por puerto serie
Serial.println(distancia);                  //Dato a mostrar
delay(100);                                        //Un segundo por favor

}
}*/
//www.elbrujitocanaio.es
//Todo el código esta bajo licencia de la Creative Commons.
#define Trig 2 //Definimos como constante Pin sensor
#define Echo 4 //Definimos como constante Pin sensor
#define PinLed 3 //Define el pin del Led
#define PinSonoro 5 //Define el pin buzzer
#define Freq 68 //Valores de 31Hz a 65535 Hz
#define AlarmaLed 20 //Define la alarma a 20 centimetros
#define AlarmaSonora 10 //Define sonido a 10 centimetros
void setup() {
Serial.begin(9600); //Define salida serie
pinMode(Trig,OUTPUT); //Pin como salida
pinMode(Echo,INPUT); //Pin como entrada
pinMode(PinLed,OUTPUT); //Pin alarma luminosa.
pinMode(PinSonoro,OUTPUT); //Pin altavoz
}
void loop() {
//////////////////////////////////////////////////////////////////////// ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////Mandar la senal
digitalWrite(Trig,LOW); //Pone bajo el pin
delayMicroseconds(2); //Pausa de tiempo
digitalWrite(Trig,HIGH); //Poner alto el pin
delayMicroseconds(10); //Pausa de tiempo
digitalWrite(Trig,LOW); //Pone bajo el pin
///////////////////////////////////////////Resibe la senal
int duracion = pulseIn(Echo,HIGH);//Guarda la senal
int distancia = (duracion/58); //Convertimos en centimetros
if (distancia <= 2) distancia =2; //Evita error
if (distancia >= 400) distancia =400;//Evita error
///////////////////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////Alarma
if (distancia <= AlarmaLed){
digitalWrite(PinLed,HIGH);
}else{
digitalWrite(PinLed,LOW);
}
if (distancia <= AlarmaSonora){
tone(PinSonoro,Freq); //Alarma
Serial.print("Distancia "); //Salida por puerto serie.CUIDADO CON EL TIPO DE LAS COMILLAS
Serial.println(distancia); //Dato a mostrar delay(100);
}else{
noTone(PinSonoro); //Apaga alarma
////////////////////////////////////////////////Salida puerto serie
Serial.print("Distancia "); //Salida por puerto serie.CUIDADO CON EL TIPO DE LAS COMILLAS
Serial.println(distancia); //Dato a mostrar
delay(100); //Un segundo por favor
}
}
