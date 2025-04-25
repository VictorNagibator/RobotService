#pragma once
#include <iostream>
#include <windows.h>

#include "GroundEnvironment.h"             
#include "AirEnvironment.h"               
#include "GPSNavigation.h"               
#include "ElectricMotorFactory.h"           
#include "StandartGroundRobotFactory.h"      
#include "CentralController.h"      
#include "MyList.h"                          
#include "BasicRobotExpert.h"                
#include "RobotManager.h"                    
#include "DetailedMapSegmentBuilder.h"       
#include "AdvancedMapDirector.h"            
#include "StreetSegmentFactory.h"                     
#include "SimpleRobot.h"    
#include "StandartDroneFactory.h"
#include "CellularCommunication.h"

int main() {
    //Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    return 0;
}