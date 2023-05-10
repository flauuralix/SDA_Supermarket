
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

typedef int infotype;							// Mendefinisikan tipe data integer (infotype)
typedef const char *infochar;					// Mendefinisikan tipe data string (infochar)
typedef struct List_Pembeli *address_P;			// Mendefinisikan tipe data pointer ke struk List_Pembeli
typedef struct List_Barang *address_B;			// Mendefinisikan tipe data pointer ke struk List_Barang 
typedef struct List_BarangBelian *address_BB;	// Mendefinisikan tipe data pointer ke struk List_BarangBelian
typedef struct List_Antrian *address_A;			// Mendefinisikan tipe data pointer ke struk List_Antrian


/*	Berkaitan dengan Pembeli = Nama, Barang Belian, No Kasir
	Tambahan = Barang Bawaan (Keranjang atau Troli)  */
	typedef struct List_Pembeli {
	address_BB BarangBelian;
	infochar Nama_Pembeli;
	infotype No_Kasir;	
	//infochar Tempat_Bawaan;
	infotype harga_barang;
	address_P next;
	} List_Pembeli;
	
	#define Tempat_Bawaan(P) (P)->Tempat_Bawaan
	typedef struct List_Bawaan *address_TB;
	
	typedef struct List_Bawaan{
	infochar Tempat_Bawaan;	
	address_TB next;
	}TempatBawaan;

/*	Berkaitan dengan Barang = Data Barang (nama,stok, harga) + jml */
	typedef struct List_Barang {
	infochar nama;
	infotype stok;
	infotype jml;
	infotype harga;
	infochar pilih; 
	}DataBarang;

/*	Berkaitan dengan Barang Belian = Nama_Barang, Harga, Jumlah_Barang */
	typedef struct List_BarangBelian {
	infochar Nama_Barang;
	infotype Harga;
	infotype Jumlah_Barang;
	address_BB next;
	} List_BarangBelian;

/*	Berkaitan dengan Antrian = Nama Pelanggan, Pembayaran sukses -> lanjut antrian berikutnya */
	typedef struct List_Antrian {
	infochar nama;
	address_A next;
	} List_Antrian;
	
/*	Berkaitan dengan Kasir = Nomor kasir */
	typedef struct Kasir{
	infotype Nomor;
	address_A next;
	} Datakasir;


// 									------------------------------
						  			  typedef address_P Queue_P;
									  typedef address_B Queue_B;
									  typedef address_BB Queue_BB;
									  typedef address_A Queue_A;
									  typedef address_TB Queue_TB;
// 									-------------------------------

void header();			//------------------- Marshya

void tampil_list();		//------------------- Athalie
void tampil_menu(); 	//------------------- Claudia
void tampil_kasir();	//------------------- Marshya


//============================================== Pembeli =================================================

boolean isEmpty_Pembeli(address_P p);

void Create_Node_Pembeli (address_P *p);

void Isi_Node_Pembeli (address_P *p , address_BB *q, infochar Nama_Pembeli, infotype No_Kasir);

void Ins_Akhir_Pembeli (address_P *p, address_P PNew);

void Enqueue_Pembeli(Queue_P *Q, Queue_BB *P, infochar Nama_Pembeli, infotype No_Kasir);


// Tempat Bawaan
void Create_Node_TempatBawaan(address_TB *t);
boolean isEmpty_TempatBawaan(address_TB p);
void Isi_Node_TempatBawaan (address_TB *p , infochar Tempat_Bawaan);
void Modif_Node_Pembeli (address_P *p , address_BB *q, address_TB *t, infochar Nama_Pembeli, infotype No_Kasir, infochar Tempat_Bawaan);
void ModifEnqueue_Pembeli(Queue_P *Q, Queue_BB *P, Queue_TB *T, infochar Nama_Pembeli, infotype No_Kasir, infochar Tempat_Bawaan);


//============================================== Barang ==================================================

boolean isEmpty_BarangBelian(address_BB p);

void Create_Node_BarangBelian (address_BB *p);

void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar nama_barang, infotype jumlah_barang);

void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew);

void Del_Awal_BarangBelian (address_BB * p, infochar * X);

void Enqueue_BarangBelian(Queue_BB *Q, infotype harga, infochar nama_barang, infotype jumlah);


//Test
void addHistoryBelian(Queue_BB *Q, infotype harga, infochar nama_barang, infotype jumlah_barang);
void printHistoryBelian(Queue_BB Q);
void deleteHistoryBelian(Queue_BB *Q);

//============================================== Antrian ================================================

boolean isEmpty_Antrian(address_A p);

void Create_Node_Antrian (address_A *p);

void Isi_Node_Antrian (address_A *p , infochar nama);

void Tampil_List_Antrian (address_A p);

void Ins_Akhir_Antrian (address_A *p, address_A PNew);

void Del_Awal_Antrian (address_A * p, infochar * X);

void Dequeue_Antrian(Queue_A *Q,infochar *X);



#endif
