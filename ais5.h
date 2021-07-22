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

#ifndef AIS5_H
#define AIS5_H
#include "aislib.h"

//=======================================================================================
//============ структура рабочего блока сообщений 5-го типа=========================
typedef struct{
     char    MessageType        [6];   // тип сообщени
     char    RepeatIndicator    [2];   // Количество повторений сообщения
     char    MMSI               [30];  // MMSI номер
     char    AisVersion         [2];   // версия AIS
     char    IMO                [30];  // номер IMO
     char    CallSign           [42];  // позывной
     char    VesselName         [120]; // наименование судна
     char    ShipType           [8];   // тип судна
     char    DimensionBow       [9];   // размерности -до носа
     char    DimensionStern     [9];   //             -до кормы
     char    DimensionPort      [6];   //             -до левого борта
     char    DimensionStarboard [6];   //             -до правого борта
     char    PositionType       [4];   // тип системы позиционирования
     char    ETAmonth           [4];   // дата прибытия  -месяц
     char    ETAday             [5];   //                -день
     char    ETAhour            [5];   //                -час
     char    ETAminute          [6];   //                -минута
     char    Draught            [8];   // осадка
     char    Destination        [120]; // место назначения 20- шестибитных символов
     char    DTE                [1];
     char    Spare              [1];   // запасной не используется
     char    end;                      // необходимо добавлять 2-а бита в конец

     std::string error;
}werkBloc5;
//=======================================================================================

class ais5
{
private:
    uint16_t addition=0;    //необходимо бит для дополнения
    werkBloc5 t;
    std::string MessageType (void);
    std::string RepeatIndicator (void);
    std::string MMSI (void);
    std::string AisVer (void);
    std::string IMO (void);
    std::string CallSign (void);
    std::string VesselName (void);
    std::string ShipType (void);
    std::string Dimension (void);
    std::string PositionType (void);
    std::string ETA (void);
    std::string Draught (void);
    std::string Destination (void);
    std::string DTE (void);
    std::string Spare (void);
    std::string WerkBlocSixString (std::string);
public:
    ais5();
    int8_t MessageType_5 (void);    
    void MessageTypeClean (void);

    uint8_t RepeatIndicator (std::string);
    uint8_t RepeatIndicator (uint8_t);  
    void RepeatIndicatorClean (void);

    int8_t MMSI (std::string);  // принимает число в виде строки до 999999999 включительно преобразует в битовую строку и прописывает в MMSI
    int8_t MMSI (uint32_t);     // недостающие цифры необходимо заполнять нулями. цифр должно быть 9
    void MMSIClean (void);      // еак же принимает целое число до 999999999 включительно преобразует в битовую строку и прописывает в MMSI


    int8_t AisVer (std::string);   // принимает число в виде строки до 3 включительно преобразует в битовую строку и прописывает в версию АИС
    int8_t AisVer (uint8_t);       // одна цифра
    void AisVerClean (void);       //Версия AIS 0 = [ITU1371] , 1-3 = будущие издания


    int8_t IMO (std::string);   //принимает число в виде строки до 9999999 включительно преобразует в битовую строку и прописывает в IMO при достоверности
    int8_t IMO (uint32_t);      // 7 цифр. недостающие заполнять нулями
    void IMOClean (void);       //принимает целое число до 9999999 включительно преобразует в битовую строку и прописывает в IMO при достоверности


    int8_t CallSign (std::string);      // позывной в виде строки
    void CallSignClean (void);

    int8_t VesselName (std::string);    // наименование судна (корабля)
    void VesselNameClean (void);

    int8_t ShipType (std::string);      // тип судна (корабля) код от 1 до 99
    int8_t ShipType (uint8_t);  
    void ShipTypeClean (void);

    int8_t Dimension (uint16_t, uint16_t, uint16_t, uint16_t);  //Dimension (Bow, Stern, Port, Starboard) в метрах
    void  DimensionClean (void);                                // Размерности

    int8_t PositionType (std::string);  // тип системы позиционирования код от 0 до 8
    int8_t PositionType (uint8_t);
    void PositionTypeClean (void);

    int8_t ETA (tm);                    //дата и время прибытия  вводится через структуру ТМ
    void ETAClean (void);

    int8_t Draught (std::string);       // осадка Метров / 10
    int8_t Draught (float);
    void DraughtClean (void);

    int8_t Destination (std::string);   // пункт назначения до 20-и символов
    void DestinationClean (void);

    int8_t DTE (bool);                  //0 = терминал данных готов, 1 = не готов (по умолчанию).
    void DTEClean (void);

    int8_t Spare (bool);                //запасной, не используется
    void SpareClean (void);
    void errorClean (void);

    std::string WerkBlocBitString (void);   // ВНИМАНИЕ!! формирует битовую строку не дополненную до шестибитной граници
    std::string WerkBlocBitStringAdded (void);  //битовая строка дополненная
    std::string WerkBlocSixString (void);   // ВНИМАНИЕ!! формирует шестибитовую строку не дополненную до шестибитной граници
    std::string WerkBlocSixStringAdded (void);  //шестибитовая строка дополненная
    void SixStringWerkBloc (std::string);
    void WerkBlocClean (void);
    uint16_t AddBit (void);
    std::string Error (void);
//=========Диагностика============
    void WerkBlocWrite ();

};

#endif // AIS5_H
