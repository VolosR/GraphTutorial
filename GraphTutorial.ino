#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();  
TFT_eSprite sprite= TFT_eSprite(&tft);

#define color1 0xF79E
#define color2 0xB1B1
#define color3 0x4A69

String week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int values[7]={0};
int sum=0;
float average=0.00;

void setup() {
  tft.init();
  tft.setRotation(1);
  sprite.createSprite(320,170);

}
void drawGraph()
  { 
  sprite.fillSprite(color3);
  sprite.fillRect(10,40,300,120,color1);
  sprite.fillRoundRect(20,20,280,110,5,color2);
  sprite.fillRect(60,30,2,80,color1);
  sprite.fillRect(60,110,218,2,color1);

  sprite.setTextDatum(4);
  sprite.setTextColor(color1,color2);
  
    for(int i=2;i<8;i=i+2){
    sprite.drawString(String(i*10),50,110-(i*10));
    for(int j=0;j<218;j=j+5)
    sprite.drawPixel(60+j,110-(i*10),color1);
    }

  sum=0;
  for(int i=0;i<7;i++){
  sprite.drawString(week[i],90+(i*30),120);
  values[i]=random(5,80);
  sum=sum+values[i];
  sprite.fillRect(82+(i*30),110-values[i],16,values[i],color1);
  }

  average=sum/7.00;
  sprite.setTextDatum(0);
  sprite.setTextColor(color3,color1);

  sprite.drawString("SUM= "+String(sum),20,136,2);
  sprite.drawString("AVERAGE= "+String(average),120,136,2);

  sprite.setTextColor(color1,color3);
  sprite.drawString("EARNINGS $",20,4,2);
  

  sprite.pushSprite(0,0);
  }

void loop() {
 drawGraph();
 delay(3000);
}
