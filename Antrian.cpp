/*       
File Name		: Antrian.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */


#include <stdio.h>
#include "header.h"


//==================================== Modul dari kating ====================================
/* 			Pengembangan program serta tambahan komentar pada sebagian modul nya 			*/



void Dequeue_Antrian(Queue_A *Q,infochar *nama)
/*
I.S : Antrian terdefinisi *Q, infochar *nama
F.S : Elemen pertama dari Antrian dihapus dan nilai nya disimpan pada variabel nama
	  Jika kosong tidak akan ada operasi apapun
*/
{	
	Del_Awal_Antrian(&(*Q),&(*nama));	
}
//------------------------------------------------------------------------------------------------------ 01



boolean isEmpty_Antrian(address_A p)
/*
I.S : Ada address_A (Antrian) terdefinisi p
F.S : Mengembalikan nilai true jika address_P kosong (NULL), false jika address_P tidak kosong
*/
{
	
	if(p == NULL)	// Mengecek apakah p = kosong ?
	{
		return 1;	// true
	}else{
		return 0;	// false
	}
	
}
//------------------------------------------------------------------------------------------------------ 02


void Create_Node_Antrian (address_A *p)
/*
I.S : Address_A terdefinisi *p
F.S : Node baru berhasil dialokasi kan pada memori dan pointer *p menunjuk Node tersebut

*/
{
	*p = (address_A)malloc(sizeof(List_Antrian));
	
}
//------------------------------------------------------------------------------------------------------ 03



void Isi_Node_Antrian (address_A *p , infochar nama)
/*
I.S : *p alamat node yang akan diisi oleh infochar nama
F.S : Node Antrian akan terisi dengan nama 
	Jika node belum dialokasikan, maka program akan menampilkan pesan "Node Belum di Alokasi".
*/
{	
	if(isEmpty_Antrian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		nama(*p) = nama;
	}
	
}
//------------------------------------------------------------------------------------------------------ 03



void Tampil_List_Antrian (address_A p)
{	
	int i = 1;
	if(isEmpty_Antrian(p)){
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
			printf("%d. %s",i,&p->nama);
			p = next(p);
			if(p != Nil){
				printf("\t");
			}
		i++;	
		}
		printf("\n");
	}	
	
}
//------------------------------------------------------------------------------------------------------ 04


void Ins_Akhir_Antrian (address_A *p, address_A PNew)
{
	
	address_A A;
	if(isEmpty_Antrian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Antrian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}
//------------------------------------------------------------------------------------------------------ 05



void Del_Awal_Antrian (address_A * p, infochar * X)
{
	
	address_A A;
	
	if(isEmpty_Antrian(*p)){
		printf("Antrian Kosong\n");
	}else{
		A = *p;
		*X = nama(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
	
}
//------------------------------------------------------------------------------------------------------ 06







//==================================== Modul buatan kelompok ====================================


void header()
{

	printf ("\n");
	printf("\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf ("\t\t\t ____________________________\n");
	printf ("\t\t\t ||                        ||   $$\\\\      $$\\     $$$$$\\\\    $$$$$$$$\\\\   $$$$$$$$$\\     $$$$$\\\\    $$\\     $$\\\n");
	printf ("\t\t\t ||   ||===============    ||   $$$ \\    $$$ |   $$ / $$ \\   $$ |   $$ |  $$ _______|   $$ / $$ \\   $$ |    $$ |\n");
	printf ("\t\t\t ||   ||\\\\        //||     ||   $$ $ \\  $ $$ |  $$ |   $$ \\  $$ |   $$ |  $$ |         $$ |   $$ \\  $$ |    $$ |\n");
	printf ("\t\t\t ||   || \\\\      // ||     ||   $$ |$ \\$ /$$ |  $$ |   $$ |  $$$$$$$$$ |  $$ |         $$ |   $$ |  $$ |    $$ |\n");
	printf ("\t\t\t ||   ||  \\\\    //  ||     ||   $$ | $$ / $$ |  $$$$$$$$$ |  $$ | $$  _|  $$ |         $$$$$$$$$ |  $$ |    $$ |\n");
	printf ("\t\t\t ||   ||   \\\\  //   ||     ||   $$ | \\_/  $$ |  $$ |   $$ |  $$ |  $$ \\   $$ |         $$ |   $$ |  $$ |    $$ |\n");
	printf ("\t\t\t ||   ||    \\\\//====||     ||   $$ |      $$ |  $$ |   $$ |  $$ |   $$ \\  $$$$$$$$$\\   $$ |   $$ |  $$$$$$$$$$ |\n");
	printf ("\t\t\t ||   ||     //     ||     ||   \\__|      \\__|  \\__|   \\__|  \\__|   \\__|  \\_________|  \\__|   \\__|  \\__________|\n");
	printf ("\t\t\t ||   ||    //      ||     ||\n");
	printf ("\t\t\t ||   ||===============    ||                'Barang Fresh Setiap Hari Dengan Harga Terjangkau'\n");
	printf ("\t\t\t ||                        ||\n");
	printf ("\t\t\t ----------------------------\n");
	printf("\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
//------------------------------------------------------------------------------------------------------ Marshya	


