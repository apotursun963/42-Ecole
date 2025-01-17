
enum nedir ?
-----------
Enum (veya numaralandırma), C'de kullanıcı tanımlı bir veri türüdür. 
Esas olarak tamsayı sabitlerine isim atamak için kullanılır, 
isimler bir programın okunmasını ve bakımını kolaylaştırır.
ve sabitleri gruplandırmak için kullanılır. 
C'deki enum'lar, tam sayı sabitlerine isim atamanıza izin vererek kodu daha okunabilir hale getirir.
Sabitlere numaralar atanır ve varsayılan olarak bu numaralar 0'dan başlar.

amaç:
	Sabit değerleri gruplayarak anlamlı isimler oluşturmak.
veri türü:
    Sadece tamsayı sabitleri içerir.
Değişkenler: 
    Sabit (readonly) değerler içerir.

struct ise
amaç:
    Birden fazla türdeki değişkeni bir arada saklamak.
veri türü:
    Farklı türde değişkenler içerebilir.
Değişkenler:
    Dinamik ve değiştirilebilir değerler içerir.


/*
Tekrar edilecek konular
-----------------------
-Fonksiyon işaretçileri
-"Makefile (program run ve compile time) ve ileri seviye"
-"Compiler" "Flags" ve "Optimizasyon" (-Wall, -Werror, -O2, -g, gdb, valgrind...)
-"Header Dosyalar ("makro", "enum" "struct", "Include guard", "extern", "inline", "Preprocessor")
-Quick Sort ve Stack
-Time Complexity, Space Complexity, Big-O Notation
-Pointer, Pointer to Pointer, Adres Referansı
-Dinamik Bellek tahsisi (malloc, free, ..) ve bunlar hangi bellek alanında tahsis ediliyor
-Bazı bash komutları:
-shuf -i 1-1000 -n 10, find . -type f -name "*.c", tree, history, whereis,
-Bellek Düzeni (memory layout)
-ANSI kodu 
*/


ARG=($(shuf -i 1-2000000 -n 100)); ./push_swap $ARG | wc -l
ARG=($(seq -200000  200000 | shuf -n 100 | tr '\n' ' ')); ./push_swap $ARG | wc -l

fish:
set ARG (seq -200000 200000 | shuf -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l


Memory Leak Nedir
-----------------
Memory Leak (Bellek Sızıntısı), bir programın dinamik bellek ayırırken, 
bu belleği düzgün şekilde serbest bırakmaması sonucu belleğin boşuna tüketilmesidir. 
Yani, bir program belleği ayırır ancak bu belleği serbest bırakmazsa, 
bu bellek sistemde kullanılmaz halde kalır ve zamanla belleği tüketir. 
Bu da sistemin performansını olumsuz etkileyebilir.
Memory Leak Tespiti: "Valgrind" ve "AddressSanitizer"



Segmentation Fault Hatasına yol açan hatalar
--------------------------------------------
Segmentation Fault (Segfault) hatası, 
programın izin verilmeyen bir bellek alanına erişmeye çalışması nedeniyle oluşur. 

Segfault Türleri:
1. Dinamik olarak ayrılmayan bir bellek alanına erişmek: 
Bellek dinamik olarak ayrılmadan örneğin bir işaretçi kullanılarak erişim yapılmaya çalışıldığında oluşur.

2. Serbest bırakılmış bir alana erişmek: 
free() ile serbest bırakılmış bir bellek bloğuna tekrar erişmeye çalışmak.

3. Null (boş) bir işaretçiye erişmeye çalışmak: 
Bir işaretçi NULL veya nullptr olduğunda, ona erişim yapılmaya çalışıldığında segfault oluşur.

4. Özyinelemeli fonksiyon çağrılarında stack bellek sınırının aşılması:
Derin özyinelemeli (rekürsif) fonksiyon çağrıları nedeniyle stack belleği tükenebilir, 
bu da stack overflow'a yol açar.


Bus Error | Abort Error 
Buffer Overflow | Stack Overflow


zaman dalgası sorunları çözmek için
---
sudo date --set="2025-01-20 17:04:31"
