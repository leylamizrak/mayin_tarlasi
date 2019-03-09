#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/**Mayýn tarlasý oyunu:
•	En az 10 x 10’luk bir mayýn tarlasý oyunu tasarlayýnýz.+
•	Bu oyun kolay, orta ve zor olmak üzere 3 seviyeden oluþacak. Kolay için 10 mayýn, orta için 25
mayýn, zor için de 40 mayýn olacak.+
•	Oyuna baþlamadan önce oyuncu istediði seviyeyi seçebilecek.+
•	Bu oyun için mayýnlar kutulara rastgele bir þekilde yerleþecek.+
•	Oyuna her yeni baþlandýðýnda mayýnlar baþka bir þekilde yine rastgele yerleþecek.+
•	Her oyun bitiminde tekrar oynamak isteyip istemediðini sorsun. Oyuncu tekrar oynamak isterse en
baþtaki gibi önce hangi seviyede oynamak istediðini sorsun.+
•	Mayýn tarlasýnýn satýrlarý için sayý, sütunlarý için de harf veriniz. Fare kullanýlmadýðý için
bir kutu seçilmek istendiðinde satýr ve sütun belirtilecek. Mesela 1a, 4d gibi.+
•	Her yeni iþlemde ekran eski bilgiyi temizlemeli */

void kolay_seviye();
void orta_seviye();
void zor_seviye();

int main()
{
    int secim;

    printf("Mayin Tarlasi Oyununa Hosgeldiniz.\n");

    printf("\nOyun kolay,orta ve zor seviyeden olusmaktadir.\n");
    printf("\nKolay seviye icin 1\nOrta seviye icin 2\nZor seviye icin 3\nseciniz:");
    scanf("%d",&secim);
    fflush(stdin);

    char tekrar;

    while(1)
    {

        while(1)
        {
            //system("cls");
            switch (secim)
            {
            case 1:
                printf("KOLAY SEVIYE\n");
                kolay_seviye();
                break;
            case 2:
                printf("ORTA SEVIYE\n");
                orta_seviye();
                break;
            case 3:
                printf("ZOR SEVIYE\n");
                zor_seviye();
                break;
            default:
                printf("Yanlis secim.\nTekrar giriniz.\n");
            }
            if(secim!=1&&secim!=2&&secim!=3)
            {
                printf("Kolay seviye icin 1\nOrta seviye icin 2\nZor seviye icin 3\nseciniz:");
                scanf("%d",&secim);
                fflush(stdin);
            }
            else break;
        }


        printf("Tekrar oynamak istiyor musunuz(e-E/h-H):");
        scanf("%c",&tekrar);
        fflush(stdin);

        if(tekrar!='e'&&tekrar!='E'&&tekrar!='h'&&tekrar!='H')
        {
            while(1)
            {
                system("cls");
                printf("Seciminizi tekrar yapin.\n");
                printf("Tekrar oynamak istiyor musunuz(e-E/h-H):");
                scanf("%c",&tekrar);
                fflush(stdin);

                if(tekrar=='E'||tekrar=='e'||tekrar=='h'||tekrar=='H')break;
            }
        }
        if(tekrar=='e'||tekrar=='E')
        {
            printf("Kolay seviye icin 1\nOrta seviye icin 2\nZor seviye icin 3\nseciniz:");
            scanf("%d",&secim);
            fflush(stdin);
        }
        else if(tekrar=='h'||tekrar=='H')
            break;

    }
    //system("cls");
    printf("PROGRAM SONA ERDI.\n");
    return 0;
}
void zor_seviye()
{
    srand(time(NULL));

    int dizi[10][10],i,j;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            dizi[i][j]=0;
            //printf("%d ",dizi[i][j]);
        }
        //printf("\n");
    }
    int sayac=0;

    int satir[40],sutun[40];
    int m=0;

    int r_satir=rand()%10,r_sutun=rand()%10;
    satir[0]=r_satir,sutun[0]=r_sutun;
    //printf("%d (%d,%d)\n",0,satir[0],sutun[0]);

    int say=0;

    while(1)
    {
        r_satir=rand()%10;
        r_sutun=rand()%10;

        say=0;

        for(j=0; j<=m; j++)
        {
            if(r_satir==satir[j]&&r_sutun==sutun[j])
                say++;
        }

        if(say==1)continue;
        else if(say==0)
        {
            m++;
            satir[m]=r_satir;
            sutun[m]=r_sutun;
            //  printf("%d (%d,%d)\n",m+1,satir[m],sutun[m]);
            sayac++;


        }
        if(sayac==39)break;

    }

//printf("\n");

    /**for(i=0; i<40; i++)
    {
        printf("(%d,%d)\n",satir[i],sutun[i]);
    }*/

    int k;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<40; k++)
            {
                if(satir[k]==i&&sutun[k]==j)
                    dizi[i][j]=1;
            }
        }
    }
    //printf("\n");
    /**for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
          printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }*/

    printf("\nMayin Tarlasi Ekrani:\n");
    printf(" ___a__b__c__d__e__f__g__h__i__j___\n");
    printf(" 1-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 2-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 3-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 4-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 5-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 6-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 7-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 8-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 9-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf("10-|__|__|__|__|__|__|__|__|__|__|_\n");

    printf("Girmek istediginiz kutu icin kutunun\nkoordinatlarini yazmalisiniz.(1a gibi)\n");

    int satir_sec,koordinat;
    char sutun_sec;
    sayac=0;

    int koordinat2;

    while(1)
    {

        printf("\nKutunun koordinatlarini girin:");
        scanf("%d%c",&satir_sec,&sutun_sec);
        fflush(stdin);
        //system("cls");

//printf("koordinat:%d\n",koordinat);


        while(1)
        {
            if(satir_sec>=1&&satir_sec<=10&&sutun_sec>='a'&&sutun_sec<='j')
                break;
            else
            {
                printf("Kutunun koordinatlarini tekrar girin\n");
                scanf("%d%c",&satir_sec,&sutun_sec);
                fflush(stdin);
                //system("cls");
            }
        }
        koordinat=sutun_sec-97;

        koordinat2=satir_sec-1;


        if(dizi[koordinat2][koordinat]==2)
        {
            printf("Bu kutu daha once secilmisti.\n");
        }

        else if(dizi[koordinat2][koordinat]!=1)
        {
            sayac++;
            printf("TEBRIKLER!!!\n");
            printf("Lutfen yeni kutu seciniz.\n");
            dizi[koordinat2][koordinat]=2;
        }
        else
        {
            if(sayac!=0)printf("Mayinli kutu.\nOyun %d adim sonra bitti.\n",sayac+1);
            else printf("Mayinli kutu.\nOyun bitti.\n");
            break;
        }

    }
}

void  orta_seviye()
{
    srand(time(NULL));

    int dizi[10][10],i,j;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            dizi[i][j]=0;
            //printf("%d ",dizi[i][j]);
        }
        //printf("\n");
    }
    int sayac=0;

    int satir[25],sutun[25];
    int m=0;

    int r_satir=rand()%10,r_sutun=rand()%10;
    satir[0]=r_satir,sutun[0]=r_sutun;
    //printf("(%d,%d)\n",satir[0],sutun[0]);

    int say=0;

    while(1)
    {
        r_satir=rand()%10;
        r_sutun=rand()%10;

        say=0;

        for(j=0; j<=m; j++)
        {
            if(r_satir==satir[j]&&r_sutun==sutun[j])
                say++;
        }

        if(say==1)continue;
        else if(say==0)
        {
            m++;
            satir[m]=r_satir;
            sutun[m]=r_sutun;
            //          printf("(%d,%d)\n",satir[m],sutun[m]);
            sayac++;


        }
        if(sayac==24)break;

    }

//printf("\n");

    for(i=0; i<25; i++)
    {
        //  printf("(%d,%d)\n",satir[i],sutun[i]);
    }

    int k;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<25; k++)
            {
                if(satir[k]==i&&sutun[k]==j)
                    dizi[i][j]=1;
            }
        }
    }
    //printf("\n");
    /**for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
          printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }*/

    printf("\nMayin Tarlasi Ekrani:\n");
    printf(" ___a__b__c__d__e__f__g__h__i__j___\n");
    printf(" 1-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 2-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 3-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 4-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 5-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 6-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 7-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 8-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 9-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf("10-|__|__|__|__|__|__|__|__|__|__|_\n");

    printf("Girmek istediginiz kutu icin kutunun\nkoordinatlarini yazmalisiniz.(1a gibi)\n");

    int satir_sec,koordinat;
    char sutun_sec;
    sayac=0;

    int koordinat2;

    while(1)
    {
        printf("\nKutunun koordinatlarini girin:");
        scanf("%d%c",&satir_sec,&sutun_sec);
        fflush(stdin);
        //system("cls");

        while(1)
        {
            if(satir_sec>=1&&satir_sec<=10&&sutun_sec>='a'&&sutun_sec<='j')
                break;
            else
            {
                printf("Kutunun koordinatlarini tekrar girin\n");
                scanf("%d%c",&satir_sec,&sutun_sec);
                fflush(stdin);
                //system("cls");
            }
        }

        koordinat=sutun_sec-97;
//printf("koordinat:%d\n",koordinat);

        koordinat2=satir_sec-1;

        if(dizi[koordinat2][koordinat]==2)
        {
            printf("Bu kutu daha once secilmisti.\n");
        }

        else if(dizi[koordinat2][koordinat]!=1)
        {
            sayac++;
            printf("TEBRIKLER!!!\n");
            printf("Lutfen yeni kutu seciniz.\n");
            dizi[koordinat2][koordinat]=2;
        }
        else
        {
            if(sayac!=0)printf("Mayinli kutu.\nOyun %d adim sonra bitti.\n",sayac+1);
            else printf("Mayinli kutu.\nOyun bitti.\n");
            break;
        }

    }
}
void kolay_seviye()
{
    srand(time(NULL));

    int dizi[10][10],i,j;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            dizi[i][j]=0;
            //  printf("%d ",dizi[i][j]);
        }
        //printf("\n");
    }
    int sayac=0;

    int satir[10],sutun[10];
    int m=0;

    int r_satir=rand()%10,r_sutun=rand()%10;
    satir[0]=r_satir,sutun[0]=r_sutun;

    int say=0;

    while(1)
    {
        r_satir=rand()%10;
        r_sutun=rand()%10;

        say=0;
        for(j=0; j<=m; j++)
        {
            if(r_satir==satir[j]&&r_sutun==sutun[j])
                say++;
        }

        if(say==1)
            continue;

        else if(say==0)
        {
            m++;
            satir[m]=r_satir;
            sutun[m]=r_sutun;
            //printf("(%d,%d)\n",satir[m],sutun[m]);
            sayac++;


        }
        if(sayac==9)break;

    }

//printf("\n");

    for(i=0; i<10; i++)
    {
        //printf("(%d,%d)\n",satir[i],sutun[i]);
    }

    int k;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<10; k++)
            {
                if(satir[k]==i&&sutun[k]==j)
                    dizi[i][j]=1;
            }
        }
    }
    //printf("\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            // printf("%d ",dizi[i][j]);
        }
        //printf("\n");
    }

    printf("\nMayin Tarlasi Ekrani:\n");
    printf(" ___a__b__c__d__e__f__g__h__i__j___\n");
    printf(" 1-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 2-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 3-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 4-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 5-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 6-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 7-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 8-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf(" 9-|__|__|__|__|__|__|__|__|__|__|_\n");
    printf("10-|__|__|__|__|__|__|__|__|__|__|_\n");

    printf("Girmek istediginiz kutu icin kutunun\nkoordinatlarini yazmalisiniz.(1a gibi)\n");

    int satir_sec,koordinat;
    char sutun_sec;
    sayac=0;

    int koordinat2;

    while(1)
    {
        printf("\nKutunun koordinatlarini girin:");
        scanf("%d%c",&satir_sec,&sutun_sec);
        fflush(stdin);
        //system("cls");

        while(1)
        {
            if(satir_sec>=1&&satir_sec<=10&&sutun_sec>='a'&&sutun_sec<='j')
                break;
            else
            {
                printf("Kutunun koordinatlarini tekrar girin\n");
                scanf("%d%c",&satir_sec,&sutun_sec);
                fflush(stdin);
                //system("cls");
            }
        }

        koordinat=sutun_sec-97;
//printf("koordinat:%d\n",koordinat);

        koordinat2=satir_sec-1;

        if(dizi[koordinat2][koordinat]==2)
        {
            printf("Bu kutu daha once secilmisti.\n");
        }

        else if(dizi[koordinat2][koordinat]!=1)
        {
            sayac++;
            printf("TEBRIKLER!!!\n");
            printf("Lutfen yeni kutu seciniz.\n");
            dizi[koordinat2][koordinat]=2;
        }
        else
        {
            if(sayac!=0)printf("Mayinli kutu.\nOyun %d adim sonra bitti.\n",sayac+1);
            else printf("Mayinli kutu.\nOyun bitti.\n");
            break;
        }

    }
}







