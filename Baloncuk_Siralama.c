#include <stdio.h> 

// Özgür SULHAN 
// 2420171011  
// Sertifika Bağlantısı: https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=OKMhwoGk0v 

void dizi_yazdir(int dizi[], int BOYUT) { 

    int i; 
    for (i = 0; i < BOYUT; i++) { 
        printf("%3d", dizi[i]); 
    } 

    printf("\n"); 

} 

void takas(int *ap, int *bp) { 

    int gecici = *ap; 
    *ap = *bp; 
    *bp = gecici; 
} 

// Baloncuk Sıralaması  
void baloncuk_sirala(int dizi[], int BOYUT) { 

    int i, j; 

    for(i = 1; i < BOYUT; i++) { 
        for (j = 0; j < BOYUT - 1; j++) { 
            if (dizi[j] > dizi[j+1]) { 
            
                takas(dizi + j, dizi + j + 1); 

            } 

        } 
        printf("iter.%2d: ", i); 
        dizi_yazdir(dizi, BOYUT); 

    } 
    printf("-------------------------\n"); 

} 

// İkili Arama  

int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) { 

    int orta_ind = (ilk_ind + son_ind) / 2; 

    if (ilk_ind > son_ind) { 

        return -1; 

    } 
    if (search == dizi[orta_ind]) { 

        return orta_ind; 

    } 
    else if (search > dizi[orta_ind]) { 

        return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind); 

    } 
    else { 

        return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1); 

    } 

} 

 
int main() { 

    int A[] = {45, 10, 88, 7, 23, 15, 3, 67, 32, 99}; 
    int N = sizeof(A) / sizeof(A[0]); 
    int aranan, sonuc; 

 
    printf("Orijinal Dizi:\n"); 
    dizi_yazdir(A, N); 
    printf("\n"); 

    baloncuk_sirala(A, N); 
    printf("Siralanmis Sonuc Dizisi:\n"); 
    dizi_yazdir(A, N); 

     
    printf("Aramak istediginiz deger:\n"); 
    scanf("%d", &aranan); 

    sonuc = ikili_arama(A, N, aranan, 0, N - 1); 

    if (sonuc == -1) { 

        printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan); 

    } 

    else { 

        printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc); 

    }   

    return 0; 

} 