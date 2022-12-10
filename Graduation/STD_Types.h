#ifndef STD_Types_H
#define STD_Types_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

#define SIZE 500
typedef struct Accout
{
   u8 Full_name [SIZE];
   u8 Full_Address[70];
   u8 National_ID [15];
   u8 age;
   u32 Bank_acc_ID;
   u8 Gurdian[SIZE];
   u8 Gurdain_ID[15];
   u8 Acc_Status;
   u32 Balance;
   u8 pass[30];
}account;
#endif