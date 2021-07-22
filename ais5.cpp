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

#include "ais5.h"

//=======конструктор====================
ais5::ais5()
{
    ais5::WerkBlocClean();
    ais5::MessageType_5();
};
//+++++++приватные++++++++++++++++++++++
//-----01-------
std::string ais5::MessageType (void)
{   std::string res;
    for (uint8_t i=0; i<6; i++){
        res += ais5::t.MessageType[i];
    }
  return res;
};
//-----02-------
std::string ais5::RepeatIndicator (void)
{   std::string res;
    for (uint8_t i=0; i<2; i++){
        res += ais5::t.RepeatIndicator[i];
    }
  return res;
};
//----03--------
std::string ais5::MMSI (void)
{   std::string res;
    for (uint8_t i=0; i<30; i++){
        res += ais5::t.MMSI[i];
    }
  return res;
};
//-----04-------
std::string ais5::AisVer (void)
{   std::string res;
    for (uint8_t i=0; i<2; i++){
        res += ais5::t.AisVersion[i];
    }
  return res;
};
//------05------
std::string ais5::IMO (void)
{   std::string res;
    for (uint8_t i=0; i<30; i++){
        res += ais5::t.IMO[i];
    }
  return res;
};
//-----06-------
std::string ais5::CallSign (void)
{   std::string res;
    for (uint8_t i=0; i<42; i++){
        res += ais5::t.CallSign[i];
    }
  return res;
};
//-----07-------
std::string ais5::VesselName (void)
{   std::string res;
    for (uint8_t i=0; i<120; i++){
        res += ais5::t.VesselName[i];
    }
  return res;
};
//-----08-------
std::string ais5::ShipType (void)
{   std::string res;
    for (uint8_t i=0; i<8; i++){
        res += ais5::t.ShipType[i];
    }
  return res;
};
//-----09-------
std::string ais5::Dimension (void)
{   std::string res;
    for (uint8_t i=0; i<9; i++){
        res += ais5::t.DimensionBow[i];}
    for (uint8_t i=0; i<9; i++){
        res += ais5::t.DimensionStern[i];}
    for (uint8_t i=0; i<6; i++){
        res += ais5::t.DimensionPort[i];}
    for (uint8_t i=0; i<6; i++){
        res += ais5::t.DimensionStarboard[i];}
  return res;
};
//----13--------
std::string ais5::PositionType (void)
{   std::string res;
    for (uint8_t i=0; i<4; i++){
        res += ais5::t.PositionType[i];
    }
  return res;
};
//---14--------
std::string ais5::ETA (void)
{   std::string res;
    for (uint8_t i=0; i<4; i++){
        res += ais5::t.ETAmonth[i];}
    for (uint8_t i=0; i<5; i++){
        res += ais5::t.ETAday[i];}
    for (uint8_t i=0; i<5; i++){
        res += ais5::t.ETAhour[i];}
    for (uint8_t i=0; i<6; i++){
        res += ais5::t.ETAminute[i];}
  return res;
};
//-----18-------
std::string ais5::Draught (void)
{   std::string res;
    for (uint8_t i=0; i<8; i++){
        res += ais5::t.Draught[i];
    }
  return res;
};
//-----19-------
std::string ais5::Destination (void)
{   std::string res;
    for (uint8_t i=0; i<120; i++){
        res += ais5::t.Destination[i];
    }
  return res;
};
//----20--------
std::string ais5::DTE (void)
{   std::string res;
    res +=ais5::t.DTE[0];
  return res;
};
//----21--------
std::string ais5::Spare (void)
{   std::string res;
    res +=ais5::t.Spare[0];
  return res;
};
//-------------
std::string ais5::WerkBlocSixString (std::string bitStr)
{   std::string res;
    res = BitSix(bitStr);
  return res;
};
//++++++++++++++++++++++++++++++++++++++++++++
//++++++++++публичные+++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++
//==01====================================================================
int8_t ais5::MessageType_5(void)
{    bool diag = true;
     ais5::MessageTypeClean();
     ais5::t.MessageType[3]='1';
     ais5::t.MessageType[5]='1';
  return  diag;
};
//-------------
void ais5::MessageTypeClean (void)
{  for (uint8_t i=0; i<6; i++){
    ais5::t.MessageType[i]='0';}
}
//==02====================================================================
uint8_t ais5::RepeatIndicator (std::string rep)
{   bool diag = true;
    uint8_t val=0;
    std::string res;
    if(rep.size()==1){             //проверяем длинну строки
            if(!(isdigit (rep[0]))){diag=false; ais5::t.error+="021,";} // проверяем нет ли букв
        }
    else {diag=false; ais5::t.error+="020,";} // длинна не равна 1 символу
    if(diag){val=std::atoi(&rep[0]);}// если проверки прошли то строку преобразуем в целое число
    if(diag){  res = BitCode(val);       // проверяем входит ли номер  в допустимый диапазон и переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=2)) ais5::t.RepeatIndicator[2-i]=res[res.size()-i]; //переписываем битовую строку в рабочий блок
        }}
return  diag;
//истина если функция отработала правильно
// если нет в регистр ошибок заносится код ошибки
// 021 при наличии буквы
// 020 если длиннее 1 символоа
};
//-------------
uint8_t ais5::RepeatIndicator (uint8_t rep)
{    bool diag = true;
     std::string res;
     if(rep<4){ res = BitCode(rep); // если проверки прошли то переводим в битовую строку
         for(uint8_t i=0; i<=res.size(); i++){
            if((res[res.size()-i] != '\0')&&(i<=2)) ais5::t.RepeatIndicator[2-i]=res[res.size()-i]; //переписываем битовую в рабочий блок
         }}
     else{diag=false; ais5::t.error+="020,";}
    return  diag;
     //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 022 входное значение больше 3х
};
//-------------
void ais5::RepeatIndicatorClean (void)
{  for (uint8_t i=0; i<2; i++){
        ais5::t.RepeatIndicator[i]='0';}
};
//==03====================================================================
int8_t ais5::MMSI(std::string mmsi)
{   bool diag = true;
    uint32_t val=0;
    std::string res;
    if(mmsi.size()<10){             //проверяем длинну строки MMSI
        for (uint8_t i=0; i<mmsi.size(); i++){
            if(!(isdigit (mmsi[i]))){diag=false; ais5::t.error+="031,";} // проверяем нет ли букв в номере mmsi присутствуют буквы
        }}
    else {diag=false; ais5::t.error+="030,";} // длинна mmsi не равна 9 символам
    if(diag){ val=std::atoi(&mmsi[0]);  // если проверки прошли то строку преобразуем в целое число
        res = BitCode(val);       // и переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=30)) ais5::t.MMSI[30-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
        }
    }
    //std::cout<<"VAL= "<< val<<std::endl;
    //std::cout<<res<<std::endl;
    return  diag;   //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 031 при наличии в номере буквы
    // 030 если номер длиннее либо короче 9 символов
};
//-------------
int8_t ais5::MMSI(uint32_t val)     // перегруженая функция записи mmsi
{   bool diag = true;
    std::string res;
    if(val>999999999){ diag=false; ais5::t.error+="032,"; }           //число MMSI больше заданного диапазона

    else { res = BitCode(val); // если проверки прошли то переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=30)) ais5::t.MMSI[30-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
        }
    }
    //std::cout<<"VAL= "<< val<<std::endl;
    //std::cout<<res<<std::endl;
    return  diag;   //истина если функция отработала правильно
    // если нет в регистр ошибок заносится код ошибки
    // 032 число MMSI больше 999999999 состоит более чем из 9-и знаков
};
//-------------
void ais5::MMSIClean (void)
{  for (uint8_t i=0; i<30; i++){
        ais5::t.MMSI[i]='0';}
};
//====04==================================================================
int8_t ais5::AisVer (std::string ver)
{    bool diag = true;
        uint8_t val=0;
        std::string res;
        if(ver.size()==1){             //проверяем длинну строки версии аис
                if(!(isdigit (ver[0]))){diag=false; ais5::t.error+="041,";} // проверяем нет ли букв в номере версии присутствуют буквы
            }
        else {diag=false; t.error+="040,";} // длинна версии не равна 1 символу
        if(diag){val=std::atoi(&ver[0]);}// если проверки прошли то строку преобразуем в целое число
        if((diag)&&(val<4)){  res = BitCode(val);       // проверяем входит ли номер версии в допустимый диапазон и переводим в битовую строку
            for(uint8_t i=0; i<=res.size(); i++){
               if((res[res.size()-i] != '\0')&&(i<=2)) ais5::t.AisVersion[2-i]=res[res.size()-i]; //переписываем битовую строку в рабочий блок
            }}else{diag=false; ais5::t.error+="042,";}  //номер версии выходит за допустимый диапазон
return  diag;   //истина если функция отработала правильно
 // если нет в регистр ошибок заносится код ошибки
 // 041 при наличии в номере версии аис буквы
 // 040 если номер версии аис длиннее либо короче 1 символоа
 // 042 номер версии аис больше 3х
};
//-------------
int8_t ais5::AisVer (uint8_t ver)
{    bool diag = true;
    std::string res;
    if(ver>3){ diag=false; ais5::t.error+="042,"; } //номер версии выходит за допустимый диапазон
    else { res = BitCode(ver); // если проверки прошли то переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=2)) ais5::t.AisVersion[2-i]=res[res.size()-i]; //переписываем битовую строку в рабочий блок
        }}
   return  diag;   //истина если функция отработала правильно
   // если нет в регистр ошибок заносится код ошибки
   // 042 номер версии аис больше 3х
};
//-------------
void ais5::AisVerClean (void)
{  for (uint8_t i=0; i<2; i++){
        ais5::t.AisVersion[i]='0';}
};
//=======05===============================================================
int8_t ais5::IMO (std::string imo)
{   bool diag = true;
    std::string res;
    uint16_t k1, k2, k3, k4, k5, k6, k7, k0;
    uint32_t val=0, val1=val;

    if(imo.size()<8){             //проверяем длинну строки MMSI
        for (uint8_t i=0; i<imo.size(); i++){
            if(!(isdigit (imo[i]))){diag=false; ais5::t.error+="051,";} // проверяем нет ли букв в номере imo присутствуют буквы
        }}
    else {diag=false; ais5::t.error+="050,";} // длинна mmsi не равна 7 символам
    if(diag){ val=std::atoi(&imo[0]);  // если проверки прошли то строку преобразуем в целое число

    if(val>9999999){diag = false; ais5::t.error+="052,";} //номер IMO выходит за допустимый диапазон
    else{
        k1 = val1%10; val1 = val1/10;          // проверка номера IMO на действительность
        //std::cout<<"k1= "<<k1<<std::endl;
        k2 = val1%10; val1 = val1/10;
        //std::cout<<"k2= "<<k2<<std::endl;
        k3 = val1%10; val1 = val1/10;
        //std::cout<<"k3= "<<k3<<std::endl;
        k4 = val1%10; val1 = val1/10;
        //std::cout<<"k4= "<<k4<<std::endl;
        k5 = val1%10; val1 = val1/10;
        //std::cout<<"k5= "<<k5<<std::endl;
        k6 = val1%10; val1 = val1/10;
        //std::cout<<"k6= "<<k6<<std::endl;
        k7 = val1%10;
        //std::cout<<"k7= "<<k7<<std::endl;
        k0 = k7*7+k6*6+k5*5+k4*4+k3*3+k2*2;
        k0 = k0%10;
        //std::cout<<"k0= "<<k0<<std::endl;
            if (k0 != k1){diag = false; ais5::t.error+="055,";}// проверка действительности номера IMO, код 035 - номер не действителен
            else{res = BitCode(val); // если проверки прошли то переводим в битовую строку
                for(uint8_t i=0; i<=res.size(); i++){
                    if((res[res.size()-i] != '\0')&&(i<=30)) {ais5::t.IMO[30-i]=res[res.size()-i];} //переписываем битовую строку с imo в рабочий блок
    }}}}
    return diag;
    // если нет в регистр ошибок заносится код ошибки
    // 050 длинна IMO не равна 7 символам
    // 051 в номере IMO присутствуют буквы
    // 052 номер IMO больше допустимого (9999999)
    // 055 номер IMO не достоверен
};
//-------------
int8_t ais5::IMO (uint32_t val)
{   bool diag = true;
    std::string res;
    uint16_t k1, k2, k3, k4, k5, k6, k7, k0;
    uint32_t val1=val;
    if(val>9999999){diag = false; ais5::t.error+="052,";} //номер IMO выходит за допустимый диапазон
    else{
        k1 = val1%10; val1 = val1/10;          // проверка номера IMO на действительность
        //std::cout<<"k1= "<<k1<<std::endl;
        k2 = val1%10; val1 = val1/10;
        //std::cout<<"k2= "<<k2<<std::endl;
        k3 = val1%10; val1 = val1/10;
        //std::cout<<"k3= "<<k3<<std::endl;
        k4 = val1%10; val1 = val1/10;
        //std::cout<<"k4= "<<k4<<std::endl;
        k5 = val1%10; val1 = val1/10;
        //std::cout<<"k5= "<<k5<<std::endl;
        k6 = val1%10; val1 = val1/10;
        //std::cout<<"k6= "<<k6<<std::endl;
        k7 = val1%10;
        //std::cout<<"k7= "<<k7<<std::endl;
        k0 = k7*7+k6*6+k5*5+k4*4+k3*3+k2*2;
        k0 = k0%10;
        //std::cout<<"k0= "<<k0<<std::endl;
            if (k0 != k1){diag = false; ais5::t.error+="055,";}// проверка действительности номера IMO, код 035 - номер не действителен
            else{res = BitCode(val); // если проверки прошли то переводим в битовую строку
                for(uint8_t i=0; i<=res.size(); i++){
                    if((res[res.size()-i] != '\0')&&(i<=30)) ais5::t.IMO[30-i]=res[res.size()-i]; //переписываем битовую строку с imo в рабочий блок
    }}}
    return diag;
    // если нет в регистр ошибок заносится код ошибки
    // 052 номер IMO больше допустимого (9999999)
    // 055 номер IMO не достоверен
};
//-------------
void ais5::IMOClean (void)
{  for (uint8_t i=0; i<30; i++){
        ais5::t.IMO[i]='0';}
};
//======06================================================================
int8_t ais5::CallSign (std::string call)
{   bool diag = true;
    std::string res;
    call=ToAppers(call);
    //std::cout<<"позывной "<<call<<std::endl;
    uint32_t j = call.size();
    if ( j<8 ){ res = ASCIISixBit(call); }
        else{diag = false; ais5::t.error+="062,";}    // длинна позывного больше семи символов
    for(uint8_t i=0; i<res.size(); i++){
        if(res[i] != '\0') ais5::t.CallSign[i]=res[i]; //переписываем битовую строку с позывным в рабочий блок
    }
    //std::cout<<"res = "<<res<<std::endl;
    return diag;
    // если нет в регистр ошибок заносится код ошибки
    // 062 длинна позывного больше семи символов
};
//-------------
void ais5::CallSignClean (void)
{  for (uint8_t i=0; i<42; i++){
        ais5::t.CallSign[i]='0';}
};
//======07================================================================
int8_t ais5::VesselName (std::string name)
{   bool diag = true;
    std::string res;
    name=ToAppers(name);
    uint32_t j = name.size();
    if ( j<21 ){ res = ASCIISixBit(name); }
        else{diag = false; ais5::t.error+="072,";}    // длинна названия больше двадцати символов
    for(uint8_t i=0; i<res.size(); i++){
        if(res[i] != '\0') ais5::t.VesselName[i]=res[i]; //переписываем битовую строку с позывным в рабочий блок
    }
    //std::cout<<"res = "<<res<<std::endl;
    return diag;
    // если нет в регистр ошибок заносится код ошибки
    // 072 длинна названия больше двадцати символов
};
//-------------
void ais5::VesselNameClean (void)
{  for (uint8_t i=0; i<120; i++){
        ais5::t.VesselName[i]='0';}
};
//======08================================================================
int8_t ais5::ShipType (std::string type)
{    bool diag = true;
     uint8_t val=0;
     // std::cout<<"тип судна ctr "<<type<<std::endl;
     std::string res;
     if(type.size()<3){             //проверяем длинну строки с типом судна
         for (uint8_t i=0; i<type.size(); i++){
             if(!(isdigit (type[i]))){diag=false; ais5::t.error+="081,";} // проверяем нет ли букв в коде типа судна
         }}
     else {diag=false; ais5::t.error+="080,";} // длинна строки с типом больше 3-х символов
     if(diag){ val=std::atoi(&type[0]);  // если проверки прошли то строку преобразуем в целое число
            if((val>20)&&(val<100)){  res = BitCode(val);// и переводим в битовую строку
                                     for(uint8_t i=0; i<=res.size(); i++){
                                        if((res[res.size()-i] != '\0')&&(i<=8)) ais5::t.ShipType[8-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
            }
         }else{diag=false; ais5::t.error+="082,";}    // тип корабля не входит в допустимый диапазон
     }
     //std::cout<<"res = "<<res<<std::endl;
     return  diag;
     //истина если функция отработала правильно
     // если нет в регистр ошибок заносится код ошибки
     // 081 при наличии буквы
     // 080 длинна строки с типом больше 3-х символов
     // 082 тип корабля не входит в допустимый диапазон
};
//-------------
int8_t ais5::ShipType (uint8_t val)
{    bool diag = true;
     std::string res;
     //  std::cout<<"тип судна int "<<val<<std::endl;
     if((val>20)&&(val<100)){  res = BitCode(val);}            //проверяем длинну строки с типом судна
     else {diag=false; ais5::t.error+="082,";} // тип корабля не входит в допустимый диапазон
     if(diag){ for(uint8_t i=0; i<=res.size(); i++){  // если проверки прошли то переводим в битовую строку
                    if((res[res.size()-i] != '\0')&&(i<=8)) ais5::t.ShipType[8-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
         }
     }
     //std::cout<<"res = "<<res<<std::endl;
     return  diag;
     //истина если функция отработала правильно
     // если нет в регистр ошибок заносится код ошибки
     // 082 тип корабля не входит в допустимый диапазон
};
//-------------
void ais5::ShipTypeClean (void)
{  for (uint8_t i=0; i<8; i++){
        ais5::t.ShipType[i]='0';}
};
//======09============================================================================
int8_t ais5::Dimension (uint16_t Bow, uint16_t Stern, uint16_t Port, uint16_t Starboard)
{   bool diag = true;
    std::string res;
    res = BitCode(Bow);
    for(uint8_t i=0; i<=res.size(); i++){  // если проверки прошли то переводим в битовую строку
                        if((res[res.size()-i] != '\0')&&(i<=9)) ais5::t.DimensionBow[9-i]=res[res.size()-i];}
    res = BitCode(Stern);
    for(uint8_t i=0; i<=res.size(); i++){  // если проверки прошли то переводим в битовую строку
                        if((res[res.size()-i] != '\0')&&(i<=9)) ais5::t.DimensionStern[9-i]=res[res.size()-i];}
    res = BitCode(Port);
    for(uint8_t i=0; i<=res.size(); i++){  // если проверки прошли то переводим в битовую строку
                        if((res[res.size()-i] != '\0')&&(i<=6)) ais5::t.DimensionPort[6-i]=res[res.size()-i];}
    res = BitCode(Starboard);
    for(uint8_t i=0; i<=res.size(); i++){  // если проверки прошли то переводим в битовую строку
                        if((res[res.size()-i] != '\0')&&(i<=4)) ais5::t.DimensionStarboard[6-i]=res[res.size()-i];}
    return diag;
};
//-------------
void ais5::DimensionClean (void)
{  for (uint8_t i=0; i<9; i++){
        ais5::t.DimensionBow[i]='0';}
   for (uint8_t i=0; i<9; i++){
        ais5::t.DimensionStern[i]='0';}
   for (uint8_t i=0; i<6; i++){
        ais5::t.DimensionPort[i]='0';}
   for (uint8_t i=0; i<6; i++){
        ais5::t.DimensionStarboard[i]='0';}
};
//=====13=============================================================================
int8_t ais5::PositionType (std::string pos)
{   bool diag = true;
    std::string res;
    uint8_t val=0;
    if(pos.size()==1){             //проверяем длинну строки версии аис
            if(!(isdigit (pos[0]))){diag=false; ais5::t.error+="131,";} // проверяем нет ли букв в типе системы позиционирования
        }
    else {diag=false; ais5::t.error+="130,";} // длинна версии не равна 1 символу
    if(diag){val=std::atoi(&pos[0]);}// если проверки прошли то строку преобразуем в целое число
    if((diag)&&(val<9)){  res = BitCode(val);       // проверяем входит ли номер версии в допустимый диапазон и переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=4)) ais5::t.PositionType[4-i]=res[res.size()-i]; //переписываем битовую строку с типом истемы позиционирования в рабочий блок
        }}else{diag=false; ais5::t.error+="132,";}  //номер версии выходит за допустимый диапазон
return  diag;   //истина если функция отработала правильно
// если нет в регистр ошибок заносится код ошибки
// 131 при наличии в номере системы позиционирования буквы
// 130 если номер системы позиционирования длиннее 1 символоа
// 132 номер системы позиционирования больше 8ми
    return diag;
};
//-------------
int8_t ais5::PositionType (uint8_t pos)
{   bool diag = true;
    std::string res;
    if(pos>8){ diag=false; ais5::t.error+="132,"; } //номер версии выходит за допустимый диапазон
    else { res = BitCode(pos); // если проверки прошли то переводим в битовую строку
        for(uint8_t i=0; i<=res.size(); i++){
           if((res[res.size()-i] != '\0')&&(i<=4)) ais5::t.PositionType[4-i]=res[res.size()-i]; //переписываем битовую строку с mmsi в рабочий блок
        }}
   return  diag;
   //истина если функция отработала правильно
   // если нет в регистр ошибок заносится код ошибки
   // 132 номер системы позиционирования больше 8ми

    return diag;
};
//-------------
void ais5::PositionTypeClean (void)
{  for (uint8_t i=0; i<4; i++){
        ais5::t.PositionType[i]='0';}
};
//======14================================================================================
int8_t ais5::ETA (tm eta)
{   bool diag = true;
    std::string res;
    res=BitCode(1 + eta.tm_mon);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=4)) ais5::t.ETAmonth[4-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }
    res=BitCode(1 + eta.tm_mday);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=5)) ais5::t.ETAday[5-i]=res[res.size()-i]; //переписываем битовую строку с днём в рабочий блок
    }
    res=BitCode(1 + eta.tm_hour);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=5)) ais5::t.ETAhour[5-i]=res[res.size()-i]; //переписываем битовую строку с часом в рабочий блок
    }
    res=BitCode(1 + eta.tm_min);
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=6)) ais5::t.ETAminute[6-i]=res[res.size()-i]; //переписываем битовую строку с минутами в рабочий блок
    }
    return  diag;
};
/*struct tm{
    int tm_sec;	//секунды, 0-61
    int tm_min;	//минуты, 0-59
    int tm_hour;	//часы, 0-23
    int tm_mday;	//день месяца, 1-31
    int tm_non;	//месяц, начиная с января, 0-11
    int tm_year;	//год после 1900
    int tm_wday;	//день, начиная с воскресенья, 0-6
    int tm_yday;	//день, начиная с 1-го января, 0-365
    int tm_isdst	//индикатор летнего времени
}*/
//-------------
void ais5::ETAClean (void)
{  for (uint8_t i=0; i<4; i++){
        ais5::t.ETAmonth[i]='0';}
   for (uint8_t i=0; i<5; i++){
        ais5::t.ETAday[i]='0';}
   for (uint8_t i=0; i<5; i++){
        ais5::t.ETAhour[i]='0';}
   for (uint8_t i=0; i<6; i++){
        ais5::t.ETAminute[i]='0';}
};
//======18=================================================================================
int8_t ais5::Draught (std::string dr)
{   bool diag = true;
    std::string res;
    float val=0;
    for (uint8_t i=0; i<dr.size(); i++){
        if((!(isdigit (dr[i])))||(!(dr[i]==','))||(!(dr[i]=='.'))){diag=false; ais5::t.error+="181,";} // проверяем нет ли букв в осадке судна
    }
    if(diag){ val=std::atof(&dr[0]);}  // если проверки прошли то строку преобразуем в число с плавающей запятой
    res=BitCode(uint16_t(val*10));
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=8)) ais5::t.Draught[8-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }
    return  diag;
};
//-------------
int8_t ais5::Draught (float dr)
{   bool diag = true;
    std::string res;
    res=BitCode(uint16_t(dr*10));
    for(uint8_t i=0; i<=res.size(); i++){
       if((res[res.size()-i] != '\0')&&(i<=8)) ais5::t.Draught[8-i]=res[res.size()-i]; //переписываем битовую строку с месяцем в рабочий блок
    }
  return  diag;
  //истина если функция отработала правильно
  // если нет в регистр ошибок заносится код ошибки
  // 181 при наличии буквы
};
//-------------
void ais5::DraughtClean (void)
{  for (uint8_t i=0; i<8; i++){
        ais5::t.Draught[i]='0';}
};
//=======19=================================================================================
int8_t ais5::Destination (std::string dest)
{   bool diag = true;
    std::string res;
    dest=ToAppers(dest);
    uint32_t j = dest.size();
    if ( j<21 ){ res = ASCIISixBit(dest); }
        else{diag = false; ais5::t.error+="192,";}    // длинна больше двадцати символов
    for(uint8_t i=0; i<res.size(); i++){
        if(res[i] != '\0') ais5::t.Destination[i]=res[i]; //переписываем битовую строку с позывным в рабочий блок
    }
    return diag;
    // если нет в регистр ошибок заносится код ошибки
    // 192 длинна названия больше двадцати символов
};
//-------------
void ais5::DestinationClean (void)
{  for (uint8_t i=0; i<120; i++){
        ais5::t.Destination[i]='0';}
};
//=====20===================================================================================
int8_t ais5::DTE (bool d)
{   bool diag = true;
    if(d){ais5::t.DTE[0]='1';}
    else{ais5::t.DTE[0]='0';}
    return  diag;
};
//-------------
void ais5::DTEClean (void)
{   ais5::t.DTE[0]='1';};
//=======21================================================================================
int8_t ais5::Spare (bool s)
{   bool diag = true;
    if(s){ais5::t.Spare[0]='1';}
    else{ais5::t.Spare[0]='0';}
    return  diag;
};
//-------------
void ais5::SpareClean (void)
{   ais5::t.Spare[0]='0';
};
//================================================================
void ais5::errorClean (void)
{
    ais5::t.error.clear();
};
//=========================================================================================
std::string ais5::WerkBlocBitString (void)
{   std::string res;
        res+=ais5::MessageType();
        res+=ais5::RepeatIndicator();
        res+=ais5::MMSI();
        res+=ais5::AisVer();
        res+=ais5::IMO();
        res+=ais5::CallSign();
        res+=ais5::VesselName();
        res+=ais5::ShipType();
        res+=ais5::Dimension();
        res+=ais5::PositionType();
        res+=ais5::ETA();
        res+=ais5::Draught();
        res+=ais5::Destination();
        res+=ais5::DTE();
        res+=ais5::Spare();
        addition=AdditionBit(res);
  return res;
};
//-------------
std::string ais5::WerkBlocBitStringAdded (void)
{   std::string res;
    std::string bitStr;
    res=AdditionBitString(ais5::WerkBlocBitString());
  return res;
};
//-------------
std::string ais5::WerkBlocSixString (void)
{   std::string res;
    std::string bitStr;
    bitStr=ais5::WerkBlocBitString();
    res = BitSix(bitStr);
  return res;
};
//-------------
std::string ais5::WerkBlocSixStringAdded (void)
{   std::string res;
    res=BitSix(ais5::WerkBlocBitStringAdded());
  return res;
};
//-------------
void ais5::WerkBlocClean (void)
{   ais5::MessageTypeClean();
    ais5::RepeatIndicatorClean();
    ais5::MMSIClean();
    ais5::AisVerClean();
    ais5::IMOClean();
    ais5::CallSignClean();
    ais5::VesselNameClean();
    ais5::ShipTypeClean();
    ais5::DimensionClean();
    ais5::PositionTypeClean();
    ais5::ETAClean();
    ais5::DraughtClean();
    ais5::DestinationClean();
    ais5::DTEClean();
    ais5::SpareClean();
    ais5::t.end='\0';
    ais5::errorClean();
};
//-------------
uint16_t ais5::AddBit (void)
{
    return ais5::addition;
};
//-------------
void ais5::SixStringWerkBloc (std::string str)
{   std::string res;
    if(str.size()<73){
        res=SixBit(str);//424
        for(int i =0; i<425; i++){t.MessageType[i]=res[i];}
    }
};
//-------------
std::string ais5::Error (void)
{   std::string res;
    if(t.error.size()>0){res=t.error;}
    else{res="ошибок нет";}
    return res;
};
//================ Методы диагностики=======================================================
void ais5::WerkBlocWrite ()
{   uint16_t i=0;
    std::string str;
    std::cout<<std::endl<<"----------------------------------------------РАБОЧИЙ БЛОК 5-го ТИПА-----------------------------------------------------"<<std::endl;
               std::cout<<"тип сообщения-------------";while (i<6){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"индикатор повтора---------";while (i<8){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"MMSI----------------------";while (i<38){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"версия АИС----------------";while (i<40){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"номер IMO-----------------";while (i<70){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"позывной------------------";while (i<112){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"Имя Судна-----------------";while (i<232){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"тип судна-----------------";while (i<240){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"расстояние до носа--------";while (i<249){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"расстояние до кормы-------";while (i<258){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"до левого борта-----------";while (i<264){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"до правого борта----------";while (i<270){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"система позиционирования--";while (i<274){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"месяц прибытия------------";while (i<278){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"день прибытия-------------";while (i<283){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"час прибытия--------------";while (i<288){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"минуты прибытия-----------";while (i<294){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"осадка--------------------";while (i<302){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"место назначения----------";while (i<422){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"DTE-----------------------";while (i<423){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl<<"запасной------------------";while (i<424){std::cout<<t.MessageType[i]; i++;}
    std::cout<<std::endl;
    std::cout<<std::endl<<"выведено бит--------------"<<i;

    if(t.error.size()==0){str="ошибок нет";}
    else{str=t.error;}

    std::cout<<std::endl<<"ошибки--------------------"<<str<<std::endl;
    std::cout<<std::endl<<"шестибитная строка--------"; std::cout<<WerkBlocSixString();
    std::cout<<std::endl<<"шестибитная строка-дополн-"; std::cout<<WerkBlocSixStringAdded();
    std::cout<<std::endl<<"размер шестибитной строки-"; std::cout<<(WerkBlocSixString()).size()<<std::endl;
    std::cout<<std::endl<<"AIS сообщения-------------";std::cout<<std::endl;
    std::cout<< AIVDMMessege(WerkBlocSixStringAdded(), AddBit(), 'A') <<std::endl;
};
