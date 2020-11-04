/* 
Author	: Dicky Febrian Dwiputra
NIM		: 3411181097
Kelas	: AIG A 2018
*/ 

#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include "boolean.h"

//adt
typedef struct{
	char nama[100] ;
	char gol[2];
	int lamakerja;
}form;

typedef struct{
	char nama[100];
	char gol[2];
	int gaji;
}DataGajian;

typedef struct{
	char nama[100];
	char gol[2];
	int gaji;
}report;

typedef struct{
	char nama[100];
	int gaji;
}paycheck;


//header
void InputData(form *fk);
int HitungGaji(form *fk);
//void LaporandanSlip(report *laporan, paycheck *slip, DataGajian gaji);

//main
int main(){
	//Kamus
	form fk[10];
	DataGajian gaji[10];
	report laporan[10];
	paycheck slip[10];
	int gajian[10];
	int i,max,pilih,pilihslip;
	boolean validasi;
	char valid;
	
	//algo
	//inisialisasi
	validasi = false;
	//menu
	printf("\t PROGRAM IMPL");
	printf("\n===================================\n Press Enter to next");
	getch();
	system("cls");
	printf("\t INPUT DATA JAM KERJA\n");
	printf("===================================\n");
	printf("Input berapa pekerja = ");
	scanf("%i",&max);
	for(i=0;i<=max-1;i++){
		InputData(&fk[i]);
		gajian[i] = HitungGaji(&fk[i]);
		gaji[i].gaji=gajian[i];
		strcpy(gaji[i].nama,fk[i].nama);
		strcpy(gaji[i].gol,fk[i].gol);	
	}
	printf("\nData sudah masuk ke Datastore Rekapan");
	//getch();	
	
	
	/*Debug
	printf("\t %s",gaji[0].gol);
	*/
	//printf("\n===================================\n Press Enter to next");
	getch();
	system("cls");
	printf("Laporan dan Slip");
	printf("\n=====================\n");
	
	//laporan dan slip
	for(i=0;i<=max-1;i++){
		LaporandanSlip(&laporan[i],&slip[i],gaji[i]);
		
		//debug
		//printf("%i\t %s\n",i+1,laporan[i].nama);	
	}
	//mencetak dan validasi
	
	do{
		system("cls");
		printf("VALIDASI DAN MENCETAK LAPORAN / SLIP");
		printf("\n=================================================\n");
		printf("1. Validasi\n");
		printf("2. Cetak Laporan\n");
		printf("3. Cetak Slip\n");
		printf("4. Exit\n");
		printf("Pilihan (1-4) = ");
		scanf("%i",&pilih);
		switch(pilih){
			case 1 :	printf("Apakah anda ingin memvalidasi laporan ? (jika benar ketik 'Y') : ");
						scanf("%s",&valid);
						if(valid=='Y'){
							validasi=true;
							printf("Anda sudah memvalidasi laporan");
							getch();
						}
						getch();
						break;
			case 2 :	system("cls");
						printf("Laporan\n");
						if(valid){
							printf("Sudah di validasi");
						}else{
							printf("Belum di validasi");
						}
						printf("\n\n\tLAPORAN\n");
						printf("=====================================================\n");
						printf("Nama \t\t || \t Golongan \t || \t Gaji \t\n");
						for(i=0;i<=max-1;i++){
							Cetak(laporan[i],slip[i],pilih);
							printf("\n");
							//debug
							/*printf("%s  \t\t    ",laporan[i].nama);
							printf("\t %s \t    ",laporan[i].gol);
							printf("\t %i \n",laporan[i].gaji);*/
						}
						getch();
						break;
			case 3 :	printf("\t\tDAFTAR SLIP GAJI\n");
						printf("===========================================\n");
						printf("No\t Nama\n");
						for(i=0;i<=max-1;i++){
							printf("%i\t %s\n",i+1,slip[i].nama);
						}
						printf("\nPilih Slip gaji yang akan dicetak : ");
						scanf("%i",&pilihslip);
						system("cls");
						printf("\tSLIP GAJI");
						printf("\n===========================================\n");
						Cetak(laporan[pilihslip-1],slip[pilihslip-1],pilih);
						getch();
						break;
			case 4 :	printf("Selamat Tinggal !!!");
						getch();
						break;
			default : printf("Pilihan anda salah!!");
						getch();			
		}
	}while(pilih!=4);
	
}

//procedure/Function
void InputData(form *fk){
	//kamus
	
	//algo
	fflush(stdin);
	printf("\nMasukan nama : ");
	gets((*fk).nama);
	
	printf("Masukan golongan : ");
	scanf("%s",&(*fk).gol);
	
	printf("Masukan jam kerja : ");
	scanf("%i",&(*fk).lamakerja);
}

int HitungGaji(form *fk){
	//kamus
	int gaji;
	//algo
	if(strcmp((*fk).gol,"A")==0){
		gaji = 100 * (*fk).lamakerja;
	}else{
		gaji = 50 * (*fk).lamakerja;
	}
	return gaji;
}

void LaporandanSlip(report *laporan, paycheck *slip, DataGajian gaji){
	//kamus

	//algo
	//laporan
		strcpy((*laporan).nama,gaji.nama);
		strcpy((*laporan).gol,gaji.gol);
		(*laporan).gaji=gaji.gaji;
		
	//slip
		strcpy((*slip).nama,gaji.nama);
		(*slip).gaji=gaji.gaji;
	}
	
void Cetak(report laporan, paycheck slip, int pilihan){
	if(pilihan==2){
		printf("%s\t\t     \t%s\t\t    \t%i",laporan.nama,laporan.gol,laporan.gaji);
	}else{
		printf("Nama anda : %s\n",slip.nama);
		printf("Gaji anda : %i\n",slip.gaji);
	}
}

