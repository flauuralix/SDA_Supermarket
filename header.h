
/*       
File Name		: header.h
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

#ifndef header_H
#define header_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include "boolean.h"


#define nama(P) (P)->nama
#define BarangBelian(P) (P)->BarangBelian
#define Dompet(P) (P)->Dompet
#define Nama_Pembeli(P) (P)->Nama_Pembeli
#define No_Kasir(P) (P)->No_Kasir
#define Harga(P) (P)->Harga
#define Jumlah_Barang(P) (P)->Jumlah_Barang	
#define Nama_Barang(P) (P)->Nama_Barang
#define next(P) (P)->next
#define Nil NULL

typedef int infotype;						  // Mendefinisikan tipe data integer (infotype)
typedef const char *infochar;				  // Mendefinisikan tipe data string (infochar)
typedef struct List_Pembeli *address_P;		  // Mendefinisikan tipe data pointer ke struk List_Pembeli (address P)
typedef struct List_Barang *address_B;	   	  // Mendefinisikan tipe data pointer ke struk List_Barang (address_B)
typedef struct List_BarangBelian *address_BB; // Mendefinisikan tipe data pointer ke struk List_BarangBelian (address BB)
typedef struct List_Antrian *address_A;		  // Mendefinisikan tipe data pointer ke struk List_Antrian (address A)




/*	Berkaitan dengan Pembeli = Nama, Barang Belian, No Kasir
	Tambahan = Barang Bawaan (Keranjang atau Troli)  */
	typedef struct List_Pembeli {
	address_BB BarangBelian;
	infochar Nama_Pembeli;
	infochar Tempat_Bawaan; //------------------- Athalie
	infotype No_Kasir;
	address_P next;
	
	} List_Pembeli;

/*	Berkaitan dengan Barang = Data Barang (nama, harga)
	Tambahan = Tidak ada  */
	typedef struct List_Barang{
	infochar nama;
	infotype harga; 	
	}DataBarang;

/*	Berkaitan dengan Barang Belian = Nama Barang, Harga, Jumlah Barang
	Tambahan = Tidak ada  */
	typedef struct List_BarangBelian {
	infochar Nama_Barang;
	infotype Harga;
	infotype Jumlah_Barang;
	address_BB next;
	} List_BarangBelian;

/*	Berkaitan dengan Antrian = Nama Pelanggan, Pembayaran sukses -> lanjut antrian berikutnya
	Tambahan = Tidak ada  */
	typedef struct List_Antrian {
	infochar nama;
	address_A next;
	} List_Antrian;

/*	Berkaitan dengan Kasir = Nomor kasir
	Tambahan = Tidak ada  */
	typedef struct Kasir{
	infotype Nomor;
	address_A next;
	}DataKasir;

 
// 									------------------------------
						  			  typedef address_P Queue_P;
									  typedef address_B Queue_B;
									  typedef address_BB Queue_BB;
									  typedef address_A Queue_A;
// 									-------------------------------


void TampilList();		//------------------- Athalie

void TampilAntrian();	//------------------- Marshya

void MainMenu();		//------------------- Claudia





//============================================== Pembeli =================================================

void Enqueue_Pembeli(Queue_P *Q, Queue_BB *P, infochar Nama_Pembeli, infotype No_Kasir);			  //=|

boolean isEmpty_Pembeli(address_P p);																  //=|

void Create_Node_Pembeli (address_P *p);															  //=|

void Isi_Node_Pembeli (address_P *p , address_BB *q, infochar Nama_Pembeli, infotype No_Kasir);		  //=|

void Ins_Akhir_Pembeli (address_P *p, address_P PNew);												  //=|



//============================================== Barang ==================================================

void Enqueue_BarangBelian(Queue_BB *Q, infochar Nama_Barang, infotype Harga, infotype Jumlah_Barang); //=|

boolean isEmpty_BarangBelian(address_BB p);															  //=|

void Create_Node_BarangBelian (address_BB *p);														  //=|

void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar nama_barang, infotype jumlah_barang);

void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew);										  //=|

void Del_Awal_BarangBelian (address_BB * p, infochar * X);											  //=|

void PrintListBarang();

void addHistoryBelian(Queue_BB *Q, infotype harga, infochar nama_barang, infotype jumlah_barang); //Athalie
void printHistoryBelian(Queue_BB Q); 	//------------------- Athalie
void deleteHistoryBelian(Queue_BB *Q);	//------------------- Athalie



//============================================== Antrian ================================================

void Dequeue_Antrian(Queue_A *Q,infochar *nama);												     //=|

boolean isEmpty_Antrian(address_A p);										 				         //=|

void Create_Node_Antrian (address_A *p);														     //=|

void Isi_Node_Antrian (address_A *p , infochar nama);						 					     //=|

void Tampil_List_Antrian (address_A p);															     //=|

void Ins_Akhir_Antrian (address_A *p, address_A PNew);											     //=|

void Del_Awal_Antrian (address_A * p, infochar * X);						 					   	 //=|


void header();			//------------------- Marshya





#endif
