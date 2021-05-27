#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#define BUF_LEN 256

int kontrol(char *b){
	
	int u,i=0,sonuc=1;
	char *b1;
	b1=b;
	u=strlen(b);
	while(i<u)
	{
	 if(isdigit(*b)==0)   //Girilen karakterin say� olup olmad��� kontrol edilip say� ise 1 de�ilse 0 de�eri veriliyor
	{
	sonuc=0;
	break;
	}
	i++;
	b++;
	}
	return sonuc;

}

void calisanekle(int b){
	int i=0;
	char *p;
	int k=0;
	p=(char*)malloc((sizeof(char)*40)*5); //  Bu fonksiyon i�erisinde �al��an bilgilerini i�erisinde depolayacak bir pointer dizi olu�turuyoruz

	printf("**Isim :");
	 scanf("%s",p);    // Burada kullan�c�dan scanf komutu ile ald���m�z �al��an bilgilerini p dizimize kaydediyoruz
	printf("**Soyisim :");
	 scanf("%s",p+20);
	printf("**Cinsiyet :");
	 scanf("%s",p+40);
	printf("**Departman :");
	 scanf("%s",p+60);
    printf("**Vardiya (Gece/Gunduz) :"); 
	 scanf("%s",p+80);

    printf("\n\n");

    system("cls");	//Ekran� temizliyoruz

	FILE *fabrika;    // Burada FILE komutu ile dosya i�lemlerinde kullan�ca��m�z� belitti�imiz bir dosya pointeri a��yoruz

	if((fabrika=fopen("calisanbilgileri.txt","a"))!=0) // calisanbilgileri.txt dosyam�z�  ekleme yapmak i�in a modu ile a��yoruz
	{

   printf("\n\t%s\t%s\t%s\t%s\t%s\n",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),strupr(p+80)); // Kaydedilen �al��an adlar�n� burada listeliyoruz
   fprintf(fabrika,"%d\t%s\t%s\t%s\t%s\t%s\n",b+1,strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),strupr(p+80)); // �al��an bilgilerini dosyam�za yaz�yoruz

   printf("\n\n\t** Calisan Basarili Bir Sekilde Eklendi. **");
	}
	
	else printf("Dosya Bulunamadi.");
	free(p);		//p de�i�keninin de�er atamas�n�n silinmesi 
   fflush(fabrika);
   fclose(fabrika);
}

int calisanListele(int c){
	char *ad,*sad,*cins,*dep,secim[10];
	int *sira,i=0,b,sec,a=1;
    char *va;
	ad=(char*)malloc((sizeof(char)*20)*c); // Burada doyadan �eilecek verilerin depolanaca��  pointer diziler olu�turuyoruz.
	sad=(char*)malloc((sizeof(char)*20)*c);
	cins=(char*)malloc((sizeof(char)*20)*c);
	dep=(char*)malloc((sizeof(char)*20)*c);
    va=(char*)malloc((sizeof(char)*20)*c);
	sira=(int*)calloc(sizeof(int),c);
	FILE *fabrika;
	if((fabrika=fopen("calisanbilgileri.txt","r"))!=0)  // calisanbilgiler.txt dosyam�z� okuma modunda a��yoruz
	{
	while(!feof(fabrika)) // feof fonksiyonu ile a��lan dosyan�n sonuna gelinceye kadar pointer dizilerine verileri yaz�yoruz
	{

		fscanf(fabrika,"%d\t%s\t%s\t%s\t%s\t%s\t\n",(sira+i),(ad+i*20),(sad+i*20),(cins+i*20),(dep+i*20),(va+i*20));

		i++;
		if((i+1)%20 == 1)
		{
		
			a++;
		}
	

	}
	fclose(fabrika); // ��lem bitince dosyam�z� kapat�yoruz
	}

	else printf("Dosya bulunamadi."); // E�er dosya yok ise uyar� vermesini istiyoruz
	
	i=0;
	b=1;
	
	printf("     ISIM \tSOYISIM \t CINSIYET \t DEPARTMAN \t VARDIYA \n");
	printf("     -----\t--------\t ---------\t ----------\t ---------\n");

	while(i<c) // Dosyadaki ki�i say�s� kadar d�nd�r�yoruz
	{
		if(i<b*20 && i<c)
		{

   		 printf("%d )  %-11s%-17s%-16s%-16s%s\t\n",*(sira+i),(ad+i*20),(sad+i*20),(cins+i*20),(dep+i*20),(va+i*20)); // �al��an bilgilerini ekrana yazd�r�yoruz

			i++;
			
			if(i==c)
			{

			printf("\n\t%d.Sayfadasiniz.\tToplam Sayfa :%d\n1-)Onceki Sayfa\t0-)Ana menu\n",b,a);
			printf("Secim Yap  :");

			scanf("%s",secim); // �al��an listeleme ekran�nda sayfalar aras�nda ge�i� yapmak i�in sayfa bilgisini al�yoruz
		
			while(kontrol(secim)==0)	
			{
		
			printf("Lutfen Gecerli Bir Deger Giriniz :");scanf("%s",secim);
			}
			sec=atoi(secim);	//Se�im de�i�kenini integer de�ere d�n��t�r�yoruz 
		
			while(b==1 && sec==1)
			{
		
				printf("Zaten Ilk Sayfadasiniz.Secim Yapiniz :");
				scanf("%s",secim);
				sec=atoi(secim);	
			}
			sec=atoi(secim);	

			while(atoi(secim)>1 || atoi(secim)<0 || kontrol(secim)==0){		//Se�im men�s�nde olmayan bir se�im yap�ld� m� kontrol ediliyor
			    printf("Yanlis Secim Yaptiniz :");
			    scanf("%s",secim);

			}
			sec=atoi(secim);
		
			system("cls");
        
		    	printf("    ISIM\tSOYISIM \t CINSIYET \t DEPARTMAN \t ISBASI SAATI \n");	//Listeleme ekran�n�n ba�l�klar�n�n olu�turulmas� 
				printf("    -----\t--------\t ---------\t ----------\t -------------\n");
		
			switch(sec)
			{
				case 1 : 
				b--;
                i=(b-1)*20;
				break;
				
				case 0 : 
				system("cls");
				printf("Devam Etmek Icin Bir Tusa Basin.");
				 break;
			}
		}

		}
		else
		{
			
		printf("\t%d.Sayfadasiniz.\tToplam Sayfa :%d\n1-)Onceki Sayfa\t2-)Sonraki Sayfa\t 0-)Ana Menu\n",b,a); //Listelemenin sonunda bulunan sayfa bilgisi ve se�im elemanlar�n�n olu�turulmas�
		printf("Secim Yap  :");
		scanf("%s",secim);
		sec=atoi(secim);
	
		while( (b==1 && sec==1) || sec<0 || sec>2 || kontrol(secim)==0){	//Yap�lan se�im men� tu�lar�nda yer al�yor mu kontrol�n�n yap�lmas� 

			if(sec==1)
			{
				printf("\nZaten Ylk Sayfadasiniz.Secim Yapiniz :\n");
				while(atoi(secim)==1 || kontrol(secim)==0){
				scanf("%s",secim);
				}
			}
			else { printf("Yanlis Secim Yaptiniz.Lutfen Tekrar Deneyiniz.");
			while(kontrol(secim)==0 || atoi(secim)>2 || atoi(secim)<0) {
			scanf("%s",secim);
			}
			}
        sec=atoi(secim);
		}
	
		if(sec==0){
		printf("Devam Etmek Icin Bir Tusaa Basin.");
		break;	//Ana men�ye d�n���n yap�lmas� 
		}
	
		system("cls");
    
	    	printf("    ISIM\tSOYISIM \t CINSIYET \t DEPARTMAN \t ISBASI SAATI \n");
			printf("    -----\t--------\t ---------\t ----------\t -------------\n");
	
		switch(sec)
		{
			case 2 :
			 b++;
			break;
			
			case 1 :
			 b--;
			break;
			
		}
		
		i=(b-1)*20;
		
		}
	}
	free(ad);		//De�i�kenlerin de�er bo�altmas� yap�lmas� 
	free(sad);
	free(cins);
	free(dep);
	free(va);
	free(sira);
}

void calisansil(int b){

	char *ad,*sa,*ci,*de,sil[10],*sira;
	int silinen,i=0,j=0,eleman;
	char *va;
	ad=(char*)malloc((sizeof(char)*20*4)*b);	//De�erlerin yer ald��� bellek yerlerinin ayarlanmas�
	sa=(char*)malloc((sizeof(char)*20*4)*b);
	ci=(char*)malloc((sizeof(char)*20*4)*b);
	de=(char*)malloc((sizeof(char)*20*4)*b);
	sira=(char*)malloc((sizeof(char)*20*4)*b);
	va=(char*)malloc((sizeof(char)*20*4)*b);
	
	int k;
	
	printf("\n\t*****************************************\n");	//Men� olu�turulmas� 
	printf("\t***                                  ****\n");
	printf("\t***       0 -) ANA MENU              ****\n");
	printf("\t***                                  ****\n");
	printf("\t*****************************************\n");
	printf("\t***                                  ****\n");
	printf("\t***  Silinecek Calisan Numarasi  :  ");
	scanf("%s",sil);
	
	while(kontrol(sil)==0 || atoi(sil)<0 ||atoi(sil)>b)	// Girilen de�erde �al��an var m� kontrol� yap�lmas� 
	{
	
	printf("Lutfen Gecerli Bir Calisan Numarasi Giriniz  :");
	scanf("%s",sil);
	}
	silinen=atoi(sil);
	
	if(silinen!=0){

	FILE *fabrika;
	
	if((fabrika=fopen("calisanbilgileri.txt","r"))!=0){

	while(!feof(fabrika)){

	fscanf(fabrika,"%d\t%s\t%s\t%s\t%s\t\t%s\n",(sira+i),(ad+i*20),(sa+i*20),(ci+i*20),(de+i*20),(va+i*20));	//Dosyadan verilerin al�nmas�
	i++;
	}
	
	fclose(fabrika);
	
	i=0;
	if((fabrika=fopen("calisanbilgileri.txt","w"))!=0)	
	{

	while(i<b)
	{
		
	while((i+1)!=silinen && i<b)
	{
		
	fprintf(fabrika,"%d\t%s\t%s\t%s\t%s\t\t%s\n",*(sira+j),(ad+i*20),(sa+i*20),(ci+i*20),(de+i*20),(va+i*20));	//Silinen �al��an�n yerine sonraki �al��an yaz�larak de�i�tirilmesi 
	i++;
	j++;
	}
	
	i++;
	}

	printf("\n%d.Calisan Silindi.Devam Etmek Icin Bir Tusa Basin.\n",silinen);	//Ka��nc� �al��an�n silindi�i bilgisi
    fflush(fabrika);
	fclose(fabrika);
	}
	else{
	
	 printf("(2)dosya acilamadi.");
	}
	
	}
	else {
	
	printf("(1)dosya acilamadi.");
	}
	
	}
	else{
    
	system("cls");
	
	printf("\nSilme Islemi Iptal Edildi.Devam Etmek Icin Bir Tusa Basin.");		//Dosya a��lamaz ise silme i�leminin iptal edilmesi 
    }
	
	free(ad);
	free(sa);
	free(ci);
	free(de);
	free(va);
	free(sira);
}

void secenekler(){
    char buf[BUF_LEN] = {0};

    time_t rawtime = time(NULL); // Tarih ve Saat �zelli�i i�in time.h k�t�phanesi ile �al��an fonksion

    if (rawtime == -1) {
        puts("The time() function failed");
    }
    struct tm *ptm = localtime(&rawtime);		//Program�n �al��t�r�ld��� b�lgeye g�re zaman diliminin ayarlanmas�

    if (ptm == NULL) {
        puts("The localtime() function failed");
    }
    puts(buf);
    printf("\n\n\n\n");
	printf("\n\t\t\t************************************************************\n");
	memset(buf, 0, BUF_LEN);
	strftime(buf, BUF_LEN, "\t\t\t***\t\t\t\t       Tarih: %d.%m.%Y ***", ptm); 
	 puts(buf);  // Tarihin ekrana yaz�lmas�
	strftime(buf, BUF_LEN, "\t\t\t***\t\t\t\t          Saat: %X ***", ptm);
	 puts(buf); // Saatin ekrana yaz�lmas�
	printf("\t\t\t***\t\t       FABRIKA-DEPO                \t ***\n");
    printf("\t\t\t***\t\t        OTOMASYONU                 \t ***\n");
    printf("\t\t\t***                                   \t\t\t ***\n");
	printf("\t\t\t***\t       1-) Kisi Ekle               \t\t ***\n");
    printf("\t\t\t***\t                                    \t\t ***\n");
	printf("\t\t\t***\t       2-) Kisi Sil                \t\t ***\n");
    printf("\t\t\t***\t                                    \t\t ***\n");
	printf("\t\t\t***\t       3-) Kisileri Listele        \t\t ***\n");		//Men� tu�lar�n�n olu�turulmas� 
    printf("\t\t\t***\t                                    \t\t ***\n");
    printf("\t\t\t***\t       4-) Urun Ekle               \t\t ***\n");
	printf("\t\t\t***\t                                    \t\t ***\n");
	printf("\t\t\t***\t       5-) Urun Sil                \t\t ***\n");
    printf("\t\t\t***\t                                    \t\t ***\n");
	printf("\t\t\t***\t       6-) Urun Listele            \t\t ***\n");
    printf("\t\t\t***\t                                    \t\t ***\n");
	printf("\t\t\t***\t       0-) Cikis                   \t\t ***\n");
	printf("\t\t\t***\t                                   \t\t ***\n");
	printf("\t\t\t************************************************************\n");
	printf("\t\t        Lutfen Secim Yapiniz  :  ");
}

void stokekle(int b){
    int i=0,u;
	char *p,*c;
	float *asb;
	p=(char*)malloc((sizeof(char)*20)*4);
	c=(char*)malloc((sizeof(char)*20)*3);
	asb=(float*)calloc(sizeof(float),3);

	printf("**Marka :"); 
	 scanf("%s",p);
	printf("**Seri No :"); 
	 scanf("%s",p+20);
	printf("**Model :"); 
	 scanf("%s",p+40);
	printf("**Renk :"); 
	 scanf("%s",p+60);
	printf("**Fiyat :"); 
	 scanf("%s",c);

    while(kontrol(c)==0){	//Girilen de�erin say� olup olmad���n�n kontrol�
     
	    printf("\t* Lutfen Gecerli Deger Giriniz :");
        scanf("%s",c);
    }

	*(asb)=atof(c);		//Float de�ere d�nd�r�lmesi 

	FILE *depo;

	if((depo=fopen("stokbilgileri.txt","a"))!=0)		//Dosyan�n ekleme modunda a��lmas�
	{

      printf("\n\t%s\t%s\t%s\t%s\t%.f\tTL",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb));			//Eklenen �r�n�n bilgilerinin ekrana yaz�lmas�
      fprintf(depo,"%d\t%s\t%s\t%s\t%s\t%f\t\n",b+1,strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb));	//Eklenen �r�n�n bilgilerinin dosyaya yaaz�lmas�
	  fflush(depo);
	  fclose(depo);
	  printf("\n\n\t** Urun Basarili Bir Sekilde Eklendi. **");
	}
	else
	{
	
	printf("Dosya Bulunamadi.");		//Dosya a��lamad�ysa verilen hata kodu
	}  
	
	free(p);
	free(c);
	free(asb);
}

void stoksil(int a){

	char *ma,*se,*mo,*re,sil[10];
	float *fiyat;
	int silinen,i=0,j=0,eleman,*sira;
	ma=(char*)malloc((sizeof(char)*20*4)*a);
	se=(char*)malloc((sizeof(char)*20*4)*a);
	mo=(char*)malloc((sizeof(char)*20*4)*a);
	re=(char*)malloc((sizeof(char)*20*4)*a);
	sira=(int*)calloc(sizeof(int),a);
	fiyat=(float*)calloc(sizeof(float),3*a);
		
	
	printf("\n\t*****************************************\n");
	printf("\t***                                  ****\n");
	printf("\t***       0 -) ANA MENU              ****\n");
	printf("\t***                                  ****\n");
	printf("\t*****************************************\n");
	printf("\t***                                  ****\n");
	printf("\t***  Silinecek Urun Numarasi  :  ");
	scanf("%s",sil);
	
	while(kontrol(sil)==0 || atoi(sil)<0 ||atoi(sil)>a)		//Girilen de�erde �r�n var m� kontrol� yap�lmas� 
	{
	
	printf("Lutfen Gecerli Bir Urun Numarasi Giriniz  :");
	 scanf("%s",sil);
	
	}
	silinen=atoi(sil);
	
	if(silinen!=0){

	FILE *depo;
	
	if((depo=fopen("stokbilgileri.txt","r"))!=0){

	while(!feof(depo)){

	fscanf(depo,"%d\t%s\t%s\t%s\t%s\t%f\t\n",(sira+i),(ma+i*20),(se+i*20),(mo+i*20),(re+i*20),(fiyat+i));		//Verilerin dosyadan al�nmas�

	i++;
	}

	fclose(depo);

	i=0;
	if((depo=fopen("stokbilgileri.txt","w"))!=0)
	{

	while(i<a)
	{

	while((i+1)!=silinen && i<a)
	{
	
	fprintf(depo,"%d\t%s\t%s\t%s\t%s\t%f\t\n",*(sira+j),(ma+i*20),(se+i*20),(mo+i*20),(re+i*20),*(fiyat+i));	//Verilerin silinen �r�n�n �zerine yaz�lacak �ekilde kayd�r�lmas�
	i++;
	j++;
	}
	i++;

	}

	printf("\n%d.Urun Silindi.Devam Etmek Icin Bir Tusa Basin.\n",silinen);		//Ka��nc� �r�n�n silindi�i bilgisi
    fflush(depo);
	fclose(depo);
	}
	else {
		
	printf("(2)dosya acilamadi.");
	}
	}
	else{
	printf("(1)dosya acilamadi.");
	} 
	
	}
	else{
    
	system("cls");
	printf("\nSilme Islemi Iptal Edildi.Devam Etmek Icin Bir Tusa Basin.");		//Dosya a��lamaz ise silme i�leminin iptal edilmesi 
    
	}
	
	free(ma);
	free(se);
	free(mo);
	free(re);
	free(fiyat);
	free(sira);
}

int stokbilgileri(int c){
	char *marka,*seri,*model,*renk,secim[10];
	int *sira,i=0,b,sec,a=1;
	float *fiyat;

	marka=(char*)malloc((sizeof(char)*20)*c);
	seri=(char*)malloc((sizeof(char)*20)*c);
	model=(char*)malloc((sizeof(char)*20)*c);
	renk=(char*)malloc((sizeof(char)*20)*c);
	fiyat=(float*)calloc(sizeof(float),c);
	sira=(int*)calloc(sizeof(int),c);
	
	FILE *depo;
	
	if((depo=fopen("stokbilgileri.txt","r"))!=0)	//Okuma modunda dosyan�n a��lmas�
	{
	
	while(!feof(depo))
	{

		fscanf(depo,"%d\t%s\t%s\t%s\t%s\t%f\t\n",(sira+i),(marka+i*20),(seri+i*20),(model+i*20),(renk+i*20),(fiyat+i));		//Verilerin dosyadan al�nmas� 
		i++;
		if((i+1)%20==1)
		a++;

	}	fclose(depo);
	}
	else{
		
		printf("Dosya bulunamadi.");
	} 
	
	i=0;
	b=1;
	
	printf("     MARKA\t  SERI NO       MODEL\t    RENK\t     FIYAT\t\n");		//Ba�l�klar�n olu�turulmas�
	printf("     -----\t  --------      -----\t    ----\t     -----\t\n");
	
	while(i<c)
	{

		if(i<b*20 && i<c)
		{
			printf("%d )  %-13s%-14s%-12s%-17s%-7.f\tTL\n",*(sira+i),(marka+i*20),(seri+i*20),(model+i*20),(renk+i*20),*(fiyat+i));		//�r�nlerin s�ra ile yaz�lmas�

			i++;
	
			if(i==c)
			{

			printf("\n\t%d.Sayfadasiniz.\tToplam Sayfa :%d\n1-)Onceki Sayfa\t0-)Ana menu\n",b,a);
			printf("Secim Yap  :");
			scanf("%s",secim);
	
			while(kontrol(secim)==0){
    
	                printf("Lutfen Gecerli Bir Deger Giriniz :");
                    scanf("%s",secim);
			}
			sec=atoi(secim);
	
			while(b==1 && sec==1){
				printf("Zaten Ilk Sayfadasiniz.Secim Yapiniz :");
				scanf("%s",secim);
				sec=atoi(secim);
			}
			sec=atoi(secim);
	
			while(atoi(secim)>1 || atoi(secim)<0 || kontrol(secim)==0){
			    printf("Yanlis Secim Yaptiniz :");
			    scanf("%s",secim);
			}
			sec=atoi(secim);
	
			system("cls");
	
		printf("   MARKA\tSERI NO       MODEL\t    RENK\t     FIYAT\t\n");
		printf("   -----\t--------      -----\t    ----\t     -----\t\n");
			switch(sec)
			{
				case 1 :
				 b--; 
				i=(b-1)*20;
                 break;
	
				case 0 : 
				system("cls");
				printf("Devam Etmek Icin Bir Tusa Basin.");
				 break;
			}
		}
		}
	
		else
		{
		printf("\t%d.Sayfadasiniz.\t Toplam Sayfa :%d\n 1-)Onceki Sayfa\t 2-)Sonraki Sayfa\t 0-)Ana Menu\n",b,a);	//Men� tu�lar�n�n olu�turulmas�
		printf("Secim Yap  :");
		scanf("%s",secim);
		sec=atoi(secim);
	
		while( (b==1 && sec==1) || sec<0 || sec>2 || kontrol(secim)==0){

			if(sec==1){
				printf("\nZaten Ylk Sayfadasiniz.Secim Yapiniz :\n");
	
				while(atoi(secim)==1 || kontrol(secim)==0){
				scanf("%s",secim);};
			}

			else {
                printf("Yanlis Secim Yaptiniz.Lutfen Tekrar Deneyiniz.");
    
	        while(kontrol(secim)==0 || atoi(secim)>2 || atoi(secim)<0) {
                scanf("%s",secim);
				}
			}
        sec=atoi(secim);
		}

		if(sec==0){
            printf("Devam Etmek Icin Bir Tusa Basin.");
            break;
		}
		system("cls");
		printf("   MARKA\tSERI NO       MODEL\t    RENK\t     FIYAT\t\n");
		printf("   -----\t--------      -----\t    ----\t     -----\t\n");
	
		switch(sec){
			case 2 : 
			b++;
             break;
	
			case 1 : 
			b--;
			 break;
		}
		
		i=(b-1)*20;
		}
	}
	
	free(marka);
	free(seri);
	free(model);
	free(renk);
	free(sira);
	free(fiyat);


}

int hesapla(){
 char *bilgi;
 float *sbilgi;
 int *sira ,i=1;

 bilgi=(char*)malloc((sizeof(char)*20)*4);
 sbilgi=(float*)calloc((sizeof(float)*3),1);
 sira=(int*)calloc(sizeof(int),1);
 FILE *fabrika;

if((fabrika=fopen("calisanbilgileri.txt","r"))!=0)
 {

 while(!feof(fabrika)){											//Dosyadaki toplam veri say�s�n� hesaplama

	bilgi=(char*)realloc(bilgi,(sizeof(char)*20*4)*i);
	sira=(int*)realloc(sira,(sizeof(int)*i));

	fscanf(fabrika,"%d\t%s\t%s\t%s\t%s\t\t%s\n",sira,bilgi,bilgi+20,bilgi+40,bilgi+60,bilgi+80);		//Verilerin toplanmas�

	i++;
}

}
else {
	
        printf("Sayac dosyasi acilamadi.Lutfen programi yeniden baslatiniz.(1)\n\n\n");
}

fflush(fabrika);
fclose(fabrika);
free(bilgi);

return *sira;

free(sira);
fflush(fabrika);
}

int depohesapla(){
 char *bilgi;
 float *sbilgi;
 int *sira, i=1;

 bilgi=(char*)malloc((sizeof(char)*20)*4);
 sbilgi=(float*)calloc((sizeof(float)*3),1);
 sira=(int*)calloc(sizeof(int),1);
 FILE *depo;

 if((depo=fopen("stokbilgileri.txt","r"))!=0)
 {

 while(!feof(depo)){											//Dosyadaki toplam veri say�s�n� hesaplama

	bilgi=(char*)realloc(bilgi,(sizeof(char)*20*4)*i);
	sira=(int*)realloc(sira,(sizeof(int)*i));

	fscanf(depo,"%d\t%s\t%s\t%s\t%s\t%f\t\n",sira,bilgi,bilgi+20,bilgi+40,bilgi+60, sbilgi);	//Verilerin toplanmas�
	i++;
}
}
else{
        printf("Sayac dosyasi acilamadi. Lutfen programi yeniden baslatiniz.(2)\n\n\n");
}
fflush(depo);
fclose(depo);
free(bilgi);

return *sira;

free(sira);
fflush(depo);
}

int main(){
	system("COLOR 8B");		//Arkaplan ve metin renginin ayarlanmas�
	
	int secim=1, b, d, secim1;
	char s[10],s1[10];

	FILE *depo;

	FILE *fabrika;

	if((depo=fopen("stokbilgileri.txt","a"))!=0){		//Dosya yoksa eklemek varsa verileri silmeden i�leme devam etmesi i�in a modunda a��l�yor 
		
  fclose(depo);
} 

else{
    printf("Dosya yok");
}

if((fabrika=fopen("calisanbilgileri.txt","a"))!=0){		//Dosya yoksa eklemek varsa verileri silmeden i�leme devam etmesi i�in a modunda a��l�yor 
	
  fclose(fabrika);
} 
else{

    printf("Dosya yok");
}
	while(secim!=0){

    system("cls");

	while(secim!=0)
	{
	b = hesapla();
    d = depohesapla();
	system("cls");
    secenekler();
	scanf("%s",s);

	while(kontrol(s)==0 || (0>atoi(s) || atoi(s)>6)){		//Men� ekran�ndaki se�eneklerden birinin se�ilip se�ilmedi�inin kontrol edilmesi
            printf("\nLutfen Dogru Bir Deger giriniz :");
            scanf("%s",s);
             }

             printf("\n\n");
	secim=atoi(s);
    system("cls");

	if(secim==1)		//1. se�enek se�ildiyse �al��an ekleme fonksiyonunun �a��r�lmas�
	{
		calisanekle(b);		
		getch();
		break;
	}

	else if(secim==2)  //2. se�enek se�ildiyse �al��an silme fonksiyonunun �a��r�lmas�
	{
		if(b==0)
		{
			printf("Kayitli Calisan Bulunamadi.");
		getch();
		}

		else{

		calisansil(b);	
		}
		break;
	}

	else if(secim==3)	//3. se�enek se�ildiyse �al��an listeleme fonksiyonunun �a��r�lmas�
	{
		if(b==0)
		{

			printf("Kayitli Calisan Bulunamadi.");
			getch();
		}
		else {

		calisanListele(b);
		}
		 getch();
		break;
	}
	else if(secim==4)	//4. se�enek se�ildiyse stok ekleme fonksiyonunun �a��r�lmas�
	{

		stokekle(d);
        getch();
		break;
	}
	else if(secim==5)	//5. se�enek se�ildiyse stok silme fonksiyonunun �a��r�lmas�
	{
		if(d==0)
		{

			printf("Kayitli Urun Bulunamadi.");

		}
		else{

		stoksil(d);
		}
		getch();
		break;
	}
	else if(secim==6)	//6. se�enek se�ildiyse stok listeleme fonksiyonunun �a��r�lmas�
	{
	
		if(d==0){
			printf("Kayitli Urun Bulunamadi.");

		}
		else{

		stokbilgileri(d);
		}
		getch();
		break;
	}
	else break;
}
}
return 1;
	getch();
}
