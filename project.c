#include <stdio.h>
#include <string.h>
#include <math.h>
 
struct data{
    int tgs,uts,uas;
    int tgsb,utsb,uasb;
    float k;
    char ket[100];
}db[1000];
int main(){
    int n,i, j, l;
    printf("Masukkan Jumlah Data : ");scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Data ke-%d\n",i+1);
        printf("Nilai Tugas : ");scanf("%d",&db[i].tgs);
        printf("Nilai UTS   : ");scanf("%d",&db[i].uts);
        printf("Nilai UAS   : ");scanf("%d",&db[i].uas);
        printf("Nilai Huruf : ");scanf("%s",&db[i].ket);    
    }
    
    printf("\n");
     
    printf("Masukan Nilai Tugas Baru   : ");scanf("%d", &db[i].tgsb);
    printf("Masukan Nilai UTS Baru     : ");scanf("%d", &db[i].utsb);
    printf("Masukan Nilai UAS Baru     : ");scanf("%d", &db[i].uasb);
    
    float nilai[3];
    
    for(i=0;i<n;i++){
    	nilai[i] = sqrt((pow((db[i].tgsb - db[i].tgs),2))+(pow((db[i].utsb - db[i].uts),2))+(pow((db[i].uasb - db[i].uas),2)));
    	
        /* printf("nilai ke: %d\n",i);
        printf("%.2f",nilai[i]);
        printf("\n"); */
    } 
 	
	printf("===========================================================\n");
    printf("              Prediksi Kelas Data               \n");
    printf("============================================================\n");
    printf("NO | Nilai Tugas | Nilai UTS | Nilai UAS |   Kelas   | nilai |\n");
    printf("============================================================\n");
    for(i=0;i<n;i++){
        printf("%d  | %d           | %d         | %d         | %s\t|%.2f  \n",i+1, db[i].tgs,db[i].uts, db[i].uas, db[i].ket, nilai[i]);
    }
    printf("============================================================\n\n");
    
    printf("masukkan k: ");scanf("%d", &db[i].k);
    
    printf("%d  | %d           | %d         | %d         ",i+1, db[i].tgsb,db[i].utsb, db[i].uasb);       
    float d[n][0], jarak;
 
  //Sorting
  for (i = 0; i < (n-1); i++) {
    for (j = 0; j < (n-1); j++) {
      if (d[j][1] > d[j + 1][1]) {
        jarak = d[j][1];
        d[j][1] = d[j + 1][1];
        d[j + 1][1] = jarak;
 
        l = d[j][0];
        d[j][0] = d[j + 1][0];
        d[j + 1][0] = l;
      }
    }
  }
  
  int baik = 0; 
  int cukup = 0; 
  int kurang = 0; 
    
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

