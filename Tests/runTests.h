//
// Created by geo_r on 24/05/2021.
//
#include "testGenerateId.h"
#include "TestEntities.h"
#include "TestRepo.h"
#include "testService.h"
#include <iostream>

using namespace std;
void runAll()
{
    test();
    testEntities();
    testRepo();
    testService();
    cout << "Testele trec";
}