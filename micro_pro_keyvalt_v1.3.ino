#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Keyboard.h"

Adafruit_SSD1306 display(-1);
/*
 * Display
 * VCC -> VCC
 * GND -> GND
 * SCL -> 3
 * SDA -> 2
 * -------------
 * Button Back -> 4
 * Button Next -> 5
 * Button Select -> 6
 * Button Insert -> 7
 */
 //buttons
int buttonState_b1 = 0;   
const int buttonPin_b1 = 4; 
int buttonState_b2 = 0;   
const int buttonPin_b2 = 5; 
int buttonState_b3 = 0;   
const int buttonPin_b3 = 6; 
int buttonState_b4 = 0;   
const int buttonPin_b4 = 7; 
int option = 0;
//
//------ Edit
char segredo[8] = "1234pato";
int cont_for_recripty = 1;
int cesar_chiper = 100;
char dicionario_cesar[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*','(',')','-','+','=','<','>','/'};
//--------------------------
//
int cesar_chiper_size = sizeof(dicionario_cesar)+1;
char dicionario[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','*','(',')','-','+','=','<','>','/'};
int point_to_return = 0;
int point_f=0;
String user = "";
String serv = "";
char enter = KEY_RETURN;
char saida_tc[16];

void setup()   
{       
  pinMode(buttonPin_b1, INPUT); 
  pinMode(buttonPin_b2, INPUT); 
  pinMode(buttonPin_b3, INPUT); 
  pinMode(buttonPin_b4, INPUT); 

  Keyboard.begin();


         
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
 
  default_screen();
  
}

//--------------------------classes -------------------------------------

void default_screen(){
  
  scree_pass();

  // Display Text
  display.setTextSize(1);
  
  // cada linha pode ter ate 15 caracteres
  // em dicionario se temos : 45
  //--------------------------------------------------------------------------------------
  for(int i = 0; i <= (15*8) ; i = i+8){
    int j = i/8;
    if(point_to_return == i){
              display.setTextColor(BLACK, WHITE); 
          }else{
              display.setTextColor(WHITE);
          }
    display.setCursor(i,20);
    
    display.println(dicionario[j]);
  }
  //--------------------------------------------------------------------------------------

   for(int i = 0; i <= (15*8) ; i = i+8){
    int j = (i+16*8)/8;

    if(point_to_return == (i+128)){
              display.setTextColor(BLACK, WHITE); 
          }else{
              display.setTextColor(WHITE);
          }
    display.setCursor(i,30);
    
    display.println(dicionario[j]);
  }
  //--------------------------------------------------------------------------------------
  for(int i = 0; i <= (15*8) ; i = i+8){
    int j = (i+32*8)/8;

    if(point_to_return == (i+128*2)){
              display.setTextColor(BLACK, WHITE); 
          }else{
              display.setTextColor(WHITE);
          }
    display.setCursor(i,40);
    
    display.println(dicionario[j]);
  }
 //--------------------------------------------------------------------------------------
  
  for(int i = 0; i <= (3*8) ; i = i+8){
    int j = (i+48*8)/8;

    if(point_to_return == (i+384)){
              display.setTextColor(BLACK, WHITE); 
          }else{
              display.setTextColor(WHITE);
          }
    display.setCursor(i,50);
    
    display.println(dicionario[j]);
  }
 
  display.display();
}

void scree_pass(){
  // Display Text
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0,0);
      display.setTextColor(WHITE);
      if(option == 0 ){
        display.println("-------Service-------");
        display.setCursor(0,8);
      display.println(serv);
      }else{
      display.println("--------User---------");
      display.setCursor(0,8);
      display.println(user);
      }
}

void embaralhamento(){
     /* Embaralhamento do segredo com o usuario e o serviço
      * A senha deve ter 16 caracteres
      *  nesse exemplo se utilizará:
      *       8 - segredo (g)
      *       4 - user (u)
      *       4 - serv (s)
      *  
      *  u u g g g g u u g g g g s s s s 
      * char saida[16] = {user_l[0], user_l[1], segredo[0], segredo[1], segredo[2], segredo[3], user_l[2], user_l[3], segredo[4],segredo[5], segredo[6],segredo[7], serv_l[0], serv_l[1], serv_l[2], serv_l[3]};
      */

    char user_l[3];
    char serv_l[3];
    int i; 
    for (i = 0; i < 4; i++) { 
        user_l[i] = user[i]; 
        serv_l[i] = serv[i];
         
    }
     
     char saida[16] = {user_l[0], user_l[1], segredo[0], segredo[1], segredo[2], segredo[3], user_l[2], user_l[3], segredo[4],segredo[5], segredo[6],segredo[7], serv_l[0], serv_l[1], serv_l[2], serv_l[3]};
     for (i = 0; i < 16; i++) { 
             saida_tc[i] = saida[i];
    }
 
  crypt();
  }



void crypt(){
   
  int i_c = 0;
  int i_s = 0;  
  int i_m = 0;
  while (cont_for_recripty > i_c){
    while (i_s < 16){
      i_m = 0;
      while( dicionario[i_m] != saida_tc[i_s]){
        i_m ++;
      }
      i_m = i_m + cesar_chiper;
     
      while( i_m > cesar_chiper_size){
        i_m = i_m - cesar_chiper_size;
        

      }
      saida_tc[i_s] = dicionario_cesar[i_m];
      
      i_s  ++;
    
      }
        i_c  ++;
  }
}

//---------------------------------------------------------------------------------------


void loop() {
  
   buttonState_b1 = digitalRead(buttonPin_b1);
   buttonState_b2 = digitalRead(buttonPin_b2);
   buttonState_b3 = digitalRead(buttonPin_b3);
   buttonState_b4 = digitalRead(buttonPin_b4);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState_b2 == HIGH) {
    
      if(((sizeof(dicionario)-1)*8) <= point_to_return){
            point_to_return = 0;
       }else{
            point_to_return = point_to_return+8;
       }
      default_screen();    
}
 if (buttonState_b1 == HIGH) {
    
      if(0 >= point_to_return){
            point_to_return = (sizeof(dicionario)-1)*8;
       }else{
            point_to_return = point_to_return-8;
       }
      default_screen();    
}
    if (buttonState_b3 == HIGH) {  
       int i = (point_to_return/8);
       String ex = String(dicionario[i]); 

      if(option == 0){
        serv = serv + ex;
        
      }else{
              user = user + ex;

     
      }
      default_screen();
    }   
    
    if (buttonState_b4 == HIGH) {

      
      if(option == 0){
        option = 1;
        default_screen();
        
      }else{
        if(user == "" ||  serv == "") {
           option = 0;
          default_screen();
      
        }else{
      embaralhamento();
      String saida = String(saida_tc); 
      Keyboard.print(saida);
      Keyboard.press(enter);
      Keyboard.release(enter);
      user = "";
      serv = "";
      
      option = 0;
      
      default_screen();
      delay(1000);
        }
      
      }
    }
}
