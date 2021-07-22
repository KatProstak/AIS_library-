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

#ifndef AISLIB_H
#define AISLIB_H
#include <iostream>
//#include <string>
//=======================================================================================
//============ таблица шестибитной кодировки=========================
class SixBitTable
{
private:
public:
    SixBitTable();
    std::string six_bit_table[120];
};
class SixBitTable2
{
private:
public:
    SixBitTable2();
    std::string six_bit_table[120];
};





//============ таблица восьмибитной кодировки=========================
class ASCIIBitTable
{
private:
public:
    ASCIIBitTable();
    std::string ASCII_bit_table[127];
};
//=======================================================================================

std::string BitCode(uint32_t);      // переводит целое число в битовую строку
std::string SixBit (std::string);   // перевод в битовую строку в  шестибитной кодировке
std::string BitSix (std::string);
std::string ASCIIBit (std::string);
std::string ASCIISixBit (std::string);// перевод из ASCII в шестибитную битовую строку
uint16_t AdditionBit (std::string ); // принимает в качестве аргумента битовую строку и вычисляет количество бит необходимых для дополнения до шестибитной граници
std::string AdditionBitString(std::string);//заполняет строку нулями до шестибитной граници
std::string CheckSum (std::string); //расчет контрольной суммы строки, строка должна оканчиваться '*' пример: !AIVDM,1,1,,B,:62?@<1SqM;T,0* либо DM,1,1,,B,:62?@<1SqM;T,0*
std::string AIVDMMessege (std::string, uint16_t, char);
std::string ToAppers (std::string);

#endif // AISLIB_H
