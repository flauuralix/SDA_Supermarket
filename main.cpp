/*
File Name		: main.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "header.h"
#include "antri.h"


/* ======= End of Header File ====== */


datakasir Kasir[5];
DataBarang list[5];

address_P Head_Pembeli = NULL;
address_BB Head_BarangBelian = NULL;
address_B Head_Barang = NULL;
address_P Pembeli = NULL;
address_B Barang;
address_BB BarangBelian;
address_A Antrian;

// variabel lokal
infotype lagi,tekan,pil;

// struk
infotype kode,jml,nokasir,harga,Nomor,i=0,stok,barang,harga_barang;
infochar nama,riwayat,Nama_Barang,pilih;


//list barang sembako
void sembako(){	
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
}

//list barang minuman
void minuman(){
	list[0].nama = "Susu Murni     ";
	list[0].stok=10;
	list[0].harga = 12000;
	
	list[1].nama = "Teh Wangi      ";
	list[1].stok=10;
	list[1].harga = 12000;
	
	list[2].nama = "Soda           ";
	list[2].stok=10;
	list[2].harga = 10000;
	
	list[3].nama = "Jus Jeruk      ";
	list[3].stok=10;
	list[3].harga = 8000;
	
	list[4].nama = "Jus Jambu      ";
	list[4].stok=10;
	list[4].harga = 8000;
}

//list barang sayur
void sayur(){
	list[0].nama = "Terong        "; 
	list[0].stok=10;
	list[0].harga = 12000;
		
	list[1].nama = "Buncis        "; 
	list[1].stok=10;
	list[1].harga = 15000;	
	
	list[2].nama = "Kangkung      "; 
	list[2].stok=10;
	list[2].harga = 16000;
		
	list[3].nama = "Jagung Manis  "; 
	list[3].stok=10;
	list[3].harga = 16000;
		
	list[4].nama = "Kentang       "; 
	list[4].stok=10;
	list[4].harga = 18000;		
	}

//list barang buah
void buah(){
	list[0].nama = "Pepaya        "; 
	list[0].stok=10;
	list[0].harga = 16000;
	
	list[1].nama = "Pisang        "; 
	list[1].stok=10;
	list[1].harga = 16000;
	
	list[2].nama = "Mangga        "; 
	list[2].stok=10;
	list[2].harga = 13000;

	list[3].nama = "Melon         "; 
	list[3].stok=10;
	list[3].harga = 15000;	
	
	list[4].nama = "Semangka      "; 
	list[4].stok=10;
	list[4].harga = 13000;
}

//print menu barang
void list_barang(){
	int i;
	for(i=0;i<5;i++){
		printf("%d. %s\t\t\t\t%d\t\t\t\t\t%d\n",i+1,list[i].nama,list[i].stok,list[i].harga);
	}
}

void tampil_menu_barang(){
	menu_barang();
	printf("\nPilihan : "); 
	scanf("%d", &pil);
	system("cls");
	switch(pil)
	{
		case 1 :{
			sembako();
			list_barang();
			break;
		}
		
		case 2 :{
			minuman();
			list_barang();
			break;
		}
					
		case 3 :{
			sayur();
			list_barang();
			break;
		}
		
		case 4 :{
			buah();
			list_barang();
			break;
		}
					

	}
}


int main() {

	int jmlTotal=0;

	// Terdapat 5 kasir sesuai pada nomor
	Kasir[0].Nomor = 1;
	Kasir[1].Nomor = 2;
	Kasir[2].Nomor = 3;
	Kasir[3].Nomor = 4;
	Kasir[4].Nomor = 5;

	for(;;) {
		
		//================================================================= Marshya ================================================================================ Tampilan Awal (Logo Supermarket)
		system ("cls");
		header();
		printf("TEKAN ENTER UNTUK LANJUT..");
		scanf("%c",&tekan);
		system ("cls");
		
		
		//================================================================= Marshya ================================================================================ Tampilan Keadaan Kasir Terkini
		void Kasir_Antrian();
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
		
		
		//================================================================= Claudia ================================================================================== Menu utama
		tampilan_kasir();
		printf("\nPilihan : ");
		scanf("%d", &pil);
		system("cls");
		
		
		switch(pil){
			
			//================================================ Claudia ================================================= Menu Pelanggan
			case 1 : {
				
				/*========== sambutan selamat datang ===========*/
				lagi = 1;
				printf("--SElAMAT DATANG DI SUPERMAERKET MARCAU--");
				printf("\n\tNAMA PELANGGAN: ");
				scanf("%s",&nama);
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				
				
				/*========== Pilih tempat untuk membawa belanjaan ===========*/
				while(Pembeli->next != NULL) {
					Pembeli = Pembeli->next;
				}
				printf   ("\t\t  +==================================================+ \n");
				printf   ("\t\t  |  SILAHKAN PILIH BARANG BAWAAN  YANG TERSEDIA      | \n");
				printf   ("\t\t  |---------------------------------------------------| \n");
				printf   ("\t\t  |               - KERANJANG                         | \n");
				printf   ("\t\t  |               - TROLI                             | \n");
				printf   ("\t\t  |---------------------------------------------------| \n");
				printf("\t\t\t Ketik pilihan anda:");
				scanf("%s", &pilih);
				
				
				/*========== Menu Barang ===========*/
				while (lagi == 1) {
					system("cls"); //________________________________________________ Marshya
					tampil_menu_barang(); 
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					
					Nama_Barang = list[kode-1].nama; //________________________________________________ Claudia
					list[kode-1].stok = list[kode-1].stok-jml;
					list[kode-1].jml += jml;
					if(list[kode-1].stok<0) {
						printf("Maaf Barang Habis\n");
						list[kode-1].stok = 0;
					}
					
					else {
						jmlTotal += jml;
						printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
						printf("\n\nTotal barang: %d\n",jmlTotal);
						harga = list[kode-1].harga * jml;
						printf("\n\nTotal Harga: %d\n",harga);
					}//___________________________________________________________________________________
					
					Pembeli->BarangBelian = Head_BarangBelian;
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
					while (lagi == 1) {
						switch(lagi) {
							case 1:
								system ("cls");
							    tampil_menu_barang();//________________________________________________ Marshya
								printf("\nPilih Barang: ");
								scanf("%d",&kode);
								printf("\nMasukan Jumlah Barang: ");
								scanf("%d",&jml);
								
								Nama_Barang = list[kode-1].nama;//________________________________________________ Claudia
								list[kode-1].stok=list[kode-1].stok-jml;
								list[kode-1].jml += jml;
								if(list[kode-1].stok<0 ) {
									printf("Maaf Barang Habis\n");
									list[kode-1].stok = 0;
								} else {
									jmlTotal += jml;
									printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
									printf("\n\nTotal barang: %d\n",jmlTotal);
									harga = (list[kode-1].harga * jml)+harga;
									printf("\n\nTotal Harga: %d\n",harga);
								}
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
				
				//___________________________________________________________________________________________________
								
				break;
			}
			case 2 : {

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
			case 3:{	
				int item;
				printf("Apakah anda ingin menambahkan atau mengurangi Item? \n1.Mengurangi Item\n2.Menambahkan Item\n3.Tidak\nInput Pilihan:");
				scanf("%d",&item);
				switch(item) {
					case 1:{
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
							printf("\nMasukan Jumlah Item Yang Ingin Dikurangi: ");//______________________________________Claudia
							scanf("%d",&jml);//____________________________________________________________________________
					
//								list[kode-1].stok = list[kode-1].stok+jml;

							if(list[kode-1].stok<0) {
								printf("Maaf Item Habis\n");
								list[kode-1].stok = 0;
							} else {

								jmlTotal -= jml;//______________________________________Claudia
//								printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
								printf("\n\nTotal barang: %d\n",jmlTotal);
								harga_barang = list[kode-1].harga * jml;
								harga -= harga_barang;//______________________________________
								printf("\n\nTotal Harga: %d\n",harga);
								}
							Pembeli->BarangBelian = Head_BarangBelian;
							Head_BarangBelian = Pembeli->BarangBelian;
							Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
							printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
							scanf("%d",&lagi);
							 	while (lagi == 1) {
								switch(lagi) {
									case 1:
										system ("cls");
										printf("\nMasukan Jumlah Item Yang Ingin Dikurangi: ");
										scanf("%d",&jml);
										
										Nama_Barang = list[kode-1].nama;	//_________________________________________Claudia
										list[kode-1].stok=list[kode-1].stok-jml;
										list[kode-1].jml -= jml;//_____________________________________________________
										if(list[kode-1].stok<0 ) {
											printf("Maaf Barang Habis\n");
											list[kode-1].stok = 0;
										} else {

											jmlTotal -= jml;//______________________________________Claudia
//											printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
											printf("\n\nTotal Item: %d\n",jmlTotal);
											harga_barang = list[kode-1].harga * jml;
											harga -= harga_barang;

//					harga = (list[kode-1].harga * jml)+harga;
											printf("\n\nTotal Harga: %d\n",harga);
										}	
										
										Pembeli->BarangBelian = Head_BarangBelian;
										Head_BarangBelian = Pembeli->BarangBelian;
										Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
										printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
										scanf("%d",&lagi);
										break;
									case 2:
										main();
										break;
								    } //___________________________________________________________________
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
					   case 2:{
						
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
							system("cls");
							tampil_menu_barang();//________________________________________________Marshya
								
							printf("\nPilih Item: ");
							scanf("%d",&kode);
							printf("\nMasukan Jumlah Item Yang Ditambah: ");
							scanf("%d",&jml);
							
							Nama_Barang = list[kode-1].nama;//______________________________________Claudia
								
//							harga = list[kode-1].harga* jml;
							list[kode-1].stok = list[kode-1].stok-jml;

							if(list[kode-1].stok<0) {
								printf("Maaf Item Habis\n");
								list[kode-1].stok = 0;
							} else {

								jmlTotal += jml;
								printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
								printf("\n\nTotal Item: %d\n",jmlTotal);
								harga_barang = list[kode-1].harga * jml;
								harga += harga_barang;
								printf("\n\nTotal Harga: %d\n",harga);
								}	//___________________________________________________________________
							
							Pembeli->BarangBelian = Head_BarangBelian;
							Head_BarangBelian = Pembeli->BarangBelian;
							Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
							printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
							scanf("%d",&lagi);
							while (lagi == 1) {
								switch(lagi) {
									case 1:
										system ("cls");
										//list_barang();
									//	system("cls");
										tampil_menu_barang();	//____________________________________________________Marshya
										printf("\nPilih Item: ");
										scanf("%d",&kode);
										printf("\nMasukan Jumlah Item Yang ingin ditambah: ");
										scanf("%d",&jml);
										
										Nama_Barang = list[kode-1].nama;	//_________________________________________Claudia
										list[kode-1].stok=list[kode-1].stok-jml;
										list[kode-1].jml += jml;
										if(list[kode-1].stok<0 ) {
											printf("Maaf Item Habis\n");
											list[kode-1].stok = 0;
										} else {

											jmlTotal += jml;
											printf("\n\nTotal %s: %d\n",Nama_Barang,10 - list[kode-1].stok);
											printf("\n\nTotal Item: %d\n",jmlTotal);
											harga_barang = list[kode-1].harga * jml;
											harga += harga_barang;

//					harga = (list[kode-1].harga * jml)+harga;
											printf("\n\nTotal Harga: %d\n",harga);
										}	//_________________________________________________________________________________
										
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
						break;
					}
					case 3:
						
						main();
						break;	
			}
			break;
		}
		
			case 4 :
				printf("\t\t\t\t   ___________History Transaksi___________\n");
				printf("\n");
				printf("------------------------------------------------------\n");
				printf("Nama Pelanggan : %s\n", &nama);
				printf("Kasir :%d\n",nokasir);
				printf("pilihan:  %s \n",&pilih);
				printf("Total barang: %d\n",jmlTotal);
				printf("Total Harga: %d\n",harga);
				printf("------------------------------------------------------\n");
				system("pause");
				break;

			case 5 :
				printf("Pilih Kasir(1-5): ");
				scanf("%d",&i);
				Dequeue_Antrian(&Kasir[i-1].next,&nama);
				printf("Nama %s telah dihapus dari antrian\n",&nama);
				system("pause");
				printf("Maaf Toko sudah ditutup");
				main();
				break;
				//printf("Pilihan Tidak Tersedia\n");
				system("pause");
				break;	
	
}
}
}







