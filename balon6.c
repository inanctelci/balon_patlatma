#include <stdio.h>
#include <stdlib.h>

struct yigin{
    struct yigin *isaretci;
	struct yigin *next;
};
typedef struct yigin stack;
stack *us = NULL;



struct dugum{
	int sira;
    char* renk;
	struct dugum *sonraki;
};
typedef struct dugum dairesel_ty_bliste;
dairesel_ty_bliste *bas = NULL;


typedef struct Bliste balon_listesi;


char ch_arr[6][10] = {
    "kirmizi",
    "turuncu",
    "sari",
    "yesil",
    "mavi",
    "mor"
    };
    

    void listele_stack();

int main ()
{
    int m;
    printf("int bir değer giriniz: ");
    scanf("%d", &m);

    int dizi[10] = {1,2,3,4,5,6,7,8,9,10};
    

    //listele(bas);
    ekle(bas,dizi,m);
    printf("asdasd");
    listele_stack();


}
                                        

void listele(dairesel_ty_bliste *ilk){
	dairesel_ty_bliste *temp = ilk;
	if(ilk == NULL){
		printf("Listede eleman yok\n");
		return;
	}
	do{
		printf("%d", temp -> sira);
        printf("  %s\n", temp -> renk);
		temp = temp -> sonraki;
	}while(temp != ilk);
}

void ekle(dairesel_ty_bliste* liste,int dizi[], int N){

    int i;
    srand(time(0));
	dairesel_ty_bliste *yeni;
	dairesel_ty_bliste *eski;
	if(N == 0){
		bas = NULL;
	}
	for(i = 0; i < N; i++){
		yeni = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
		if(i == 0){
			bas = yeni;
			yeni -> sira = dizi[i];
            yeni -> renk = ch_arr[rand()%6];
			yeni -> sonraki = bas;
		}
		else{
			yeni -> sira = dizi[i];
            yeni -> renk =  ch_arr[rand()%6];
			eski -> sonraki = yeni;
			yeni -> sonraki = bas;
		}
		eski = yeni;		
	}

	stack *new;
	new = (stack*)malloc(sizeof(stack));
    new = bas;
	if(us == NULL)
		new -> next = NULL;
	else
		new -> next = us;
	us = new;
}

void listele_stack(){
	stack *temp = us;
	while(temp != NULL){
		printf("%c ", temp -> us);
		temp = temp -> next;
	}
	printf("\n");
}