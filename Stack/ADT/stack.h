/**
* File : stack.h  
* Stack diimplementasi dengan tabel kontigu (berurutan) dan ukuran sama.
* TOP adalah alamat element puncak.
* Iplementasi Stak dalam bahasa C++ dengan alokasi statik.
*/

#ifndef stack_H 
#define stack_H 
#define Nil 0
#define MaxEl 10 

/**
* Control Element Type 
* Diguanakan untuk mengubah tipe data Stack
*/
typedef int infotype; 
/* indeks tabel */ 
typedef int address;   

/* defenisi gerbong stack [index | element ]*/
typedef struct { 
	/* tabel penyimpan elemen */ 
	infotype T[MaxEl+1];
	/* alamat TOP: elemen puncak */  
    address TOP;         
} Stack; 

/**---------------SELEKTOR------------------**/

/**
* Dengan S adalah Stack maka :
* - Mengakses elemen TOP menggunakan S.T[(S.TOP)] dengan selektor menjadi InfoTop(S)
* - Mengakses TOP menggunakan S.TOP dengan selektor menjadi Top(S)
*/
#define Top(S) (S).TOP 
#define InfoTop(S) (S).T[(S).TOP] 

/**---------------KONSTRUKTOR/KREATOR---------**/

/** 
* I.S. Sembarang 
* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai 
* Ciri stack kosong : TOP bernilai Nil 
*/ 
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}

/**-------------Predikat Untuk test keadaan KOLEKSI ------**/ 

/* Mengirim true jika Stack kosong */ 
bool IsEmpty (Stack S){
	return Top(S) == Nil;
}

/* Mengirim true jika tabel penampung nilai elemen stack penuh */ 
bool IsFull(Stack S){
	return Top(S) == MaxEl+1;
}

/**------------ Menambahkan sebuah elemen ke Stack --------**/

/**
* Menambahkan X sebagai elemen Stack S. 
* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
* F.S. X menjadi TOP yang baru,TOP bertambah 1 
* Menghapus sebuah elemen Stack 
*/  
void Push (Stack *S, infotype X){
	if(!IsFull(*S)){
		Top(*S)++;
		InfoTop(*S) = X;
	}	
}

/** 
* Menghapus X dari Stack S. 
* I.S. S  tidak mungkin kosong  
* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 
*/ 
void Pop (Stack *S, infotype *X){
	if(!IsEmpty(*S)){
		*X = InfoTop(*S);
		Top(*S)--;
	}
}

#endif 