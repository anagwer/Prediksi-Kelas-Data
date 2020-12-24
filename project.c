#include <stdio.h>
#include <string.h>
#include <math.h>
 
struct data{
    int tgs,uts,uas;
    int tgsb,utsb,uasb;
    float k, nilai;
    char ket[100];
}db[1000], x;

//Fungsi/function Proses shorting atau mengurutkan data yang akan diambil dari data yang terkecil
/* PENJELASAN SORTING
baris 26 : 	mendeklarasikan prosedur sort dengan tipe data int yang menerima masukan nilai jumlah banyaknya angka yang bertipe integer.
baris 27 : 	mendeklarasikan variable i, dan j yang bertipe integer.
baris 28 : 	melakukan perulangan i sebanyak n – 1.
baris 30 : 	melakukan perulangan j dimana j adalah i - 1 dan sampai kurang dari n.
baris 32 : 	kondisi dimana array pada index dengan nilai variable j lebih besar 
			dari array pada index dengan nilai varible j+1 maka nilai j dimasukkan 
			dengan nilai j+1.
baris 34 : 	memasukkan nilai x dengan nilai db pada index ke j.
baris 35 : 	mengganti nilai db pada index ke j dengan nilai db pada index ke j+1.
baris 36 : 	mengganti nilai db pada index ke j+1 dengan nilai x.
*/

void Sort(int n){
  int i, j;
  for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(db[j].nilai > db[j+1].nilai)
            {
                x=db[j];
                db[j]=db[j+1];
                db[j+1]=x;
            }
        }
    }
}


int main(){
    int n,i, j, l;
    
    //memasukkan jumlah data yang akan diolah
    printf("Masukkan Jumlah Data : ");scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Data ke-%d\n",i+1);
        printf("Nilai Tugas : ");scanf("%d",&db[i].tgs);
        printf("Nilai UTS   : ");scanf("%d",&db[i].uts);
        printf("Nilai UAS   : ");scanf("%d",&db[i].uas);
        printf("Nilai Huruf : ");scanf("%s",&db[i].ket);
    }
    
    printf("\n");
     
    //memasukkan nilai baru
    printf("Masukan Nilai Tugas Baru   : ");scanf("%d", &db[i].tgsb);
    printf("Masukan Nilai UTS Baru     : ");scanf("%d", &db[i].utsb);
    printf("Masukan Nilai UAS Baru     : ");scanf("%d", &db[i].uasb);
    
    //menghitung nilai akhir
    //fungsi sqrt berguna untuk menghitung akar kuadrat
    //fungsi pow(x,y) berfungsi untuk mengakarkan angka x dengan angka y
    
    for(i=0;i<n;i++){
    	db[i].nilai = sqrt((pow((db[i].tgsb - db[i].tgs),2))+(pow((db[i].utsb - db[i].uts),2))+(pow((db[i].uasb - db[i].uas),2)));
    } 
    
	printf("===========================================================\n");
    printf("              Prediksi Kelas Data               \n");
    printf("============================================================\n");
    printf("NO | Nilai Tugas | Nilai UTS | Nilai UAS |   Kelas   | nilai |\n");
    printf("============================================================\n");
    for(i=0;i<n;i++){
        printf("%d  | %d          | %d        | %d        | %s\t|%.2f  \n",i+1, db[i].tgs,db[i].uts, db[i].uas, db[i].ket, db[i].nilai);
    }
    printf("============================================================\n\n");
    
    //memasukkan jumlah data yang akan diambil.
    printf("masukkan k: ");scanf("%d", &db[i].k);
    
    //menampilkan hasil akhir program
    
    printf("\n");
    printf("=================================================\n");
    printf("            Hasil Prediksi Kelas Data               \n");
    printf("=================================================\n");
    printf(" Nilai Tugas | Nilai UTS | Nilai UAS |   Kelas   \n");
    printf("=================================================\n");
    printf(" %d          | %d        | %d        ", db[i].tgsb,db[i].utsb, db[i].uasb);       
	float d[n][2];
  
  //Pemanggilan fungsi shorting
   Sort(n);
   
  int baik = 0; 
  int cukup = 0; 
  int kurang = 0; 
    
	//membandingkan kata apa yang sering muncul pada sebagian data yang telah diambil oleh variable K
	//fungsi strcmp = digunakan untuk membandingkan string dengan string yang lainnya.
  for (i = 0; i < db[i].k; i++) {
  	l = d[i][0];
    if (strcmp(db[l].ket, "baik") == 0) {
      baik++;
    }
    if (strcmp(db[l].ket, "cukup") == 0) {
      cukup++;
    }
    if (strcmp(db[l].ket, "kurang") == 0) {
      kurang++;
    }
  }
  
  	//menampilkan hasil kelasnya
      printf("| %s \n", db[l].ket);
	
  if (baik > cukup && baik > kurang) {
    printf("\n baik");
  }
 
  if (cukup > baik && cukup > kurang) {
    printf("\n cukup");
  }
 
  if (kurang > cukup && kurang > baik) {
    printf("\n kurang");
  }
 
}
