/*       
File Name		: Barang.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */


#include <stdio.h>
#include "header.h"


//==================================== Modul dari kating ====================================
/* 			Pengembangan program serta tambahan komentar pada sebagian modul nya 			*/


void Enqueue_BarangBelian(Queue_BB *Q, infochar Nama_Barang, infotype Harga, infotype Jumlah_Barang)
/*
I.S : Antrian Barang Belian (Queue_BB terdefinisi *Q), Nama Barang, Harga, dan Jumlah Barang
F.S : Data dengan node baru Barang Belian (Nama barang, Harga, dan Jumlah Barang)
*/
{	
	address_BB a = NULL;											// pointer Barang Belian = kosong (NULL)
	
	Create_Node_BarangBelian(&a);									// Membuat Node Barang Belian baru
	Isi_Node_BarangBelian(&a, Harga, Nama_Barang, Jumlah_Barang);	// Mengisi Node Barang Belian tersebut
	Ins_Akhir_BarangBelian(&(*Q),a);								// Menyisipkan Barang Beliaan di akhir
	
}
//------------------------------------------------------------------------------------------------------ 01


boolean isEmpty_BarangBelian(address_BB p)
/*
I.S : Ada address_BB (Barang Belian) terdefinisi p
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


void Create_Node_BarangBelian (address_BB *p)
/*
I.S : Address_BB terdefinisi *p
F.S : Node baru berhasil dialokasi kan pada memori dan pointer *p menunjuk Node tersebut

*/
{
	*p = (address_BB)malloc(sizeof(List_BarangBelian));
	
}
//------------------------------------------------------------------------------------------------------ 03


void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar nama_barang, infotype jumlah_barang)
/*
I.S : *p alamat node yang akan diisi oleh infotype dan infochar
F.S : Node pada list barang belian dengan alamat *p terisi nilai-nilainya yaitu harga, nama barang, dan jumlah barang. 
	Jika node belum dialokasikan, maka program akan menampilkan pesan "Node Belum di Alokasi".
*/
{	
	if(isEmpty_BarangBelian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Harga(*p) = harga;
		Nama_Barang(*p) = nama_barang;
		Jumlah_Barang(*p) = jumlah_barang;
	}
	
}
//------------------------------------------------------------------------------------------------------ 04


void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew)

{
	address_BB A;
	if(isEmpty_BarangBelian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_BarangBelian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}
//------------------------------------------------------------------------------------------------------ 05


void Del_Awal_BarangBelian (address_BB * p, infochar * X)
/*
I.S :
F.S :
*/
{
	address_BB A;
	
	if(isEmpty_BarangBelian(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = Nama_Barang(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
}

//------------------------------------------------------------------------------------------------------ 06





//==================================== Modul buatan kelompok ====================================



void addHistoryBelian(Queue_BB *Q, infotype harga, infochar nama_barang, infotype jumlah_barang)
{
	address_BB a = NULL;
	Create_Node_BarangBelian(&a);
	Isi_Node_BarangBelian(&a, harga, nama_barang, jumlah_barang);
	Ins_Akhir_BarangBelian(&(*Q), a);
}
//------------------------------------------------------------------------------------------------------ Athalie

void printHistoryBelian(Queue_BB Q)
{
	address_BB a = Q;
	if(isEmpty_BarangBelian(Q))
	{
	printf("List Kosong\n");
	}
	else
	{
		printf("=============================================================\n");
		printf("| %-20s | %-10s | %-10s |\n", "Nama Barang", "Harga", "Jumlah");
		printf("=============================================================\n");
	
		while(a != NULL)
		{
			printf("| %-20s | %-10d | %-10d |\n", Nama_Barang(a), Harga(a), Jumlah_Barang(a));
			a = next(a);
		}
	
		printf("=============================================================\n");
	}
}

//------------------------------------------------------------------------------------------------------ Athalie


void deleteHistoryBelian(Queue_BB *Q)
{
	infochar X;
	Del_Awal_BarangBelian(&(*Q), &X);
}
//------------------------------------------------------------------------------------------------------ Athalie












