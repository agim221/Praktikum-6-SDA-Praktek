#include "list.c"

int main() {
	list L;
	
	createElement(&L);
	addFirstKota("Bandung", &L);
	addFirstKota("Jakarta", &L);
	addLastKota("Garut",&L);
	addAfterKota(SearchKota(L, "Jakarta"), "Banten", &L);
//	delFirstKota(&L);
//	delAfterKota(first(L) ,&L);
//	delLastKota(&L);
	addFirstMhs("Agim", "Bandung", &L);
	addFirstMhs("revandi", "Bandung", &L);
	addFirstMhs("Ferdi", "Bandung", &L);
	addFirstMhs("Sambo", "Bandung", &L);
	addFirstMhs("Farhan", "Garut", &L);
	addAfterMhs(SearchNama("Bandung", "Ferdi", L), "Najib", &L);
	addLastMhs("Bandung", "Jami", &L);
	addLastMhs("Garut", "Jodi", &L);
//	delFirstKota(&L);
//	delAllMhs("Jakarta", &L);
	addAfterMhs(SearchNama("Garut", "Farhan", L), "Danu", &L);
//	addAfterKota(SearchKota(L, "Jakarta"), "Banten", &L);
//	delAllKota(&L);
//	delFirstMhs("Bandung", &L);
//	delAfterMhs(SearchNama("Bandung", "revandi", L), &L); 
//	delLastMhs("Bandung", &L);
//	delAllMhs("Bandung", &L);
//	printMhs("Bandung", L);
	printf("%d ", countElementMhs("Bandung", L));
	printf("%d ", countElementMhs("Jakarta", L));
	printf("%d ", countElementMhs("Garut", L));
	printf("%d ", countElementMhs("Banten", L));
//	printSemuaKotaMhs(L);
	printKota(L);
	tampilkanMenuUtama(&L);
	
	return 0;
}
