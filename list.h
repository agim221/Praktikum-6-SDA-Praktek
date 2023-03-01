#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#define nextK(L) (L).next
#define kotaMhs(L) (L).mhs
#define nama(L) (L).nama
#define nextB(L) (L).next
#define first(L) (L).first
#define last(L) (L).last
#define kota(L) (L).kota

typedef char* String;
typedef struct namaMhs *almtNamaMhs;
typedef struct namaMhs {
	String nama;
	almtNamaMhs next;
} Mhs;

typedef struct namaKota *almtNamaKota;
typedef struct namaKota {
	String kota;
	almtNamaKota next;
	almtNamaMhs mhs;
} Kota;

typedef struct {
	Kota *first;
	Kota *last;
} list;

void createElement(list *L);
almtNamaKota SearchKota (list L, char *k);
almtNamaMhs SearchNama (char *k, char *n, list L);
void addFirstKota(char *kota, list *L);
void addAfterKota(Kota *prev, char *k, list *L);
void addLastKota(char *kota, list *L);
void delFirstKota(list *L);
void delAfterKota(Kota *prev, list *L);
void delLastKota(list *L);
void delAllKota(list *L);
void addFirstMhs(char *nama, char *k, list *L);
void addAfterMhs(Mhs *prev, char *n, list *L);
void addLastMhs(char *k, char *n, list *L);
void delFirstMhs(char *kota, list *L);
void delAfterMhs(Mhs *prev, list *L);
void delLastMhs(char *kota, list *L);
void delAllMhs(char *kota, list *L);
void printMhs(char *kota, list L);
int countElementKota(list L);
int countElementMhs(char *k, list L);
void printKota(list L);
void printSemuaKotaMhs(list L);

//Menu
void tampilkanMenuUtama(list *L);
void pilihMenuUtama(int pilih, list *L);
void tampilkanMenuTambahKota(list *L);
void pilihMenuTambahKota(int pilih, list *L);
void tambahKotaAwal(list *L);
void tambahKotaTengah(list *L);
void tambahKotaAkhir(list *L);

void tampilkanMenuTambahMhs(list *L);
void pilihMenuTambahMhs(int pilih, list *L);
void tambahMhsAwal(list *L);
void tambahMhsTengah(list *L);
void tambahMhsAkhir(list *L);

void tampilkanMenuHapusKota(list *L);
void pilihMenuHapusKota(int pilih, list *L);
void hapusKotaAwal(list *L);
void hapusKotaTengah(list *L);
void hapusKotaAkhir(list *L);

void tampilkanMenuHapusMhs(list *L);
void pilihMenuHapusMhs(int pilih, list *L);
void hapusMhsAwal(list *L);
void hapusMhsTengah(list *L);
void hapusMhsAkhir(list *L);

//check
int checkKota(char *k, list L);
int checkMhs(char *k, char *nama,  list L);

void tampilkanMenuTampilkanData(list L);
void pilihMenuTampilkanData(int pilih, list L);
