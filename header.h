
/*       
File Name		: header.h
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "boolean.h"


/* ======= End of Header File ====== */



//--------------------------------------------- Claudia

boolean cek_nodepelanggan(address_BB p);

void node_baru(address_BB *p);

void isi_nodebarang (address_BB *p , infotype harga, infochar Nama_Barang, infotype Jumlah_Barang);

void node_Insakhir (address_BB *p, address_BB PNew);

void del_awalbarang (address_BB * p, infochar * X);



//--------------------------------------------- Mars

void header();

void Kasir_Antrian();

void Delete_Awal_Antrian (address_A * p, infochar * X);

void Ins_Akhir_Antrian (address_A *p, address_A PNew);

void Tampil_Antrian (address_A p);

void Isi_Node_Antrian (address_A *p , infochar nama);

void Create_Node_Antrian (address_A *p);

boolean isEmpty_Antrian(address_A p);











