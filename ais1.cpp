//This file is part of the C++ AIS library.
//Copyright (c) 2021 Maxim Sayshin. Email: sayrhin@gmail.com
//Telegram: @NewSimpleton
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// The author warns that this is a research code, not a production tool.

#include "ais1.h"
#include "math.h"
//=======конструктор====================
ais1::ais1 ()
{
    WerkBlocClean();
};
//+++++++приватные++++++++++++++++++++++

//++++++++++публичные+++++++++++++++++++++++++
//==01============================================================
int8_t ais1::MessageType_1(void)
{    bool diag = true;
     MessageTypeClean();
     ais1::t.MessageType[5]='1';
  return  diag;
};
//-------------
int8_t ais1::MessageType_2(void)
{    bool diag = true;
     MessageTypeClean();
     ais1::t.MessageType[4]='1';
  return  diag;
};
//-------------
int8_t ais1::MessageType_3(void)
{    bool diag = true;
     MessageTypeClean();
     ais1::t.MessageType[4]='1';
     ais1::t.MessageType[5]='1';
  return  diag;
};
//-------------
std::string ais1::MessageType (void)
{   std::string res;
    for (uint8_t i=0; i<6; i++){
        res += ais1::t.MessageType[i];
    }
  return res;
};
//-------------
void ais1::MessageTypeClean (void)
{  for (uint8_t i=0; i<6; i++){
    ais1::t.MessageType[i]='0';}
};
//==02============================================================
uint8_t ais1::RepeatIndicator (std::string rep)
{   bool diag = true;
    uint8_t val=0;
    std::string res;
    if(rep.size()==1){             //проверяем длинну строки
            if(!(isdigit (rep[0]))){diag=false; ais1::t.error+="021,";} // проверяем нет ли букв
        }
    else {diag=false; ais1::t.error+="020,";} // длинна не равна 1 символу
    if(diag){val=std::atoi(&rep[0]);}// если проверки прошли то строку преобразуем в целое число
    if(diag){  res = BitCode(val);       // проверяем входит ли номер  в допустимый диапазон и переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=2)) ais1::t.RepeatIndicator[2-i]=res[res.size()-i]; //переписываем битовую строку в рабочий блок
        }}
return  diag;
//истина если функция отработала правильно
// если нет в регистр ошибок заносится код ошибки
// 021 при наличии буквы
// 020 если длиннее 1 символоа
};
//-------------
uint8_t ais1::RepeatIndicator (uint8_t rep)
{    bool diag = true;
     std::string res;
     if(rep<4){ res = BitCode(rep); // если проверки прошли то переводим в битовую строку
         for(uint8_t i=0; i<=res.size(); i++){
            if((res[res.size()-i] != '\0')&&(i<=2)) ais1::t.RepeatIndicator[2-i]=res[res.size()-i]; //переписываем битовую в рабочий блок
         }}
     else{diag=false; ais1::t.error+="020,";}
    return  diag;
     //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 022 входное значение больше 3х
};
//-------------
std::string ais1::RepeatIndicator (void)
{   std::string res;
    for (uint8_t i=0; i<2; i++){
        res += ais1::t.RepeatIndicator[i];
    }
  return res;
};
//-------------
void ais1::RepeatIndicatorClean (void)
{  for (uint8_t i=0; i<2; i++){
        ais1::t.RepeatIndicator[i]='0';}
};
//==03====================================================================
int8_t ais1::MMSI(std::string mmsi)
{   bool diag = true;
    uint32_t val=0;
    std::string res;
    if(mmsi.size()<10){             //проверяем длинну строки MMSI
        for (uint8_t i=0; i<mmsi.size(); i++){
            if(!(isdigit (mmsi[i]))){diag=false; ais1::t.error+="031,";} // проверяем нет ли букв в номере mmsi присутствуют буквы
        }}
    else {diag=false; ais1::t.error+="030,";} // длинна mmsi не равна 9 символам
    if(diag){ val=std::atoi(&mmsi[0]);  // если проверки прошли то строку преобразуем в целое число
        res = BitCode(val);       // и переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=30)) ais1::t.MMSI[30-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
        }
    }
    return  diag;
    //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 031 при наличии в номере буквы
    // 030 если номер длиннее либо короче 9 символов
};
//-------------
int8_t ais1::MMSI(uint32_t val)     // перегруженая функция записи mmsi
{   bool diag = true;
    std::string res;
    if(val>999999999){ diag=false; ais1::t.error+="032,"; }           //число MMSI больше заданного диапазона

    else { res = BitCode(val); // если проверки прошли то переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=30)) ais1::t.MMSI[30-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
        }
    }
    return  diag;
    //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 032 число MMSI больше 999999999 состоит более чем из 9-и знаков
};
//-------------
std::string ais1::MMSI (void)
{   std::string res;
    for (uint8_t i=0; i<30; i++){
        res += ais1::t.MMSI[i];
    }
  return res;
};
//-------------
void ais1::MMSIClean (void)
{  for (uint8_t i=0; i<30; i++){
        ais1::t.MMSI[i]='0';}
};
//======04========================================================
int8_t ais1::NavigationStatys (std::string nave)
{    bool diag = true;
     uint8_t val=0;
     std::string res;
     if(nave.size()<3){             //проверяем длинну строки
         for (uint8_t i=0; i<nave.size(); i++){
             if(!(isdigit (nave[i]))){diag=false; ais1::t.error+="041,";} // проверяем нет ли букв
         }}
     else {diag=false; ais1::t.error+="040,";} // длинна строки статуса больше 2-х символов
     if(diag){ val=std::atoi(&nave[0]);  // если проверки прошли то строку преобразуем в целое число
            if(val<16){  res = BitCode(val);// и переводим в битовую строку
                                     for(uint8_t i=0; i<=res.size(); i++){
                                        if((res[res.size()-i] != '\0')&&(i<=4)) ais1::t.navigation[4-i]=res[res.size()-i]; //переписываем битовую строку в рабочий блок
            }
         }else{diag=false; ais1::t.error+="042,";}    // статус не входит в допустимый диапазон
     }
     return  diag;
     //истина если функция отработала правильно
     // если нет в регистр ошибок заносится код ошибки
     // 041 при наличии буквы
     // 040 длинна строки с типом больше 2-х символов
     // 042 статус не входит в допустимый диапазон
};
//-------------
int8_t ais1::NavigationStatys (uint8_t val)
{    bool diag = true;
     std::string res;
     if(val<16){  res = BitCode(val);}            //проверяем длинну строки
     else {diag=false; ais1::t.error+="042,";} // статус не входит в допустимый диапазон
     if(diag){ for(uint8_t i=0; i<=res.size(); i++){  // если проверки прошли то переводим в битовую строку
                    if((res[res.size()-i] != '\0')&&(i<=4)) ais1::t.navigation[4-i]=res[res.size()-i]; //переписываем битовую строку в рабочий блок
         }
     }
     return  diag;
     //истина если функция отработала правильно
     // если нет в регистр ошибок заносится код ошибки
     // 042 статус не входит в допустимый диапазон
};
//-------------
std::string ais1::NavigationStatys (void)
{   std::string res;
    for (uint8_t i=0; i<4; i++){
        res += ais1::t.navigation[i];
    }
  return res;
};
//-------------
void  ais1::NavigationStatysClean (void)
{  for (uint8_t i=0; i<4; i++){
        ais1::t.navigation[i]='0';}
};
//======05========================================================
int8_t ais1::ROT (int16_t rot_sens)
{   bool diag = true;
    std::string res;
    int16_t rot;
    rot=4.733*(sqrt(fabs(rot_sens)));
    if (rot_sens<0){rot=0-rot;}
    if ((rot>=-128)&&(rot<=127)){res=BitCode(rot);
        for(uint8_t i=0; i<=res.size(); i++){
            if((res[res.size()-i] != '\0')&&(i<=8)) ais1::t.ROT[8-i]=res[res.size()-i];}} //переписываем битовую строку в рабочий блок
    else if(rot==128){ais1::ROTClean(); ais1::t.ROT[0]='1';}
    else {diag=false; ais1::t.error+="052,";}
    return diag;
    // 052 не входит в допустимый диапазон
};
/*      • 0 = не поворачивается
        • 1… 126 = поворот вправо со скоростью до 708 градусов в минуту или выше
        • 1… -126 = поворот влево со скоростью до 708 градусов в минуту или выше
        • 127 = поворот направо более чем на 5 градусов / 30 с (TI недоступен)
        • -127 = поворот влево более чем на 5 градусов / 30 с (TI недоступен)
        • 128 (80 в шестнадцатеричном формате) указывает, что информация о повороте недоступна (по умолчанию)*/
//-------------
std::string ais1::ROT (void)
{   std::string res;
    for (uint8_t i=0; i<8; i++){
        res += ais1::t.ROT[i];
    }
  return res;
};
//-------------
void ais1::ROTClean (void)
{  for (uint8_t i=0; i<8; i++){
        ais1::t.ROT[i]='0';}
};
//=====06=========================================================
int8_t ais1::SOG (std::string sog)
{   bool diag = true;
    std::string res;
    float val=0;
    for (uint8_t i=0; i<sog.size(); i++){
        if((!(isdigit (sog[i])))||(!(sog[i]==','))||(!(sog[i]=='.'))){diag=false; ais1::t.error+="061,";} // проверяем нет ли букв в осадке судна
    }
    if(diag){ val=std::atof(&sog[0]);} else{}  // если проверки прошли то строку преобразуем в число с плавающей запятой
    if(val>102.2){val=102.2;}   //значение 102.2 указывает что скорость 102.2 узла и выше
                                    // значение 102.3 указывает что скорость недоступна
    else if(val>=0){
    res=BitCode(uint16_t(val*10));
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=10)) ais1::t.SOG[10-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }} {diag = false; ais1::t.error+=064;}
    return  diag;
    //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 061 при наличии буквы в значении скорости
    // 064 отрицательное значение скорости
};
//-------------
int8_t ais1::SOG (float sog)
{   bool diag = true;
    std::string res;
    if(sog>102.2){sog=102.2;}   //значение 102.2 указывает что скорость 102.2 узла и выше
                                // значение 102.3 указывает что скорость недоступна
    else if (sog>=0){res=BitCode(uint16_t(sog*10));
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=10)) ais1::t.SOG[10-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }} else {diag = false; ais1::t.error+=064;}
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 064 отрицательное значение скорости
};
//-------------
int8_t ais1::SOGno (void)
{   bool diag = true;
    const uint16_t sog = 1023;
    std::string res;
    res = BitCode(sog);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=10)) ais1::t.SOG[10-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }
  return  diag;
};
//-------------
std::string ais1::SOG (void)
{   std::string res;
    for (uint8_t i=0; i<10; i++){
        res += ais1::t.SOG[i];
    }
  return res;
};
//-------------
void ais1::SOGClean (void)
{  for (uint8_t i=0; i<10; i++){
        ais1::t.SOG[i]='0';}
};
//====07==========================================================
/*Значение 1 указывает на DGPS с точностью <10 м.
 * значение 0  по умолчанию, указывает на GNSS с точностью> 10 м.*/
int8_t ais1::PositionAccuracy (bool val)
{   bool diag = true;
    if (val){ais1::t.PositionAccuracy[0]='1';}
    else {ais1::t.PositionAccuracy[0]='0';}
  return  diag;
};
//-------------
int8_t ais1::PositionAccuracy (std::string str)
{   bool diag = true;
    if (str=="DGPS"){ais1::t.PositionAccuracy[0]='1';}
    else if (str == "GPS"){ais1::t.PositionAccuracy[0]='0';}
    else if (str == "GNSS"){ais1::t.PositionAccuracy[0]='0';}
    else {diag = false; ais1::t.error+="071,";}
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 071 введённое значение не соответствует форме
};
//-------------
std::string ais1::PositionAccuracy (void)
{   std::string res;
    res +=ais1::t.PositionAccuracy[0];
  return res;
};
//-------------
void ais1::PositionAccuracyClean (void)
{  for (uint8_t i=0; i<1; i++){
        ais1::t.PositionAccuracy[i]='0';}
};
//====08==========================================================
int8_t ais1::lon (int16_t g, float m)
{   bool diag = true;
    int32_t m1;
    std::string res;
    //std::cout<<"grad="<<g<<"  min="<<m<<std::endl;
    if ((g<0)&&(g>-181)){m-=g*60; m=0-m;}
    else if ((g>=0)&&(g<181)) {m+=g*60;}
    else if (g==181){m=181*60;}
    else {m=181*60; diag = false; ais1::t.error+="082,";}
    m1= int32_t(m*10000);
    res= BitCode(m1);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=28)) ais1::t.lon[28-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 082 долгота не входит в допустимый диапазон
};
//-------------
std::string ais1::lon (void)
{   std::string res;
    for (uint8_t i=0; i<28; i++){
        res += ais1::t.lon[i];
    }
  return res;
};
//-------------
void ais1::lonClean (void)
{  for (uint8_t i=0; i<28; i++){
        ais1::t.lon[i]='0';}
};
//====09==========================================================
int8_t ais1::lat (int16_t g, float m)
{   bool diag = true;
    int32_t m1;
    std::string res;
    //std::cout<<"grad="<<g<<"  min="<<m<<std::endl;
    if ((g<0)&&(g>-91)){m-=g*60; m=0-m;}
    else if ((g>=0)&&(g<91)) {m+=g*60;}
    else if (g==91){m=91*60;}
    else {m=91*60; diag = false; ais1::t.error+="092,";}
    m1= int32_t(m*10000);
    res= BitCode(m1);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=27)) ais1::t.lat[27-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 092 широта не входит в допустимый диапазон
};
//-------------
std::string ais1::lat (void)
{   std::string res;
    for (uint8_t i=0; i<27; i++){
        res += ais1::t.lat[i];
    }
  return res;
};
//-------------
void ais1::latClean (void)
{  for (uint8_t i=0; i<27; i++){
        ais1::t.lat[i]='0';}
};
//===10===========================================================
int8_t ais1::COG (float cog)    //Относительно истинного севера с точностью до 0,1 градуса
{   bool diag = true;
    std::string res;
    uint16_t icog;
    cog = cog*10;
    icog = uint16_t(cog);
    if ((icog<=3600)&&(icog>=0)){ res= BitCode(cog);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=12)) ais1::t.COG[12-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }}else{diag = false; ais1::t.error+="102,";}
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 102 COG не входит в допустимый диапазон
};
//-------------
std::string ais1::COG (void)
{   std::string res;
    for (uint8_t i=0; i<12; i++){
        res += ais1::t.COG[i];
    }
  return res;
};
//-------------
void ais1::COGClean (void)
{  for (uint8_t i=0; i<12; i++){
        ais1::t.COG[i]='0';}
};
//=====11=========================================================
int8_t ais1::HDG (uint16_t hdg) //От 0 до 359 градусов, 511 = не доступно.
{   bool diag = true;
    std::string res;
    if ((hdg>=0)&&((hdg<360)||(hdg==511))){res= BitCode(hdg);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=9)) ais1::t.HDG[9-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }}else{diag = false; ais1::t.error+="112,";}
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 112 HDG не входит в допустимый диапазон
};
//-------------
std::string ais1::HDG (void)
{   std::string res;
    for (uint8_t i=0; i<9; i++){
        res += ais1::t.HDG[i];
    }
  return res;
};
//-------------
void ais1::HDGClean (void)
{  for (uint8_t i=0; i<9; i++){
        ais1::t.HDG[i]='0';}
};
//===12===========================================================
//60, если отметка времени недоступна (по умолчанию)
//61, если система позиционирования находится в режиме ручного ввода
//62, если электронная система определения местоположения работает в режиме приблизительного расчета
//63, если система позиционирования не работает
int8_t ais1::Time (uint8_t time)
{   bool diag = true;
    std::string res;
    if ((time>=0)&&(time<64)){res= BitCode(time);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=6)) ais1::t.time[6-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }}else{diag = false; ais1::t.error+="122,";}
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 122 time не входит в допустимый диапазон
};
//-------------
std::string ais1::Time (void)
{   std::string res;
    for (uint8_t i=0; i<6; i++){
        res += ais1::t.time[i];
    }
  return res;
};
//-------------
void ais1::TimeClean (void)
{  for (uint8_t i=0; i<6; i++){
        ais1::t.time[i]='0';}
};
//==13============================================================
//0 Недоступно (по умолчанию)
//1 Никакого особого маневра
//2 Специальный маневр (например, региональное прохождение)
//Системы речного и внутреннего судоходства, обозначают это поле "Голубой знак" следующими перечисленными значениями:
//0 Недоступно (по умолчанию)
//1 да
//2 нет
  int8_t ais1::DTE (uint8_t dte)
  {   bool diag = true;
      std::string res;
      if ((dte>=0)&&(dte<3)){res= BitCode(dte);
      for(uint8_t i=0; i<=res.size(); i++){
         if((res[res.size()-i] != '\0')&&(i<=2)) ais1::t.DTE[2-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
      }}else{diag = false; ais1::t.error+="132,";}
    return  diag;
    //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 132 DTE не входит в допустимый диапазон
  };
//-------------
  std::string ais1::DTE (void)
  {   std::string res;
      for (uint8_t i=0; i<2; i++){
          res += ais1::t.DTE[i];
      }
    return res;
  };
//-------------
 void ais1::DTEClean (void)
 {  for (uint8_t i=0; i<2; i++){
          ais1::t.DTE[i]='0';}
 };
//=====15=========================================================
int8_t ais1::RAIM (bool raim)
{   bool diag = true;
    if (raim){ais1::t.RAIM[0]='1';}
    else {ais1::t.RAIM[0]='0';}
  return  diag;
};
//-------------
std::string ais1::RAIM (void)
{   std::string res;
    res +=ais1::t.RAIM[0];
  return res;
};
//-------------
void ais1::RAIMClean (void)
{   ais1::t.RAIM[0]='0';};
//================================================================
std::string ais1::Spare (void)
{   std::string res;
    for (uint8_t i=0; i<3; i++){
        res += ais1::t.spare[i];
    }
  return res;
};
//-------------
void ais1::SpareClean (void)
{  for (uint8_t i=0; i<3; i++){
        ais1::t.spare[i]='0';}
};
//-------------
std::string ais1::Radio (void)
{   std::string res;
    for (uint8_t i=0; i<19; i++){
        res += ais1::t.radio[i];
    }
  return res;
};
//-------------
void ais1::RadioClean (void)
{  for (uint8_t i=0; i<19; i++){
        ais1::t.radio[i]='0';}
};
//================================================================
void ais1::errorClean (void)
{
    ais1::t.error.clear();
};
//================================================================
std::string ais1::WerkBlocBitString (void)
{   std::string res;
        res+=ais1::MessageType();
        res+=ais1::RepeatIndicator();
        res+=ais1::MMSI();
        res+=ais1::NavigationStatys();
        res+=ais1::ROT();
        res+=ais1::SOG();
        res+=ais1::PositionAccuracy();
        res+=ais1::lon();
        res+=ais1::lat();
        res+=ais1::COG();
        res+=ais1::HDG();
        res+=ais1::Time();
        res+=ais1::DTE();
        res+=ais1::Spare();
        res+=ais1::RAIM();
        res+=ais1::Radio();
        addition=AdditionBit(res);
  return res;
};
//-------------
std::string ais1::WerkBlocBitStringAdded (void)
{   std::string res;
    std::string bitStr;
    res=AdditionBitString(ais1::WerkBlocBitString());
  return res;
};
//-------------
std::string ais1::WerkBlocSixString (void)
{   std::string res;
    std::string bitStr;
    bitStr=ais1::WerkBlocBitString();
    res = BitSix(bitStr);
  return res;
};
//-------------
std::string ais1::WerkBlocSixStringAdded (void)
{   std::string res;
    res=BitSix(ais1::WerkBlocBitStringAdded());
  return res;
};
//-------------
std::string ais1::WerkBlocSixString (std::string bitStr)
{   std::string res;
    res = BitSix(bitStr);
  return res;
};
//-------------
void ais1::WerkBlocClean (void)
{   ais1::MessageTypeClean();
    ais1::RepeatIndicatorClean();
    ais1::MMSIClean();
    ais1::NavigationStatysClean();
    ais1::ROTClean();
    ais1::SOGClean();
    ais1::PositionAccuracyClean();
    ais1::lonClean();
    ais1::latClean();
    ais1::COGClean();
    ais1::HDGClean();
    ais1::TimeClean();
    ais1::DTEClean();
    ais1::RAIMClean();
    ais1::SpareClean();
    ais1::RadioClean();
    ais1::t.end='\0';
    ais1::errorClean();
};
//-------------
uint16_t ais1::AddBit (void)
{
    return ais1::addition;
};
//-------------
std::string ais1::Error (void)
{   std::string res;
    if(t.error.size()>0){res=t.error;}
    else{res="ошибок нет";}
    return res;
};
//==============Методы диагностики==================================================
void ais1::WerkBlocWrite (void)
{   uint16_t i=0;
    std::string str;
    std::cout<<std::endl<<"----------------------------------------------РАБОЧИЙ БЛОК 1, 2, 3 ТИПОВ-------------------------------------------------"<<std::endl;
               std::cout<<"тип сообщения-------------"; while (i<6){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"индикатор повтора---------"; while (i<8){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"MMSI----------------------"; while (i<38){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"статус навигации----------"; while (i<42){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"скорость поворота ROT-----"; while (i<50){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"скорость отн. земли SOG---"; while (i<60){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"точность положения--------"; while (i<61){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"долгота-------------------"; while (i<89){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"широта--------------------"; while (i<116){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"курс отн. земли COG-------"; while (i<128){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"истинное направление------"; while (i<137){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"отметка времени-----------"; while (i<143){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"индикатор манёвра---------"; while (i<145){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"не используется-----------"; while (i<148){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"RAIM----------------------"; while (i<149){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"радио статус--------------"; while (i<168){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl;
    std::cout<<std::endl<<"выведено бит--------------"<<i;

    if(t.error.size()==0){str="ошибок нет";}
    else{str=t.error;}

    std::cout<<std::endl<<"ошибки--------------------"<<str;
    std::cout<<std::endl<<"шестибитная строка--------"; std::cout<<WerkBlocSixString();
    std::cout<<std::endl<<"шестибитная строка-дополн-"; std::cout<<WerkBlocSixStringAdded();
    std::cout<<std::endl<<"размер шестибитной строки-"; std::cout<<(WerkBlocSixString()).size()<<std::endl;
    std::cout<<std::endl<<"AIS сообщения-------------";std::cout<<std::endl;
    std::cout<< AIVDMMessege(WerkBlocSixStringAdded(), AddBit(), 'A') <<std::endl;
};
