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

#ifndef AIS1_H
#define AIS1_H
#include "aislib.h"
using namespace std;
//=======================================================================================
//============ структура рабочего блока сообщений 1, 2, 3-го типа =======================
typedef struct{
    char MessageType      [6];   // тип сообщения
    char RepeatIndicator  [2];   // индикатор поворота
    char MMSI             [30];  // MMSI номер
    char navigation       [4];   // состояние навигацииltitude
    char ROT              [8];   // скорость поворота
    char SOG              [10];  // скорость относительно земли
    char PositionAccuracy [1];   // точность положения
    char lon              [28];  // долгота
    char lat              [27];  // широта
    char COG              [12];  // курс относительно земли
    char HDG              [9];   // истинное направление от 0 до 359, недоступно-511
    char time             [6];   // отметка времени
    char DTE              [2];   // индикатор манёвра
    char spare            [3];   // не используется
    char RAIM             [1];   //
    char radio            [19];  // радио статус
    char      end;
    std::string error;
}werkBloc1;
//=======================================================================================
class ais1
{
private:
    uint16_t addition=0;    //необходимо бит для дополнения
    werkBloc1 t;    
    std::string MessageType (void);
    std::string RepeatIndicator (void);
    std::string MMSI (void);
    std::string NavigationStatys (void);
    std::string ROT (void);
    std::string SOG (void);
    std::string PositionAccuracy (void);
    std::string lon (void);
    std::string lat (void);
    std::string COG (void);
    std::string HDG (void);
    std::string DTE (void);
    std::string Time (void);
    std::string RAIM (void);
    std::string Spare (void);
    std::string Radio (void);
    std::string WerkBlocSixString (std::string);
public:
  ais1 ();
  int8_t MessageType_1 (void);
  int8_t MessageType_2 (void);
  int8_t MessageType_3 (void);  
  void MessageTypeClean (void);

  uint8_t RepeatIndicator (std::string);
  uint8_t RepeatIndicator (uint8_t);  
  void RepeatIndicatorClean (void);

  int8_t MMSI (std::string); // принимает число в виде строки до 999999999 включительно преобразует в битовую строку и прописывает в MMSI
  //недостающие цифры необходимо заполнять нулями. цифр должно быть 9
  int8_t MMSI (uint32_t); //принимает целое число до 999999999 включительно преобразует в битовую строку и прописывает в MMSI  
  void MMSIClean (void);

  int8_t NavigationStatys (std::string);
  int8_t NavigationStatys (uint8_t);  
  void  NavigationStatysClean (void);

  int8_t ROT (int16_t); //???
  void ROTClean (void);

  int8_t SOG (std::string);
  int8_t SOG (float);
  int8_t SOGno (void);  
  void SOGClean (void);

  int8_t PositionAccuracy (bool);
  int8_t PositionAccuracy (std::string);  
  void PositionAccuracyClean (void);

  int8_t lon (int16_t, float);  
  void lonClean (void);

  int8_t lat (int16_t, float);
  void latClean (void);

  int8_t COG (float);
  void COGClean (void);

  int8_t HDG (uint16_t);
  //int8_t HDG (float);
  void HDGClean (void);

  int8_t Time (uint8_t); 
  void  TimeClean (void);

  int8_t DTE (uint8_t);  
  void  DTEClean (void);

  int8_t RAIM (bool);  
  void  RAIMClean (void); 
  void SpareClean (void);  
  void RadioClean (void);
  void errorClean (void);

  std::string WerkBlocBitString (void);   // ВНИМАНИЕ!! формирует битовую строку не дополненную до шестибитной граници
  std::string WerkBlocBitStringAdded (void);  //битовая строка дополненная
  std::string WerkBlocSixString (void);   // ВНИМАНИЕ!! формирует шестибитовую строку не дополненную до шестибитной граници
  std::string WerkBlocSixStringAdded (void);  //шестибитовая строка дополненная
  void WerkBlocClean (void);    //метод инициализации/отчистки рабочего блока
  uint16_t AddBit (void);
  std::string Error (void);
  //=========Диагностика===============
  void WerkBlocWrite (void);
};

#endif // AIS1_H
