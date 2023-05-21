/*
File Name		: main.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "header.h"


/* ======= End of Header File ====== */


Datakasir Kasir[5];
DataBarang list[10];


address_P Head_Pembeli = NULL;
address_BB Head_BarangBelian = NULL;
address_B Head_Barang = NULL;
address_P Pembeli = NULL;
address_B Barang;
address_BB BarangBelian;
address_A Antrian;
address_TB TBawaan ;

// variabel Global
infotype lagi,tekan,pil,kembalian;

// struk
infotype kode,jml,nokasir,harga=0,Nomor,i=0,stok,barang,harga_barang,uang,jmlTotal = 0;
infochar nama,riwayat,Nama_Barang,pilih,tempatbawa;




int main() 
{
	// ============================ Athalie
	Kasir_Tersedia();
	tampil_list();

	for(;;) 
	{
		system ("cls");

		//Tampilan awal (logo) ====================== Marshya
		header();
		printf("TEKAN ENTER UNTUK LANJUT..");
		scanf("%c",&tekan);
		system ("cls");

		//Tampil Kasir ====================== Marshya
		tampil_kasir();

		//Menu utama ====================== Claudia
		tampil_menu();
		printf("\nPilihan : ");
		scanf("%d", &pil);
		system("cls");
		
		//Pemisahan modul ============================ Athalie
		switch(pil) 
		{
			case 1 :
				// Menu Pelanggan
			{

				Pelanggan();
				break;
			}

			case 2 :
				// Menu Proses Kasir
			{
				ProsesKasir();
				break;
			}
			case 3: {
				StokBarang();
				break;
			}
			case 4:
				// Menu Pembayaran
			{
				Pembayaran();
				break;
			}

			case 5 :
				// Menu History
				History();
				break;

			case 6 :
				Exit();

				break;
				//printf("Pilihan Tidak Tersedia\n");
				system("pause");
				break;
		}
	}
}





void Kasir_Tersedia() 
{
	// Terdapat 5 kasir sesuai pada nomor
	/*Kasir[0].Nomor = 1;
	Kasir[1].Nomor = 2;
	Kasir[2].Nomor = 3;
	Kasir[3].Nomor = 4;
	Kasir[4].Nomor = 5;
	*/
	for (int i = 0; i<5; i++)
	{
		Kasir[i].Nomor = i + 1;
	}
	
}

/*
void tampil_kasir() {
	//Tampilan Keadaan Kasir Terkini ====================== Marshya

	printf ("\t___________________________________________________________________________________________________________________________________");
	printf ("\n\t|             |");
	printf ("\n\t|   Kasir 1   |");
	Tampil_List_Antrian(Kasir[0].next);
	printf ("\t|             |");
	printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
	printf ("\n\t|             |");
	printf ("\n\t|   Kasir 2   |");
	Tampil_List_Antrian(Kasir[1].next);
	printf ("\t|             |");
	printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
	printf ("\n\t|             |");
	printf ("\n\t|   Kasir 3   |");
	Tampil_List_Antrian(Kasir[2].next);
	printf ("\t|             |");
	printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
	printf ("\n\t|             |");
	printf ("\n\t|   Kasir 4   |");
	Tampil_List_Antrian(Kasir[3].next);
	printf ("\t|             |");
	printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
	printf ("\n\t|             |");
	printf ("\n\t|   Kasir 5   |");
	Tampil_List_Antrian(Kasir[4].next);
	printf ("\t|             |");
	printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");

} */

void tampil_kasir() 
{
    printf("\t___________________________________________________________________________________________________________________________________");
    for (int i = 0; i < 5; i++) 
	{
        printf("\n\t|             |");
        printf("\n\t|   Kasir %d   |", i + 1);
        Tampil_List_Antrian(Kasir[i].next);
        printf("\t|             |");
        printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
    }
    printf("\n\n");
}



void Pelanggan() 
{
	lagi = 1;
	jmlTotal = 0;
    harga = 0;

	// Sambutan selamat datang ====================== Claudia
	printf("--SElAMAT DATANG DI SUPERMAERKET MARCAU--");
	printf("\n\n");

	// Nama  dan tempat bawaan untuk pelanggan ====================== Athalie
	printf("Tolong masukan NAMA Anda :\t");
	scanf(" %s", &nama);

	printf("Silahkan pilih tempat bawaan anda\n");
	printf("Ketikan 'Keranjang' atau 'Troli' ");
	scanf(" %s", &tempatbawa);
	
	//Tambahkan Pelanggan ====================== Athalie
	ModifEnqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,&TBawaan,nama,nokasir,tempatbawa);
	Pembeli = Head_Pembeli;
		while(Pembeli->next != NULL) 
		{
			Pembeli = Pembeli->next;
		}




	//========== Menu Barang ===========
	while (lagi == 1) 
	{
		system("cls");
		print_barang();
		printf("\nPilih Barang: ");
		scanf("%d",&kode);
		printf("\nMasukan Jumlah Barang: ");
		scanf("%d",&jml);

		Nama_Barang = list[kode-1].nama;

		if(list[kode-1].stok<jml) 
		{
			do
			{
				printf("\nMaaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
				printf("Stok %s yang tersedia: %d\n", Nama_Barang, list[kode-1].stok);
				//          printf("Stok %s yang tersedia:10\n", Nama_Barang,jml,10 - list[kode-1].stok);
				printf("Masukkan jumlah barang yang akan dibeli: ");
				scanf("%d", &jml);
			}
			while(list[kode-1].stok<jml);
				jmlTotal = 0;
				jmlTotal += jml;
				printf("\n\nTotal barang: %d\n",jmlTotal);
				harga += list[kode-1].harga * jml;
				printf("\n\nTotal Harga: %d\n",harga);
				list[kode-1].stok = list[kode-1].stok-jml;
				list[kode-1].jml += jml;
		} else
			{
				//Tampilan total barang yang sudah diambil & harganya
				list[kode-1].stok = list[kode-1].stok-jml;
				list[kode-1].jml += jml;
				jmlTotal += jml;
				printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
				//printf("\nTotal %s: %d\n", Nama_Barang, list[kode-1].stok + jml);
				//printf("\n\nTotal %s: %d\n",Nama_Barang,jml,10 - list[kode-1].stok - jml);
				printf("\n\nTotal barang: %d\n",jmlTotal);
				harga += list[kode-1].harga * jml;
				printf("\n\nTotal Harga: %d\n",harga);
			}	


		Pembeli->BarangBelian = Head_BarangBelian;
		Head_BarangBelian = Pembeli->BarangBelian;
		Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
		printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
		scanf("%d",&lagi);

		// Pengulangan while jika ingin belanja baranrg lagi jika tidak ke Menu
		while (lagi == 1) 
		{
			switch(lagi) 
			{
				case 1:
					system ("cls");
					print_barang();
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);

					Nama_Barang = list[kode-1].nama;
					if(list[kode-1].stok<jml) 
					{
						do
						{
							printf("\nMaaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
							printf("Stok %s yang tersedia: %d\n", Nama_Barang, list[kode-1].stok);
							printf("Masukkan jumlah barang yang akan dibeli: ");
							scanf("%d", &jml);
						}
						while(list[kode-1].stok<jml);
						jmlTotal += jml;
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga += (list[kode-1].harga * jml);
						printf("\n\nTotal Harga: %d\n",harga);
						list[kode-1].stok = list[kode-1].stok-jml;
						list[kode-1].jml += jml;
					} else 
						{
							list[kode-1].stok=list[kode-1].stok-jml;
							list[kode-1].jml += jml;
							jmlTotal += jml;
							printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
							//printf("\nTotal %s : %d\n", Nama_Barang, list[kode-1].stok + jml);
							printf("\n\nTotal barang: %d\n",jmlTotal);
							harga += list[kode-1].harga * jml;
							printf("\n\nTotal Harga: %d\n",harga);
						}
//
//								if(list[kode-1].stok<0 )
//								{
//									 printf("Maaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
//		                             list[kode-1].stok = 0;
//		                             printf("Stok %s yang tersedia: %d\n", Nama_Barang, 10 - list[kode-1].stok);
//                                     printf("Masukkan jumlah barang yang akan dibeli: ");
//                                     scanf("%d", &jml);
//                                     jmlTotal += jml;
//                                     printf("\n\nTotal barang: %d\n",jmlTotal);
//									 harga = (list[kode-1].harga * jml)+harga;
//									 printf("\n\nTotal Harga: %d\n",harga);
//								}
//								else
//								{
//									jmlTotal += jml;
//									printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
//									printf("\n\nTotal barang: %d\n",jmlTotal);
//									harga = (list[kode-1].harga * jml)+harga;
//									printf("\n\nTotal Harga: %d\n",harga);
//								}
//
//
					Pembeli->BarangBelian = Head_BarangBelian;
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
					break;

				case 2:
					main();
			}
		}
	}
}




void ProsesKasir()
{
<<<<<<< HEAD

=======
	printf("\n\n\t\t\t ANTRIAN KASIR\t\t\t\n");
>>>>>>> de936f936ab8f20a584688a5712f5e4d8ec4e1c3
	printf ("\n\t   Kasir 1  : ");
	Tampil_List_Antrian(Kasir[0].next);
	printf ("\n\t   Kasir 2  : ");
	Tampil_List_Antrian(Kasir[1].next);
	printf ("\n\t   Kasir 3  :");
	Tampil_List_Antrian(Kasir[2].next);
	printf ("\n\t   Kasir 4  :");
	Tampil_List_Antrian(Kasir[3].next);
	printf ("\n\t   Kasir 5  :");
	Tampil_List_Antrian(Kasir[4].next);


	printf("\nPilih No. Kasir (1-5): ");
	scanf("%d",&nokasir);
	Antrian = NULL;
	Create_Node_Antrian(&Antrian);
	Isi_Node_Antrian(&Antrian, Pembeli->Nama_Pembeli);
	Ins_Akhir_Antrian(&Kasir[nokasir-1].next,Antrian);
	printf("\nAnda Sudah Masuk Antrian\n");
	system("pause");

}

void StokBarang() {
	int item;
	printf("Apakah anda ingin menambahkan atau mengurangi Item? \n1.Mengurangi Item\n2.Menambahkan Item\n3.Tidak\nInput Pilihan:");
	scanf("%d",&item);


	switch(item) {
		case 1: {
			printf("Anda berada dikasir berapa(1-5)?: ");
			scanf("%d",&i);
			Dequeue_Antrian(&Kasir[i-1].next,&nama);

			printf("Nama %s telah dihapus dari antrian silahkan antri kembali\n",&nama);
			system("pause");
			lagi = 1;
			Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
			Pembeli = Head_Pembeli;
			while(Pembeli->next != NULL) {
				Pembeli = Pembeli->next;
			}
			 	while (lagi == 1) {
			switch(lagi) {
				case 1:
					system ("cls");
					print_barang();
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);

					Nama_Barang = list[kode-1].nama;
					if(list[kode-1].stok<jml) {
						do{
							printf("\nMaaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
							printf("Stok %s yang tersedia: %d\n", Nama_Barang, list[kode-1].stok);
							printf("Masukkan jumlah barang yang akan dibeli: ");
							scanf("%d", &jml);
						}while(list[kode-1].stok<jml);
						jmlTotal -= jml;
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga -= (list[kode-1].harga * jml);
						printf("\n\nTotal Harga: %d\n",harga);
						list[kode-1].stok = list[kode-1].stok+jml;
						list[kode-1].jml -= jml;
					} else {
						list[kode-1].stok=list[kode-1].stok+jml;
						list[kode-1].jml -= jml;
						jmlTotal -= jml;
						printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
//						printf("\nTotal %s : %d\n", Nama_Barang, list[kode-1].stok + jml);
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga -= list[kode-1].harga * jml;
						printf("\n\nTotal Harga: %d\n",harga);
					}
			// =======================================================================
				Pembeli->BarangBelian = Head_BarangBelian;
				Head_BarangBelian = Pembeli->BarangBelian;
				Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
				printf("\nApakah Ingin Mengurangi Item Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
				scanf("%d",&lagi);
				while (lagi == 1) {
			switch(lagi) {
				case 1:
					system ("cls");
					print_barang();
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);

					Nama_Barang = list[kode-1].nama;
					if(list[kode-1].stok<jml) {
						do{
							printf("\nMaaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
							printf("Stok %s yang tersedia: %d\n", Nama_Barang, list[kode-1].stok);
							printf("Masukkan jumlah barang yang akan dibeli: ");
							scanf("%d", &jml);
						}while(list[kode-1].stok<jml);
						jmlTotal -= jml;
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga -= (list[kode-1].harga * jml);
						printf("\n\nTotal Harga: %d\n",harga);
						list[kode-1].stok = list[kode-1].stok+jml;
						list[kode-1].jml -= jml;
					} else {
						list[kode-1].stok=list[kode-1].stok+jml;
						list[kode-1].jml -= jml;
						jmlTotal -= jml;
						printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
//						printf("\nTotal %s : %d\n", Nama_Barang, list[kode-1].stok + jml);
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga -= list[kode-1].harga * jml;
						printf("\n\nTotal Harga: %d\n",harga);
					}
							Pembeli->BarangBelian = Head_BarangBelian;
							Head_BarangBelian = Pembeli->BarangBelian;
							Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
							printf("\nApakah Ingin Mengurangi Item Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
							scanf("%d",&lagi);
							break;
						case 2:
							main();
							break;
					}
				}
			}
			printf("\nNAMA PELANGGAN: ");
			scanf("%s",&nama);
			Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
			Pembeli = Head_Pembeli;
			while(Pembeli->next != NULL) {
				Pembeli = Pembeli->next;
			}

			printf("\nPilih No. Kasir (1-5): ");
			scanf("%d",&nokasir);
			Antrian = NULL;
			Create_Node_Antrian(&Antrian);
			Isi_Node_Antrian(&Antrian, Pembeli->Nama_Pembeli);
			Ins_Akhir_Antrian(&Kasir[nokasir-1].next,Antrian);
			printf("\nAnda Sudah Masuk Antrian\n");
			system("pause");

			break;
		}

		break;
		case 2: {

			printf("Anda berada dikasir berapa(1-5)?: ");
			scanf("%d",&i);
			Dequeue_Antrian(&Kasir[i-1].next,&nama);

			printf("Nama %s telah dihapus dari antrian silahkan antri kembali\n",&nama);
			system("pause");
			lagi = 1;
			Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
			Pembeli = Head_Pembeli;
			while(Pembeli->next != NULL) {
				Pembeli = Pembeli->next;
			}
			//list_barang();
			while (lagi == 1) {
			switch(lagi) {
				case 1:
					system ("cls");
					print_barang();
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);

					Nama_Barang = list[kode-1].nama;
					if(list[kode-1].stok<jml) {
						do{
							printf("\nMaaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
							printf("Stok %s yang tersedia: %d\n", Nama_Barang, list[kode-1].stok);
							printf("Masukkan jumlah barang yang akan dibeli: ");
							scanf("%d", &jml);
						}while(list[kode-1].stok<jml);
						jmlTotal += jml;
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga += (list[kode-1].harga * jml);
						printf("\n\nTotal Harga: %d\n",harga);
						list[kode-1].stok = list[kode-1].stok-jml;
						list[kode-1].jml += jml;
					} else {
						list[kode-1].stok=list[kode-1].stok-jml;
						list[kode-1].jml += jml;
						jmlTotal += jml;
						printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
//						printf("\nTotal %s : %d\n", Nama_Barang, list[kode-1].stok + jml);
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga += list[kode-1].harga * jml;
						printf("\n\nTotal Harga: %d\n",harga);
					}
				Pembeli->BarangBelian = Head_BarangBelian;
				Head_BarangBelian = Pembeli->BarangBelian;
				Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
				printf("\nApakah Ingin Menambahkan Item lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
				scanf("%d",&lagi);
				while (lagi == 1) {
			switch(lagi) {
				case 1:
					system ("cls");
					print_barang();
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);

					Nama_Barang = list[kode-1].nama;
					if(list[kode-1].stok<jml) {
						do{
							printf("\nMaaf, jumlah barang yang Anda beli melebihi stok yang tersedia.\n");
							printf("Stok %s yang tersedia: %d\n", Nama_Barang, list[kode-1].stok);
							printf("Masukkan jumlah barang yang akan dibeli: ");
							scanf("%d", &jml);
						}while(list[kode-1].stok<jml);
						jmlTotal += jml;
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga += (list[kode-1].harga * jml);
						printf("\n\nTotal Harga: %d\n",harga);
						list[kode-1].stok = list[kode-1].stok-jml;
						list[kode-1].jml += jml;
					} else {
						list[kode-1].stok=list[kode-1].stok-jml;
						list[kode-1].jml += jml;
						jmlTotal += jml;
						printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
//						printf("\nTotal %s : %d\n", Nama_Barang, list[kode-1].stok + jml);
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga += list[kode-1].harga * jml;
						printf("\n\nTotal Harga: %d\n",harga);
					}

							Pembeli->BarangBelian = Head_BarangBelian;
							Head_BarangBelian = Pembeli->BarangBelian;
							Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
							printf("\nApakah Ingin Menambahkan Item Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
							scanf("%d",&lagi);
							break;
						case 2:
							main();
					}
				}
			}
			printf("\nNAMA PELANGGAN: ");
			scanf("%s",&nama);
			Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
			Pembeli = Head_Pembeli;
			while(Pembeli->next != NULL) {
				Pembeli = Pembeli->next;
			}

			printf("\nPilih No. Kasir (1-5): ");
			scanf("%d",&nokasir);
			Antrian = NULL;
			Create_Node_Antrian(&Antrian);
			Isi_Node_Antrian(&Antrian, Pembeli->Nama_Pembeli);
			Ins_Akhir_Antrian(&Kasir[nokasir-1].next,Antrian);
			printf("\nAnda Sudah Masuk Antrian\n");
			system("pause");
			break;
		}
//					case 3:
//						main();
//
//				   break;
//

	}
}
}
}

void Pembayaran() {
printf("Anda berada di kasir berapa (1-5)?: ");
scanf("%d", &i);
 Dequeue_Antrian(&Kasir[i - 1].next, &nama);
 
printf("__________________Struk Belanja__________________________________________\n");
printf("\n");
printf("\n--------------------------------------------------------------------------\n");
printf("Nama Pelanggan  : %s\n", &nama);
printf("Kasir           : %d\n", nokasir);
printf("Pilihan         : %s\n", &tempatbawa);
printf("--------------------------------------------------------------------------\n");
printf(" NAMA BARANG\t\tJUMLAH\t\t HARGA \n");
for (int index = 1; index <= 10; index++) {
    if (list[index - 1].stok != 10) {
        int jmlbrg = 10 - list[index - 1].stok;
        printf("\n%s\t\tx%d \t\t %d\n", list[index - 1].nama, jmlbrg, list[index - 1].harga);
    }
}
printf("--------------------------------------------------------------------------\n");

int jmlTotal = 0;  // Inisialisasi jmlTotal dengan 0
int harga = 0;    // Inisialisasi harga dengan 0
for (int index = 1; index <= 10; index++) {
    if (list[index - 1].stok != 10) {
        int jmlbrg = 10 - list[index - 1].stok;
        jmlTotal += jmlbrg;                      // Menambahkan jmlbrg ke jmlTotal
        harga += jmlbrg * list[index - 1].harga; // Menambahkan harga barang ke harga
    }
}
printf("\nTotal barang   : %d\n", jmlTotal);
printf("Total Harga    : %d\n", harga);

printf("Uang Anda      : ");
scanf("%d", &uang);
if (uang >= harga) {
    int kembalian = uang - harga;
    printf("Kembalian      : %d\n", kembalian);
} else {
    int sisa;
    sisa = harga - uang;
    printf("Maaf, uang yang Anda masukkan tidak cukup untuk melakukan pembayaran.\n");
    printf("---------------------------TIDAK LUNAS------------------------------------\n");
    printf("Sisa tagihan Anda sebesar %d.\n", sisa);
    printf("Silakan masukkan uang tambahan untuk menyelesaikan transaksi.\n");
    printf("Total Harga    : %d\n", sisa);
    printf("Uang Anda      : ");
    scanf("%d", &uang);
    if (uang >= harga) {
        int kembalian = uang - harga;
        printf("Kembalian      : %d\n", kembalian);

        printf("_________________________________________________________________________\n");
    }
}
   
	printf("-----------------------------LUNAS---------------------------------------\n");
	printf("Terima kasih telah berbelanja!\n");
	printf("Nama %s telah dihapus dari antrian\n",&nama);
	printf("_________________________________________________________________________\n");
	system("pause");

}




void History() 
{

	//printHistoryBelian(Head_BarangBelian); // Barang Belian
	//printHistoryPembeli(Head_Pembeli); 		// Pembeli
	//printHistoryBelian(Head_BarangBelian, Head_Pembeli, TBawaan);
	TestIsi();
	system("pause");
	main();
}

void Exit() 
{
	printf("Terima kasih sudah mengunjungi SUpermarket Marcau, selamat tinggal :)");
	exit(1);
}

//header tampilan
void header() {
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



void tampil_menu() {
	printf("\t|-----------------------------|");
	printf("\n\t|\t     MENU             |");
	printf("\n\t|-----------------------------|");
	printf(" \n\t|     1.  PELANGGAN           |\n");
	printf("\t|-----------------------------|");
	printf(" \n\t|     2. PILIH KASIR          |\n");
	printf("\t|-----------------------------|");
	printf("\n\t|     3.  MENGUBAH PESANAN    |\n ");
	printf("\t|-----------------------------|");
	printf("\n\t|     4.  PEMBAYARAN          |\n");
	printf("\t|-----------------------------|");
	printf(" \n\t|     5. HISTORI BARANG       |\n");
	printf("\t|-----------------------------|");
	printf(" \n\t|     6.     EXIT             |\n");
	printf("\t|-----------------------------|");
}
//------------------------------------------------------------------------------------------------------ Claidia


void print_barang() 
{

	int i=0;
	for(i=0; i<10; i++) {
		printf("%d. %s\t\t\t\t%d\t\t\t\t\t%d\n",i+1,list[i].nama,list[i].stok,list[i].harga);
	}
}

void tampil_list() 
{

	list[0].nama = "Minyak goreng  ";
	list[0].stok=10;
	list[0].harga = 25000;

	list[1].nama = "Gula           ";
	list[1].stok=10;
	list[1].harga = 9000;

	list[2].nama = "Mie goreng     ";
	list[2].stok=10;
	list[2].harga = 3000;

	list[3].nama = "Mie kuah       ";
	list[3].stok=10;
	list[3].harga = 3000;

	list[4].nama = "Beras          ";
	list[4].stok=10;
	list[4].harga = 25000;

	list[5].nama = "Susu Murni     ";
	list[5].stok=10;
	list[5].harga = 12000;

	list[6].nama = "Teh Wangi      ";
	list[6].stok=10;
	list[6].harga = 12000;

	list[7].nama = "Soda           ";
	list[7].stok=10;
	list[7].harga = 10000;

	list[8].nama = "Jus Jeruk      ";
	list[8].stok=10;
	list[8].harga = 8000;

	list[9].nama = "Jus Jambu      ";
	list[9].stok=10;
	list[9].harga = 8000;
	
	list[9].nama = "Susu Bubuk      ";
	list[9].stok=10;
	list[9].harga = 8000;	

}
//------------------------------------------------------------------------------------------------------ Athalie

