//
// Created by franc on 03.11.2022.
//

#ifndef PHOENIXSYSTEMTEST_IP_V4_H
#define PHOENIXSYSTEMTEST_IP_V4_H

/**
 * Dodanie prefiksu do zbioru.
 * @param base - wartość bazowa
 * @param mask - maska
 * @return 0 przy sukcesie, -1 dla błędnych danych
 */
int add(unsigned int base, char mask);

/**
 * Usunięcie prefiksu ze zbioru.
 * @param base - wartość bazowa
 * @param mask - maska
 * @return 0 przy sukcesie, -1 dla błędnych danych
 */
int del(unsigned int base, char mask);

/**
 * Sprawdzenie czy adres ip zawiera się w zbiorze prefiksów.
 * @param ip - adres
 * @return maska najmniejszego prefiksu (o największej wartości maski) w zbiorze, który zawiera wskazany adres.
 */
char check(unsigned int ip);

#endif //PHOENIXSYSTEMTEST_IP_V4_H