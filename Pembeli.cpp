
/*       
File Name		: Pembeli.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */


#include <stdio.h>
#include "header.h"
#include <cstring>

/* ======= End of Header File ====== */



//============================================================================================
/*   			                Pengembangan modul pada program  	    		        	*/

boolean isEmpty_Pembeli(address_P p)
/*
I.S : Ada pointer P (Pembeli) terdefinisi p
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

void Create_Node_Pembeli (address_P *p)
/*
I.S : Ada pointer P (Pembeli) terdefinisi *p belum dialokasi kan
F.S : Terbentuk Node dengan alamat *p
*/
{	
	*p = (address_P)malloc(sizeof(List_Pembeli));
	/*	if(p != Nil){
		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
	}else{
		printf("Gagal Alokasi\n");
	}*/
	
}

void Isi_Node_Pembeli (address_P *p , address_BB *q, infochar Nama_Pembeli, infotype No_Kasir)
/*
I.S : Alamat Pembeli (address_P terdefinisi *p), Alamat Barang Belian (address BB terdefinisi *q), Nama_Pembeli, No_Kasir 
F.S : 
- Jika *p belum dialokasikan akan menampilkan "Node belum di Alokasi" 
- Jika *p sudah dialokasikan maka nilai dari Nama_Pembeli, No_Kasir, dan *q akan diisi atau diimasukan pada Node Pembeli
*/
{

	if(isEmpty_Pembeli(*p)){
		printf("Node Belum di Alokasi");
	}else{
		next(*p) = Nil;
		BarangBelian(*p) = *q;
		Nama_Pembeli(*p) = Nama_Pembeli;
		No_Kasir(*p) = No_Kasir;
	}
	
}

void Ins_Akhir_Pembeli (address_P *p, address_P PNew)
/*
I.S : Alamat Pembeli (*p), dan Alamat Pembeli baru (PNew)
F.S : LinkedList pembeli terbentuk, Alamat node pembeli pertama menunjuk pada node pertama pada linkedlist, 
	Node pembeli baru udah disisipkan pada akhir linkedlist
*/
{
	
	address_P A;
	if(isEmpty_Pembeli(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Pembeli(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


void Enqueue_Pembeli(Queue_P *Q, Queue_BB *P, infochar Nama_Pembeli, infotype No_Kasir)
/*
I.S : 
- Antrian Pembeli (Queue_P terdefinisi *Q)
- Antrian BarangBelian (Queue_BB terdefinisi *P)
- Data Pembeli (Infochar terdefinisi Nama_Pembeli)
- Data No kasir (Infotype terdefinisi No_Kasir)

F.S :
- Nama_Pembeli dan No_Kasir telah dimasukan ke dalam Antrian Pembeli (*Q) di posisi terakhir
*/

{
	address_P a = NULL;  // variabel lokal a -> pointer P (Pembeli)
	address_BB b = NULL; // variabel lokal b -> pointer BB (Barang Belian)
	
	Create_Node_Pembeli(&a);	   				     	 // Membuat node Pembeli baru pada linkedlist
	Create_Node_BarangBelian(&b);   				  	// Membuat node Barang Belian baru pada linkedlist
	Isi_Node_Pembeli(&a, &b, Nama_Pembeli,No_Kasir); 	// Mengisi data pada node yang telah dibuat pada linkedlist
	Ins_Akhir_Pembeli(&(*Q),a);		          		  	// Memasukan node yang telah dibuat pada akhir antrian pembeli
	
}




//============================================================================================
/*   			               Penambahan modul pada program  	    		        		*/






// Tempat Bawaan
void Create_Node_TempatBawaan(address_TB *t)
{
	*t = (address_TB)malloc(sizeof(List_Pembeli));
}
//------------------------------------------------------------------------------------------------------ Athalie


boolean isEmpty_TempatBawaan(address_TB p)
{
	
	if(p == NULL)	// Mengecek apakah p = kosong ?
	{
		return 1;	// true
	}else{
		return 0;	// false
	}
	
}
//------------------------------------------------------------------------------------------------------ Athalie


void Isi_Node_TempatBawaan (address_TB *p , infochar Tempat_Bawaan)
{	
	if(isEmpty_TempatBawaan(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Tempat_Bawaan(*p) = Tempat_Bawaan;
	}
}
//------------------------------------------------------------------------------------------------------ Athalie



void Modif_Node_Pembeli (address_P *p , address_BB *q, address_TB *t, infochar Nama_Pembeli, infotype No_Kasir, infochar Tempat_Bawaan)
/*
I.S : Alamat Pembeli (address_P terdefinisi *p), Alamat Barang Belian (address BB terdefinisi *q), Nama_Pembeli, No_Kasir 
F.S : 
- Jika *p belum dialokasikan akan menampilkan "Node belum di Alokasi" 
- Jika *p sudah dialokasikan maka nilai dari Nama_Pembeli, No_Kasir, dan *q akan diisi atau diimasukan pada Node Pembeli
*/
{

	if(isEmpty_Pembeli(*p)){
		printf("Node Belum di Alokasi");
	}else{
		next(*p) = Nil;
		BarangBelian(*p) = *q;
		Tempat_Bawaan(*t) = Tempat_Bawaan;
		Nama_Pembeli(*p) = Nama_Pembeli;
		No_Kasir(*p) = No_Kasir;
	}
}
//------------------------------------------------------------------------------------------------------ Athalie



void ModifEnqueue_Pembeli(Queue_P *Q, Queue_BB *P, Queue_TB *T, infochar Nama_Pembeli, infotype No_Kasir, infochar Tempat_Bawaan)
{
	address_P a = NULL;
	address_BB b = NULL;
	address_TB t = NULL;
	
	Create_Node_Pembeli(&a); // Membuat node Pembeli baru pada linkedlist
    Create_Node_BarangBelian(&b); // Membuat node Barang Belian baru pada linkedlist
    Create_Node_TempatBawaan(&t); // Membuat node Tempat Bawaan baru pada linkedlist
    
   	Isi_Node_Pembeli(&a, &b, Nama_Pembeli,No_Kasir); // Mengisi data pada node yang telah dibuat pada linkedlist
    Isi_Node_TempatBawaan(&t, Tempat_Bawaan); // Mengisi data pada node Tempat Bawaan
    Ins_Akhir_Pembeli(&(*Q), a); // Memasukan node yang telah dibuat pada akhir antrian pembeli
    /*Ins_Akhir_TempatBawaan(&(*T), t); // Memasukan node Tempat Bawaan yang telah dibuat pada akhir antrian Tempat Bawaan
    */
}

