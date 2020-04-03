#include <18F452.h>
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz)
#FUSES PUT                      //Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#use delay(clock=20000000)
#include <lcd.c>
int s,ms=60,i;
enum funciones {lef,rig,tiem};
void left(){
output_high(PIN_B1);
}
void right(){

output_high(PIN_B2);
}
   void numfun(int a){
switch(a){
   case lef:
   left();
   break;
   case rig:
   right();
   break;
}
}


void main(){
int choose;
lcd_init();
while(true){
if (input(PIN_A0)==1){
   choose++;
   delay_ms(60);
   if (choose>2) choose=0; 
switch (choose){
      case 0:
      lcd_gotoxy(4,1);
      printf(lcd_putc, "escoja");
      lcd_gotoxy(4,2);
      printf(lcd_putc, " IZQUIERDA");
      delay_ms(60);
      BREAK;
      case 1: 
      lcd_gotoxy(4,1);
      printf(lcd_putc, "escoja");
      lcd_gotoxy(4,2);
      printf(lcd_putc,"  DERECHA  ");
      delay_ms(60);
      BREAK;
      } 
   }


if (input(pin_A1)==1){
    lcd_putc("\f");
       lcd_gotoxy(4,1);
      printf(lcd_putc,"Tiempo");
      delay_ms(60);
      s++;
       lcd_gotoxy(4,2);
     printf(lcd_putc,"%u s.",s);
      delay_ms(1000);
    }
    
IF (input(PIN_A2)==1){
     delay_ms(50);
     numfun(choose);

  for(i=0;i<60;i++){
      s--;   
  for (int j=0;j<60;j++){
    ms--;
   lcd_gotoxy(4,2);
   printf(lcd_putc,"%u%3.2w",s,ms);
   delay_ms(30);
   
   if (ms==0) {
   ms=60;
   break;
    }
   }
  if (s==0) break;
        }
       }
      }
     }
   

