#include "list.h"

void createElement(list *L) {
	first(*L) = NULL;
}

int countElementKota(list L) {
	int hasil = 0;
	
	Kota *bantu;
	bantu = first(L);
	
	while(bantu != NULL) {
		bantu = nextB(*bantu);
		hasil++;
	}
	
	return hasil;
}

int countElementMhs(char *k, list L) {
	int hasil = 0;
	Kota *kota;
	Mhs *bantu;
	kota = SearchKota(L, k);
	bantu = kotaMhs(*kota);
	
	while(bantu != NULL) {
		hasil++;
		bantu = nextK(*bantu);
	}
	return hasil;
}

void addFirstKota(char *kota, list *L) {
	Kota *baru;
	baru = (Kota *) malloc(sizeof(Kota));
	kota(*baru)  = kota;
	
	if(first(*L) == NULL) {
		 nextB(*baru) = NULL;
	} else {
		nextB(*baru) = first(*L);
	}
	kotaMhs(*baru) = NULL;
	first(*L) = baru;
}

void addAfterKota(Kota *prev, char *k, list *L) {
	if(prev != NULL) {
		Kota *baru;
		baru = (Kota *) malloc(sizeof(Kota));
		kota(*baru) = k;
		if(nextB(*prev) == NULL) {
			nextB(*baru) = NULL;
		} else {
			nextB(*baru) = nextK(*prev);
		}
		kotaMhs(*baru) = NULL;
		nextB(*prev) = baru;
	} else {
		printf("prev berisi NULL");
	}
}

void addLastKota(char *kota, list *L) {
	Kota *baru;
	baru = (Kota *) malloc(sizeof(Kota));
	kota(*baru) = kota;
	if(first(*L) == NULL) {
		addFirstKota(kota, L);
	} else {
		Kota *last, *beforeLast;
		last = first(*L);
		beforeLast = NULL;
		
		while(last != NULL) {
			beforeLast = last;
			last = nextB(*last);
		}
		addAfterKota(beforeLast, kota, L);
	}
}

void delFirstKota(list *L) {
	if(first(*L) != NULL) {
		Kota *hapus;
		hapus = first(*L);
		delAllMhs(kota(*hapus), L);
		
		if(nextB(*hapus) == NULL) {
			first(*L) = NULL;
		} else {
			first(*L) = nextB(*hapus);
		}
		nextB(*hapus) = NULL;
		free(hapus);
	} else {
		printf("\nData Kosong");
	}
}

void delAfterKota(Kota *prev, list *L) {
	if(prev != NULL) {
		Kota *hapus;
		hapus = nextB(*prev);
		delAllMhs(kota(*hapus), L);
		if(hapus == NULL) {
			nextB(*prev) = NULL;
		} else {
			nextB(*prev) = nextB(*hapus);
		}
		nextB(*hapus) = NULL;
		free(hapus);
	} else {
		
	}
}

void delLastKota(list *L) {
	if(first(*L) != NULL) {
		Kota *last, *beforeLast;
		last = first(*L);
		beforeLast = NULL;
		
		if(nextB(*last) == NULL) {
			delFirstKota(L);
		} else {
			while(nextB(*last) != NULL) {
				beforeLast = last;
				last = nextB(*last);
			}
			delAfterKota(beforeLast, L);
		}
	} else {
		printf("\nData Kosong");
	}
}

void delAllMhs(char *kota, list *L) {
	int i = 0;

	while(i < countElementMhs(kota, *L)) {
		delLastMhs(kota, L);
	}
	printf("test");
}

void delAllKota(list *L) {
	int i = 0;
	while(i < countElementKota(*L)) {
		delLastKota(L);
	}
}

void addFirstMhs(char *mhs, char *k, list *L) {
	Kota *bantu;
	bantu = SearchKota(*L, k);
	Mhs *baru;
	baru = (Mhs *) malloc(sizeof(Mhs));
	nama(*baru) = mhs;
	
	if(bantu == NULL) {
		nextK(*baru) = NULL;
	} else {
		nextK(*baru) = kotaMhs(*bantu);
	}
	kotaMhs(*bantu) = baru;
	baru = NULL;
}

void addAfterMhs(Mhs *prev, char *n, list *L) {
	Mhs *baru; 
//	last = nextK(*beforeLast);
	baru = (Mhs *) malloc(sizeof(Mhs));
	nama(*baru) = n;
	
	if(prev != NULL) {
		if(nextK(*prev) == NULL) {
			nextK(*baru) = NULL;
		} else {
			nextK(*baru) = nextK(*prev);
		}
		nextK(*prev) = baru; 
	} else {
		printf("\nMemori Penuh");
	}
}

void addLastMhs(char *k, char *n, list *L) {
	Mhs *beforeLast, *last;
	Kota *bantu;
	bantu = SearchKota(*L, k);
	last = kotaMhs(*bantu);
	beforeLast = NULL;
	if(last == NULL) {
		addFirstKota(k, L);
	} else {
		while(last != NULL) {			
			beforeLast = last;
			last = nextK(*last);
		}
		addAfterMhs(beforeLast, n, L);
	}
}

void delFirstMhs(char *kota, list *L) {
	Kota *bantu;
	Mhs *hapus;
	bantu = SearchKota(*L, kota);
	hapus = kotaMhs(*bantu);
	if(hapus != NULL) {
		if(nextK(*hapus) == NULL) {
			kotaMhs(*bantu) = NULL;
		} else {
			kotaMhs(*bantu) = nextK(*hapus);
		}
		free(hapus);
		hapus = NULL;
	} else {
		
	}
}

void delAfterMhs(Mhs *prev, list *L) {
	if(prev != NULL) {
		Mhs *hapus;
		hapus = nextK(*prev);
		if(nextK(*hapus) == NULL) {
			nextK(*prev) = NULL;
		} else {
			nextK(*prev) = nextK(*hapus);
		}
		free(hapus);
		hapus = NULL;
	}
}

void delLastMhs(char *kota, list *L) {
	Kota *bantu;
	Mhs *beforeLast, *last;
	bantu = SearchKota(*L, kota);
	last = kotaMhs(*bantu);
	beforeLast = NULL;
	if(last != NULL) {
		if(nextK(*last) == NULL) {
			delFirstMhs(kota, L);
		} else {
			while(nextK(*last) != NULL) {
				beforeLast = last;
				last = nextK(*last);
			}
			delAfterMhs(beforeLast, L);
		}
	} else {
		
	}
}

void printKota(list L) {
	Kota *bantu;
	bantu = first(L);
	
	while(bantu != NULL) {
		printf("%s ", kota(*bantu));
		bantu = nextB(*bantu);
	}
}

void printMhs(char *kota, list L) {
	Kota *bantu;
	bantu = SearchKota(L, kota);
	Mhs *print;
	print = kotaMhs(*bantu);
	
	while(print != NULL) {
		printf("%s ", nama(*print));
		print = nextK(*print);
	}
}

void printSemuaKotaMhs(list L) {
	Kota *bantuK;
	Mhs *bantuM;
	
	bantuK = first(L);
	
	while(bantuK != NULL) {
		printf("%s : \n", kota(*bantuK));
		bantuM = kotaMhs(*bantuK);
		while(bantuM != NULL) {
			printf("- %s\n", nama(*bantuM));
			bantuM = nextK(*bantuM);
		}
		bantuK = nextB(*bantuK);
	}
}

almtNamaKota SearchKota (list L, char *k) {
	Kota *P;
	int ketemu = 0;
	
	P = first(L);
	while((P != NULL) && (!ketemu)) {
		if(!strcmp(k, kota(*P))) {
			ketemu = 1;
		} else {
			P = nextK(*P);
		}
	}
	
	return (P);
}

almtNamaMhs SearchNama (char *k, char *n, list L) {
	Kota *bantu;
	bantu = SearchKota(L, k);
	Mhs *P; 
	P = kotaMhs(*bantu);
	int ketemu = 0;
	while((P != NULL) && !ketemu) {
		if(!strcmp(n, nama(*P))) {
			ketemu = 1;
			break;
		}
		P = nextK(*P);
	}

	return (P);
}

void tampilkanMenuUtama(list *L) {
	int pilih;
	system("cls");
	
	printf("1. Tambah Kota\n");
	printf("2. Tambah Mahasiswa\n");
	printf("3. Hapus Kota\n");
	printf("4. Hapus Mahasiswa\n");
	printf("5. Tampilkan Data\n");
	printf("99. Keluar Program\n");
	printf("Pilih Menu :\n");
	
	scanf("%d", &pilih);
	pilihMenuUtama(pilih, L);
}

void pilihMenuUtama(int pilih, list *L) {
	switch(pilih) {
		case 1: 
			tampilkanMenuTambahKota(L);
			break;
		case 2: ;
			tampilkanMenuTambahMhs(L);
			break;
		case 3: 
			tampilkanMenuHapusKota(L);
			break;
		case 4: 
			tampilkanMenuHapusMhs(L);
			break;
		case 5: 
			tampilkanMenuTampilkanData(*L);
			break;
		case 99: 
			exit(0);
			break;
		default : 
			printf("Pilihan Tidak Valid\n");
			tampilkanMenuUtama(L);
	}
}

void tampilkanMenuTambahKota(list *L) {
	int pilih;
	system("cls");
	
	printf("1. Tambahkan Kota di Awal\n");
	printf("2. Tambahkan Kota di Tengah\n");
	printf("3. Tambahkan Kota di Akhir\n");
	printf("99. Kembali\n");
	printf("Pilih Menu :\n");
	
	scanf("%d", &pilih);
	pilihMenuTambahKota(pilih, L);
}


void pilihMenuTambahKota(int pilih, list *L) {
	switch(pilih) {
		case 1: 
			tambahKotaAwal(L);
			break;
		case 2: 
			tambahKotaTengah(L);
			break;
		case 3: 
			tambahKotaAkhir(L);
			break;
		case 99:
			tampilkanMenuUtama(L);
			break;
		default: 
			printf("Pilihan Tidak Valid\n");
			tampilkanMenuTambahKota(L);
	}
}

void tambahKotaAwal(list *L) {
	char *kota;
	int ada;
	kota = (char *) malloc(sizeof(char));
	
	do {
		printf("Masukan Nama Kota :\n");
		scanf("%s", kota);
		ada = checkKota(kota, *L);
		if(ada == 0) {
			addFirstKota(kota, L);
			break;
		}
		else printf("Kota Tersebut Sudah Ada, Masukan Nama Kota Lainnya\n");
	} while(1);
	
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tambahKotaTengah(list *L) {
	char *prev, *kota;
	int ada;
	prev = (char *) malloc(sizeof(char));
	kota = (char *) malloc(sizeof(char));
	
	printKota(*L);
	do {
		printf("\nIngin Menambahkan Setelah Kota apa\n");
		scanf("%s", prev);
		ada = checkKota(prev, *L);
		if(ada) {
			printf("Masukan Nama Kota : \n");
			scanf("%s", kota);
			addAfterKota(SearchKota(*L, prev), kota, L);
			break;
		} else {
			printf("Kota Tersebut Tidak ada\n");
		}
	} while(1);
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tambahKotaAkhir(list *L) {
	char *kota;
	int ada;
	kota = (char *) malloc(sizeof(char));
	
	do {
		printf("Masukan Nama Kota :\n");
		scanf("%s", kota);
		ada = checkKota(kota, *L);
		if(ada == 0) {
			addLastKota(kota, L);
			break;
		}
		else printf("Kota Tersebut Sudah Ada, Masukan Nama Kota Lainnya\n");
	} while(1);
	
	printf("\n");
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tampilkanMenuTambahMhs(list *L) {
	int pilih;
	system("cls");
	
	printf("1. Tambahkan Kota di Awal\n");
	printf("2. Tambahkan Kota di Tengah\n");
	printf("3. Tambahkan Kota di Akhir\n");
	printf("99. Kembali\n");
	printf("Pilih Menu :\n");
	
	scanf("%d", &pilih);
	pilihMenuTambahMhs(pilih, L);
}

void pilihMenuTambahMhs(int pilih, list *L) {
	switch(pilih) {
		case 1: 
			tambahMhsAwal(L);
			break;
		case 2: 
			tambahMhsTengah(L);
			break;
		case 3:
			tambahMhsAkhir(L); 
			break;
		case 99: 
			tampilkanMenuUtama(L);
			break;
		default:
			printf("Pilihan Tidak Valid\n");
			tampilkanMenuTambahMhs(L);
	}
}

void tambahMhsAwal(list *L) {
	char *namaKota;
	char *namaMhs;
	int ada;
	namaKota = (char *) malloc(sizeof(char));
	namaMhs = (char *) malloc(sizeof(char));
	
	do {
		printf("Ingin menambahkan dikota mana, Masukan Nama Kota :\n");
		scanf("%s", namaKota);
		ada = checkKota(namaKota, *L);
		if(ada) {
			printf("Masukan Nama Mahasiswa : \n");
			scanf("%s", namaMhs);
			addFirstMhs(namaMhs, namaKota, L);
			break;
		}
		else printf("Kota Tersebut Tidak Ada, Masukan Nama Kota Lainnya\n");
	} while(1);
	
	printf("\n");
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tambahMhsTengah(list *L) {
	char *nama, *kota;
	Mhs *prev;
	int ada;
	nama = (char *) malloc(sizeof(char));
	kota = (char *) malloc(sizeof(char));
	
	printKota(*L);
	do {
		printf("\nIngin Menambahkan Setelah Kota apa\n");
		scanf("%s", kota);
		ada = checkKota(kota, *L);
		if(ada) {
			printMhs(kota, *L);
			printf("\nIngin Menambahkan Setelah nama siapa ?\n");
			scanf("%s", nama);
			prev = SearchNama(kota, nama, *L);
			printf("Masukan Nama yang Ingin di Tambahkan : \n");
			scanf("%s", nama);
			addAfterMhs(prev, nama, L);
			break;
		} else {
			printf("Kota Tersebut Tidak ada\n");
		}
	} while(1);
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tambahMhsAkhir(list *L) {
	char *namaKota;
	char *namaMhs;
	int ada;
	namaKota = (char *) malloc(sizeof(char));
	namaMhs = (char *) malloc(sizeof(char));
	
	do {
		printf("Ingin menambahkan dikota mana, Masukan Nama Kota :\n");
		scanf("%s", namaKota);
		ada = checkKota(namaKota, *L);
		if(ada) {
			printf("Masukan Nama Mahasiswa : \n");
			scanf("%s", namaMhs);
			addLastMhs(namaKota, namaMhs, L);
			break;
		}
		else printf("Kota Tersebut Tidak Ada, Masukan Nama Kota Lainnya\n");
	} while(1);
	
	printf("\n");
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tampilkanMenuHapusKota(list *L) {
	int pilih;
	printf("1. Hapus Kota di Awal\n");
	printf("2. Hapus Kota di Tengah\n");
	printf("3. Hapus Kota di Akhir\n");
	printf("99. Kembali\n");
	printf("Pilih Menu :\n");
	
	scanf("%d", &pilih);
	pilihMenuHapusKota(pilih, L);
}

void pilihMenuHapusKota(int pilih, list *L) {
	switch(pilih) {
		case 1:
			hapusKotaAwal(L); 
			break;
		case 2:
			hapusKotaTengah(L);
			break;
		case 3: 
			hapusKotaAkhir(L);
			break;
		case 99: break;
		default: 
			printf("Pilihan tidak valid");
			tampilkanMenuHapusKota(L);
	}
	
	printf("\n");
	system("pause");
	
	tampilkanMenuUtama(L);
}

void hapusKotaAwal(list *L) {
	if(countElementKota(*L)) {

		int pilih;
	
		printKota(*L);
		printf("\nYakin ingin menghapus %s ? \n1. Ya\n2. Tidak\n", kota(*first(*L)));
		scanf("%d", &pilih);
		switch(pilih) {
			case 1:
				delFirstKota(L);
				break;
			case 2:
				tampilkanMenuHapusKota(L);
				break;
			default:
				printf("Pilihan Tidak Valid\n");
				hapusKotaAwal(L);
		}
	
		printf("\n");
		system("pause");
	
		tampilkanMenuUtama(L);
	} else {
		printf("Data Kosong\n");
	}
}

void hapusKotaTengah(list *L) {
	if(countElementKota(*L) != 0) {
		char *kota;
		kota = (char *) malloc(sizeof(char));
	 	Kota *last, *beforeLast;
	 	last = first(*L);
	 	beforeLast = NULL;
	 	printKota(*L);
	 	printf("\nKota mana yang ingin di hapus ? \n");
	 	scanf("%s", kota);
	 	
	 	while(strcmp(kota, kota(*last))) {
	 		beforeLast = last;
	 		last = nextB(*last);
		 }
		 delAfterKota(beforeLast, L);
	} else {
		
	}
}

void hapusKotaAkhir(list *L) {
	if(countElementKota(*L) != 0) {
		int pilih;
		Kota *bantu;
		bantu = first(*L);
		printKota(*L);
		while(nextB(*bantu) != NULL) {
			bantu = nextB(*bantu);
		}
		printf("\nYakin ingin menghapus kota %s\n1. Ya\n2. Tidak", kota(*bantu));
		scanf("%d", &pilih);
		switch(pilih) {
			case 1: 
				delLastKota(L);
				break;
			case 2: 
				tampilkanMenuHapusKota(L);
				break;
			default: 
				printf("\nPilihan Tidak valid\n");
				tampilkanMenuHapusKota(L);
		}
		
	} else {
		
	}
}

void tampilkanMenuHapusMhs(list *L) {
	int pilih;
	
	printf("1. Hapus Mahasiswa di Awal\n");
	printf("2. Hapus Mahasiswa di Tengah\n");
	printf("3. Hapus Mahasiswa di Akhir\n");
	printf("99. Kembali\n");
	printf("Pilih Menu :\n");
	
	scanf("%d", &pilih);
	pilihMenuHapusMhs(pilih, L);
}


void pilihMenuHapusMhs(int pilih, list *L) {
	switch(pilih) {
		case 1:
			hapusMhsAwal(L); 
			break;
		case 2:
			hapusMhsTengah(L);
			break;
		case 3: 
			hapusMhsAkhir(L);
			break;
		case 99: break;
			tampilkanMenuUtama(L);
		default: 
			printf("Pilihan tidak valid");
			tampilkanMenuHapusKota(L);
	}
	
	printf("\n");
	system("pause");
	
	tampilkanMenuUtama(L);
}

void hapusMhsAwal(list *L) {
	char *nama, *kota;
	Mhs *bantu;
	int ada, pilih;
	nama = (char *) malloc(sizeof(char));
	kota = (char *) malloc(sizeof(char));
	
	printKota(*L);
	do {
		printf("\nIngin Menghapus di Kota apa\n");
		scanf("%s", kota);
		ada = checkKota(kota, *L);
		if(ada) {
			bantu = kotaMhs(*SearchKota(*L, kota));
			
			printMhs(kota, *L);
			printf("\nYakin ingin Menghapus nama %s ?\n1. Ya\n2. Tidak\n", nama(*bantu));
			scanf("%d", &pilih);
			switch(pilih) {
				case 1:
					delFirstMhs(kota, L);
					break;
				case 2:
					tampilkanMenuHapusMhs(L);
					break;
				default:
					printf("Pilihdan Tidak Valid");
					tampilkanMenuHapusMhs(L);
			}
		} else {
			printf("Kota Tersebut Tidak ada\n");
		}
		break;
	} while(1);
	
	system("pause");
	
	tampilkanMenuUtama(L);
}

void hapusMhsTengah(list *L) {
	char *nama, *kota;
	Mhs *bantu, *hapus;
	int ada, pilih;
	nama = (char *) malloc(sizeof(char));
	kota = (char *) malloc(sizeof(char));
	
	do {
		printKota(*L);
		printf("\nIngin Menghapus di Kota apa\n");
		scanf("%s", kota);
		ada = checkKota(kota, *L);
		if(ada) {
			bantu = kotaMhs(*SearchKota(*L, kota));
			
			printMhs(kota, *L);
			printf("\nIngin Menghapus Siapa ?\n");
			scanf("%s", nama);
			
			while(strcmp(nama, nama(*bantu))) {
				hapus = bantu;
				bantu = nextK(*bantu);
			}
			
			printf("\nYakin ingin Menghapus nama %s ?\n1. Ya\n2. Tidak\n", nama(*bantu));
			scanf("%d", &pilih);
			switch(pilih) {
				case 1:
					delAfterMhs(hapus, L);
					break;
				case 2:
					tampilkanMenuHapusMhs(L);
					break;
				default:
					printf("Pilihdan Tidak Valid");
					tampilkanMenuHapusMhs(L);
			}
		} else {
			printf("Kota Tersebut Tidak ada\n");
		}
		break;
	} while(1);
	
	system("pause");
	
	tampilkanMenuUtama(L);
}

void hapusMhsAkhir(list *L) {
	char *kota;
	Mhs *bantu;
	int ada, pilih;
	kota = (char *) malloc(sizeof(char));
	
	printKota(*L);
	do {
		printf("\nIngin Menghapus di Kota apa\n");
		scanf("%s", kota);
		ada = checkKota(kota, *L);
		if(ada) {
			bantu = kotaMhs(*SearchKota(*L, kota));
			
			while(nextK(*bantu) != NULL) {
				bantu = nextK(*bantu);
			}
			
			printMhs(kota, *L);
			printf("\nYakin ingin Menghapus nama %s ?\n1. Ya\n2. Tidak\n", nama(*bantu));
			scanf("%d", &pilih);
			switch(pilih) {
				case 1:
					delLastMhs(kota, L);
					break;
				case 2:
					tampilkanMenuHapusMhs(L);
					break;
				default:
					printf("Pilihdan Tidak Valid");
					tampilkanMenuHapusMhs(L);
			}
		} else {
			printf("Kota Tersebut Tidak ada\n");
		}
		break;
	} while(1);
	
	system("pause");
	
	tampilkanMenuUtama(L);
}

void tampilkanMenuTampilkanData(list L) {
	int pilih;
	
	printf("1. Tampilkan Kota\n");
	printf("2. Tampilkan Mahasiswa\n");
	printf("3. Tampilkan Kota dan Mahasiswa\n");
	printf("99. Kembali\n");
	printf("Pilih Menu :\n");
	scanf("%d", &pilih);
	pilihMenuTampilkanData(pilih, L);
}


void pilihMenuTampilkanData(int pilih, list L) {
	char *kota;
	kota = (char *) malloc(sizeof(char));
	switch(pilih) {
		case 1:
			printKota(L);
			break;
		case 2:
			printf("Ingin melihat mahasiswa di kota mana ?\n");
			scanf("%s", kota);
			printMhs(kota, L);
			break;
		case 3:
			printSemuaKotaMhs(L);
			break;
		case 99:
			tampilkanMenuUtama(&L);
			break;
		default:
			printf("Pilihan Tidak Valid\n");
			tampilkanMenuTampilkanData(L);
	}
	
	printf("\n");
	system("pause");
	tampilkanMenuUtama(&L);
}

int checkKota(char *k, list L) {
	int ketemu = 0;
	Kota *bantu;
	bantu = first(L);
	
	while(bantu != NULL && !ketemu) {
		if(!strcmp(k, kota(*bantu))) {
			ketemu = 1;	
		}
		bantu = nextB(*bantu);
	}
	
	return ketemu;
}

int checkMhs(char *k, char *nama, list L) {
	int ketemu = 0;
	Kota *bantu;
	Mhs *mhs;
	bantu = SearchKota(L, k);
	mhs = kotaMhs(*bantu);
	
	while(mhs != NULL && !ketemu) {
		if(!strcmp(nama, nama(*mhs))) {
			ketemu = 1;
		}
		mhs = nextK(*mhs);	
	}
	
	return ketemu;
}
