//
// Created by platon on 15.12.2021.
//

#ifndef THREADS_AVS_CABINET_H
#define THREADS_AVS_CABINET_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class Cabinet {
public:
    static void visitCabinetFirst(int id);
    static void visitDoctor(int id, int doctor);
    static void visitCabinetSecond(int id);

};

#endif //THREADS_AVS_CABINET_H
