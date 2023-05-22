/*       
File Name		: Barang.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */


#include <stdio.h>
#include "header.h"

/* ======= End of Header File ====== */


//============================================================================================
/*   			                Pengembangan modul pada program  	    		        	*/


boolean isEmpty_BarangBelian(address_BB p)
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
//------------------------------------------------------------------------------------------------------ 01


void Create_Node_BarangBelian (address_BB *p)
/*
I.S : Address_BB terdefinisi *p
F.S : Node baru berhasil dialokasi kan pada memori dan pointer *p menunjuk Node tersebut

*/
{
	*p = (address_BB)malloc(sizeof(List_BarangBelian));
	
}
//------------------------------------------------------------------------------------------------------ 02


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
//------------------------------------------------------------------------------------------------------ 03


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
//------------------------------------------------------------------------------------------------------ 04


void Del_Awal_BarangBelian (address_BB * p, infochar * X)
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

//------------------------------------------------------------------------------------------------------ 05


//------------------------------------------------------------------------------------------------------

void Enqueue_BarangBelian(Queue_BB *Q, infotype harga, infochar nama_barang, infotype jumlah)
/*
I.S : Antrian Barang Belian (Queue_BB terdefinisi *Q), Nama Barang, Harga, dan Jumlah Barang
F.S : Data dengan node baru Barang Belian (Nama barang, Harga, dan Jumlah Barang)
*/
{	
	address_BB a = NULL;										// pointer Barang Belian = kosong (NULL)
	
	Create_Node_BarangBelian(&a);								// Membuat Node Barang Belian baru
	Isi_Node_BarangBelian(&a, harga, nama_barang, jumlah);		// Mengisi Node Barang Belian tersebut
	Ins_Akhir_BarangBelian(&(*Q),a);							// Menyisipkan Barang Beliaan di akhir
	
}

//------------------------------------------------------------------------------------------------------ 06





//============================================================================================
/*   			               Penambahan modul pada program  	    		        		*/




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
		printf("| %-20s | %-10s | %-10s |\n", "Nama Barang", "Total Harga", "Jumlah");
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


void TulisFile(Queue_BB Q)
{
	address_BB a = Q;
	FILE *file = fopen("History.txt", "a");
	if (file == NULL)
	{
		printf("Gagal membuka file History.txt");
        return;
	}
	
	else
	{
		fprintf(file, "===================================================\n");
		fprintf(file, "| %-20s | %-10s | %-10s |\n", "Nama Barang", "Total Harga", "Jumlah");
		fprintf(file, "===================================================\n");
	
		while(a != NULL)
		{
			fprintf(file, "| %-20s | %-10d | %-10d |\n", Nama_Barang(a), Harga(a), Jumlah_Barang(a));
			a = next(a);
		}
	
		fprintf(file, "===================================================\n");
	}
	
	fclose(file);
}


void bacaFile()
{
    FILE *file = fopen("History.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file History.txt");
        return;
    }

    char buffer[255];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(file);
}



void deleteHistoryBelian(Queue_BB *Q)
{
	infochar X;
	Del_Awal_BarangBelian(&(*Q), &X);
}
//------------------------------------------------------------------------------------------------------ Athalie


void printHistoryPembeli(Queue_P Q)
{
	address_P a = Q;
	if(isEmpty_Pembeli(Q))
	{
	printf("List Kosong\n");
	}
	else
	{
		printf("=============================================================\n");
		printf("| %-20s | %-10s |\n", "Kasir No", "Nama Pembeli");
		printf("=============================================================\n");
	
		while(a != NULL)
		{
			printf("| %-10d | %-20s |\n", No_Kasir(a), Nama_Pembeli(a));
			a = next(a);
		
		}
	
		printf("=============================================================\n");
	}
}


void printHistoryBelian(Queue_BB Q, Queue_P P, Queue_TB R)
{
	address_BB a = Q;
	address_P b = P;
	address_TB t = R;
	
	if(isEmpty_BarangBelian(Q) || isEmpty_Pembeli(P))
	{
	printf("List Kosong\n");
	}
	else
	{
		printf("=============================================================\n");
		printf("| %-20s | %-20s | %-20s | %-20s | %-10s | %-10s |\n", "Kasir No", "Nama Pembeli", "Tempat Bawaan", "Nama Barang", "Total Harga", "Jumlah");
		printf("=============================================================\n");
	
		while(a != NULL)
		{
			printf("| %-20s | %-20s | %-20s | %-20s | %-10d | %-10d |\n", No_Kasir(b), Nama_Pembeli(b), Tempat_Bawaan(t), Nama_Barang(a), Harga(a), Jumlah_Barang(a));
			a = next(a);
			b = next(b);
			t = next(t);
		}
	
		printf("=============================================================\n");
	}
}
	
	
/*
void printHistoryPembeli(Queue_P P)
{
	address_P a = P;
	
	FILE *file = fopen("history.txt", "r");
	    if (file != NULL) {
        printf("Riwayat Pembeli:\n");
        printf("===========================================================\n");
        printf("| %-20s | %-20s | %-10s | %-10s |\n", "Nama Pembeli", "Nama Barang", "No Kasir", "Harga Barang");
        printf("===========================================================\n");
        
        while (fscanf(file, "%[^|]|%[^|]|%d|%d|%[^\n]\n", pembeli.namaPembeli, pembeli.namaBarang, &pembeli.noKasir, &pembeli.hargaBarang, pembeli.tempatBawaan) == 5) {
            printf("| %-20s | %-20s | %-10d | %-10d |\n", pembeli.namaPembeli, pembeli.namaBarang, pembeli.noKasir, pembeli.hargaBarang);
        }
        
        printf("===========================================================\n");
        
        fclose(file);
    } else {
        printf("Gagal membuka file history.txt\n");
    }
	
	
}
*/


void addHistoryBelian(Queue_BB *Q, infotype harga, infochar nama_barang, infotype jumlah_barang)
{
	address_BB a = NULL;
	Create_Node_BarangBelian(&a);
	Isi_Node_BarangBelian(&a, harga, nama_barang, jumlah_barang);
	Ins_Akhir_BarangBelian(&(*Q),a);
}