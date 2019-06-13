/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:32:33 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/06/13 15:55:19 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data {
    int n;
    std::string s1;
    std::string s2;
};

void* serialize(void) {
    Data* dataPtr = new Data;
    std::string alphaNumerics = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (size_t i = 0; i < 8; i++)
        dataPtr->s1 += alphaNumerics[rand() % 61];
    dataPtr->n = rand();
    for (size_t i = 0; i < 8; i++)
        dataPtr->s2 += alphaNumerics[rand() % 61];
    return dataPtr;
}

Data* deserialize(void* raw) {
    Data* res = reinterpret_cast<Data*>(raw);
    return res;
}

int main() {
    srand(time(NULL));
    void* serialize = serialize();
    Data* deserialize = deserialize(serialize);
    return 0;
}
