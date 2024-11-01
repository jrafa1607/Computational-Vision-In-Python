#include <proeikon>
#include <imgpv>
#include <string.h>
//#define BYTE unsigned char
//#define WORD unsigned int
//#define DWORD unsigned long

struct cab{
   char     tipo[2];
}assinatura;


struct cab1{
   DWORD	tamanho_imagem;
   short    reservado1;
   short 	reservado2;
   DWORD	inicio_dados_imagem;
}cab_arq;


struct cab2{
   long		tamanho_do_cabecalho_da_imagem;
   DWORD	largura;
   DWORD	altura;
   short	planos;
   short	bits_por_ponto;
   DWORD	tipo_de_compressao;
   DWORD	tamanho_da_imagem_comprimida;
   DWORD	resolucao_horizontal;
   DWORD	resolucao_vertical;
   DWORD	numero_maximo_de_cores;
   DWORD	numero_de_cores_usadas;
}cab_mapa_bits;

struct cab3{
   BYTE blue;
   BYTE green;
   BYTE red;
   BYTE reserv;
}paleta[256];

struct cab4{
   BYTE blue;
   BYTE green;
   BYTE red;
}pixel24b;


int main(int argc, char** argv){
    FILE *fp;
    long int i, qtd_cores, rdiv4=0;
    BYTE pixel, pix1, pix2, pix3, pix4, pix5, pix6, pix7, pix8;
    char nome_img[255]="\0";
  
    //monta o nome da imagem
    strcpy(nome_img,argv[1]);

	system("cls");
	if( (fp=fopen(nome_img,"rb+"))==NULL){
		 printf("O arquivo de imagem %s nao pode ser lido\n", nome_img);
	     exit(1);
	 }
	
	
	 printf("\nCabecalho do arquivo");
     fread(&assinatura, sizeof (struct cab), 1, fp);
     
	 if(strcmp(assinatura.tipo,"BM")!=0){
	 	printf("\nAssinatura nao confere!");
	 	exit(1);
	 }
	 
	 printf("\nTipo            : %c%c", assinatura.tipo[0],assinatura.tipo[1]);
	
	
	 fread(&cab_arq, sizeof (struct cab1), 1, fp);
	 printf("\nTamanho arquivo : %ld", sizeof (cab_arq.tamanho_imagem));
	 printf("\nReservado 1     : %d", sizeof (cab_arq.reservado1));
	 printf("\nReservado 2     : %d", sizeof (cab_arq.reservado2));
	 printf("\nInicio Dados    : %ld", sizeof (cab_arq.inicio_dados_imagem));
	 printf("\nTamanho do cabec: %d", sizeof (struct cab)+sizeof (struct cab1));
	
	 printf("\n\nCabecalho de mapa de bits");
	 fread(&cab_mapa_bits, sizeof (struct cab2), 1, fp);
	 printf("\nTamanho cabecalho : %ld", cab_mapa_bits.tamanho_do_cabecalho_da_imagem);
	 printf("\nLargura da Imagem : %ld", cab_mapa_bits.largura);
	 printf("\nAltura da Imagem  : %ld", cab_mapa_bits.altura);
	 printf("\nN§ de Planos      : %d" , cab_mapa_bits.planos);
	 printf("\nBits por Pixel    : %d" , cab_mapa_bits.bits_por_ponto);
	 printf("\nCompressao Usada  : %ld", cab_mapa_bits.tipo_de_compressao);
	 printf("\nTamanho Img(dados): %ld", cab_mapa_bits.tamanho_da_imagem_comprimida);
	 printf("\nResolucao Horiz.  : %ld", cab_mapa_bits.resolucao_horizontal);
	 printf("\nResolucao Vertical: %ld", cab_mapa_bits.resolucao_vertical);
	 printf("\nN§ Cores Usadas   : %ld", cab_mapa_bits.numero_maximo_de_cores);
	 printf("\nN§ Cores Important: %ld", cab_mapa_bits.numero_de_cores_usadas);
	
	
	 rdiv4=cab_mapa_bits.largura%4;
	 printf("\nResto da Div.por 4 : %d", rdiv4);
	
	 if(rdiv4>2)rdiv4-=2;
	
	// getchar();
	
	 qtd_cores=(int)pow(2,cab_mapa_bits.bits_por_ponto);
	
	//Lê Paleta de cores, se houver
	 printf("\n\nPaleta de Cores");
	 if(qtd_cores <= 256 && cab_arq.inicio_dados_imagem>54){
	   for(i=0;i<qtd_cores;i++){
	      fread(&paleta[i], sizeof (struct cab3), 1, fp);
	      printf("\nCor %3d: %3d %3d %3d %3d",i,paleta[i].red, paleta[i].green, paleta[i].blue, paleta[i].reserv);
	   }
	 }
	  
	
	//Lê Mapa de bits para exibir a imagem na tela gráfica
	IMGCOR img(cab_mapa_bits.altura, cab_mapa_bits.largura);
	
	//Se for imagem binária (1 bit por pixel)
	if(qtd_cores==2){
	   for(int l=cab_mapa_bits.altura; l>0; l--){
		for(int c=0; c<int(cab_mapa_bits.largura) ; c+=8){
	        fread(&pixel, sizeof(BYTE), 1, fp);
			pix1=(pixel>>7)%2; img(l,c)=COR(paleta[pix1].red,paleta[pix1].green,paleta[pix1].blue);
	        pix2=(pixel>>6)%2; img(l,c+1)=COR(paleta[pix2].red,paleta[pix2].green,paleta[pix2].blue);
			pix3=(pixel>>5)%2; img(l,c+2)=COR(paleta[pix3].red,paleta[pix3].green,paleta[pix3].blue);
			pix4=(pixel>>4)%2; img(l,c+3)=COR(paleta[pix4].red,paleta[pix4].green,paleta[pix4].blue);
			pix5=(pixel>>3)%2; img(l,c+4)=COR(paleta[pix5].red,paleta[pix5].green,paleta[pix5].blue);
			pix6=(pixel>>2)%2; img(l,c+5)=COR(paleta[pix6].red,paleta[pix6].green,paleta[pix6].blue);
			pix7=(pixel>>1)%2; img(l,c+6)=COR(paleta[pix7].red,paleta[pix7].green,paleta[pix7].blue);
			pix8=pixel%2     ; img(l,c+7)=COR(paleta[pix8].red,paleta[pix8].green,paleta[pix8].blue);
		}
	    
		if(rdiv4>0){
		  if(rdiv4%2==0 ) fread(&pixel, sizeof(BYTE), rdiv4+1, fp);
		  else fread(&pixel, sizeof(BYTE), rdiv4-1, fp);
		}
	   }
	 }
	 //Se for imagem de 16 cores (4 bits por pixel)
	 else if(qtd_cores==16){
	   for(int l=cab_mapa_bits.altura; l>0; l--){
		for(int c=0; c<int(cab_mapa_bits.largura)+ rdiv4 ; c+=2){
	        fread(&pixel, sizeof(BYTE), 1, fp);
			pix1=pixel>>4;
	        img(l,c)=COR(paleta[pix1].red,paleta[pix1].green,paleta[pix1].blue);
			pix2=pixel & 15;
	        img(l,c+1)=COR(paleta[pix2].red,paleta[pix2].green,paleta[pix2].blue);
		}
	   }
	 }
	 //Se for imagem de 256 cores  (8 bits por pixel)
	 else if(qtd_cores==256){
	     for(int l=cab_mapa_bits.altura; l>0; l--){
		  for(int c=0; c<int(cab_mapa_bits.largura) + rdiv4; c++){
	        fread(&pixel, sizeof(BYTE), 1, fp);
	        img(l,c)=COR(paleta[pixel].red,paleta[pixel].green,paleta[pixel].blue);
		  }
		 }
	 }
	 //Se for imagem de 16 milhoes de cores (24 bits por pixel)
	 else{
	     for(int l=cab_mapa_bits.altura; l>0; l--){
		  for(int c=0; c<int(cab_mapa_bits.largura) + rdiv4; c++){
	        fread(&pixel24b, sizeof(cab4), 1, fp);
			img(l,c)=COR(pixel24b.red,pixel24b.green,pixel24b.blue);
		  }
		 }
	 
	 }
	
	pvMostra(img,1,argv[1]);

   return 0;
}
