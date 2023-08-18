#include <IBusBM.h>
IBusBM ibus;

int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
 

bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}

const char* durum;
int statu;
int gazKanal = readChannel(1,-100, 100, 0);
int donusKanal = readChannel(3, -100, 100, 0);
void setup() 
{
  Serial.begin(115200);
  ibus.begin(Serial1);
  durum = "Seri Ekran Acildi";
  Serial.println(durum);
  for(int i=2;i<=9;i++)
  {
  	pinMode(i,OUTPUT);
  }
  durum = "Pinler tanimlandi";
  Serial.println(durum);
}

void loop() 
{

if(-10 < gazKanal && gazKanal < 10 && -10 < gazKanal && gazKanal < 10)
{
	sifir();
  durum = "kumanda 0 konumunda";
  Serial.println(durum);
}

if(10 < gazKanal && gazKanal < 110 && -10 < donusKanal && donusKanal < 10)
{
	ileri();
  durum = "kumanda ileri konumunda";
  Serial.println(durum);
}

if(-110 < gazKanal && gazKanal < -10 && -10 < donusKanal && donusKanal < 10)
{
	geri();
  durum = "kumanda geri konumunda";
  Serial.println(durum);
}

if(-10 < gazKanal && gazKanal < 10 && -110 < donusKanal && donusKanal < -10)
{
	solSabit();
  durum = "kumanda sol konumunda";
  Serial.println(durum);
}

if(-10 < gazKanal && gazKanal < 10 && 10 < donusKanal && donusKanal < 110)
{
	sagSabit();
  durum = "kumanda sağ konumunda";
  Serial.println(durum);
}
if(10 < gazKanal && gazKanal < 100 && 10 < donusKanal && donusKanal < 100)
{
	sagIleri();
  durum = "kumanda sağ-ileri konumunda";
  Serial.println(durum);
}
if(10 < gazKanal && gazKanal < 100 && -100 < donusKanal && donusKanal < -10)
{
	solIleri();
  durum = "kumanda sol-ileri konumunda";
  Serial.println(durum);
}
if(-100 < gazKanal && gazKanal < -10 && -100 < donusKanal && donusKanal < -10)
{
	solGeri();
  durum = "kumanda sol-geri konumunda";
  Serial.println(durum);
}
if( -100 < gazKanal && gazKanal < -10 && 10 < donusKanal && donusKanal < 100)
{
	sagGeri();
  durum = "kumanda sağ-geri konumunda";
  Serial.println(durum);
}
}


int sifir()
{
	for(int i = 2; i  <= 9; i++)
    {
        analogWrite(i,0);
    }
}
int ileri()
{
	for(int i = 3; i <= 9; i += 2)
    {
    	analogWrite(i,gazKanal);
    }
	for(int i = 2; i <= 8; i += 2)
    {
    	analogWrite(i,0);
    }   	
}
int geri()
{
	for(int i = 2; i <= 8; i += 2)
    {
      gazKanal = -gazKanal;
    	analogWrite(i,gazKanal);
      gazKanal = -gazKanal; 
    }
	for(int i = 3; i <= 9; i += 2)
    {
    	analogWrite(i,0);
    }
}
int solSabit()
{
	for(int i = 3; i <= 5; i += 2)
    {
    	analogWrite(i,abs(donusKanal));
    }
	for(int i = 2; i <= 4; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 6; i <= 8; i += 2)
    {
    	analogWrite(i,abs(donusKanal));
    }
	for(int i = 7; i <= 9; i += 2)
    {
    	analogWrite(i,0);
    }
}
int sagSabit()
{
	for(int i = 3; i <= 5; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 2; i <= 4; i += 2)
    {
    	analogWrite(i,donusKanal);
    }
	for(int i = 6; i <= 8; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 7; i <= 9; i += 2)
    {
    	analogWrite(i,donusKanal);
    }
}
int sagIleri()
{
  int deger;
  if(abs(donusKanal) < abs(gazKanal))
  {
    deger = abs(gazKanal);
  }
  else if(abs(gazKanal) < abs(donusKanal))
  {
    deger = abs(donusKanal);
  }
  else
  {
    deger = abs(gazKanal);
  }
  	for(int i = 3; i <= 5; i += 2)
    {
    	analogWrite(i,deger - 20);
    }
	for(int i = 2; i <= 4; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 7; i <= 9; i += 2)
    {
    	analogWrite(i,deger);
    }
	for(int i = 6; i <= 8; i += 2)
    {
    	analogWrite(i,0);
    }
}
int solIleri()
{
  int deger;
  if(abs(donusKanal) < abs(gazKanal))
  {
    deger = abs(gazKanal);
  }
  else if(abs(gazKanal) < abs(donusKanal))
  {
    deger = abs(donusKanal);
  }
  else
  {
    deger = abs(gazKanal);
  }
  	for(int i = 3; i <= 5; i += 2)
    {
    	analogWrite(i,deger);
    }
	for(int i = 2; i <= 4; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 7; i <= 9; i += 2)
    {
    	analogWrite(i,deger - 20);
    }
	for(int i = 6; i <= 8; i += 2)
    {
    	analogWrite(i,0);
    }
}
int sagGeri()
{
  int deger;
  if(abs(donusKanal) < abs(gazKanal))
  {
    deger = abs(gazKanal);
  }
  else if(abs(gazKanal) < abs(donusKanal))
  {
    deger = abs(donusKanal);
  }
  else
  {
    deger = abs(gazKanal);
  }
  	for(int i = 3; i <= 5; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 2; i <= 4; i += 2)
    {
    	analogWrite(i,deger);
    }
	for(int i = 7; i <= 9; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 6; i <= 8; i += 2)
    {
    	analogWrite(i,deger - 20);
    }
}
int solGeri()
{
  int deger;
  if(abs(donusKanal) < abs(gazKanal))
  {
    deger = abs(gazKanal);
  }
  else if(abs(gazKanal) < abs(donusKanal))
  {
    deger = abs(donusKanal);
  }
  else
  {
    deger = abs(gazKanal);
  }
  	for(int i = 3; i <= 5; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 2; i <= 4; i += 2)
    {
    	analogWrite(i,deger - 20);
    }
	for(int i = 7; i <= 9; i += 2)
    {
    	analogWrite(i,0);
    }
	for(int i = 6; i <= 8; i += 2)
    {
    	analogWrite(i,deger);
    }
}