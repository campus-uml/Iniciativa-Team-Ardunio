/* 
Programa: Arduino Solar Tracker
Autor:	Humberto Higinio
Web: www.humbertohiginio.com
Canal de Youtube: https://www.youtube.com/user/HHSolis
Video Exclusivo para mi canal de Youtube
Todos los Derechos Reservados - 2016
Código de Dominio Público
*/

#include <Servo.h>
//Definiendo Servos
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 20;
//Asignando LDRs
int ldrtopl = 2; //top left LDR
int ldrtopr = 1; //top right LDR
int ldrbotl = 3; // bottom left LDR
int ldrbotr = 0; // bottom right LDR

 void setup () 
 {
  servohori.attach(10);
  servohori.write(0);
  servoverti.attach(9);
  servoverti.write(0);
  delay(500);
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //capturando valores analogicos de cada LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  // calculando el Promedio
  int avgtop = (topl + topr) / 2; //Promedio del top LDRs
  int avgbot = (botl + botr) / 2; //Promedio del bottom LDRs
  int avgleft = (topl + botl) / 2; //Promedio del left LDRs
  int avgright = (topr + botr) / 2; //Promedio del right LDRs

  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}
