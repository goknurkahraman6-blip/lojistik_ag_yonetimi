# Lojistik Yönetim Sistemi (Graf + Hash Tablosu Hibrit Yapı)

Bu proje, **Veri Yapıları ve Algoritmalar Dersi Final Değerlendirme Ödevi-4** kapsamında geliştirilmiştir. Projenin amacı, bir lojistik firmasının şehirler arası bağlantılarını graf yapısı ile modellemek ve şehirlerdeki paket bilgilerine hızlıca sorgulanabilmesini sağlamak için hibrit bir veri yapısı sistemi kurmaktır.

---

## 1. Proje Teknik Özellikleri

* **Hash Fonksiyonu:** Tip A (Modulo m: `h(k) = k mod 10`) ( son rakamı çift).
* **Collision (Çakışma) Yöntemi:** Açık Adresleme (Linear Probing) ( son rakamı 4, 0-4 arası).
* **Graf Gezinme Algoritması:** BFS (Breadth First Search) ( sondan 2. rakamı 2, çift).

---

## 2. Sistem Mimarisi ve Veri Yapıları

Sistem, iki temel veri yapısını lojistik senaryosuna hibrit olarak entegre eder:

### 2.1. Graf Yapısı (Şehir Bağlantıları)
* **Temsil:** Şehirler düğüm (vertex), yollar kenar (edge) olarak modellenmiştir.
* **Depolama:** Bellek yönetimi için **Komşuluk Listesi (Adjacency List)** yapısı kullanılmıştır.
* **Gezinme:** Şehirler arası ağ taraması **BFS** algoritması ile katman katman gerçekleştirilir.

### 2.2. Hash Tablosu (Paket Yönetimi)
* **Temsil:** Paket ID'si ile paket detayları (içerik) eşleştirilir.
* **İndeksleme:** **Tip A** hash fonksiyonu ile O(1) sürede erişim hedeflenir.
* **Çakışma Çözümü:** İndeks çakışmalarında **Linear Probing** ile bir sonraki boş hücreye yerleşim yapılır.

---

## 3. Proje Dosya Yapısı (Modular Structure)

Hocamızın isteğine uygun olarak, proje mantıksal katmanlarına göre ayrılmış çok dosyalı bir yapıda (`inner files`) geliştirilmiştir:

* `src/`
    * `common.h`: Ortak kütüphaneler, sabitler ve makrolar.
    * `graph.h` / `graph.c`: Graf düğüm yapıları, bağlantı ekleme ve BFS gezinme fonksiyonları.
    * `hash.h` / `hash.c`: Paket yapıları, hash fonksiyonu, Linear Probing ve bellek durum fonksiyonları.
    * `main.c`: Kullanıcı arayüzü menüsü ve hibrit yapının kontrolü.
* `README.md`: Proje tanıtım ve kullanım dosyası.

---

## 4. Kurulum ve Çalıştırma

Projeyi yerel makinenizde derleyip çalıştırmak için aşağıdaki adımları izleyebilirsiniz:

### 4.1. Gereksinimler
* Bir C Derleyicisi (GCC, Clang, TDM-GCC vb.) (TDM-GCC Recommended).
* (İsteğe bağlı) Make (Makefile kullanıyorsanız).

### 4.2. Derleme (Compile)
Terminal veya Komut İstemi (CMD) üzerinden projenin bulunduğu klasöre gidin ve aşağıdaki komutu çalıştırın:

```bash
# Tüm C dosyalarını birlikte derleme
gcc -o lojistik_sistemi common.h graph.c graph.h hash.c hash.h main.c
