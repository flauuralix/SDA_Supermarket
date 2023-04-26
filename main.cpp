/*       
File Name		: main.cpp
Description		: Tubes Struktur Data dan Algoritma
Author			: Athalie Aurora, Claudia Berlian H, Marshya Nurrizatuzzahra
*/

/* ========== Header File ========== */

#include <stdio.h>
#include "header.h"



/* ======= End of Header File ====== */


datakasir Kasir[5];
DataBarang list[400];

address_P Head_Pembeli = NULL;
address_BB Head_BarangBelian = NULL;
address_B Head_Barang = NULL;
address_P Pembeli = NULL;
address_B Barang; 
address_BB BarangBelian;
address_A Antrian;
	
infotype pil,kode,jml,nokasir,harga,lagi,Nomor,i=0;
infochar nama,riwayat,Nama_Barang,pilih;

void list_barang(){
	int i;
	
	for(i=0;i<5;i++){
		printf("%d. %s\t\t\t\t%d\t\t\t\t\t%d\n",i+1,list[i].nama,list[i].harga);
	}
}


void TampilList()
{
	
	list[1].nama = "Susu bubuk"	,list[1].harga = 25000;
	list[2].nama = "Minuman bersinergi", list[2].harga = 10000;
	list[3].nama = "Soda", list[3].harga = 15000;
	list[4].nama = "Ikan kaleng", list[4].harga = 35000;
	list[5].nama = "Manisan kaleng", list[5].harga = 30000;
	list[6].nama = "Snack", list[6].harga = 10000;
	list[7].nama = "Bumbu Rendang", list[7].harga = 9000;
	list[8].nama = "Bumbu Opor", list[8].harga = 9000;
	list[9].nama = "Bumbu Soto", list[9].harga = 9000;
	list[10].nama = "Roti Tawar", list[10].harga = 15000;
	list[11].nama = "Roti Manis", list[11].harga = 12000;
	list[12].nama = "Tepung terigu", list[12].harga = 15000;
	list[13].nama = "Tepung tapioka", list[13].harga = 19000;
	list[14].nama = "Tepung sagu", list[14].harga = 20000;
	list[15].nama = "Telur", list[15].harga = 10000;
	list[16].nama = "Cetakan kue", list[16].harga = 8500;
	list[17].nama = "Susu ultra", list[17].harga = 19000;
	list[18].nama = "Pewarna makanan", list[18].harga = 9000;
	list[19].nama = "Baking powder", list[19].harga = 15000;
	list[20].nama = "Baking soda", list[20].harga = 14000;
	list[21].nama = "Coklat batang", list[21].harga = 25000;
	list[22].nama = "Permen Coklat", list[22].harga = 5000;
	list[23].nama = "Permen Buah", list[23].harga = 5000;
	list[24].nama = "Permen Karet", list[24].harga = 5000;
	list[25].nama = "Mie Indomie goreng", list[25].harga = 3000;
	list[26].nama = "Mie Indomie kuah", list[26].harga = 3000;
	list[27].nama = "Mie Indomie aceh", list[27].harga = 3000;
	list[28].nama = "Mie Indomie rendang", list[28].harga = 3000;
	list[29].nama = "Mie Indomie sambal ijo", list[29].harga = 3000;
	list[30].nama = "Mie Indomie sambal matah", list[30].harga = 3000;
	list[31].nama = "Spagheti mentah", list[31].harga = 20000;
	list[32].nama = "Bumbu Spagheti", list[32].harga = 15000;
	list[33].nama = "Makaroni mentah ", list[33].harga = 20000;
	list[34].nama = "Bumbu Pedas", list[34].harga = 12000;
	list[35].nama = "Bumbu Keju", list[35].harga = 10000;
	list[36].nama = "Bumbu asin", list[36].harga = 10000;
	list[37].nama = "Kecap manis", list[37].harga = 14000;
	list[38].nama = "Kecap asin", list[38].harga = 13000;
	list[39].nama = "Minyak goreng", list[39].harga = 35000;
	list[40].nama = "Minyak zaitun", list[40].harga = 30000;
	list[41].nama = "Jus Jambu", list[41].harga = 12000;
	list[42].nama = "Jus Alpukat", list[42].harga = 12000;	
	list[43].nama = "Jus Strawberry", list[43].harga = 14000;	
	list[44].nama = "Jus Anggur", list[44].harga = 12000;	
	list[45].nama = "Jus Jeruk", list[45].harga = 12000;
	list[46].nama = "Jus Rambutan", list[46].harga = 12000;
	list[47].nama = "Jus Durian", list[47].harga = 15000;
	list[48].nama = "Jus Apel", list[48].harga = 10000;			
	list[49].nama = "Jus Melon", list[49].harga = 15000;	
	list[50].nama = "Jus Sirsak", list[50].harga = 12000;
	list[51].nama = "Beras", list[51].harga = 20000;		
	list[52].nama = "Gula", list[52].harga = 10000;
	list[53].nama = "Garam", list[53].harga = 10000;
	list[54].nama = "Perisa", list[54].harga = 10000;	
	list[55].nama = "Bawang putih", list[55].harga = 10000;
	list[56].nama = "Bawang merah", list[56].harga = 10000;
	list[57].nama = "Bawang bombay", list[57].harga = 10000;
	list[58].nama = "Daging Sapi", list[58].harga = 40000;	
	list[59].nama = "Daging Ayam", list[59].harga = 30000;
	list[60].nama = "Daging Kambing", list[60].harga = 35000;
	list[61].nama = "Kerang", list[61].harga = 15000;		
	list[62].nama = "Ikan Gurame", list[62].harga = 40000;
	list[63].nama = "Ikan Bawal", list[63].harga = 20000;
	list[64].nama = "Ikan Teri", list[64].harga = 15000;	
	list[65].nama = "Ikan Tongkol", list[65].harga = 18000;
	list[66].nama = "Ikan Patin", list[66].harga = 15000;
	list[67].nama = "Kacang Hijau", list[67].harga = 12000;
	list[68].nama = "Kacang Merah", list[68].harga = 15000;	
	list[69].nama = "Kacang Almond", list[69].harga = 25000;
	list[70].nama = "Kacang Kedelei", list[70].harga = 16000;
	list[71].nama = "Kacang Mete", list[71].harga = 35000;		
	list[72].nama = "Jagung Manis", list[72].harga = 16000;
	list[73].nama = "Kentang", list[73].harga = 18000;
	list[74].nama = "Wortel", list[74].harga = 15000;	
	list[75].nama = "Brokoli", list[75].harga = 15000;
	list[76].nama = "Cabai merah", list[76].harga = 18000;
	list[77].nama = "Cabai hijau", list[77].harga = 18000;
	list[78].nama = "Tomat", list[78].harga = 15000;	
	list[79].nama = "Timun", list[79].harga = 10000;
	list[80].nama = "Sawi", list[80].harga = 12000;
	list[81].nama = "Bayam", list[81].harga = 18000;		
	list[82].nama = "Kangkung", list[82].harga = 18000;
	list[83].nama = "Buncis", list[83].harga = 16000;
	list[84].nama = "Terong", list[84].harga = 14000;	
	list[85].nama = "Pepaya", list[85].harga = 16000;
	list[86].nama = "Pisang", list[86].harga = 16000;
	list[87].nama = "Mangga", list[87].harga = 13000;
	list[88].nama = "Melon", list[88].harga = 15000;	
	list[89].nama = "Semangka", list[89].harga = 13000;
	list[90].nama = "Anggur", list[90].harga = 12000;
	list[91].nama = "Nanas", list[91].harga = 13000;		
	list[92].nama = "Kelapa Parut", list[92].harga = 12000;
	list[93].nama = "Teh Hijau", list[93].harga = 10000;
	list[94].nama = "Teh Melati", list[94].harga = 10000;	
	list[95].nama = "Teh Poci", list[95].harga = 10000;
	list[96].nama = "Kopi susu", list[96].harga = 13000;
	list[97].nama = "Kopi Hitam", list[97].harga = 15000;
	list[98].nama = "Kopi gula", list[98].harga = 12000;	
	list[99].nama = "Susu Vanila", list[99].harga = 11000;
	list[100].nama = "Susu Strawberry", list[100].harga = 11000;																				
	list[101].nama = "Susu Coklat", list[101].harga = 13000;	
	list[102].nama = "Saus Tomat", list[102].harga = 11000;	
	list[103].nama = "Saus Sambal", list[103].harga = 12000;	
	list[104].nama = "Sereal", list[104].harga = 12000;	
	list[105].nama = "Oat meat", list[105].harga = 12000;	
	list[106].nama = "Kripik kentang", list[106].harga = 15000;	
	list[107].nama = "Kripik Singkong", list[107].harga = 15000;	
	list[108].nama = "Kripik bayam", list[108].harga = 20000;	
	list[109].nama = "Bakso", list[109].harga = 15000;	
	list[110].nama = "Sosis", list[110].harga = 12000;	
	list[111].nama = "Keju", list[111].harga = 12000;	
	list[112].nama = "Yoghurt Vanila ", list[112].harga = 11000;	
	list[113].nama = "Yoghurt Strawberry", list[113].harga = 15000;	
	list[114].nama = "Yoghurt Coklat", list[114].harga = 13000;	
	list[115].nama = "Biskuit Marie", list[115].harga = 12000;	
	list[116].nama = "Biskuit Regal", list[116].harga = 12000;	
	list[117].nama = "Biskuit Bayi", list[117].harga = 12000;	
	list[118].nama = "Roti Gandum", list[118].harga = 12000;	
	list[119].nama = "Sarden Kaleng", list[119].harga = 12000;	
	list[120].nama = "Mayones", list[120].harga = 10000;	
	list[121].nama = "Tepung Maizena", list[121].harga = 12000;	
	list[122].nama = "Merica bubuk", list[122].harga = 10000;	
	list[123].nama = "Susu kental manis putih", list[123].harga = 11000;	
	list[124].nama = "Susu kental manis coklat", list[124].harga = 11000;	
	list[125].nama = "Wafer", list[125].harga = 15000;	
	list[126].nama = "Chips", list[126].harga = 15000;	
	list[127].nama = "Tahu", list[127].harga = 12000;	
	list[128].nama = "Tempe", list[128].harga = 12000;	
	list[129].nama = "Cumi-cumi", list[129].harga = 25000;	
	list[130].nama = "Bakpao", list[130].harga = 17000;	
	list[131].nama = "Dimsum", list[131].harga = 16000;	
	list[132].nama = "Siomay", list[132].harga = 11000;	
	list[133].nama = "Kulit tahu", list[133].harga = 18000;	
	list[134].nama = "Kornet sapi", list[134].harga = 21000;	
	list[135].nama = "Lada Hitam", list[135].harga = 10000;	
	list[136].nama = "Pisang", list[136].harga = 17000;	
	list[137].nama = "Selai nanas", list[137].harga = 11000;	
	list[138].nama = "Selai strawberry", list[138].harga = 12000;	
	list[139].nama = "Selai anggur", list[139].harga = 11000;	
	list[140].nama = "Selai coklat", list[140].harga = 11000;	
	list[141].nama = "Selai markisa", list[141].harga = 11000;	
	list[142].nama = "Sirup Jeruk", list[142].harga = 13000;	
	list[143].nama = "Sirup Sirsak", list[143].harga = 13000;	
	list[144].nama = "Sirup cocopandan", list[144].harga = 13000;	
	list[145].nama = "Sirup Coklat", list[145].harga = 12000;	
	list[146].nama = "Sirup strawberrry", list[146].harga = 12000;	
	list[147].nama = "Sirup Mangga", list[147].harga = 14000;	
	list[148].nama = "Sirup Durian", list[148].harga = 12000;	
	list[149].nama = "Sirup Melon", list[149].harga = 12000;	
	list[150].nama = "Sirup Mawar", list[150].harga = 11000;	
	list[151].nama = "Sirup Vanila", list[151].harga = 14000;	
	list[152].nama = "Paprika Merah", list[152].harga = 15000;	
	list[153].nama = "Paprika Hijau", list[153].harga = 15000;	
	list[154].nama = "Paprika Kuning", list[154].harga = 15000;	
	list[155].nama = "Serai", list[155].harga = 17000;	
	list[156].nama = "Jahe", list[156].harga = 12000;	
	list[157].nama = "Lemon", list[157].harga = 12000;	
	list[158].nama = "Mentega", list[158].harga = 12000;	
	list[159].nama = "Saus BBQ", list[159].harga = 12000;	
	list[160].nama = "Saus Tiram", list[160].harga = 12000;	
	list[161].nama = "Saus Kacang", list[161].harga = 12000;	
	list[162].nama = "Abon sapi", list[162].harga = 12000;	
	list[163].nama = "Abon ayam", list[163].harga = 12000;	
	list[164].nama = "Pudding Mangga", list[164].harga = 12000;	
	list[165].nama = "Pudding Strawberry", list[165].harga = 12000;	
	list[166].nama = "Pudding Melon", list[166].harga = 12000;	
	list[167].nama = "Pudding Coklat", list[167].harga = 12000;	
	list[168].nama = "Pudding Vanila", list[168].harga = 12000;	
	list[169].nama = "Jelly Sirsak", list[169].harga = 12000;	
	list[170].nama = "Jelly Jeruk", list[170].harga = 12000;	
	list[171].nama = "Jelly Asam", list[171].harga = 12000;	
	list[172].nama = "Agar netral", list[172].harga = 12000;	
	list[173].nama = "Agar kopi", list[173].harga = 12000;	
	list[174].nama = "Agar melon", list[174].harga = 12000;	
	list[175].nama = "Kue Tart", list[175].harga = 12000;	
	list[176].nama = "Kue Bolu", list[176].harga = 12000;	
	list[177].nama = "Kue Kering", list[177].harga = 12000;	
	list[178].nama = "Kembang Kol", list[178].harga = 12000;	
	list[179].nama = "Sawi Hiijau", list[179].harga = 12000;	
	list[180].nama = "Sawi Putih", list[180].harga = 12000;							
	list[181].nama = "Lotus", list[181].harga = 12000;	
	list[182].nama = "Labu Siam", list[182].harga = 12000;	
	list[183].nama = "Labu kuning", list[183].harga = 12000;	
	list[184].nama = "Ubi jalar", list[184].harga = 12000;	
	list[185].nama = "Ubi cilembu", list[185].harga = 12000;	
	list[186].nama = "Sambal terasi", list[186].harga = 12000;	
	list[187].nama = "Sambal matah", list[187].harga = 12000;	
	list[188].nama = "Tuna Kalengan", list[188].harga = 12000;	
	list[189].nama = "Eggroll", list[189].harga = 12000;	
	list[190].nama = "Air Minral", list[190].harga = 12000;	
	list[191].nama = "Air Aqua", list[191].harga = 12000;	
	list[192].nama = "Air Le mineral", list[192].harga = 12000;	
	list[193].nama = "Air Galon", list[193].harga = 12000;	
	list[194].nama = "Air Manis", list[194].harga = 12000;	
	list[195].nama = "Air Asam", list[195].harga = 12000;	
	list[196].nama = "Air Asin", list[196].harga = 12000;	
	list[197].nama = "Tepung Jagung", list[197].harga = 12000;	
	list[198].nama = "Bubur Bayi instan", list[198].harga = 12000;	
	list[199].nama = "Cococrunch coklat", list[199].harga = 12000;	
	list[200].nama = "Cengkalen", list[200].harga = 12000;	
	list[201].nama = "Madu instan", list[201].harga = 15000;	
	list[202].nama = "Madu rasa", list[202].harga = 15000;	
	list[203].nama = "Madu alami", list[203].harga = 16000;	
	list[204].nama = "Raket nyamuk", list[204].harga = 12000;	
	list[205].nama = "Rakeet badminton", list[205].harga = 50000;	
	list[206].nama = "Kok badminton", list[206].harga = 20000;	
	list[207].nama = "Bola sepak", list[207].harga = 12000;	
	list[208].nama = "Bola basket", list[208].harga = 12000;	
	list[209].nama = "Bola pingpong", list[209].harga = 15000;	
	list[210].nama = "Kaca besar", list[210].harga = 12000;
	list[211].nama = "Kaca kecil", list[211].harga = 15000;	
	list[212].nama = "Lem superglue", list[212].harga = 15000;	
	list[213].nama = "Lem tembok", list[213].harga = 16000;	
	list[214].nama = "Lem kertas", list[214].harga = 12000;	
	list[215].nama = "Walpaper", list[215].harga = 50000;	
	list[216].nama = "Sarung sholat", list[216].harga = 20000;	
	list[217].nama = "Mukena", list[217].harga = 12000;	
	list[218].nama = "Sarung tangan", list[218].harga = 12000;	
	list[219].nama = "Masker muka", list[219].harga = 15000;	
	list[220].nama = "Bedak putih", list[220].harga = 12000;
	list[221].nama = "Penghapus papan", list[221].harga = 15000;	
	list[222].nama = "Papan tulis", list[222].harga = 15000;	
	list[223].nama = "Mainan motor", list[223].harga = 16000;	
	list[224].nama = "Mainan mobil", list[224].harga = 12000;	
	list[225].nama = "Mainan lego", list[225].harga = 50000;	
	list[226].nama = "Mainan robot", list[226].harga = 20000;	
	list[227].nama = "Paku", list[227].harga = 12000;	
	list[228].nama = "Baut", list[228].harga = 12000;	
	list[229].nama = "Sapu rumah", list[229].harga = 15000;	
	list[230].nama = "Sapu lidi", list[230].harga = 12000;		
	list[231].nama = "Cat warna", list[231].harga = 15000;	
	list[232].nama = "Spidol", list[232].harga = 15000;	
	list[233].nama = "Ciput putih", list[233].harga = 16000;	
	list[234].nama = "Ciput hitam", list[234].harga = 12000;	
	list[235].nama = "Manset putih", list[235].harga = 50000;	
	list[236].nama = "Manset hitam", list[236].harga = 20000;	
	list[237].nama = "Sunscreen", list[237].harga = 12000;	
	list[238].nama = "Krim badan", list[238].harga = 12000;	
	list[239].nama = "Krim wajah", list[239].harga = 15000;	
	list[240].nama = "Stereofoam", list[240].harga = 12000;		
	list[241].nama = "Selimut besar", list[241].harga = 15000;	
	list[242].nama = "Selimut kecil", list[242].harga = 15000;	
	list[243].nama = "Kertas bungkus", list[243].harga = 16000;	
	list[244].nama = "Kertas origami", list[244].harga = 12000;	
	list[245].nama = "Kertas wrapping", list[245].harga = 50000;	
	list[246].nama = "Kertas mini", list[246].harga = 20000;	
	list[247].nama = "Kertas tisu", list[247].harga = 12000;	
	list[248].nama = "Plastik mika", list[248].harga = 12000;	
	list[249].nama = "Plastik besar", list[249].harga = 15000;	
	list[250].nama = "Plastik kecil", list[250].harga = 12000;
	list[251].nama = "Gunting", list[251].harga = 10000;	
	list[252].nama = "Obor", list[252].harga = 15000;	
	list[253].nama = "Lilin", list[253].harga = 16000;	
	list[254].nama = "Sabun mandi", list[254].harga = 12000;	
	list[255].nama = "Sabun Cuci piring", list[255].harga = 50000;	
	list[256].nama = "Sabun lantai", list[256].harga = 20000;	
	list[257].nama = "Sampo rambut", list[257].harga = 12000;	
	list[258].nama = "Sikat gigi", list[258].harga = 12000;	
	list[259].nama = "Sikat wc", list[259].harga = 15000;	
	list[260].nama = "Sikat badan", list[260].harga = 12000;
	list[261].nama = "Pasta gigi", list[261].harga = 10000;	
	list[262].nama = "Handuk", list[262].harga = 15000;	
	list[263].nama = "Tissue Toilet", list[263].harga = 16000;	
	list[264].nama = "Tissue Muka", list[264].harga = 12000;	
	list[265].nama = "Tissue Meja", list[265].harga = 50000;	
	list[266].nama = "Deterjen bubuk", list[266].harga = 20000;	
	list[267].nama = "Deterjen cair", list[267].harga = 12000;	
	list[268].nama = "Pewangi bubuk", list[268].harga = 12000;	
	list[269].nama = "Pewangi cair", list[269].harga = 15000;	
	list[270].nama = "Pengharum ruangan", list[270].harga = 12000;
	list[271].nama = "Pengharum pakaian", list[271].harga = 10000;	
	list[272].nama = "Pengharum lantai", list[272].harga = 15000;	
	list[273].nama = "Pembersih kaca", list[273].harga = 16000;	
	list[274].nama = "Insektisida", list[274].harga = 12000;	
	list[275].nama = "Obat nyamuk", list[275].harga = 50000;	
	list[276].nama = "Obat cacing", list[276].harga = 20000;	
	list[277].nama = "Obat luka", list[277].harga = 12000;	
	list[278].nama = "Betadine", list[278].harga = 12000;	
	list[279].nama = "Kapas", list[279].harga = 15000;	
	list[280].nama = "Vitamin C", list[280].harga = 12000;
	list[281].nama = "Obat sakit kepala", list[281].harga = 10000;	
	list[282].nama = "Obat batuk", list[282].harga = 15000;	
	list[283].nama = "Minyak telon", list[283].harga = 16000;	
	list[284].nama = "Minyak kemiri", list[284].harga = 12000;	
	list[285].nama = "Pil KB", list[285].harga = 50000;	
	list[286].nama = "Alat test kehamilan", list[286].harga = 20000;	
	list[287].nama = "Alat peraga edukatif", list[287].harga = 12000;	
	list[288].nama = "Alat pertukangan", list[288].harga = 12000;	
	list[289].nama = "Alat listrik", list[289].harga = 15000;	
	list[290].nama = "Pipa PVC", list[290].harga = 12000;
	list[291].nama = "Semen", list[291].harga = 10000;	
	list[292].nama = "Cat tembok", list[292].harga = 15000;	
	list[293].nama = "Cat acrilic", list[293].harga = 16000;	
	list[294].nama = "Cat kayu", list[294].harga = 12000;	
	list[295].nama = "Skeatboard", list[295].harga = 50000;	
	list[296].nama = "Paku", list[296].harga = 20000;	
	list[297].nama = "Palu", list[297].harga = 12000;	
	list[298].nama = "Obeng", list[298].harga = 12000;	
	list[299].nama = "Gergaji", list[299].harga = 15000;	
	list[300].nama = "Bor", list[300].harga = 12000;
	list[301].nama = "Conditioner", list[301].harga = 15000;	
	list[302].nama = "Sapu lidi", list[302].harga = 15000;	
	list[303].nama = "Sapu ijuk", list[303].harga = 16000;	
	list[304].nama = "Sapu rumah", list[304].harga = 12000;	
	list[305].nama = "Ember", list[305].harga = 50000;	
	list[306].nama = "Gayung", list[306].harga = 20000;	
	list[307].nama = "Sendok", list[307].harga = 12000;	
	list[308].nama = "Garpu", list[308].harga = 12000;	
	list[309].nama = "Tempat makan", list[309].harga = 15000;	
	list[310].nama = "Tas sekolah anak", list[310].harga = 12000;
	list[311].nama = "Tas kampus", list[311].harga = 15000;	
	list[312].nama = "Tas kerja", list[312].harga = 15000;	
	list[313].nama = "Tas laptop", list[313].harga = 16000;	
	list[314].nama = "Kabel laptop", list[314].harga = 12000;	
	list[315].nama = "Kabel hp", list[315].harga = 50000;	
	list[316].nama = "Kabel listrik", list[316].harga = 20000;	
	list[317].nama = "Gelas plastik", list[317].harga = 12000;	
	list[318].nama = "Gelas kaca", list[318].harga = 12000;	
	list[319].nama = "Gelas melanin", list[319].harga = 15000;	
	list[320].nama = "Tisu Basah", list[320].harga = 12000;
	list[321].nama = "Tidu kering", list[321].harga = 15000;	
	list[322].nama = "Masker kesehatan", list[322].harga = 15000;	
	list[323].nama = "Masker kain", list[323].harga = 16000;	
	list[324].nama = "Masker sekali pakai", list[324].harga = 12000;	
	list[325].nama = "Hand Sanitizer", list[325].harga = 50000;	
	list[326].nama = "Pensil biasa", list[326].harga = 20000;	
	list[327].nama = "Pulpen biasa", list[327].harga = 12000;	
	list[328].nama = "Penghapus biasa", list[328].harga = 12000;	
	list[329].nama = "Pensil mekanik", list[329].harga = 15000;	
	list[330].nama = "Isi pensil mekanik", list[330].harga = 12000;		
	list[331].nama = "Pulpen ajaib", list[331].harga = 15000;	
	list[332].nama = "Penghapus aneka bentuk", list[332].harga = 15000;	
	list[333].nama = "Buku gambar", list[333].harga = 16000;	
	list[334].nama = "Buku sekolah", list[334].harga = 12000;	
	list[335].nama = "Buku kampus", list[335].harga = 50000;	
	list[336].nama = "Tipe X", list[336].harga = 20000;	
	list[337].nama = "Kuas lukis", list[337].harga = 12000;	
	list[338].nama = "Amplop", list[338].harga = 12000;	
	list[339].nama = "Staples", list[339].harga = 15000;	
	list[340].nama = "Isolosi", list[340].harga = 12000;		
	list[341].nama = "Doubletipe", list[341].harga = 15000;	
	list[342].nama = "Solatipe", list[342].harga = 15000;	
	list[343].nama = "Kasur tidur", list[343].harga = 16000;	
	list[344].nama = "Bantal", list[344].harga = 12000;	
	list[345].nama = "Guling", list[345].harga = 50000;	
	list[346].nama = "Kasur lipat", list[346].harga = 20000;	
	list[347].nama = "Sarung bantal", list[347].harga = 12000;	
	list[348].nama = "Sarung guling", list[348].harga = 12000;	
	list[349].nama = "Sprei", list[349].harga = 15000;	
	list[350].nama = "Gorden", list[350].harga = 12000;
	list[351].nama = "Tiang gorden", list[351].harga = 10000;	
	list[352].nama = "Korek api", list[352].harga = 15000;	
	list[353].nama = "Penyedot debu", list[353].harga = 16000;	
	list[354].nama = "Figura", list[354].harga = 12000;	
	list[355].nama = "Tempat foto", list[355].harga = 50000;	
	list[356].nama = "Dompet kecil", list[356].harga = 20000;	
	list[357].nama = "Dompet besar", list[357].harga = 12000;	
	list[358].nama = "Mouse", list[358].harga = 12000;	
	list[359].nama = "Headset", list[359].harga = 15000;	
	list[360].nama = "Earphone", list[360].harga = 12000;
	list[361].nama = "Charger Hp tipe C", list[361].harga = 10000;	
	list[362].nama = "Charger Laptop", list[362].harga = 15000;	
	list[363].nama = "Charger Hp tipe mikro", list[363].harga = 16000;	
	list[364].nama = "Charger Hp iphone", list[364].harga = 12000;	
	list[365].nama = "Tempat minum", list[365].harga = 50000;	
	list[366].nama = "Music box", list[366].harga = 20000;	
	list[367].nama = "CD", list[367].harga = 12000;	
	list[368].nama = "Radio", list[368].harga = 12000;	
	list[369].nama = "Antena TV", list[369].harga = 15000;	
	list[370].nama = "Pendingin laptop", list[370].harga = 12000;
	list[371].nama = "Camera", list[371].harga = 10000;	
	list[372].nama = "Koper kecil", list[372].harga = 15000;	
	list[373].nama = "Koper besar", list[373].harga = 16000;	
	list[374].nama = "Rambut palsu", list[374].harga = 12000;	
	list[375].nama = "Kumis palsu", list[375].harga = 50000;	
	list[376].nama = "Topi koboy", list[376].harga = 20000;	
	list[377].nama = "Topi gaya", list[377].harga = 12000;	
	list[378].nama = "Topi sekolah", list[378].harga = 12000;	
	list[379].nama = "Dasi sekolah", list[379].harga = 15000;	
	list[380].nama = "Seragam sekolah", list[380].harga = 12000;
	list[381].nama = "Logo osis", list[381].harga = 10000;	
	list[382].nama = "Baju kaos", list[382].harga = 15000;	
	list[383].nama = "Baju daster", list[383].harga = 16000;	
	list[384].nama = "Baju rompi", list[384].harga = 12000;	
	list[385].nama = "Jam tangan", list[385].harga = 50000;	
	list[386].nama = "Jam dinding", list[386].harga = 20000;	
	list[387].nama = "Baterai senter", list[387].harga = 12000;	
	list[388].nama = "Baterai lampu", list[388].harga = 12000;	
	list[389].nama = "Senter kecil", list[389].harga = 15000;	
	list[390].nama = "Senter besar", list[390].harga = 12000;
	list[391].nama = "Lampu belajar", list[391].harga = 10000;	
	list[392].nama = "Bohlan lampu", list[392].harga = 15000;	
	list[393].nama = "Kerudung pasmina", list[393].harga = 16000;	
	list[394].nama = "Kerudung segitiga", list[394].harga = 12000;	
	list[395].nama = "Kerudung instan", list[395].harga = 50000;	
	list[396].nama = "Tas selempang", list[396].harga = 20000;	
	list[397].nama = "Tas sekolah", list[397].harga = 12000;	
	list[398].nama = "Dompet koin", list[398].harga = 12000;	
	list[399].nama = "Dompet panjang", list[399].harga = 15000;	
	list[400].nama = "Dompet lipat", list[400].harga = 12000;	
																	
}

int main(){
	Kasir[0].Nomor = 1; 
	Kasir[1].Nomor = 2;
	Kasir[2].Nomor = 3;
	Kasir[3].Nomor = 4;
	Kasir[4].Nomor = 5;
	
	TampilList();
	
	for(;;){
		system ("cls");
	     header();
	     int tekan;
	     printf("TEKAN ENTER UNTUK LANJUT..");
	     scanf("%c",&tekan);
	     system ("cls");
		void Kasir_Antrian();
		printf ("\t___________________________________________________________________________________________________________________________________");
		printf ("\n\t|             |");
		printf ("\n\t|   Kasir 1   |"); Tampil_List_Antrian(Kasir[0].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t|             |");
		printf ("\n\t|   Kasir 2   |"); Tampil_List_Antrian(Kasir[1].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t|             |");	
		printf ("\n\t|   Kasir 3   |"); Tampil_List_Antrian(Kasir[2].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t|             |");
		printf ("\n\t|   Kasir 4   |"); Tampil_List_Antrian(Kasir[3].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------");	
		printf ("\n\t|             |");	
		printf ("\n\t|   Kasir 5   |"); Tampil_List_Antrian(Kasir[4].next);
		printf ("\t|             |");
		printf ("\n\t-----------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n");
		tampilan_kasir();			
		printf("\nPilihan : "); 
		scanf("%d", &pil);
		system("cls");
		switch(pil)
		{
			case 1 :{
					lagi = 1;
			    printf("--SElAMAT DATANG DI SUPERMAERKET MARCAU--");
				printf("\n\tNAMA PELANGGAN: ");
				scanf("%s",&nama);
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
					Pembeli = Pembeli->next;	
				}
			
  	printf   ("\t\t  +======================================+ \n");
	printf   ("\t\t  |   TEMPAT BELANJA YANG TERSEDIA       | \n");
	printf   ("\t\t  |--------------------------------------| \n");
	printf   ("\t\t  |           - KERANJANG                | \n");
	printf   ("\t\t  |           - TROLI                    | \n");
    printf   ("\t\t  |--------------------------------------| \n");
    printf("\t\t Silahkan ketik pilihan anda:");
    scanf("%s",&pilih);


				list_barang();
				while (lagi == 1){
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					Nama_Barang = list[kode-1].nama;
					harga = list[kode-1].harga * jml;
			
					Pembeli->BarangBelian = Head_BarangBelian;				
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
				}
				break;
			}
			case 2 :{
			
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
			case 3 :
				int item;
			printf("Apakah anda ingin menambahkan atau mengurangi Item? \n1.Ya\n2.Tidak\nInput Pilihan:");
			scanf("%d",&item);
			switch(item){
			 case 1:
			    printf("Anda di kasir berapa(1-5)?: ");
				scanf("%d",&i);
				Dequeue_Antrian(&Kasir[i-1].next,&nama);
				system("pause");
				printf("Nama %s telah dikeluar dari antrian silahkan antri kembali\n",&nama);
			   	lagi = 1;
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
					Pembeli = Pembeli->next;	
				}
				
				list_barang();
				while (lagi == 1){
					printf("\nPilih Barang: ");
					scanf("%d",&kode);
					printf("\nMasukan Jumlah Barang: ");
					scanf("%d",&jml);
					Nama_Barang = list[kode-1].nama;
					harga = list[kode-1].harga * jml;
					
		
					Pembeli->BarangBelian = Head_BarangBelian;				
					Head_BarangBelian = Pembeli->BarangBelian;
					Enqueue_BarangBelian(&Head_BarangBelian,harga,Nama_Barang,jml);
					printf("\nBelanja Lagi?\n 1.Ya\n 2.Tidak\nInput Pilihan: ");
					scanf("%d",&lagi);
				}
				printf("\nNAMA PELANGGAN: ");
				scanf("%s",&nama);
				Enqueue_Pembeli(&Head_Pembeli,&Head_BarangBelian,nama,nokasir);
				Pembeli = Head_Pembeli;
				while(Pembeli->next != NULL){ 
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
				case 2:
					main();

			}
			
				break;
			
			
			case 4 :
				printf("\t\t\t\t   ___________History Transaksi___________\n");
				printf("\n");
				printf("------------------------------------------------------\n");
				printf("Nama Pelanggan : %s\n", &nama);
				printf("Kasir :\n");
				printf("pilihan:  %s \n",&pilih);
				printf("______Nama Barang_____   __Jumlah__   ____Harga____\n");
				printf("___________________________________________________\n");
				printf("Total                     jml brg        jml hrg   \n");
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
				exit(1);
				break;
				printf("Pilihan Tidak Tersedia\n");
				system("pause");
				break;

	    	}
	    }
	}


	
		

	


