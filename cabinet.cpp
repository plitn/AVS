//
// Created by platon on 15.12.2021.
//
#include "cabinet.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex m;

void Cabinet::visitCabinetFirst(int id) {
    m.lock();
    int sleep_time = std::rand() % 200;
    std::cout << "Пациент №" << id << " Вошел в кабинет распределения №1 и пробыл там " << sleep_time << '\n';


    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
    m.unlock();
    Cabinet::visitDoctor(id, std::rand() % 3);
}

void Cabinet::visitCabinetSecond(int id) {
    m.lock();
    int sleep_time = std::rand() % 200;
    std::cout << "Пациент №" << id << " Вошел в кабинет распределения №2 и пробыл там " << sleep_time << '\n';


    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
    m.unlock();
    Cabinet::visitDoctor(id, std::rand() % 3);
}


void Cabinet::visitDoctor(int id, int doctor) {
    int sleep_time = std::rand() % 200;
    if (doctor == 1) {
        m.lock();
        std::cout << "Пациент №" << id << " Вошел в кабинет хирурга и пробыл там " << sleep_time << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        m.unlock();
    } else if (doctor == 2) {
        m.lock();
        std::cout << "Пациент №" << id << " Вошел в кабинет стоматолога и пробыл там " << sleep_time << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        m.unlock();
    } else if (doctor == 0) {
        m.lock();
        std::cout << "Пациент №" << id << " Вошел в кабинет терапевта и пробыл там " << sleep_time << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        m.unlock();
    }
}
