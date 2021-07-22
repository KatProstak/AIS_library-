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

#include "aislib.h"
//=======================================================================================
SixBitTable::SixBitTable()
{   six_bit_table[48]="000000"; //"0"
    six_bit_table[49]="000001";
    six_bit_table[50]="000010";
    six_bit_table[51]="000011";
    six_bit_table[52]="000100";
    six_bit_table[53]="000101";
    six_bit_table[54]="000110";
    six_bit_table[55]="000111";
    six_bit_table[56]="001000";
    six_bit_table[57]="001001";
    six_bit_table[58]="001010";
    six_bit_table[59]="001011";
    six_bit_table[60]="001100";
    six_bit_table[61]="001101";
    six_bit_table[62]="001110";
    six_bit_table[63]="001111";
    six_bit_table[64]="010000";
    six_bit_table[65]="010001";
    six_bit_table[66]="010010";
    six_bit_table[67]="010011";
    six_bit_table[68]="010100";
    six_bit_table[69]="010101";
    six_bit_table[70]="010110";
    six_bit_table[71]="010111";
    six_bit_table[72]="011000";
    six_bit_table[73]="011001";
    six_bit_table[74]="011010";
    six_bit_table[75]="011011";
    six_bit_table[76]="011100";
    six_bit_table[77]="011101";
    six_bit_table[78]="011110";
    six_bit_table[79]="011111";
    six_bit_table[80]="100000";
    six_bit_table[81]="100001";
    six_bit_table[82]="100010";
    six_bit_table[83]="100011";
    six_bit_table[84]="100100";
    six_bit_table[85]="100101";
    six_bit_table[86]="100110";
    six_bit_table[87]="100111";
    six_bit_table[96]="101000";
    six_bit_table[97]="101001";
    six_bit_table[98]="101010";
    six_bit_table[99]="101011";
    six_bit_table[100]="101100";
    six_bit_table[101]="101101";
    six_bit_table[102]="101110";
    six_bit_table[103]="101111";
    six_bit_table[104]="110000";
    six_bit_table[105]="110001";
    six_bit_table[106]="110010";
    six_bit_table[107]="110011";
    six_bit_table[108]="110100";
    six_bit_table[109]="110101";
    six_bit_table[110]="110110";
    six_bit_table[111]="110111";
    six_bit_table[112]="111000";
    six_bit_table[113]="111001";
    six_bit_table[114]="111010";
    six_bit_table[115]="111011";
    six_bit_table[116]="111100";
    six_bit_table[117]="111101";
    six_bit_table[118]="111110";
    six_bit_table[119]="111111";};
//=======================================================================================
SixBitTable2::SixBitTable2()
{   six_bit_table[64]="000000"; //'@'
    six_bit_table[65]="000001"; //'A'
    six_bit_table[66]="000010"; //'B'
    six_bit_table[67]="000011"; //'C'
    six_bit_table[68]="000100"; //'D'
    six_bit_table[69]="000101"; //'E'
    six_bit_table[70]="000110"; //'F'
    six_bit_table[71]="000111"; //'G'
    six_bit_table[72]="001000"; //'H'
    six_bit_table[73]="001001"; //'I'
    six_bit_table[74]="001010"; //'J'
    six_bit_table[75]="001011"; //'K'
    six_bit_table[76]="001100"; //'L'
    six_bit_table[77]="001101"; //'M'
    six_bit_table[78]="001110"; //'N'
    six_bit_table[79]="001111"; //'O'
    six_bit_table[80]="010000"; //'P'
    six_bit_table[81]="010001"; //'Q'
    six_bit_table[82]="010010"; //'R'
    six_bit_table[83]="010011"; //'S'
    six_bit_table[84]="010100"; //'T'
    six_bit_table[85]="010101"; //'U'
    six_bit_table[86]="010110"; //'V'
    six_bit_table[87]="010111"; //'W'
    six_bit_table[88]="011000"; //'X'
    six_bit_table[89]="011001"; //'Y'
    six_bit_table[90]="011010"; //'Z'
    six_bit_table[91]="011011"; //'['
    six_bit_table[92]="011100"; //'\'
    six_bit_table[93]="011101"; //']'
    six_bit_table[94]="011110"; //'^'
    six_bit_table[95]="011111"; //'_'
    six_bit_table[32]="100000"; //' '
    six_bit_table[33]="100001"; //'!'
    six_bit_table[34]="100010"; //'"'
    six_bit_table[35]="100011"; //'#'
    six_bit_table[36]="100100"; //'$'
    six_bit_table[37]="100101"; //'%'
    six_bit_table[38]="100110"; //'&'
    six_bit_table[39]="100111"; //'`'
    six_bit_table[40]="101000"; //'('
    six_bit_table[41]="101001"; //')'
    six_bit_table[42]="101010"; //'*'
    six_bit_table[43]="101011"; //'+'
    six_bit_table[44]="101100"; //','
    six_bit_table[45]="101101"; //'-'
    six_bit_table[46]="101110"; //'.'
    six_bit_table[47]="101111"; //'/'
    six_bit_table[48]="110000"; //'0'
    six_bit_table[49]="110001"; //'1'
    six_bit_table[50]="110010"; //'2'
    six_bit_table[51]="110011"; //'3'
    six_bit_table[52]="110100"; //'4'
    six_bit_table[53]="110101"; //'5'
    six_bit_table[54]="110110"; //'6'
    six_bit_table[55]="110111"; //'7'
    six_bit_table[56]="111000"; //'8'
    six_bit_table[57]="111001"; //'9'
    six_bit_table[58]="111010"; //':'
    six_bit_table[59]="111011"; //';'
    six_bit_table[60]="111100"; //'<'
    six_bit_table[61]="111101"; //'='
    six_bit_table[62]="111110"; //'>'
    six_bit_table[63]="111111"; //'?'
};
//=======================================================================================
ASCIIBitTable:: ASCIIBitTable()
{   ASCII_bit_table[32]="00100000";
    ASCII_bit_table[33]="00100001";
    ASCII_bit_table[34]="00100010";
    ASCII_bit_table[35]="00100011";
    ASCII_bit_table[36]="00100100";
    ASCII_bit_table[37]="00100101";
    ASCII_bit_table[38]="00100110";
    ASCII_bit_table[39]="00100111";
    ASCII_bit_table[40]="00101000";
    ASCII_bit_table[41]="00101001";
    ASCII_bit_table[42]="00101010";
    ASCII_bit_table[43]="00101011";
    ASCII_bit_table[44]="00101100";
    ASCII_bit_table[45]="00101101";
    ASCII_bit_table[46]="00101110";
    ASCII_bit_table[47]="00101111";
    ASCII_bit_table[48]="00110000";
    ASCII_bit_table[49]="00110001";
    ASCII_bit_table[50]="00110010";
    ASCII_bit_table[51]="00110011";
    ASCII_bit_table[52]="00110100";
    ASCII_bit_table[53]="00110101";
    ASCII_bit_table[54]="00110110";
    ASCII_bit_table[55]="00110111";
    ASCII_bit_table[56]="00111000";
    ASCII_bit_table[57]="00111001";
    ASCII_bit_table[58]="00111010";
    ASCII_bit_table[59]="00111011";
    ASCII_bit_table[60]="00111100";
    ASCII_bit_table[61]="00111101";
    ASCII_bit_table[62]="00111110";
    ASCII_bit_table[63]="00111111";
    ASCII_bit_table[64]="01000000";
    ASCII_bit_table[65]="01000001";
    ASCII_bit_table[66]="01000010";
    ASCII_bit_table[67]="01000011";
    ASCII_bit_table[68]="01000100";
    ASCII_bit_table[69]="01000101";
    ASCII_bit_table[70]="01000110";
    ASCII_bit_table[71]="01000111";
    ASCII_bit_table[72]="01001000";
    ASCII_bit_table[73]="01001001";
    ASCII_bit_table[74]="01001010";
    ASCII_bit_table[75]="01001011";
    ASCII_bit_table[76]="01001100";
    ASCII_bit_table[77]="01001101";
    ASCII_bit_table[78]="01001110";
    ASCII_bit_table[79]="01001111";
    ASCII_bit_table[80]="01010000";
    ASCII_bit_table[81]="01010001";
    ASCII_bit_table[82]="01010010";
    ASCII_bit_table[83]="01010011";
    ASCII_bit_table[84]="01010100";
    ASCII_bit_table[85]="01010101";
    ASCII_bit_table[86]="01010110";
    ASCII_bit_table[87]="01010111";
    ASCII_bit_table[88]="01011000";
    ASCII_bit_table[89]="01011001";
    ASCII_bit_table[90]="01011010";
    ASCII_bit_table[91]="01011011";
    ASCII_bit_table[92]="01011100";
    ASCII_bit_table[93]="01011101";
    ASCII_bit_table[94]="01011110";
    ASCII_bit_table[95]="01011111";
    ASCII_bit_table[96]="01100000";
    ASCII_bit_table[97]="01100001";
    ASCII_bit_table[98]="01100010";
    ASCII_bit_table[99]="01100011";
    ASCII_bit_table[100]="01100100";
    ASCII_bit_table[101]="01100101";
    ASCII_bit_table[102]="01100110";
    ASCII_bit_table[103]="01100111";
    ASCII_bit_table[104]="01101000";
    ASCII_bit_table[105]="01101001";
    ASCII_bit_table[106]="01101010";
    ASCII_bit_table[107]="01101011";
    ASCII_bit_table[108]="01101100";
    ASCII_bit_table[109]="01101101";
    ASCII_bit_table[110]="01101110";
    ASCII_bit_table[111]="01101111";
    ASCII_bit_table[112]="01110000";
    ASCII_bit_table[113]="01110001";
    ASCII_bit_table[114]="01110010";
    ASCII_bit_table[115]="01110011";
    ASCII_bit_table[116]="01110100";
    ASCII_bit_table[117]="01110101";
    ASCII_bit_table[118]="01110110";
    ASCII_bit_table[119]="01110111";
    ASCII_bit_table[120]="01111000";
    ASCII_bit_table[121]="01111001";
    ASCII_bit_table[122]="01111010";
    ASCII_bit_table[123]="01111011";
    ASCII_bit_table[124]="01111100";
    ASCII_bit_table[125]="01111101";
    ASCII_bit_table[126]="01111110";};
//==================================================================================
std::string BitCode (uint32_t val)            //перекодировщик числа в битовую строку
{   std::string res;

    do{
        if(val%2==0){res.insert(0, 1, '0');}else{res.insert(0, 1, '1');}
        val/=2;
    }
    while(val>=1);
return res;
}
//==================================================================================
std::string SixBit (std::string str)
{   uint8_t k;
    SixBitTable t;
    std::string res;    
    uint32_t j = str.size();
    for (uint32_t i =0; i < j; i++){
        k=(int8_t)str[i];
        if(((k>47)&&(k<88))||((k>95)&&(k<120))){res += t.six_bit_table [k];}
        else{res += t.six_bit_table [63];}
    }
    return res;
};
//==================================================================================
std::string BitSix (std::string str)
{   std::string res, str2;
    SixBitTable t;
    uint16_t j = (str.size());
    for(uint16_t i=0; i<j; i+=6){
        str2=str.substr(i, 6);        
        for(uint16_t ii = 48; ii < 120; ii++)
                {if(((ii<88)||(ii>95))&&(str2 == t.six_bit_table[ii])){res +=ii;} } }
  return res;
};
//==================================================================================
std::string ASCIIBit (std::string str)
{   uint8_t k;
    ASCIIBitTable t;
    std::string res;
    uint32_t j = str.size();
    for (uint32_t i =0; i < j; i++){
        k=(int8_t)str[i];
        if((k>32)&&(k<127)){res += t.ASCII_bit_table [k];}
        else{res += t.ASCII_bit_table [32];}
    }
    return res;
};
//===================================================================
std::string ASCIISixBit (std::string str)
{   short int k;
    SixBitTable2 t;
    std::string res;
    uint32_t j = str.size();
    for (uint32_t i =0; i < j; i++){
        k=int(str[i]);
        if((k>31)&&(k<96)){res += t.six_bit_table [k];}
        else{res += t.six_bit_table [63];}
    }
    return res;
};
//===================================================================
uint16_t AdditionBit (std::string str )
{
    uint16_t i, ost;
    ost = str.size()%6;
    i=6-ost;
    if(i==6){i=0;}
    return i;
};
//===================================================================;
std::string AdditionBitString(std::string str)
{   std::string res;
    uint16_t i=AdditionBit(str);
    res=str;
    if(i!=0){
        for(uint16_t j=0; j<i; j++){res.append("0");}
    }else{}
  return res;
};
//===================================================================;

std::string CheckSum (std::string str)
{   std::string res;
    char m[3];     
    //std::cout<<"str1 "<<str<<std::endl;
        uint16_t i = 0, len = str.size(), Checksum = 0;
        for (i=0; i<len; ++i)
        {
            switch (str[i])
            {	case '!': break;// игнорируем
                case '*': i = len;// оканчиваем и прерываем цикл
                    continue;
                default:
                        if (Checksum == 0) {Checksum = str[i];}		// подсчитываем сумму
                        else {Checksum = Checksum ^ str[i];}
                    break;
                }
            }
        snprintf(&m[0], 3, "%02X", Checksum );
        res+=m[0]; res+=m[1];
      return res;
};
//===================================================================
std::string AIVDMMessege (std::string useful, uint16_t addbit, char chenal )
{   std::string res, res1;
    int d, j;
    std::string field1 {"!AIVDM"};  //Поле 1,!AIVDM, определяет его как пакет AIVDM.
    char        field2[2]={'1','\0'};         //Поле 2, количество фрагментов в текущем накапливающемся сообщении.
    char        field3[2]={'1','\0'};         //Поле 3, является номером фрагмента этого предложения.
    char        field4[2]={'0','\0'};         //Поле 4, является последовательным идентификатором сообщения для нескольких предложений.
    char        field5=chenal;         //Поле 5, является кодом радиоканала.
    std::string field6 = useful;    //Поле 6, (177KQJ5000G? TO`K> RA1wUbN0TKH) является полезной нагрузкой данных.
    char        field7[2];             //Поле 7, количество битов заполнения, необходимых для дополнения полезной нагрузки данных до 6-битной границы
  //  char        nul[2] ={'5','\0'};
                snprintf(&field7[0], 2, "%d", addbit);
        if(useful.size()<57){res=field1+','+field2+','+field3+','+','+field5+','+field6+','+field7[0]+'*';
        res+=CheckSum(res); res+=13; res+=10;}
        else if(useful.size()%56){ d =1+useful.size()/56;
            snprintf(&field2[0], 2, "%d", d);
            for( j=0; j<d; j++){
                snprintf(&field3[0], 2, "%d", j+1);
                res+=field1+','+field2+','+field3+','+field4+','+field5+',';
                    for(int i=56*j; (i<56*(j+1))&&(!(field6[i]=='\0')); i++){res+=field6[i];}
                    if(j==(d-1)){res+=','; res+=field7[0]; res+='*'; res+=CheckSum(res.substr((74+4)*j, 76)); res+=13; res+=10;
                    //std::cout<<"str1 "<<res.substr((74+4)*j, 76)<<std::endl;
                    }
                    else if (j<d-1){res+=",0*"; res+=CheckSum(res.substr((74+4)*j, 76)); res+=13; res+=10;
                   // std::cout<<"str1 "<<res.substr((74+4)*j, 76)<<std::endl;
                    }
            }
           }
  return res;
};
//===================================================================
std::string ToAppers (std::string str)
{   std::string res;
    uint16_t i=0;
    while((!(str[i]=='\0'))){
        res+=std::toupper(str[i]);
        i++;}
 return res;
};
