//
// Created by eyal on 19/12/18.
//

#include "symTblClass.h"

map<string,double> symTblClass::symTbl = {};// the symbol table
map<string,string> symTblClass::bindedSymTbl = {};// binded symbols table
TCPClient symTblClass::client = TCPClient(); // the client for the set commands

//the samples values initalized!
atomic<double> symTblClass::airspeed_indicator_indicated_speed_kt(0);
atomic<double> symTblClass::altimeter_indicated_altitude_ft(0);
atomic<double> symTblClass::altimeter_pressure_alt_ft(0);
atomic<double> symTblClass::attitude_indicator_indicated_pitch_deg(0);
atomic<double> symTblClass::attitude_indicator_indicated_roll_deg(0);
atomic<double> symTblClass::attitude_indicator_internal_pitch_deg(0);
atomic<double> symTblClass::attitude_indicator_internal_roll_deg(0);
atomic<double> symTblClass::encoder_indicated_altitude_ft(0);
atomic<double> symTblClass::encoder_pressure_alt_ft(0);
atomic<double> symTblClass::gps_indicated_altitude_ft(0);
atomic<double> symTblClass::gps_indicated_ground_speed_kt(0);
atomic<double> symTblClass::gps_indicated_vertical_speed(0);
atomic<double> symTblClass::indicated_heading_deg(0);
atomic<double> symTblClass::magnetic_compass_indicated_heading_deg(0);
atomic<double> symTblClass::slip_skid_ball_indicated_slip_skid(0);
atomic<double> symTblClass::turn_indicator_indicated_turn_rate(0);
atomic<double> symTblClass::vertical_speed_indicator_indicated_speed_fpm(0);
atomic<double> symTblClass::flight_aileron(0);
atomic<double> symTblClass::flight_elevator(0);
atomic<double> symTblClass::flight_rudder(0);
atomic<double> symTblClass::flight_flaps(0);
atomic<double> symTblClass::engine_throttle(0);
atomic<double> symTblClass::engine_rpm(0);

//add symbol to the map
bool symTblClass::addSym(const string newSym) {
    for(auto oldSym : symTbl) {
        if (newSym == oldSym.first)
            return false; //returns false if the symbol already exist in the table
    }
    symTbl.emplace(pair<string,double>(newSym,0.0));
    return true;// emplaced successfully
}

bool symTblClass::addBinded(const string newBinded, const string newBind) {
    bindedSymTbl[newBinded] = newBind;
}

//method to set the values in the symbol table
bool symTblClass::setSym(const string symbl, const double newVal) {
    //if its binded need to send set command
    double test = -1; //TODO: need to remove and replace with the actual value
    if(isBinded(symbl)){
        string setCommand = "set " + bindedSymTbl[symbl] + " " + to_string(test) + "\r\n\r\n";
        symTblClass::client.send_data(setCommand);
    }
    auto it = symTbl.find(symbl);
    if (it != symTbl.end()){
        (*it).second = newVal;
        return true;//return true if changed sucessefully
    }
    // if we got here it means there is no symbol with this name
    return false;
}

//gets value of a certain symbol
double symTblClass::getVlaue(const string symbl) {
    if(isBinded(symbl)){
        return (GetValueOfBinded(getBind(symbl)));
    }
    for(auto pair : symTbl) {
        if (symbl == pair.first)
            return pair.second; //returns the value of the symbol
    }
    //if we got here it means the symbl doesnt exist in the map
    throw("symbl doesnt exist in the map");
}

// gets the value of a binded parameter
double symTblClass::GetValueOfBinded(string bind) {
    if(bind == "/instrumentation/airspeed-indicator/indicated-speed-kt")
    {
        return symTblClass::airspeed_indicator_indicated_speed_kt.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/altimeter/indicated-altitude-ft")
    {
        return symTblClass::altimeter_indicated_altitude_ft.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/altimeter/pressure-alt-ft")
    {
        return symTblClass::altimeter_pressure_alt_ft.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/attitude-indicator/indicated-pitch-deg")
    {
        return symTblClass::attitude_indicator_indicated_pitch_deg.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/attitude-indicator/indicated-roll-deg")
    {
        return symTblClass::attitude_indicator_indicated_roll_deg.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/attitude-indicator/internal-pitch-deg")
    {
        return symTblClass::attitude_indicator_internal_pitch_deg.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/attitude-indicator/internal-roll-deg")
    {
        return symTblClass::attitude_indicator_internal_roll_deg.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/encoder/indicated-altitude-ft")
    {
        return symTblClass::encoder_indicated_altitude_ft.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/encoder/pressure-alt-ft")
    {
        return symTblClass::encoder_pressure_alt_ft.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/gps/indicated-altitude-ft")
    {
        return symTblClass::gps_indicated_altitude_ft.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/gps/indicated-ground-speed-kt")
    {
        return symTblClass::gps_indicated_ground_speed_kt.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/gps/indicated-vertical-speed")
    {
        return symTblClass::gps_indicated_vertical_speed.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/heading-indicator/indicated-heading-deg")
    {
        return symTblClass::indicated_heading_deg.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/magnetic-compass/indicated-heading-deg")
    {
        return symTblClass::magnetic_compass_indicated_heading_deg.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/slip-skid-ball/indicated-slip-skid")
    {
        return symTblClass::slip_skid_ball_indicated_slip_skid.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/turn-indicator/indicated-turn-rate")
    {
        return symTblClass::turn_indicator_indicated_turn_rate.load(memory_order_seq_cst);
    }
    else if(bind == "/instrumentation/vertical-speed-indicator/indicated-speed-fpm")
    {
        return symTblClass::vertical_speed_indicator_indicated_speed_fpm.load(memory_order_seq_cst);
    }
    else if(bind == "/controls/flight/aileron")
    {
        return symTblClass::flight_aileron.load(memory_order_seq_cst);
    }
    else if(bind == "/controls/flight/elevator")
    {
        return symTblClass::flight_elevator.load(memory_order_seq_cst);
    }
    else if(bind == "/controls/flight/rudder")
    {
        return symTblClass::flight_rudder.load(memory_order_seq_cst);
    }
    else if(bind == "/controls/flight/flaps")
    {
        return symTblClass::flight_flaps.load(memory_order_seq_cst);
    }
    else if(bind == "/controls/engines/engine/throttle")
    {
        return symTblClass::engine_throttle.load(memory_order_seq_cst);
    }
    else
    {
        return symTblClass::engine_rpm.load(memory_order_seq_cst);
    }
}

//looking if the string is a valid symbol
bool symTblClass::isSym(const string symbl) {
    for(auto pair : symTbl) {
        if (symbl == pair.first)
            return true;
    }
    return false;
}
// check if a symbol is binded
bool symTblClass::isBinded(const string binded) {
    for(auto pair : bindedSymTbl) {
        if (binded == pair.first)
            return true;
    }
    return false;
}

string symTblClass::getBind(string binded) {
    return bindedSymTbl[binded];
}

